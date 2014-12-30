#ifndef PLANNINGITEMS_H
#define PLANNINGITEMS_H

#include <cstddef>
#include "cursesm.h"
#include "planningcontroller.h"
#include "planningitem.h"
class PlanningMenuItem : public NCursesMenuItem {
public:
	PlanningItem *item;

	PlanningMenuItem(PlanningItem* item) : NCursesMenuItem(item->getTask().c_str()){
		this->item = item;
	}
	bool action() {

		return false;
	}
};

class PlanningItems : public NCursesMenu
{
private:
  NCursesMenuItem** I;

public:
  PlanningItems(PlanningController*);
  PlanningItems& operator =(const PlanningItems&);
  virtual void On_Menu_Init();
  virtual void On_Menu_Termination();
  virtual void On_Item_Init(NCursesMenuItem&);
  virtual void On_Item_Termination(NCursesMenuItem&);
};


class PlanningItemsMenuItem : public NCursesMenuItem {
private:
	PlanningController* ctr;

public:
	PlanningItemsMenuItem(PlanningController* ctl) : NCursesMenuItem("Planning") {
		this->ctr = ctl;
	}
	bool action() {
		PlanningItems menu2(ctr);
		menu2();

		return false;
	}

};

#endif // PLANNINGITEMS_H
