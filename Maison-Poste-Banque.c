   	//--------------------------------------------------
	// Poste + Boulangerie
	//-------------------------------------------------------------------

	//Avancer-------------------------------------------
	P2OUT &=~ (ROUE_GAUCHE); //sens
	P2OUT |= ROUE_DROITE; //sens
	TA1CCR1 = MOTEUR_GAUCHE_PWM;
	TA1CCR2 = MOTEUR_DROIT_PWM;
	//--------------------------------------------------

	__delay_cycles(EXCEL_732 + EXCEL_311 + EXCEL_266); // G

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

	__delay_cycles(EXCEL_215); // F

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

	__delay_cycles(EXCEL_586 + CIBLE); // Poste

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

	__delay_cycles(EXCEL_586 + CIBLE); // F

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

	__delay_cycles(EXCEL_382); // E

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

	__delay_cycles(EXCEL_135 + CIBLE); // HOPITAL

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

	__delay_cycles(EXCEL_135 + CIBLE); // E

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

	__delay_cycles(EXCEL_301); // D

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

	__delay_cycles(EXCEL_280 + EXCEL_617); // A

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

