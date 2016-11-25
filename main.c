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
	/*P2SEL |= (MOTEUR_GAUCHE | MOTEUR_DROIT);
	P2SEL2|= (MOTEUR_GAUCHE | MOTEUR_DROIT);*/

	// Interruptions enable
	P1IE |= (CAPTEUR_BLANCHE_GAUCHE); // Capteur Blanche Gauche
	P1IE |= (CAPTEUR_BLANCHE_CENTRE); // Capteur Blanche Centre
	P1IE |= (CAPTEUR_BLANCHE_DROIT); // Capteur Blanche Droite
	P1IE |= (CAPTEUR_OBSTACLE); // Capteur Obstacle

	// Define front
	P1IES &= ~CAPTEUR_BLANCHE_GAUCHE; // Font descendant
	P1IES &= ~CAPTEUR_BLANCHE_CENTRE; // Font descendant
	P1IES &= ~CAPTEUR_BLANCHE_DROIT; // Font descendant
	P1IES |= CAPTEUR_OBSTACLE; // Font descendant

	// Reset des flags
	P1IFG &= ~(CAPTEUR_BLANCHE_GAUCHE);
	P1IFG &= ~(CAPTEUR_BLANCHE_CENTRE);
	P1IFG &= ~(CAPTEUR_BLANCHE_DROIT);
	P1IFG &= ~(CAPTEUR_OBSTACLE);

	// Optocoupleur
	/*P2IE |= BIT0 | BIT3; // activation de l'interruption
	P2IES &= ~BIT0 | ~BIT3; // Detection sur front montant
	P2IFG &= ~BIT0 | ~BIT3; // Flag ‡ 0*/
}

void init_pwm(){
	BCSCTL1 = CALBC1_1MHZ; //Fr√©quence d'horloge 1MHz
	DCOCTL = CALDCO_1MHZ; //Fr√©quence d'horloge 1MHz
	TA1CTL = TASSEL_2 | MC_1 | ID_0;
	TA1CCTL1 = OUTMOD_7;
	TA1CCTL2 = OUTMOD_7;
	TA1CCR0 = 4000;
}

/**
 * Move
 */
void start(int roue_right, int roue_left){
	//TAIFG &=~ (MOTEUR_GAUCHE|MOTEUR_DROIT);
	set_sens_straight();
	TA1CCR1 = roue_right;
	TA1CCR2 = roue_left;
}
void stop(){
	//TAIFG |= (MOTEUR_GAUCHE|MOTEUR_DROIT);
	//P2OUT &=~ (MOTEUR_GAUCHE|MOTEUR_GAUCHE);
}

void left90(){
	start(MOTEUR_DROIT_PWM, 0);
}

void right90(){
	start(0, MOTEUR_GAUCHE_PWM);
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
	roue_left 	= MOTEUR_GAUCHE_PWM;
	roue_right  = MOTEUR_DROIT_PWM;
	set_sens_straight();

	// INIT circuit
	circuit_index	= 0;
	next_inter_side = get_next_inter(circuit_index, get_circuit());
	__enable_interrupt();
	while(1){

		if(TA1CCR0 < 3000){
			engine = ENGINE_LEFT;
			P1OUT |= LED1;
			P1OUT &=~ LED2;
		}else{
			engine = ENGINE_STRAIGHT;
			P1OUT |= LED2;
			P1OUT &=~ LED1;
		}
			/*else if(test == 2){
			engine = ENGINE_STRAIGHT;
			test++;
		}else if(test == 3){
			engine = ENGINE_RIGHT;
			test++;
		}else if(test == 4){
			engine = ENGINE_STOP;
			test = 1;
		}*/

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

		/*// Gauche
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
		}*/

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
	/**
	 * OBSTACLE
	 */
	if(test_capt(CAPTEUR_OBSTACLE)){
		stop();
	}

	/**
	 * Perte ligne centrale
	 */
	// Ligne extÈrieure + !centre = Repositionnement
	/*if(!test_capt(CAPTEUR_BLANCHE_CENTRE)){
		// repositionnement ‡ gauche
		if((test_capt(CAPTEUR_BLANCHE_DROIT) && !test_capt(CAPTEUR_BLANCHE_GAUCHE))){
			engine = ENGINE_CORRECT_LEFT;
		}
		// repositionnement ‡ droite
		if((test_capt(CAPTEUR_BLANCHE_GAUCHE) && !test_capt(CAPTEUR_BLANCHE_DROIT))){
			engine = ENGINE_CORRECT_RIGHT;
		}
	}
	// Ligne extÈrieure droite + milieu + !gauche --> intersection ‡ droite
	else if (test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE) && !test_capt(CAPTEUR_BLANCHE_GAUCHE)){
		if(next_inter_side == DROITE){
			engine = ENGINE_RIGHT;
			get_next_inter(circuit_index, get_circuit());
			circuit_index++;
		}else if(next_inter_side == AVANCE){
			engine = ENGINE_STRAIGHT;
			get_next_inter(circuit_index, get_circuit());
			 circuit_index++;
		}
	}
	// Ligne extÈrieure gauche + milieu + !droite --> intersection ‡ gauche
	else if (!test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE) && test_capt(CAPTEUR_BLANCHE_GAUCHE)){
		if(next_inter_side == GAUCHE){
			engine = ENGINE_LEFT;
			get_next_inter(circuit_index, get_circuit());
			circuit_index++;
		}else if(next_inter_side == AVANCE){
			engine = ENGINE_STRAIGHT;
			get_next_inter(circuit_index, get_circuit());
			circuit_index++;
		}
	}
	// Ligne extÈrieure gauche & droite + milieu --> intersection ‡ gauche et ‡ droite
	else if (test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE) && test_capt(CAPTEUR_BLANCHE_GAUCHE)){
		if(next_inter_side == GAUCHE){
			engine = ENGINE_LEFT;
			get_next_inter(circuit_index, get_circuit());
			circuit_index++;
		}else if(next_inter_side == DROITE){
			engine = ENGINE_RIGHT;
			get_next_inter(circuit_index, get_circuit());
			circuit_index++;
		}else if(next_inter_side == AVANCE){
			engine = ENGINE_STRAIGHT;
			get_next_inter(circuit_index, get_circuit());
			circuit_index++;
		}
	}else{
		engine = ENGINE_STRAIGHT;
	}
	reset_capt(CAPTEUR_BLANCHE_CENTRE);
	reset_capt(CAPTEUR_BLANCHE_DROIT);
	reset_capt(CAPTEUR_BLANCHE_GAUCHE);
	reset_capt(CAPTEUR_OBSTACLE);*/
}
