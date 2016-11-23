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
	set_sens_avant();
}

/**
 * Roue A arrière
 * Roue B avant
 */
void rotation_right(){
	P2OUT |= ROUE_GAUCHE; //A
	P2OUT |= ROUE_DROITE; //B
}

/**
 * Roue A avant
 * Roue B arrière
 */
void rotation_left(){
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT &=~ (ROUE_DROITE); //sens
}

void set_sens_avant(){
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
}
