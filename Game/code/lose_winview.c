#include "../header/funcoes_jogo.h"
#include <curses.h>

int lose_winview(int i, int pontos) {	
	
	initscr();
	start_color();
	noecho(); 	
	
	if (i == 1) {
		
		attron(COLOR_PAIR(4));
		printw ("Voce Perdeu :(    Pontuacao %d\n\n", pontos - 10);
		printw ("Para reiniciar aperte W\n\n");
		attroff(COLOR_PAIR(4));
		teclas = getch();
		if (teclas != 'w') {
			endwin();
			return 1;
		}
	} else {
		printw ("\n Voce VENCEU :)\n\n");
    		printw ("\n Para reiniciar aperte W \n\n");
    		teclas = getch();
    		if (teclas != 'w') {
			quickStopSound();
    			endwin();
    			return 1;    			
		}
	}
	return 0;
}
