/*
 * 	Project App Robot
 * 	Author : Paul Bouquet
 * 	Name : main.h
 * 	Version : 1.0
 * 	Date : 15/11/2016
*/
#ifndef __ROBOT_MAIN_HEADER
#define __ROBOT_MAIN_HEADER

// Param�tres
#define MAIN_PARAM 1

// includes
#include <msp430g2553.h>
#include <gps.h>
#include <capteur.h>
#include <move.h>

// Prototypes
void init_ports(void);
void init_pwm(void);
int main(void);

#endif