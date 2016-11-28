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
static const int C1[] 	= {10, GAUCHE, GAUCHE, DROITE, GAUCHE, GAUCHE, GAUCHE, DROITE, DROITE, AVANCE}; 			// Boulangerie + Banque + Maison
static const int C2[] 	= {GAUCHE, GAUCHE, GAUCHE, DROITE, DROITE, GAUCHE, GAUCHE, DROITE, AVANCE, AVANCE}; 		// Boulangerie + Hopital + Maison
static const int C3[] 	= {GAUCHE, GAUCHE, DROITE, GAUCHE, AVANCE, GAUCHE, DROITE, GAUCHE, DROITE, AVANCE, AVANCE}; 	// Boulangerie + Poste + Maison
static const int C4[] 	= {AVANCE, GAUCHE, GAUCHE, DROITE, GAUCHE, GAUCHE, AVANCE, DROITE, GAUCHE, AVANCE, DROITE, AVANCE, AVANCE};	// Banque + Hopital + Maison
static const int C5[] 	= {AVANCE, GAUCHE, GAUCHE, DROITE, GAUCHE, GAUCHE, DROITE, GAUCHE, DROITE, AVANCE, AVANCE}; 	// Banque + Poste + Maison
static const int C6[] 	= {AVANCE, GAUCHE, GAUCHE, DROITE, DROITE, DROITE, GAUCHE, DROITE, DROITE}; 			// Banque + Boulangerie + Maison
static const int C7[] 	= {AVANCE, AVANCE, GAUCHE, AVANCE, DROITE, GAUCHE, AVANCE, DROITE, DROITE, GAUCHE, DROITE, DROITE, AVANCE}; 	// Hopital + Banque + Maison
static const int C8[] 	= {AVANCE, AVANCE, GAUCHE, AVANCE, DROITE, GAUCHE, GAUCHE, GAUCHE, DROITE, AVANCE, AVANCE}; 	// Hopital + Poste + Maison
static const int C9[] 	= {AVANCE, AVANCE, GAUCHE, AVANCE, DROITE, DROITE, GAUCHE, GAUCHE, DROITE, DROITE, DROITE}; 	// Hopital + Boulangerie + Maison
static const int C10[] 	= {AVANCE, AVANCE, GAUCHE, DROITE, GAUCHE, DROITE, DROITE, GAUCHE, DROITE, DROITE, AVANCE}; 	// Poste + Banque + Maison
static const int C11[] 	= {AVANCE, AVANCE, GAUCHE, DROITE, DROITE, DROITE, GAUCHE, AVANCE, DROITE, AVANCE, AVANCE}; 	// Poste + Hopital + Maison
static const int C12[] 	= {AVANCE, AVANCE, GAUCHE, DROITE, GAUCHE, DROITE, AVANCE, DROITE, GAUCHE, DROITE, DROITE}; 	// Poste + Boulangerie + Maison

#endif
