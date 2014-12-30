/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Egbert Verhage
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
*/

#include "editor/planningeditor.h"
#include "editor/planningmenu.h"
#include "editor/planningitems.h"
#include "planningcontroller.h"
#include "planningitem.h"
#include <cstddef>
#include <cursesapp.h>
#include <cursesm.h>
#include <cursesf.h>

extern PlanningController ctr;

void PlanningEditor::init_labels(Soft_Label_Key_Set &S) const {
	for(int i=1; i <= S.labels(); i++) {
		char buf[8];
		assert(i < 100);
		::sprintf(buf, "Key%02d", i);
		S[i] = buf;                                      // Text
		S[i] = Soft_Label_Key_Set::Soft_Label_Key::Left; // Justification
	}

}

void PlanningEditor::title()
{
  const char * const titleText = "EggieCode.org Planning Editor";
  const int len = ::strlen(titleText);

  titleWindow->bkgd(screen_titles());
  titleWindow->addstr(0, (titleWindow->cols() - len)/2, titleText);
  titleWindow->noutrefresh();
}


int PlanningEditor::run()
{
	PlanningMenu planning_menu;
	planning_menu();
	endwin();
	return 0;
}
