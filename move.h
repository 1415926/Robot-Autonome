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
#define MOTEUR_GAUCHE_PWM_HAUT (PWM_PERIOD - 5)
#define MOTEUR_GAUCHE_PWM_BAS 3
#define MOTEUR_DROIT_PWM_HAUT (PWM_PERIOD - 4)
#define MOTEUR_DROIT_PWM_BAS 3

//prototypes
void init_move(int *engine_left, int *engine_right);
void start(int *engine_left, int *engine_right);
void stop(int *engine_left, int *engine_right);
void start_left(int *engine_left);
void start_right(int *engine_right);
void stop_left(int *engine_left);
void stop_right(int *engine_right);
void tourner_droite();
void tourner_gauche();
void set_sens_avant();

#endif
