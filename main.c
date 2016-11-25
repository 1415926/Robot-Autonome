/*
 * 	Project App Robot
 * 	Author : Paul Bouquet
 * 	Name : main.c
 * 	Version : 2.0
 * 	Date : 15/11/2016
 * 	Functions :
*/

#include "main.h"

// Initialise tous les ports utiles
void init_ports(void){
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	// PDIR
	//P1DIR
	P1DIR |= (LED1 | LED2 | LED3 | LED4);
	P1OUT &= ~(LED1 | LED2 | LED3 | LED4);
	//P2DIR
	P2DIR |= (BIT1 | BIT2 | BIT4 | BIT5);
	P2OUT &= ~(BIT1 | BIT2 | BIT4 | BIT5);

	// PSEL
	P2SEL |= (MOTEUR_GAUCHE|MOTEUR_DROIT);

	// Interruptions enable
	P1IE |= (CAPTEUR_BLANCHE_GAUCHE); // Capteur Blanche Gauche
	P1IE |= (CAPTEUR_BLANCHE_CENTRE); // Capteur Blanche Centre
	P1IE |= (CAPTEUR_BLANCHE_DROIT); // Capteur Blanche Droite
	P1IE |= (CAPTEUR_OBSTACLE); // Capteur Obstacle

	// Define front
	P1IES &= ~CAPTEUR_BLANCHE_GAUCHE; // Font descendant
	P1IES &= ~CAPTEUR_BLANCHE_CENTRE; // Font descendant
	P1IES &= ~CAPTEUR_BLANCHE_DROIT; // Font descendant
	P1IES &= ~CAPTEUR_OBSTACLE; // Font descendant

	// Reset des flags
	P1IFG &= ~(CAPTEUR_BLANCHE_GAUCHE);
	P1IFG &= ~(CAPTEUR_BLANCHE_CENTRE);
	P1IFG &= ~(CAPTEUR_BLANCHE_DROIT);
	P1IFG &= ~(CAPTEUR_OBSTACLE);
}

void init_pwm(){
	BCSCTL1 = CALBC1_1MHZ; //FrÃ©quence d'horloge 1MHz
	DCOCTL = CALDCO_1MHZ; //FrÃ©quence d'horloge 1MHz
	TA1CTL = TASSEL_2 | MC_1 | ID_0;
	TA1CCTL1 = OUTMOD_7;
	TA1CCTL2 = OUTMOD_7;
	TA1CCR0 = 4000;
}

/**
 * Move
 */
void start(int roue_right, int roue_left){
	set_sens_straight();
	TA1CCR1 = roue_right;
	TA1CCR2 = roue_left;
}

void stop(){
	start(0,0);
}

void left90(void){
	do{
		P2OUT	|= (ROUE_GAUCHE);
		P2OUT	|= (MOTEUR_DROIT|ROUE_DROITE);
		P2OUT	&=~ (MOTEUR_GAUCHE);
	}while(test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE));
	P2OUT &=~ (MOTEUR_GAUCHE|MOTEUR_DROIT);
}

void right90(void){
	do{
	    P2OUT	|=  (MOTEUR_GAUCHE);
	    P2OUT	&=~ (ROUE_GAUCHE|ROUE_DROITE);
	    P2OUT	&=~ (MOTEUR_DROIT);
	}while(test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE));
	P2OUT &=~ (MOTEUR_GAUCHE|MOTEUR_DROIT);
}

void set_sens_straight(){
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
}

void set_sens_right(){
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT &=~ ROUE_DROITE; //sens
}

void set_sens_left(){
	P2OUT |= (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
}


/**
 * GPS
 */
// Associe le tableau du circuit a celui choisi
const int * get_circuit(void){
	switch(MAIN_PARAM){
		case 1:  return C1;
		case 2:  return C2;
		case 3:  return C3;
		case 4:  return C4;
		case 5:  return C5;
		case 6:  return C6;
		case 7:  return C7;
		case 8:  return C8;
		case 9:  return C9;
		case 10: return C10;
		case 11: return C11;
		case 12: return C12;
		default: return 0;
	}
}

// retourne le nombre d'intersection attendue
int get_next_inter(int index, const int * circuit){
	return circuit[index+1];
}


int main(void){
	/**
	 * INITIALISATION
	 */
	init_ports();
	init_pwm();
	engine		= ENGINE_STRAIGHT;

	// INIT circuit
	circuit_index	= 0;
	next_inter_side = get_next_inter(circuit_index, get_circuit());
	__enable_interrupt();
	while(1){

		/**
		 * LED
		 */
		// Ligne centrale
		if(test_capt(CAPTEUR_BLANCHE_CENTRE)){
			P1OUT |= LED3;
		}else{
			P1OUT &=~ LED3;
		}

		// Capteur obstacle test
		if(test_capt(CAPTEUR_OBSTACLE)){
			P1OUT |= LED4;
		}else{
			P1OUT &=~ LED4;
		}

		// Gauche
		if(test_capt(CAPTEUR_BLANCHE_GAUCHE)){
			P1OUT |= LED1;
		}else{
			P1OUT &=~ LED1;
		}

		//Droite
		if(test_capt(CAPTEUR_BLANCHE_DROIT)){
			P1OUT |= LED2;
		}else{
			P1OUT &=~ LED2;
		}

		// STATE
		switch (engine){
		case ENGINE_RIGHT:			right90();break;
		case ENGINE_LEFT:			left90();break;
		case ENGINE_STOP:			stop();break;
		case ENGINE_STRAIGHT:		start(MOTEUR_DROIT_PWM, MOTEUR_GAUCHE_PWM);
									break;
		case ENGINE_CORRECT_RIGHT:  start(TURN_PWM, MOTEUR_GAUCHE_PWM);
									break;
		case ENGINE_CORRECT_LEFT:  	start(MOTEUR_DROIT_PWM, TURN_PWM);
									break;
		default:					start(MOTEUR_DROIT_PWM, MOTEUR_GAUCHE_PWM);
									break;
		}
	}
}

// Interruption capteur
#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR(void) {

	engine = 0;

	/**
	 * OBSTACLE
	 */
	if(!test_capt(CAPTEUR_OBSTACLE)){
		engine = ENGINE_STOP;
	}

	/**
	 * Perte ligne centrale
	 */
	// Ligne extérieure + !centre = Repositionnement
	if(!test_capt(CAPTEUR_BLANCHE_CENTRE) && engine == 0){
		// repositionnement à gauche
		if((test_capt(CAPTEUR_BLANCHE_DROIT) && !test_capt(CAPTEUR_BLANCHE_GAUCHE))){
			engine = ENGINE_CORRECT_LEFT;
		}else{
		// repositionnement à droite
		//if((test_capt(CAPTEUR_BLANCHE_GAUCHE) && !test_capt(CAPTEUR_BLANCHE_DROIT))){
			engine = ENGINE_CORRECT_RIGHT;
		}
	}else{
		// Ligne extérieure droite + milieu + !gauche --> intersection à droite
		if (test_capt(CAPTEUR_BLANCHE_DROIT) && !test_capt(CAPTEUR_BLANCHE_GAUCHE) && engine == 0){
			engine = ENGINE_RIGHT;
			/*if(next_inter_side == DROITE){
				engine = ENGINE_RIGHT;
				next_inter_side = get_next_inter(circuit_index, get_circuit());
				circuit_index++;
			}else if(next_inter_side == AVANCE){
				engine = ENGINE_STRAIGHT;
				next_inter_side = get_next_inter(circuit_index, get_circuit());
				 circuit_index++;
			}*/
		}

		// Ligne extérieure gauche + milieu + !droite --> intersection à gauche
		else if (!test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_GAUCHE) && engine == 0){
			engine = ENGINE_LEFT;
			/*if(next_inter_side == GAUCHE){
				engine = ENGINE_LEFT;
				next_inter_side = get_next_inter(circuit_index, get_circuit());
				circuit_index++;
			}else if(next_inter_side == AVANCE){
				engine = ENGINE_STRAIGHT;
				next_inter_side = get_next_inter(circuit_index, get_circuit());
				circuit_index++;
			}*/
		}

		// Ligne extérieure gauche & droite + milieu --> intersection à gauche et à droite
		else if (test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_GAUCHE) && engine == 0){
			engine = ENGINE_LEFT;
			/*if(next_inter_side == GAUCHE){
				engine = ENGINE_LEFT;
				next_inter_side = get_next_inter(circuit_index, get_circuit());
				circuit_index++;
			}else if(next_inter_side == DROITE){
				engine = ENGINE_RIGHT;
				next_inter_side = get_next_inter(circuit_index, get_circuit());
				circuit_index++;
			}else if(next_inter_side == AVANCE){
				engine = ENGINE_STRAIGHT;
				next_inter_side = get_next_inter(circuit_index, get_circuit());
				circuit_index++;
			}*/

		// TOUT à zéro
		}
		/*}else if(!test_capt(CAPTEUR_BLANCHE_DROIT) && !test_capt(CAPTEUR_BLANCHE_GAUCHE) && engine == 0){
			engine = ENGINE_STOP;
		}*/
	}

	if(engine == 0){
		engine = ENGINE_STRAIGHT;
	}

	reset_capt(CAPTEUR_BLANCHE_CENTRE);
	reset_capt(CAPTEUR_BLANCHE_DROIT);
	reset_capt(CAPTEUR_BLANCHE_GAUCHE);
	reset_capt(CAPTEUR_OBSTACLE);
}
