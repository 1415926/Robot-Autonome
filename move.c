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

void init_move(int *engine_left, int *engine_right, int *turn_left, int *turn_right){
	*engine_left 	= MOTEUR_STOP;
	*engine_right 	= MOTEUR_STOP;
	*turn_left		= 0;
	*turn_right		= 0;
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

void correction_right(int *turn_right){
	*turn_right = 1;
}

void correction_left(int *turn_left){
	*turn_left = 1;
}

void clean_right(int *turn_right){
	*turn_right = 0;
}

void clean_left(int *turn_left){
	*turn_left = 0;
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
