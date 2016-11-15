/*
 * 	Project App Robot
 * 	Author : Paul Bouquet
 * 	Name : gps.h
 * 	Version : 1.0
 * 	Date : 15/11/2016
*/

#ifndef __ROBOT_GPS_HEADER
#define __ROBOT_GPS_HEADER

// Constantes de circuits
// index 1 : nombre d'intersection
// index 2 : 1 = gauche | 2 = droite
int C1[][] 	= {{1,1}, {1,1}, {1,2}, {1,1}, {1,1}, {1,2}, {1,2}}; 		// Boulangerie + Banque + Maison
int C2[][] 	= {}; 														// Boulangerie + Hopital + Maison
int C3[][] 	= {}; 														// Boulangerie + Poste + Maison
int C4[][] 	= {}; 														// Banque + Hopital + Maison
int C5[][] 	= {}; 														// Banque + Poste + Maison
int C6[][] 	= {}; 														// Banque + Boulangerie + Maison
int C7[][] 	= {}; 														// Hopital + Banque + Maison
int C8[][] 	= {}; 														// Hopital + Poste + Maison
int C9[][] 	= {}; 														// Hopital + Boulangerie + Maison
int C10[][] = {}; 														// Poste + Banque + Maison
int C11[][] = {}; 														// Poste + Hopital + Maison
int C12[][] = {}; 														// Poste + Boulangerie + Maison

// Protoypes
int * get_circuit(void);
void get_next_inter(int *index, int *next_inter_side, int *circuit);

#endif
