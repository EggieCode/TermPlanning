#include "planningitems.h"

#include <cstddef>
#include "cursesm.h"
#include "planningcontroller.h"
#include "planningitem.h"
#include "planningmenu.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>


PlanningItems::PlanningItems(PlanningController *ctr)
	: NCursesMenu (lines()-1,cols()-1),
	  I(0)
{
	I = new NCursesMenuItem*[ctr->getItems()->size() + 3];
	int i = 0;
	for(auto item: *ctr->getItems() ) {
		I[i] = new PlanningMenuItem(item);
		i++;
	}

	I[i++] = new QuitItem(); // Terminating empty item
	I[i++] = new NCursesMenuItem(); // Terminating empty item

	try {
		InitMenu(I, TRUE, TRUE);
	}
	catch(NCursesException ex) {
		endwin();
		std::cout << ex.errorno << std::endl;
		std::cout << ex.message << std::endl;
	}

//	this->set_options(Menu);

	boldframe("Menu", "");
	this->attron(A_REVERSE);
	for(int y = 1; y<  lines() - 2; y++ ) {
		this->printw(y, cols() - 25,"|");
	}


	this->printw(1, cols() - 24," Deadlines:           ");
	this->attroff(A_REVERSE);


	this->options_off(O_SHOWDESC);
}


PlanningItems& PlanningItems::operator=(const PlanningItems& rhs)
{
	if (this != &rhs) {
		*this = rhs;
	}
	return *this;
}



void PlanningItems::On_Menu_Init()
{
	refresh();
}

void PlanningItems::On_Menu_Termination()
{
	refresh();
}

void PlanningItems::On_Item_Init(NCursesMenuItem& item)
{

	for(int y = 2; y< lines() -2; y++) {
		for(int x = cols() - 23; x< cols() - 2; x++) {
			this->printw(y,x," ");
		}
	}

	PlanningMenuItem *planningItem = dynamic_cast<PlanningMenuItem *>(&item);
	if(planningItem != 0) {
		for(int i = 0; i < planningItem->item->getDeadlineCount() ; i++) {
			const std::time_t* unixtime = &planningItem->item->getDeadlines()[i];

			struct std::tm *t = localtime(unixtime);
			char date[20];
			std::strftime(date,sizeof(date),"%d-%m-%Y",t);
			this->printw(i + 2, cols() - 23,date);
		}

	}
	refresh();
}

void PlanningItems::On_Item_Termination(NCursesMenuItem& item)
{
	refresh();
}

