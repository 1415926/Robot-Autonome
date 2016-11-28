#include "main.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    //Init led and moteur-------------------------------

    //P1DIR
    P1DIR |= (LED1 | LED2 | LED3 | LED4);
   	P1OUT &= ~(LED1 | LED2 | LED3 | LED4);
   	//P2DIR
   	P2DIR |= (BIT1 | BIT2 | BIT4 | BIT5);
   	P2OUT &= ~(BIT1 | BIT2 | BIT4 | BIT5);
   	//P2SEL
   	P2SEL |= (MOTEUR_GAUCHE|MOTEUR_DROIT);
   	//--------------------------------------------------

   	// Interruptions enable
	P1IE |= (CAPTEUR_BLANCHE_GAUCHE); // Capteur Blanche Gauche
	P1IE |= (CAPTEUR_BLANCHE_CENTRE); // Capteur Blanche Centre
	P1IE |= (CAPTEUR_BLANCHE_DROIT); // Capteur Blanche Droite
	P1IE |= (CAPTEUR_OBSTACLE); // Capteur Obstacle

	// Define front
	P1IES &= ~CAPTEUR_BLANCHE_GAUCHE; // Font descendant
	P1IES &= ~CAPTEUR_BLANCHE_CENTRE; // Font descendant
	P1IES &= ~CAPTEUR_BLANCHE_DROIT; // Font descendant
	P1IES &= ~CAPTEUR_OBSTACLE; // Font descendant

	// Reset des flags
	P1IFG &= ~(CAPTEUR_BLANCHE_GAUCHE);
	P1IFG &= ~(CAPTEUR_BLANCHE_CENTRE);
	P1IFG &= ~(CAPTEUR_BLANCHE_DROIT);
	P1IFG &= ~(CAPTEUR_OBSTACLE);

   	//Init pwm------------------------------------------
   	BCSCTL1 = CALBC1_1MHZ; //Frequence d'horloge 1MHz
   	DCOCTL = CALDCO_1MHZ; //Frequence d'horloge 1MHz
   	TA1CTL = TASSEL_2 | MC_1 | ID_0;
   	TA1CCTL1 = OUTMOD_7;
   	TA1CCTL2 = OUTMOD_7;
   	TA1CCR0 = 4000;
   	//--------------------------------------------------

   	//Allumer led verte---------------------------------
   	P1OUT &= ~(BIT0);
   	P1OUT |= (BIT6);
   	//--------------------------------------------------
	// Banque + Boulangerie
	//-------------------------------------------------------------------

	//Avancer-------------------------------------------
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;
	//--------------------------------------------------

	__delay_cycles(EXCEL_732 + EXCEL_311); // H

	//Stop----------------------------------------------
	TA1CCR1 = 0;
	TA1CCR2 = 0;
	//--------------------------------------------------

	//Tourner gauche------------------------------------
	P2OUT |= ROUE_GAUCHE; //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;

	__delay_cycles(TOURNER);
	//--------------------------------------------------

	//Avancer-------------------------------------------
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;
	//--------------------------------------------------

	__delay_cycles(EXCEL_339); // I

	//Tourner gauche------------------------------------
	P2OUT |= ROUE_GAUCHE; //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;

	__delay_cycles(TOURNER);
	//--------------------------------------------------

	//Avancer-------------------------------------------
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;
	//--------------------------------------------------

	__delay_cycles(EXCEL_259 + CIBLE); // Banque

	//Stop----------------------------------------------
	TA1CCR1 = 0;
	TA1CCR2 = 0;
	//--------------------------------------------------

	__delay_cycles(3000000);

	//Tourner gauche------------------------------------
	P2OUT |= ROUE_GAUCHE; //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;

	__delay_cycles(TOURNER * 2);
	//--------------------------------------------------

	//Avancer-------------------------------------------
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;
	//--------------------------------------------------

	__delay_cycles(EXCEL_259 + CIBLE); // I

	//Tourner droite------------------------------------
	P2OUT &=~ ROUE_GAUCHE; //sens
	P2OUT &=~ ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;

	__delay_cycles(TOURNER);
	//--------------------------------------------------


	//Stop----------------------------------------------
	TA1CCR1 = 0;
	TA1CCR2 = 0;
	//--------------------------------------------------

	//Avancer-------------------------------------------
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;
	//--------------------------------------------------

	__delay_cycles(EXCEL_339); // H

	//Stop----------------------------------------------
	TA1CCR1 = 0;
	TA1CCR2 = 0;
	//--------------------------------------------------

	//Tourner gauche------------------------------------
	P2OUT |= ROUE_GAUCHE; //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;

	__delay_cycles(TOURNER);
	//--------------------------------------------------

	//Avancer-------------------------------------------
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;
	//--------------------------------------------------

	__delay_cycles(EXCEL_266); // G

	//Tourner gauche------------------------------------
	P2OUT &= ~(ROUE_GAUCHE); //sens
	P2OUT &= ~(ROUE_DROITE); //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;

	__delay_cycles(TOURNER);
	//--------------------------------------------------

	//Avancer-------------------------------------------
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;
	//--------------------------------------------------

	__delay_cycles(EXCEL_215 + EXCEL_301 + EXCEL_382); // D

	//Stop----------------------------------------------
	TA1CCR1 = 0;
	TA1CCR2 = 0;
	//--------------------------------------------------

	//Tourner gauche------------------------------------
	P2OUT |= ROUE_GAUCHE; //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;

	__delay_cycles(TOURNER);
	//--------------------------------------------------

	//Avancer-------------------------------------------
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;
	//--------------------------------------------------

	__delay_cycles(EXCEL_998); // C

	//Stop----------------------------------------------
	TA1CCR1 = 0;
	TA1CCR2 = 0;
	//--------------------------------------------------

	//Tourner gauche------------------------------------
	P2OUT |= ROUE_GAUCHE; //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;

	__delay_cycles(TOURNER);
	//--------------------------------------------------

	//Avancer-------------------------------------------
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;
	//--------------------------------------------------

	__delay_cycles(EXCEL_280); // B

	//Stop----------------------------------------------
	TA1CCR1 = 0;
	TA1CCR2 = 0;
	//--------------------------------------------------

	//Tourner droite------------------------------------
	P2OUT &=~ ROUE_GAUCHE; //sens
	P2OUT &=~ ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;

	__delay_cycles(TOURNER);
	//--------------------------------------------------

	//Avancer-------------------------------------------
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;
	//--------------------------------------------------

	__delay_cycles(EXCEL_177 + CIBLE); // Boulangerie

	//Stop----------------------------------------------
	TA1CCR1 = 0;
	TA1CCR2 = 0;
	//--------------------------------------------------

	__delay_cycles(3000000);

	//Tourner gauche------------------------------------
	P2OUT |= ROUE_GAUCHE; //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;

	__delay_cycles(TOURNER * 2);
	//--------------------------------------------------

	//Avancer-------------------------------------------
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;
	//--------------------------------------------------

	__delay_cycles(EXCEL_177 + CIBLE); // B

	//Stop----------------------------------------------
	TA1CCR1 = 0;
	TA1CCR2 = 0;
	//--------------------------------------------------

	//Tourner droite------------------------------------
	P2OUT &=~ ROUE_GAUCHE; //sens
	P2OUT &=~ ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;

	__delay_cycles(TOURNER);
	//--------------------------------------------------

	//Avancer-------------------------------------------
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;
	//--------------------------------------------------

	__delay_cycles(EXCEL_617); // A

	//Stop----------------------------------------------
	TA1CCR1 = 0;
	TA1CCR2 = 0;
	//--------------------------------------------------

	//Tourner droite------------------------------------
	P2OUT &=~ ROUE_GAUCHE; //sens
	P2OUT &=~ ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;

	__delay_cycles(TOURNER);
	//--------------------------------------------------

	//Avancer-------------------------------------------
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;
	//--------------------------------------------------

	__delay_cycles(EXCEL_311+CIBLE); // MAISON

	//Stop----------------------------------------------
	TA1CCR1 = 0;
	TA1CCR2 = 0;
	//--------------------------------------------------

   	//Fin-----------------------------------------------
   	while(1)
   	{
   		P1OUT &= ~(BIT6);
   		P1OUT |= (BIT0);
   	}
   	//--------------------------------------------------

	return 0;
}

// Interruption capteur
#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR(void) {
	/**
	 * OBSTACLE
	 */
	if(!test_capt(CAPTEUR_OBSTACLE)){
		//engine = ENGINE_STOP;
	}

	/**
	 * Perte ligne centrale
	 */
	// Ligne ext�rieure + !centre = Repositionnement
	if(test_capt(CAPTEUR_BLANCHE_CENTRE)){
		if((test_capt(CAPTEUR_BLANCHE_DROIT) && !test_capt(CAPTEUR_BLANCHE_GAUCHE))){
			// repositionnement � gauche
			TA1CCR2 = TURN_PWM;
		}else{
			// repositionnement � droite
			TA1CCR1 = TURN_PWM;
		}
	}
}
















