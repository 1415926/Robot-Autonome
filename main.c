/*
 * 	Project App Robot
 * 	Author : Paul Bouquet
 * 	Name : main.c
 * 	Version : 1.0
 * 	Date : 15/11/2016
 * 	Functions :
*/

#include "main.h"

// Initialise tous les ports utiles
void init_ports(void){
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	// PDIR
	//P1DIR
	P1DIR |= BIT6;
	P1OUT &= ~BIT6;
	P1DIR |= BIT0;
	P1OUT &= ~BIT0;
	//P2DIR
	P2DIR |= (BIT1 | BIT2 | BIT4 | BIT5);

	// PSEL
	P1SEL = 0x00;
	P1SEL2 = 0x00;
	P2SEL = 0x00;
	P2SEL2 = 0x00;

	// Interruptions enable
	P1IE |= (CAPTEUR_BLANCHE_GAUCHE); // Capteur Blanche Gauche
	P1IE |= (CAPTEUR_BLANCHE_CENTRE); // Capteur Blanche Centre
	P1IE |= (CAPTEUR_BLANCHE_DROIT); // Capteur Blanche Droite
	P1IE |= (CAPTEUR_OBSTACLE); // Capteur Obstacle
	P2IE |= (MOTEUR_GAUCHE); // Moteur gauche
	P2IE |= (MOTEUR_DROIT); // Moteur droit

	// Define front
	P1IES |= CAPTEUR_BLANCHE_GAUCHE; // Font descendant
	P1IES |= CAPTEUR_BLANCHE_CENTRE; // Font descendant
	P1IES |= CAPTEUR_BLANCHE_DROIT; // Font descendant
	P1IES |= CAPTEUR_OBSTACLE; // Font descendant
	P1IES &= ~(MOTEUR_GAUCHE); // Font montant
	P1IES &= ~(MOTEUR_DROIT); // Font montant

	// Reset des flags
	P1IFG &= ~(CAPTEUR_BLANCHE_GAUCHE);
	P1IFG &= ~(CAPTEUR_BLANCHE_CENTRE);
	P1IFG &= ~(CAPTEUR_BLANCHE_DROIT);
	P1IFG &= ~(CAPTEUR_OBSTACLE);
	P2IFG &= ~(MOTEUR_GAUCHE);
	P2IFG &= ~(MOTEUR_DROIT);
}

void init_pwm(){
	/*** GPIO Set-Up ***/
	P2SEL |= (BIT2 | BIT4);
	P2SEL2 |= (BIT2 | BIT4);

	/*** Timer0_A Set-Up ***/
	TA0CCR0 |= 1000 - 1;
	TA0CCTL1 |= OUTMOD_7;
	TA0CCR1 |= 100;
	TA0CTL |= TASSEL_1 + MC_1;

	/*** Timer1_A Set-Up ***/
	TA1CCR0 |= 1000 - 1;
	TA1CCTL1 |= OUTMOD_7;
	TA1CCR1 |= 100;
	TA1CTL |= TASSEL_1 + MC_1;
}

int main(void) {
	init_ports();
	init_pwm();
	*circuit = get_circuit();
	get_next_inter(circuit_index, next_inter_side, circuit);
	init_move();

	__enable_interrupt();
	while(1){
		/*// Ligne centrale
		if(test_direct(CAPTEUR_BLANCHE_CENTRE)){
			avancer();
		}else{
			stop();
		}*/
	}
}

// Interruption pwm
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer0_A0 (void) {
	   //if(TA0CCR1 > 100)
		   P2OUT |= (BIT2);
}

// Interruption pwm
#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer1_A0 (void) {
	   //if(TA1CCR1 > 100)
		   P2OUT |= (BIT4);
}

// Interruption capteur
#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR(void) {
	/*// Capteur obstacle test
	if(test_capt(CAPTEUR_OBSTACLE)){
		stop();
	}

	// Gauche
	if(test_capt(CAPTEUR_BLANCHE_GAUCHE)){
		P1OUT |= LED1;
	}

	//Droite
	if(test_capt(CAPTEUR_BLANCHE_DROIT)){
		P1OUT |= LED2;
	}*/

	/*
	// Capteur obstacle test
	if(test_direct(CAPTEUR_OBSTACLE)){
		P1OUT |= LED2;
	}

	// Ligne extérieure + !centre = Repositionnement
	else if((test_capt(CAPTEUR_BLANCHE_DROIT) || test_capt(CAPTEUR_BLANCHE_GAUCHE)) && !test_capt(CAPTEUR_BLANCHE_CENTRE)){
		// repositionnement
	}
	// Ligne extérieure droite + milieu + !gauche --> intersection à droite
	else if (test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE) && !test_capt(CAPTEUR_BLANCHE_GAUCHE)){
		if(*next_inter_side == DROITE){
			// TODO : On tourne à droite
			get_next_inter(circuit_index, next_inter_side, circuit);
		}else if(*next_inter_side == AVANCE){
			// TODO : On continue d'avancer
			get_next_inter(circuit_index, next_inter_side, circuit);
		}
	}
	// Ligne extérieure gauche + milieu + !droite --> intersection à gauche
	else if (!test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE) && test_capt(CAPTEUR_BLANCHE_GAUCHE)){
		if(*next_inter_side == GAUCHE){
			// TODO : On tourne à gauche
			get_next_inter(circuit_index, next_inter_side, circuit);
		}else if(*next_inter_side == AVANCE){
			// TODO : On continue d'avancer
			get_next_inter(circuit_index, next_inter_side, circuit);
		}
	}
	// Ligne extérieure gauche & droite + milieu --> intersection à gauche et à droite
	else if (test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE) && test_capt(CAPTEUR_BLANCHE_GAUCHE)){
		if(*next_inter_side == GAUCHE){
			// TODO : On tourne à gauche
			get_next_inter(circuit_index, next_inter_side, circuit);
		}else if(*next_inter_side == DROITE){
			// TODO : On tourne à droite
			get_next_inter(circuit_index, next_inter_side, circuit);
		}else if(*next_inter_side == AVANCE){
			// TODO : On continue d'avancer
			get_next_inter(circuit_index, next_inter_side, circuit);
		}
	}*/
	reset_capt(CAPTEUR_BLANCHE_CENTRE);
	reset_capt(CAPTEUR_BLANCHE_DROIT);
	reset_capt(CAPTEUR_BLANCHE_GAUCHE);
	reset_capt(CAPTEUR_OBSTACLE);
}
