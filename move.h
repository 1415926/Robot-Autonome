/*
 * 	Project App Robot
 * 	Author : Paul Bouquet
 * 	Name : move.h
 * 	Version : 1.0
 * 	Date : 15/11/2016
*/

#ifndef __ROBOT_MOVE_HEADER
#define __ROBOT_MOVE_HEADER

#define MOTEUR_GAUCHE BIT2
#define MOTEUR_DROIT BIT4
#define ROUE_GAUCHE BIT1
#define ROUE_DROITE BIT5

//prototypes
void init_move();
void avancer();
void stop();
void tourner_droite();
void tourner_gauche();
void set_sens_avant();

#endif
