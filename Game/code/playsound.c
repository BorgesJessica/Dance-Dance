#include "../header/funcoes_jogo.h"
#include <stdlib.h> 

	void playsound(int i){
		
		char str[255];
		char *audioPath = "../audio/";

		if (i == 7) {
			sprintf (str,"play %sgameover.wav -q &",audioPath); 
			system (str);
		}
		if (i == 8) {
			sprintf (str,"play %sCelebration.mp3 -q &",audioPath); 
			system (str);
		}
		if (i == 1) {
			sprintf (str,"play %sUpInMyJam.mp3 -q &",audioPath); 
			system (str);
		}
		if (i == 2) {
			sprintf (str,"play %s2.wav -q &",audioPath); 
			system (str);
		}
		else if (i == 3) {
			sprintf (str,"play %s3.wav -q &",audioPath); 
			system (str);
		}
	}
