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
#define LED3 BIT7
#define LED4 BIT5
#define MOTEUR_STOP 0
#define MOTEUR_START 1
#define ENGINE_RIGHT 1
#define ENGINE_LEFT 2
#define ENGINE_CORRECT_RIGHT 3
#define ENGINE_CORRECT_LEFT 4
#define ENGINE_STRAIGHT 5

// includes
#include <msp430g2553.h>
#include "gps.h"
#include "capteur.h"
#include "move.h"

// Prototypes
void init_ports(void);
void init_pwm(void);
void start(int roue_right, int roue_left);
void stop(void);
void left90(void);
void right90(void);
int get_next_inter(int index, const int * circuit);
const int * get_circuit(void);
void set_sens_avant();
int main(void);

// vars
int engine;
int roue_left;
int roue_right;
int circuit_index;
int next_inter_side;
#endif
