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

void init_move(int *engine_left, int *engine_right){
	stop(engine_left, engine_right);
	set_sens_avant();
}

void start(int *engine_left, int *engine_right){
	start_left(engine_left);
	start_right(engine_right);
}

void stop(int *engine_left, int *engine_right){
	stop_left(engine_left);
	stop_right(engine_right);
}

void start_left(int *engine_left){
	*engine_left 	= MOTEUR_START;
	P2OUT 			|= (MOTEUR_GAUCHE);
}

void start_right(int *engine_right){
	*engine_right 	= MOTEUR_START;
	P2OUT 			|= (MOTEUR_DROIT);
}

void stop_left(int *engine_left){
	*engine_left 	= MOTEUR_STOP;
	P2OUT 			&=~ (MOTEUR_GAUCHE);
}

void stop_right(int *engine_right){
	*engine_right 	= MOTEUR_STOP;
	P2OUT 			&=~ (MOTEUR_DROIT);
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
