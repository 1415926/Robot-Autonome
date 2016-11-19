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
	P2OUT |= (MOTEUR_GAUCHE);
	P2OUT |= (MOTEUR_DROIT);
}

void stop(){
	P2OUT &=~ (MOTEUR_GAUCHE);
	P2OUT &=~ (MOTEUR_DROIT);
}

/**
 * Roue A arrière
 * Roue B avant
 */
void tourner_droite(){
	P2OUT |= ROUE_GAUCHE; //A
	P2OUT |= ROUE_DROITE; //B
}

/**
 * Roue A avant
 * Roue B arrière
 */
void tourner_gauche(){
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT &=~ (ROUE_DROITE); //sens
}

void set_sens_avant(){
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
}
