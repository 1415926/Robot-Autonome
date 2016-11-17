/*
 * 	Project App Robot
 * 	Author : Paul Bouquet
 * 	Name : move.c
 * 	Version : 1.0
 * 	Date : 15/11/2016
 * 	Functions :
 * 	-
 *	-
 * 	-
*/

#include "main.h"

void init_move(){
	stop();
	set_sens_avant();
}

void avancer(){
	P2OUT |= (BIT2);
	P2OUT |= (BIT4);
}

void stop(){
	P2OUT &=~ (BIT2);
	P2OUT &=~ (BIT4);
}

/**
 * Roue A arrière
 * Roue B avant
 */
void tourner_droite(){
	P2OUT |= BIT1; //A
	P2OUT |= BIT5; //B
}

/**
 * Roue A avant
 * Roue B arrière
 */
void tourner_gauche(){
	P2OUT &=~ (BIT1); //sens
	P2OUT &=~ (BIT5); //sens
}

void set_sens_avant(){
	P2OUT &=~ (BIT1); //sens
	P2OUT |= BIT5; //sens
}
