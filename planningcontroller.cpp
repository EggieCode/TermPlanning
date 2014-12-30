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
#include "planningcontroller.h"
#include "planningitem.h"
#include <vector>
#include <string>
#include <json-c/json.h>

PlanningController::PlanningController()
{
	items = new std::vector<PlanningItem*>();
}

void PlanningController::addItem(std::string task, std::time_t *deadlines, int count_deadlines) {
	PlanningItem* item = new PlanningItem(task,deadlines, count_deadlines);
	items->push_back(item);
}

void PlanningController::addItem(PlanningItem &item) {
	items->push_back(&item);
}

std::vector<PlanningItem*> *PlanningController::getItems() {
	return items;
}

void PlanningController::load(){


	json_object	*new_obj = json_object_from_file("/home/egbert/.local/planning_c.json");
	json_object *json_planning_items;
	if(!json_object_object_get_ex(new_obj,"items",&json_planning_items))
		return;

	int arraylen = json_object_array_length(json_planning_items);
	for(int i = 0; i < arraylen; i++) {

		json_object *item = json_object_array_get_idx(json_planning_items, i);
		json_object *obj_task ;
		json_object *obj_deadlines;
		int64_t *deadlines;
		std::string task;
		int count_deadlines = 0;
		json_object_object_get_ex(item, "task", &obj_task);
		if(!json_object_object_get_ex(item, "deadline", &obj_deadlines))
			json_object_object_get_ex(item, "deadlines",&obj_deadlines);

		json_type deadlines_type = json_object_get_type(obj_deadlines);

		if(deadlines_type == json_type_int) {

			long deadline = (json_object_get_int64(obj_deadlines));
			deadlines = new long[1]{deadline};
			count_deadlines = 1;

			obj_deadlines = json_object_new_array();
			json_object_object_add(item, "deadlines", obj_deadlines);

			json_object_array_add(obj_deadlines,json_object_new_int64(deadline));
			json_object_object_del(item, "deadline");

		} else if(deadlines_type == json_type_array) {

			int arraylen = json_object_array_length(obj_deadlines);
			deadlines = new long[arraylen];
			count_deadlines = arraylen;
			for(int x = 0; x < arraylen; x++) {

				json_object *obj_deadline = json_object_array_get_idx(obj_deadlines, x);
				deadlines[x] = ( json_object_get_int64(obj_deadline));
			}

		}



		task = (json_object_get_string(obj_task));


		this->addItem(task,deadlines, count_deadlines);


	}

	json_object_to_file("/home/egbert/.local/planning_c.json",new_obj);

	//	free(json_planning_items);
	free(new_obj);



}
