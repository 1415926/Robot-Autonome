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

// Initialise le timer associ� � la pwm
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
	// if ( (capteur ext�rieur droit || capteur ext�rieur gauche) && !capteur milieu)
	// repositionnement
	// else if (capteur ext�rieur droit + capteur milieu + !capteur ext�rieur gauche)
	// intersection � droite --> on tourne si demand�
	// else if (capteur ext�rieur gauche + capteur milieu + !capteur ext�rieur droit)
	// intersection � gauche --> on tourne si demand�
	// else if (capteur ext�rieur gauche + capteur milieu + capteur ext�rieur droit)
	// intersection 2 c�t�s --> on tourne si demand�
	// }
}

/*// Interruption PWM
#pragma vector=PORT2_VECTOR
__interrupt void PORT2_ISR(void) {

}*/
