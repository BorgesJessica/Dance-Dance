#include "../header/funcoes_jogo.h"
#include <curses.h>
#include <time.h>

void gameview() {

	const char seta_direita[] = "\
				|\\\n\
			 _______| \\\n\
			|________  \\\n\
			|________   \\\n\
			|________   / \n\
			|_______   / \n\
				| /\n\
				|/\n",
	 seta_esquerda[] = "\
	   /|\n\
	  / |_____\n\
	 /  ______|\n\
	/   ______|\n\
	\\   ______|\n\
	 \\  ______|\n\
	  \\ |\n\
	   \\|\n",
	 seta_cima[] ="\
		    /\\\n\
		   /  \\\n\
		  /    \\\n\
		 /      \\\n\
		/________\\\n\
		   |  |\n\
		   |__|\n",
	 seta_baixo[] ="\
		    __\n\
		   |  |\n\
		___|__|___\n\
		\\        /\n\
		 \\      /\n\
		  \\    /\n\
		   \\  /\n\
		    \\/\n\n";
	const char cara_1[] = "(°_o)", cara_2[] = "(T_T)", cara_3[] = ":-)", cara_4[] = ":-(";
	const char *caras[4]; caras[0] = cara_1; caras[1] = cara_2;	caras[2] = cara_3; caras[3] = cara_4;
	int jogada, cara, nivel = 1, *ptr_nivel = &nivel, pontos = 0, *ptr_pontos = &pontos;
		
	srand(time(NULL));
	playsound(1);
	while (1) {
		initscr();
		start_color();
		noecho(); 
		clear();
    		refresh();
    		jogada = rand()%4;
		
	    	if (jogada == 0) { 		
	    		attron(COLOR_PAIR(1));
	    		printw ("  %s", seta_cima);
	    		attroff(COLOR_PAIR(1));
	    		printw ("  %s", seta_esquerda);
	    		printw ("  %s", seta_direita);
	    		printw ("  %s", seta_baixo);
	    		attron(COLOR_PAIR(2));
	    		printw ("  %s", caras[jogada]);
	    		attroff(COLOR_PAIR(2));
	    		printw ("  Nivel  %d  Pontuação %d\n", *ptr_nivel, *ptr_pontos);
	    	}
	    	if (jogada == 1) {    	
	    		printw ("  %s", seta_cima);
	    		attron(COLOR_PAIR(1));
	    		printw ("  %s", seta_esquerda);
	    		attroff(COLOR_PAIR(1));
	    		printw ("  %s", seta_direita);
	    		printw ("  %s", seta_baixo);
	    		attron(COLOR_PAIR(2));
	    		printw ("  %s", caras[jogada]);
	    		attroff(COLOR_PAIR(2));
	    		printw ("  Nivel  %d  Pontuação %d\n", *ptr_nivel, *ptr_pontos);
	    	}
	    	if (jogada == 2) {
	    		printw ("  %s", seta_cima);
	    		printw ("  %s", seta_esquerda);
	    		attron(COLOR_PAIR(1));
	    		printw ("  %s", seta_direita);
	    		attroff(COLOR_PAIR(1));
	    		printw ("  %s", seta_baixo);
	    		attron(COLOR_PAIR(2));
	    		printw ("  %s", caras[jogada]);
	    		attroff(COLOR_PAIR(2));
	    		printw ("  Nivel  %d  Pontuação %d\n", *ptr_nivel, *ptr_pontos);	
	    	}
	    	if (jogada == 3) {
	    		printw ("  %s", seta_cima);
	    		printw ("  %s", seta_esquerda);
	    		printw ("  %s", seta_direita);
	    		attron(COLOR_PAIR(1));
	    		printw ("  %s", seta_baixo);
	    		attroff(COLOR_PAIR(1));
	    		attron(COLOR_PAIR(2));
	    		printw ("  %s", caras[jogada]);
	    		attroff(COLOR_PAIR(2));
	    		printw ("  Nivel  %d  Pontuação %d\n", *ptr_nivel, *ptr_pontos);	
	    	}
	    	timeout(5000);
		teclas = getch();
		
	    	*ptr_pontos = *ptr_pontos + 10;
	    	if (!((teclas == 'w' && jogada == 0) || (teclas == 'a' && jogada == 1) || (teclas == 'd' && jogada == 2) || (teclas == 's' && jogada == 3))) {
	    		quickStopSound();
			playsound(7);
			
			if (lose_winview(1, *ptr_pontos) == 1) {
				return;
			}
			playsound(1);			
			*ptr_pontos = 0;
			*ptr_nivel = 1;
	    	}	    	
	    	if (*ptr_pontos == 100) {
			playsound(2);
	    		*ptr_nivel = *ptr_nivel + 1;
	       	}
	    	if (*ptr_pontos == 300) {
			playsound(3);
	    		*ptr_nivel = *ptr_nivel + 1;
	    	}
	    	if (*ptr_pontos == 600) {
			quickStopSound();
			playsound(8);	    		
			if (lose_winview(2, *ptr_pontos) == 1) {
				return;
			}  
			quickStopSound();
			playsound(1);
	    		*ptr_pontos = 0;
	    		*ptr_nivel = 1;			
	    	}
	    
	    	endwin();    			    	
    }

} 
