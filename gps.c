/*
 * 	Project App Robot
 * 	Author : Paul Bouquet
 * 	Name : gps.c
 * 	Version : 1.0
 * 	Date : 15/11/2016
 * 	Functions :
 * 	- Interactions avec Mouvement.c
 *	- Fonction incrémentale de positionnement
 * 	- Mémorisation à chaque t de l'emplacement du robot
*/

#include "main.h"

// Associe le tableau du circuit a celui choisi
int * get_circuit(void){
	switch(MAIN_PARAM){
		case 1:  return C1;
		case 2:  return C2;
		case 3:  return C3;
		case 4:  return C4;
		case 5:  return C5;
		case 6:  return C6;
		case 7:  return C7;
		case 8:  return C8;
		case 9:  return C9;
		case 10: return C10;
		case 11: return C11;
		case 12: return C12;
		default: return 0;
	}
}

// retourne le nombre d'intersection attendue
void get_next_inter(int *index, int *next_inter_side, int *circuit){
	*index++;
	*next_inter_side = circuit[*index];
}
