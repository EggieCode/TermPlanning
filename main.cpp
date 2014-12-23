#include <iostream>
#include <planningcontroller.h>
#include <stdio.h>
#include <planningitem.h>
#include <vector>
#include <cstring>
#include <math.h>
#include <ncurses.h>
#include <curses.h>


using namespace std;


const char *HEADER = "\033[95m";
const char *OKBLUE = "\033[94m";
const char *OKGREEN = "\033[92m";
const char *WARNING = "\033[93m";
const char *FAIL = "\033[91m";
const char *ENDC = "\033[0m";

PlanningController ctr;

void print_items() {
	vector<PlanningItem*> *items = ctr.getItems();
	vector<PlanningItem*>::iterator i = items->begin();

	cout << "Planning: " << endl ;
	while (i != items->end()) {
		cout << OKGREEN << "* " << (*i)->getTask().c_str();
		int tabs = 30 - (*i)->getTask().length();

		for(; 0 < tabs; tabs--)
			cout<< " ";

		cout << WARNING;
		const time_t* unixtime = (*i)->getDeadlines()[0];
		struct tm *t = localtime(unixtime);

		char date[20] ;
		strftime(date, sizeof(date), "%Y-%m-%d", t);
		cout << date << endl;
		i++;
	}
	cout << ENDC;

}

void ncurses() {

	int ch;

	initscr();			/* Start curses mode 		*/
	raw();				/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */

	printw("Type any character to see it in bold\n");
	ch = getch();			/* If raw() hadn't been called
					 * we have to press enter before it
					 * gets to the program 		*/
	if(ch == KEY_F(1))		/* Without keypad enabled this will */
		printw("F1 Key pressed");/*  not get to us either	*/
					/* Without noecho() some ugly escape
					 * charachters might have been printed
					 * on screen			*/
	else
	{	printw("The pressed key is ");
		attron(A_BOLD);
		printw("%c", ch);
		attroff(A_BOLD);
	}
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
}


int main(int args, char ** argv)
{
	ctr.load();
	if(args > 1 && strcmp(argv[1],"edit") == 0)
		ncurses();
	else
		print_items();
	return 0;

}

