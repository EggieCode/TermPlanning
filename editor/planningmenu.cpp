#include "planningmenu.h"
#include <cstddef>
#include "cursesm.h"
#include "planningitems.h"
extern PlanningController ctr;

PlanningMenu::PlanningMenu()
	: NCursesMenu (n_items + 2, 18, (lines() / 2) - 6, (cols()/2) - 9),
	  I(0)
{
	I = new NCursesMenuItem*[1+n_items];
//	I[0] = new PadAction("Planning items");
	I[0] = new PlanningItemsMenuItem(&ctr);
	I[1] = new QuitItem();
	I[2] = new NCursesMenuItem(); // Terminating empty item

	InitMenu(I, TRUE, TRUE);

	boldframe("Menu", "");
}
PlanningMenu& PlanningMenu::operator=(const PlanningMenu& rhs)
{
	if (this != &rhs) {
		*this = rhs;
	}
	return *this;
}

PlanningMenu::~PlanningMenu()
{

}

