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
#define VITESSE 17.52
#define MOTEUR_GAUCHE BIT2
#define MOTEUR_DROIT BIT4
#define ROUE_GAUCHE BIT1
#define ROUE_DROITE BIT5
#define MOTEUR_GAUCHE_PWM 4000
#define MOTEUR_DROIT_PWM 3950
#define TURN_PWM MOTEUR_DROIT_PWM/1.07
#define LED1 BIT0
#define LED2 BIT6
#define LED3 BIT7
#define LED4 BIT5
#define TOURNER	400000
#define EXCEL_732 4178082
#define EXCEL_311 1775114
#define EXCEL_617 3521689
#define EXCEL_177 1010274
#define EXCEL_280 1598174
#define EXCEL_998 5696347
#define EXCEL_301 1718037
#define EXCEL_135 770548
#define EXCEL_382 2180365
#define EXCEL_586 3344749
#define EXCEL_215 1227169
#define EXCEL_259 1478311
#define EXCEL_339 1934932
#define EXCEL_266 1518265
#define CIBLE 856164


// includes
#include <msp430g2553.h>
#include "capteur.h"

// Prototypes
int main(void);
#endif
