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

void set_sens_avant(){
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
}
