#include <iostream>
#include <planningcontroller.h>
#include <stdio.h>
#include <planningitem.h>
#include <vector>
#include <cstring>
#include "editor/planningeditor.h"

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
		const time_t* unixtime = &((*i)->getDeadlines()[0]);
		struct tm *t = localtime(unixtime);

		char date[20] ;
		strftime(date, sizeof(date), "%Y-%m-%d", t);
		cout << date << endl;
		i++;
	}
	cout << ENDC;

}
int main(int args, char ** argv)
{
	ctr.load();

	if(args > 1 && strcmp(argv[1],"edit") == 0) {
		PlanningEditor* editor = new PlanningEditor();
		editor->run();
	} else
		print_items();
	return 0;

}

