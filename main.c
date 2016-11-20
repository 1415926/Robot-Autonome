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
	P1DIR |= (LED1 | LED2);
	P1OUT &= ~(LED1 | LED2);
	//P2DIR
	P2DIR |= (BIT1 | BIT2 | BIT4 | BIT5);
	P2OUT &= ~(BIT1 | BIT2 | BIT4 | BIT5);

	// PSEL
	P1SEL |= LED2;
	/*P2SEL |= (MOTEUR_GAUCHE | MOTEUR_DROIT);
	P2SEL2|= (MOTEUR_GAUCHE | MOTEUR_DROIT);*/

	// Interruptions enable
	P1IE |= (CAPTEUR_BLANCHE_GAUCHE); // Capteur Blanche Gauche
	P1IE |= (CAPTEUR_BLANCHE_CENTRE); // Capteur Blanche Centre
	P1IE |= (CAPTEUR_BLANCHE_DROIT); // Capteur Blanche Droite
	P1IE |= (CAPTEUR_OBSTACLE); // Capteur Obstacle

	// Define front
	P1IES |= CAPTEUR_BLANCHE_GAUCHE; // Font descendant
	P1IES |= CAPTEUR_BLANCHE_CENTRE; // Font descendant
	P1IES |= CAPTEUR_BLANCHE_DROIT; // Font descendant
	P1IES |= CAPTEUR_OBSTACLE; // Font descendant

	// Reset des flags
	P1IFG &= ~(CAPTEUR_BLANCHE_GAUCHE);
	P1IFG &= ~(CAPTEUR_BLANCHE_CENTRE);
	P1IFG &= ~(CAPTEUR_BLANCHE_DROIT);
	P1IFG &= ~(CAPTEUR_OBSTACLE);
}

void init_pwm(){
	DCOCTL = 0;             		// Select lowest DCOx and MODx
	BCSCTL1 = CALBC1_1MHZ;  		// Set range
	DCOCTL = CALDCO_1MHZ;   		// Set DCO step + modulation

	/*** GPIO Set-Up ***/
	increment = 1;

	/*** Timer0_A Set-Up ***/
	TA0CCR0 |= 1000;					// PWM period
	TA0CCR1 |= 1;					// TA0CCR1 PWM duty cycle
	TA0CCTL1 |= OUTMOD_7;			// TA0CCR1 output mode = reset/set
	TA0CTL |= TASSEL_2 + MC_1;		// SMCLK, Up Mode (Counts to TA0CCR0)

	/*** Timer1_A Set-Up ***/
	TA1CCR0 |= 2000;					// Counter value
	TA1CCTL0 |= CCIE;				// Enable Timer1_A interrupts
	TA1CTL |= TASSEL_2 + MC_1;		// SMCLK, Up Mode (Counts to TA1CCR0)

	_BIS_SR(LPM0_bits + GIE);		// Enter Low power mode 0 with interrupts enabled
}

int main(void){
	init_ports();
	init_pwm();

	get_next_inter(circuit_index, next_inter_side, get_circuit());
	init_move();

	__enable_interrupt();

	/*while(1){
		// Ligne centrale
		if(test_direct(CAPTEUR_BLANCHE_CENTRE)){
			avancer();
		}else{
			stop();
		}
	}*/
}

// Interruption pwm
#pragma vector=TIMER1_A0_VECTOR     // Timer1 A0 interrupt service routine
   __interrupt void Timer1_A0 (void) {

    TA0CCR1 += increment*2;			// Increase or decrease duty cycle

    if(TA0CCR1 > 998 || TA0CCR1 < 2){
    	increment = -increment; 	// Reverse direction if it falls within values
    	stop();
    }else if(TA0CCR1 > 500 && TA0CCR1 < 700){
    	//P2OUT |= MOTEUR_GAUCHE;
    	P2OUT |= MOTEUR_DROIT;
    }else{
		stop();
    }
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

	// Ligne ext�rieure + !centre = Repositionnement
	else if((test_capt(CAPTEUR_BLANCHE_DROIT) || test_capt(CAPTEUR_BLANCHE_GAUCHE)) && !test_capt(CAPTEUR_BLANCHE_CENTRE)){
		// repositionnement
	}
	// Ligne ext�rieure droite + milieu + !gauche --> intersection � droite
	else if (test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE) && !test_capt(CAPTEUR_BLANCHE_GAUCHE)){
		if(*next_inter_side == DROITE){
			// TODO : On tourne � droite
			get_next_inter(circuit_index, next_inter_side, get_circuit());
		}else if(*next_inter_side == AVANCE){
			// TODO : On continue d'avancer
			get_next_inter(circuit_index, next_inter_side, get_circuit());
		}
	}
	// Ligne ext�rieure gauche + milieu + !droite --> intersection � gauche
	else if (!test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE) && test_capt(CAPTEUR_BLANCHE_GAUCHE)){
		if(*next_inter_side == GAUCHE){
			// TODO : On tourne � gauche
			get_next_inter(circuit_index, next_inter_side, get_circuit());
		}else if(*next_inter_side == AVANCE){
			// TODO : On continue d'avancer
			get_next_inter(circuit_index, next_inter_side, get_circuit());
		}
	}
	// Ligne ext�rieure gauche & droite + milieu --> intersection � gauche et � droite
	else if (test_capt(CAPTEUR_BLANCHE_DROIT) && test_capt(CAPTEUR_BLANCHE_CENTRE) && test_capt(CAPTEUR_BLANCHE_GAUCHE)){
		if(*next_inter_side == GAUCHE){
			// TODO : On tourne � gauche
			get_next_inter(circuit_index, next_inter_side, get_circuit());
		}else if(*next_inter_side == DROITE){
			// TODO : On tourne � droite
			get_next_inter(circuit_index, next_inter_side, get_circuit());
		}else if(*next_inter_side == AVANCE){
			// TODO : On continue d'avancer
			get_next_inter(circuit_index, next_inter_side, get_circuit());
		}
	}*/
	reset_capt(CAPTEUR_BLANCHE_CENTRE);
	reset_capt(CAPTEUR_BLANCHE_DROIT);
	reset_capt(CAPTEUR_BLANCHE_GAUCHE);
	reset_capt(CAPTEUR_OBSTACLE);
}
