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
	P1IE |= (BIT1); // Capteur
	P1IE |= (BIT2); // Capteur
	P1IE |= (BIT3); // Capteur
	P1IE |= (BIT4); // Capteur
	P1IES &= ~(BIT1); // Font montant
	P1IES &= ~(BIT2); // Font montant
	P1IES &= ~(BIT3); // Font montant
	P1IES &= ~(BIT4); // Font montant
	P1IFG &= ~(BIT1);
	P1IFG &= ~(BIT2);
	P1IFG &= ~(BIT3);
	P1IFG &= ~(BIT4);
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

	__enable_interrupt();
	while(1);
	
	return 0;
}

// Interruption capteur
#pragma vector=PORT2_VECTOR
__interrupt void PORT2_ISR(void) {
	// if ( (capteur ext�rieur droit || capteur ext�rieur gauche) && !capteur milieu)
	// repositionnement
	// else if (capteur ext�rieur droit + capteur milieu + !capteur ext�rieur gauche)
	// intersection � droite --> on tourne si demand� --> circuit = get_circuit();
	// else if (capteur ext�rieur gauche + capteur milieu + !capteur ext�rieur droit)
	// intersection � gauche --> on tourne si demand� --> circuit = get_circuit();
	// else if (capteur ext�rieur gauche + capteur milieu + capteur ext�rieur droit)
	// intersection 2 c�t�s --> on tourne si demand� --> circuit = get_circuit();
	// }
	//P1IFG &= ~(BIT3);
}

/*// Interruption PWM
#pragma vector=PORT2_VECTOR
__interrupt void PORT2_ISR(void) {

}*/
