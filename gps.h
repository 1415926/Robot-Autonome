/*
 * 	Project App Robot
 * 	Author : Paul Bouquet
 * 	Name : gps.h
 * 	Version : 1.0
 * 	Date : 15/11/2016
*/

#ifndef ROBOT_GPS_HEADER
#define ROBOT_GPS_HEADER

#define GAUCHE 1
#define DROITE 2
#define AVANCE 3

// Constantes de circuits
// index 1 : nombre d'intersection
static const int C1[] 	= {GAUCHE, GAUCHE, DROITE, GAUCHE, GAUCHE, DROITE, DROITE}; 	// Boulangerie + Banque + Maison
static const int C2[] 	= {}; 															// Boulangerie + Hopital + Maison
static const int C3[] 	= {}; 															// Boulangerie + Poste + Maison
static const int C4[] 	= {}; 															// Banque + Hopital + Maison
static const int C5[] 	= {}; 															// Banque + Poste + Maison
static const int C6[] 	= {}; 															// Banque + Boulangerie + Maison
static const int C7[] 	= {}; 						 									// Hopital + Banque + Maison
static const int C8[] 	= {}; 															// Hopital + Poste + Maison
static const int C9[] 	= {}; 															// Hopital + Boulangerie + Maison
static const int C10[] = {}; 															// Poste + Banque + Maison
static const int C11[] = {}; 															// Poste + Hopital + Maison
static const int C12[] = {}; 															// Poste + Boulangerie + Maison

// Protoypes
const int * get_circuit(void);
void get_next_inter(int *index, int *next_inter_side, const int *circuit);

#endif
