#include "../header/funcoes_jogo.h"
#include <curses.h>

void startmenu() {

	initscr();
	start_color();
	noecho();
	cbreak();
	curs_set(0);
	nodelay(stdscr, false);
	keypad(stdscr, true);
	wresize(stdscr,90,94);
	box(stdscr, 80,43);      
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_RED);
	
	mvprintw(1,3,"oooO");
	mvprintw(2,3,"(....).... Oooo....");
	mvprintw(3,3,"\\..(.....(.....)...");
	mvprintw(4,3,"..\\_)..... )../....");
	mvprintw(5,3,"......... (_/.....");
	mvprintw(6,3,"oooO");
	mvprintw(7,3,"(....).... Oooo....");
	mvprintw(8,3,"\\..(.....(.....)...");
	mvprintw(9,3,"..\\_)..... )../....");
	mvprintw(10,3,"......... (_/.....");
	
	attron(COLOR_PAIR(1));
	mvprintw(2,25,"|||||||||     |||||  ||    ||  |||||||| |||||||||");
	attron(COLOR_PAIR(1));
	mvprintw(3,25,"||      |||  ||   || ||||  ||  ||       ||");
	attron(COLOR_PAIR(1));
	mvprintw(4,25,"||       ||| ||   || || || ||  ||       ||||||");
	attron(COLOR_PAIR(1));
	mvprintw(5,25,"||       ||| ||||||| ||  ||||  ||       ||");
	attron(COLOR_PAIR(1));
	mvprintw(6,25,"||      |||  ||   || ||   |||  ||       ||");
	attron(COLOR_PAIR(1));
	mvprintw(7,25,"|||||||||    ||   || ||    ||  |||||||| |||||||||");
	attron(COLOR_PAIR(1));
	
	attron(COLOR_PAIR(1));
	mvprintw(11,2,"|||||||||     |||||  ||    ||  |||||||| |||||||||");
	attron(COLOR_PAIR(1));
	mvprintw(12,2,"||      |||  ||   || ||||  ||  ||       ||");
	attron(COLOR_PAIR(1));
	mvprintw(13,2,"||       ||| ||   || || || ||  ||       ||||||");
	attron(COLOR_PAIR(1));
	mvprintw(14,2,"||       ||| ||||||| ||  ||||  ||       ||");
	attron(COLOR_PAIR(1));
	mvprintw(15,2,"||      |||  ||   || ||   |||  ||       ||");
	attron(COLOR_PAIR(1));
	mvprintw(16,2,"|||||||||    ||   || ||    ||  |||||||| |||||||||");
	attron(COLOR_PAIR(1));
	
	mvprintw(18,1," Utilize as teclas W,A,S e D como as setas, selecione as que estão em vermelho.");
	mvprintw(20,25,"Você tem 5s para cada jogada.");	
	mvprintw(25,23,"Para comecar aperte qualquer tecla.");
	teclas = getch();
	
	endwin();
	return;
}
