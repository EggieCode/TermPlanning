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

#ifndef PLANNINGITEM_H
#define PLANNINGITEM_H

#include <iostream>
#include <ctime>
class PlanningItem
{
public:
	PlanningItem(std::string task,std::time_t **deadlines, int count_deadlines) { this->task = task; this->deadlines = deadlines; this->count_deadlines = count_deadlines; }
    //~PlanningItem() { delete task; delete deadline; }
    std::string getTask() { return task; }
	std::time_t **getDeadlines() { return deadlines; }
	int getDeadlineCount() { return count_deadlines; }

    void setTask(std::string task) { this->task = task; }
	void addDeadline(std::time_t deadline) { (*this->deadlines[count_deadlines++]) = deadline; }


private:
    std::string task;
	std::time_t **deadlines;
	int count_deadlines;

};

#endif // PLANNINGITEM_H
