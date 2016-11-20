/*
 * 	Project App Robot
 * 	Author : Paul Bouquet
 * 	Name : main.h
 * 	Version : 1.0
 * 	Date : 15/11/2016
*/
#ifndef ROBOT_MAIN_HEADER
#define ROBOT_MAIN_HEADER

// Paramètres
#define MAIN_PARAM 1
#define LED1 BIT0
#define LED2 BIT6
#define MOTEUR_STOP 0
#define MOTEUR_START 1

// includes
#include <msp430g2553.h>
#include "gps.h"
#include "capteur.h"
#include "move.h"

// Prototypes
void init_ports(void);
void init_pwm(void);
int main(void);

// vars
int *next_inter_side;
int *circuit_index;
int increment;
int *engine_left;
int *engine_right;

#endif
