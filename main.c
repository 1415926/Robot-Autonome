/*
 * 	Project App Robot
 * 	Author : Paul Bouquet
 * 	Name : main.c
 * 	Version : 1.0
 * 	Date : 15/11/2016
 * 	Functions :
*/

#include <main.h>

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
}

// Initialise le timer associé à la pwm
void init_pwm(void){

}


int main(void) {
	init_ports();
	init_pwm();
	__enable_interrupt();

	// configuration
	int *next_inter_side; // 1 = gauche & 2 = droite
	int *circuit_index;

	while(1){

	}
	
	return 0;
}

// Interruption capteur
#pragma vector=PORT2_VECTOR
__interrupt void PORT2_ISR(void) {
	// if ( (capteur extérieur droit || capteur extérieur gauche) && !capteur milieu)
	// repositionnement
	// else if (capteur extérieur droit + capteur milieu + !capteur extérieur gauche)
	// intersection à droite --> on tourne si demandé
	// else if (capteur extérieur gauche + capteur milieu + !capteur extérieur droit)
	// intersection à gauche --> on tourne si demandé
	// else if (capteur extérieur gauche + capteur milieu + capteur extérieur droit)
	// intersection 2 côtés --> on tourne si demandé
	// }
}

/*// Interruption PWM
#pragma vector=PORT2_VECTOR
__interrupt void PORT2_ISR(void) {

}*/
