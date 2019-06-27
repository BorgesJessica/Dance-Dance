#include "../header/funcoes_jogo.h"
#include <curses.h>

void main () {
	
	initscr();
	start_color();
	noecho(); 
	clear();
	cbreak();
	curs_set(0);
	nodelay(stdscr, false);
	keypad(stdscr,true);
	wresize(stdscr,90,94); 
	box(stdscr,80,43);
	refresh();
	startmenu();	
	gameview();

	endwin();
	return;

}
