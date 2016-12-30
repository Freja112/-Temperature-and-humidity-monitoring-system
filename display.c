#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <stdio.h>



void display(){
	initscr();

	if(!has_colors()){
		endwin();
		fprintf(stderr, "Error - no color support on this terminal\n");
		exit(1);
	}
	if(start_color() != OK){
		endwin();
		fprintf(stderr, "Error - could not initialize colors\n");
		exit(2);
	}

	init_pair(1, COLOR_BLACK, COLOR_YELLOW);
	init_pair(2, COLOR_RED, COLOR_YELLOW);
	init_pair(3, COLOR_GREEN, COLOR_WHITE);
	init_pair(4, COLOR_RED, COLOR_WHITE);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);

	attrset(COLOR_PAIR(1));

	move(3, 5);
	printw("%s", "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+");		// 5~49
	move(4, 5);
	printw("%s", "|           Humidity/Temp. Senser           |");
	move(5, 5);
	printw("%s", "+-=-=-=-=-=-=-=-=-=-=-=-=+=-=-=-=-=-=-=-=-=-+");
	move(6, 5);
	printw("%s", "|  Senser 1 Humidity     |                  |");		// 38
	move(7, 5);
	printw("%s", "|           Temperature  |                  |");
	move(8, 5);
	printw("%s", "+-=-=-=-=-=-=-=-=-=-=-=-=+=-=-=-=-=-=-=-=-=-+");
	move(9, 5);
	printw("%s", "|  Senser 2 Humidity     |                  |");
	move(10, 5);
	printw("%s", "|           Temperature  |                  |");
	move(11, 5);
	printw("%s", "+-=-=-=-=-=-=-=-=-=-=-=-=+=-=-=-=-=-=-=-=-=-+");

	move(13, 5);
	printw("%s", "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+");
	move(14, 5);
	printw("%s", "|      Humidity/Temp. Controller Status     |");
	move(15, 5);
	printw("%s", "+-=-=-=-=-=-=-=-=-=-=+=-=-=-=-=-=-=-=-=-=-=-+");
	move(16, 5);
	printw("%s", "|    Controller 1    |                      |");
	move(17, 5);
	printw("%s", "|    Controller 2    |                      |");
	move(18, 5);
	printw("%s", "+-=-=-=-=-=-=-=-=-=-=+=-=-=-=-=-=-=-=-=-=-=-+");
	move(19, 5);
	attrset(COLOR_PAIR(5));
	printw("Ctrl + C : QUIT");
	refresh();
	//endwin();
	//exit(EXIT_SUCCESS);
}

void DrawSenser(int num, float* value){
	attrset(COLOR_PAIR(2));

	switch(num){
	case 0:
		mvprintw(6, 38, "%.1f", value[0]);
		mvprintw(7, 38, "%.1f", value[1]);
		refresh();
		break;
	case 1:
		mvprintw(9, 38, "%.1f", value[0]);
		mvprintw(10, 38, "%.1f", value[1]);
		refresh();
		break;
	}
}

void DrawCtrl(int num, bool status){
	switch(num){
	case 0:
		if(status){
			attrset(COLOR_PAIR(3));
			mvprintw(16, 36, "O N");
			refresh();
		} else {
			attrset(COLOR_PAIR(4));
			mvprintw(16, 36, "OFF");
			refresh();
		}
		break;
	case 1:
		if(status){
			attrset(COLOR_PAIR(3));
			mvprintw(17, 36, "O N");
			refresh();
		} else {
			attrset(COLOR_PAIR(4));
			mvprintw(17, 36, "OFF");
			refresh();
		}
		break;
	}	
}
