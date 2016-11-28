/*
 * 	Project App Robot
 * 	Author : Paul Bouquet
 * 	Name : move.h
 * 	Version : 1.0
 * 	Date : 15/11/2016
*/

#ifndef ROBOT_MOVE_HEADER
#define ROBOT_MOVE_HEADER

#define MOTEUR_GAUCHE BIT2
#define MOTEUR_DROIT BIT4
#define ROUE_GAUCHE BIT1
#define ROUE_DROITE BIT5
#define MOTEUR_GAUCHE_PWM 4000
#define MOTEUR_DROIT_PWM 3930
#define TURN_PWM MOTEUR_DROIT_PWM/1.07
#define TURN_COUNT 100000

#endif
