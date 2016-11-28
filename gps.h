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
#define CIBLE 3

// Constantes de circuits
// index 1 : nombre d'intersection
static const int C1[] 	= {10, GAUCHE, GAUCHE, DROITE, GAUCHE, GAUCHE, GAUCHE, DROITE, DROITE, 10}; 			// Boulangerie + Banque + Maison
static const int C2[] 	= {GAUCHE, GAUCHE, GAUCHE, DROITE, DROITE, GAUCHE, GAUCHE, DROITE, 10, 10}; 		// Boulangerie + Hopital + Maison
static const int C3[] 	= {GAUCHE, GAUCHE, DROITE, GAUCHE, 10, GAUCHE, DROITE, GAUCHE, DROITE, 10, 10}; 	// Boulangerie + Poste + Maison
static const int C4[] 	= {10, GAUCHE, GAUCHE, DROITE, GAUCHE, GAUCHE, 10, DROITE, GAUCHE, 10, DROITE, 10, 10};	// Banque + Hopital + Maison
static const int C5[] 	= {10, GAUCHE, GAUCHE, DROITE, GAUCHE, GAUCHE, DROITE, GAUCHE, DROITE, 10, 10}; 	// Banque + Poste + Maison
static const int C6[] 	= {10, GAUCHE, GAUCHE, DROITE, DROITE, DROITE, GAUCHE, DROITE, DROITE}; 			// Banque + Boulangerie + Maison
static const int C7[] 	= {10, 10, GAUCHE, 10, DROITE, GAUCHE, 10, DROITE, DROITE, GAUCHE, DROITE, DROITE, 10}; 	// Hopital + Banque + Maison
static const int C8[] 	= {10, 10, GAUCHE, 10, DROITE, GAUCHE, GAUCHE, GAUCHE, DROITE, 10, 10}; 	// Hopital + Poste + Maison
static const int C9[] 	= {10, 10, GAUCHE, 10, DROITE, DROITE, GAUCHE, GAUCHE, DROITE, DROITE, DROITE}; 	// Hopital + Boulangerie + Maison
static const int C10[] 	= {10, 10, GAUCHE, DROITE, GAUCHE, DROITE, DROITE, GAUCHE, DROITE, DROITE, 10}; 	// Poste + Banque + Maison
static const int C11[] 	= {10, 10, GAUCHE, DROITE, DROITE, DROITE, GAUCHE, 10, DROITE, 10, 10}; 	// Poste + Hopital + Maison
static const int C12[] 	= {10, 10, GAUCHE, DROITE, GAUCHE, DROITE, 10, DROITE, GAUCHE, DROITE, DROITE}; 	// Poste + Boulangerie + Maison

#endif
