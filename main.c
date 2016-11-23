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
	P2SEL |= (BIT2|BIT4);
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
	P1IES &= ~CAPTEUR_OBSTACLE; // Font descendant

	// Reset des flags
	P1IFG &= ~(CAPTEUR_BLANCHE_GAUCHE);
	P1IFG &= ~(CAPTEUR_BLANCHE_CENTRE);
	P1IFG &= ~(CAPTEUR_BLANCHE_DROIT);
	P1IFG &= ~(CAPTEUR_OBSTACLE);

	// Optocoupleur
	/*P2IE |= BIT0 | BIT3; // activation de l'interruption
	P2IES &= ~BIT0 | ~BIT3; // Detection sur front montant
	P2IFG &= ~BIT0 | ~BIT3; // Flag � 0*/
}

void init_pwm(){
	BCSCTL1 = CALBC1_1MHZ; //Fréquence d'horloge 1MHz
	DCOCTL = CALDCO_1MHZ; //Fréquence d'horloge 1MHz
	TA1CTL = TASSEL_2 | MC_1 | ID_0;
	TA1CCTL1 = OUTMOD_7;
	TA1CCTL2 = OUTMOD_7;
	TA1CCR0 = 4000;
}

/**
 * Move
 */
void motor(){
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;
}
void start(){
	motor();
	set_sens_avant();
}
void stop(){
	P2OUT &=~ (MOTEUR_GAUCHE|MOTEUR_GAUCHE);
}

void left90(){

}

void right90(){

}

int main(void){
	/**
	 * INITIALISATION
	 */
	init_ports();
	init_pwm();
	init_move();

	// INIT circuit
	//get_next_inter(circuit_index, next_inter_side, get_circuit());

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
		case ENGINE_STRAIGHT:		start();break;
		case ENGINE_CORRECT_RIGHT:  rotation_right();break;
		case ENGINE_CORRECT_LEFT:  	rotation_left();break;
		default:					start();break;
		}
	}
}



// Interruption capteur
#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR(void) {
	// Capteur obstacle test
	if(test_capt(CAPTEUR_OBSTACLE)){
		stop();
	}

	/**
	 * Perte ligne centrale
	 */
	// Ligne ext�rieure + !centre = Repositionnement
	if(!test_capt(CAPTEUR_BLANCHE_CENTRE)){
		// repositionnement � gauche
		if((test_capt(CAPTEUR_BLANCHE_DROIT) && !test_capt(CAPTEUR_BLANCHE_GAUCHE))){
			engine = ENGINE_CORRECT_LEFT;
		}
		// repositionnement � droite
		if((test_capt(CAPTEUR_BLANCHE_GAUCHE) && !test_capt(CAPTEUR_BLANCHE_DROIT))){
			engine = ENGINE_CORRECT_RIGHT;
		}
	}
	// Ligne ext�rieure droite + milieu + !gauche --> intersection � droite
	else if (test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE) && !test_capt(CAPTEUR_BLANCHE_GAUCHE)){
		if(*next_inter_side == DROITE){
			engine = ENGINE_RIGHT;
			get_next_inter(circuit_index, next_inter_side, get_circuit());
		}else if(*next_inter_side == AVANCE){
			engine = ENGINE_STRAIGHT;
			get_next_inter(circuit_index, next_inter_side, get_circuit());
		}
	}
	// Ligne ext�rieure gauche + milieu + !droite --> intersection � gauche
	else if (!test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE) && test_capt(CAPTEUR_BLANCHE_GAUCHE)){
		if(*next_inter_side == GAUCHE){
			engine = ENGINE_LEFT;
			get_next_inter(circuit_index, next_inter_side, get_circuit());
		}else if(*next_inter_side == AVANCE){
			engine = ENGINE_STRAIGHT;
			get_next_inter(circuit_index, next_inter_side, get_circuit());
		}
	}
	// Ligne ext�rieure gauche & droite + milieu --> intersection � gauche et � droite
	else if (test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE) && test_capt(CAPTEUR_BLANCHE_GAUCHE)){
		if(*next_inter_side == GAUCHE){
			engine = ENGINE_LEFT;
			get_next_inter(circuit_index, next_inter_side, get_circuit());
		}else if(*next_inter_side == DROITE){
			engine = ENGINE_RIGHT;
			get_next_inter(circuit_index, next_inter_side, get_circuit());
		}else if(*next_inter_side == AVANCE){
			engine = ENGINE_STRAIGHT;
			get_next_inter(circuit_index, next_inter_side, get_circuit());
		}
	}
	reset_capt(CAPTEUR_BLANCHE_CENTRE);
	reset_capt(CAPTEUR_BLANCHE_DROIT);
	reset_capt(CAPTEUR_BLANCHE_GAUCHE);
	reset_capt(CAPTEUR_OBSTACLE);
}
