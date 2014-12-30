#ifndef PLANNINGMENU_H
#define PLANNINGMENU_H

#include <cstddef>
#include "cursesm.h"

class PassiveItem : public NCursesMenuItem
{
public:
	PassiveItem(const char* text) : NCursesMenuItem(text){
		options_off(O_SELECTABLE);

	}

};

class QuitItem : public NCursesMenuItem
{
public:
	QuitItem() : NCursesMenuItem("Close") {
	}

	bool action() {
		return TRUE;
	}
};

class PlanningMenu : public NCursesMenu
{
private:
  NCursesMenuItem** I;
  #define n_items 3
public:
  PlanningMenu();
  ~PlanningMenu();
  PlanningMenu& operator =(const PlanningMenu& rhs);
//  virtual void On_Menu_Init();
//  virtual void On_Menu_Termination();
//  virtual void On_Item_Init(NCursesMenuItem&);
//  virtual void On_Item_Termination(NCursesMenuItem&);
};


#endif // PLANNINGMENU_H
