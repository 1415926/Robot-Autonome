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
	//P2DIR

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
	P1IES &= ~(CAPTEUR_BLANCHE_GAUCHE); // Font montant
	P1IES &= ~(CAPTEUR_BLANCHE_CENTRE); // Font montant
	P1IES &= ~(CAPTEUR_BLANCHE_DROIT); // Font montant
	P1IES &= ~(CAPTEUR_OBSTACLE); // Font montant
	// Reset des flags
	P1IFG &= ~(CAPTEUR_BLANCHE_GAUCHE);
	P1IFG &= ~(CAPTEUR_BLANCHE_CENTRE);
	P1IFG &= ~(CAPTEUR_BLANCHE_DROIT);
	P1IFG &= ~(CAPTEUR_OBSTACLE);
}

// Initialise le timer associ� � la pwm
void init_pwm(void){

}


int main(void) {
	init_ports();
	init_pwm();

	// configuration
	int *next_inter_side;
	int *circuit_index;
	int *circuit;
	circuit = get_circuit();
	get_next_inter(&index, &next_inter_side, &circuit);

	__enable_interrupt();
	while(1);
	
	return 0;
}

// Interruption capteur
#pragma vector=PORT2_VECTOR
__interrupt void PORT2_ISR(void) {
	// Capteur obstacle test
	if(test_capt(CAPTEUR_OBSTACLE)){
		// TODO : stop robot
	}
	// Ligne ext�rieure + !centre = Repositionnement
	else if((test_capt(CAPTEUR_BLANCHE_DROIT) || test_capt(CAPTEUR_BLANCHE_GAUCHE)) && !test_capt(CAPTEUR_BLANCHE_CENTRE)){
		// repositionnement
	}
	// Ligne ext�rieure droite + milieu + !gauche --> intersection � droite
	else if (test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE) && !test_capt(CAPTEUR_BLANCHE_GAUCHE)){
		if(*next_inter_side == DROITE){
			// TODO : On tourne � droite
			get_next_inter(&index, &next_inter_side, &circuit);
		}else if(*next_inter_side == AVANCE){
			// TODO : On continue d'avancer
			get_next_inter(&index, &next_inter_side, &circuit);
		}
	}
	// Ligne ext�rieure gauche + milieu + !droite --> intersection � gauche
	else if (!test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE) && test_capt(CAPTEUR_BLANCHE_GAUCHE)){
		if(*next_inter_side == GAUCHE){
			// TODO : On tourne � gauche
			get_next_inter(&index, &next_inter_side, &circuit);
		}else if(*next_inter_side == AVANCE){
			// TODO : On continue d'avancer
			get_next_inter(&index, &next_inter_side, &circuit);
		}
	}
	// Ligne ext�rieure gauche & droite + milieu --> intersection � gauche et � droite
	else if (test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE) && test_capt(CAPTEUR_BLANCHE_GAUCHE)){
		if(*next_inter_side == GAUCHE){
			// TODO : On tourne � gauche
			get_next_inter(&index, &next_inter_side, &circuit);
		}else if(*next_inter_side == DROITE){
			// TODO : On tourne � droite
			get_next_inter(&index, &next_inter_side, &circuit);
		}else if(*next_inter_side == AVANCE){
			// TODO : On continue d'avancer
			get_next_inter(&index, &next_inter_side, &circuit);
		}
	}
	reset_capt(CAPTEUR_BLANCHE_CENTRE);
	reset_capt(CAPTEUR_BLANCHE_DROIT);
	reset_capt(CAPTEUR_BLANCHE_GAUCHE);
	reset_capt(CAPTEUR_OBSTACLE);
}

/*// Interruption PWM
#pragma vector=PORT2_VECTOR
__interrupt void PORT2_ISR(void) {

}*/
