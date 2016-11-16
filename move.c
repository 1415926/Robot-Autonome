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

#include "move.h"

void avancer(){
	P2OUT |= (BIT2);
	P2OUT |= (BIT4);
}

void stop(){
	P2OUT &=~ (BIT2);
	P2OUT &=~ (BIT4);
}

void set_sens_avant(){
	P2OUT |= (BIT1); //sens
	P2OUT &=~ BIT5; //sens
}
