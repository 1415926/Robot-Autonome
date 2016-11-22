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
#define SENS_AVANT 1
#define SENS_DROITE 2
#define SENS_GAUCHE 3

//prototypes
void init_move(int *engine_left, int *engine_right, int *turn_left, int *turn_right);
void start(int *engine_left, int *engine_right);
void stop(int *engine_left, int *engine_right);
void start_left(int *engine_left);
void start_right(int *engine_right);
void stop_left(int *engine_left);
void stop_right(int *engine_right);
void correction_right(int *turn_right);
void correction_left(int *turn_left);
void clean_right(int *turn_right);
void clean_left(int *turn_left);
void rotation_right();
void rotation_left();
void set_sens_avant();

#endif
