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

	// Interruptions
	P1IE |= (CAPTEUR_BLANCHE_GAUCHE); // Capteur Blanche Gauche
	P1IE |= (CAPTEUR_BLANCHE_CENTRE); // Capteur Blanche Centre
	P1IE |= (CAPTEUR_BLANCHE_DROIT); // Capteur Blanche Droite
	P1IE |= (CAPTEUR_OBSTACLE); // Capteur Obstacle

	P1IES |= CAPTEUR_BLANCHE_GAUCHE; // Font descendant
	P1IES |= CAPTEUR_BLANCHE_CENTRE; // Font descendant
	P1IES |= CAPTEUR_BLANCHE_DROIT; // Font descendant
	P1IES |= CAPTEUR_OBSTACLE; // Font descendant

	P1IES |= BIT5; // A SUPPRIMER TEST
	P1IE |= BIT5; // A SUPPRIMER TEST

	// Reset des flags
	P1IFG &= ~(CAPTEUR_BLANCHE_GAUCHE);
	P1IFG &= ~(CAPTEUR_BLANCHE_CENTRE);
	P1IFG &= ~(CAPTEUR_BLANCHE_DROIT);
	P1IFG &= ~(CAPTEUR_OBSTACLE);
}

int main(void) {
	init_ports();

	*circuit = get_circuit();
	get_next_inter(circuit_index, next_inter_side, circuit);
	set_sens_avant();

	if(test_direct(BIT5)){
		avancer();
		P1OUT |= BIT6;
	}else{
		P1OUT &= ~BIT6;
		set_sens_arriere();
	}

	__enable_interrupt();
	while(1);
}

// Interruption capteur
#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR(void) {
	// Capteur obstacle test
	if(test_capt(CAPTEUR_OBSTACLE)){
		//P1OUT |= BIT6;
	}

	/*// Ligne extérieure + !centre = Repositionnement
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
	reset_capt(BIT5);
}

/*// Interruption PWM
#pragma vector=PORT2_VECTOR
__interrupt void PORT2_ISR(void) {

}*/
