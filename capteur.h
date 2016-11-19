/*
 * 	Project App Robot
 * 	Author : Paul Bouquet
 * 	Name : capteur.h
 * 	Version : 1.0
 * 	Date : 15/11/2016
*/

#ifndef ROBOT_CAPT_HEADER
#define ROBOT_CAPT_HEADER

#define CAPTEUR_BLANCHE_GAUCHE BIT1
#define CAPTEUR_BLANCHE_CENTRE BIT2
#define CAPTEUR_BLANCHE_DROIT BIT3
#define CAPTEUR_OBSTACLE BIT4

int test_capt(char capt_adress);
int test_direct(char capt_adress);
void reset_capt(char capt_adress);

#endif
