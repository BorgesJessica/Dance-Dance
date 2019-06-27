#if !defined FUNCOES_JOGO_H
#define FUNCOES_JOGO

	#include <stdio.h>
	#include <stdlib.h>
	
	// Functions prototpes:
	
	void startmenu();					
	void gameview();			
	int lose_winview(int,int);				
	void playsound (int); 
	void quickStopSound ();							
	
	// Global variables:
	
	char teclas;
	
#endif

