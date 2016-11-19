/*
 * 	Project App Robot
 * 	Author : Paul Bouquet
 * 	Name : main.h
 * 	Version : 1.0
 * 	Date : 15/11/2016
*/
#ifndef __ROBOT_MAIN_HEADER
#define __ROBOT_MAIN_HEADER

// Paramètres
#define MAIN_PARAM 1
#define LED1 BIT0
#define LED2 BIT6
#define INCREMENT_PWM 5

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
int *circuit;

#endif
