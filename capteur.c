/*
 * 	Project App Robot
 * 	Author : Paul Bouquet
 * 	Name : capteur.c
 * 	Version : 1.0
 * 	Date : 15/11/2016
 * 	Functions :
 * 	-
 *	-
 * 	-
*/

#include "main.h"

// Retourne 1 si detecte
int test_capt(char capt_adress){
	if((P1IN & capt_adress) == 0)
		return 1;
	else
		return 0;
}

// Abaisse le flag associé
void reset_capt(char capt_adress){
	P1IFG &= ~(capt_adress);
}

