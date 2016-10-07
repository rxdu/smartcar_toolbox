/*******************************************************************************
 *     Smart Car Toolbox
 *     
 *     Copyright (C) 2016 Ruixiang Du  <http://rdu.im> 
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *******************************************************************************/
/*
 * test_logging.cpp
 *
 *  Created on: Oct 6, 2016
 *      Author: rdu
 */

#include <memory>
#include "logging/logging_helper.h"

using namespace smartcar;

int main(int argc, char* argv[])
{
	LoggingHelper helper("test_log", "/home/rdu");

	helper.AddItemNameToEntryHead("x1");
	helper.AddItemNameToEntryHead("x2");
	helper.AddItemNameToEntryHead("x3");
	helper.AddItemNameToEntryHead("x4");

	helper.PassEntryHeaderToLogger();

	for(int i = 0; i < 500; i++) {
		helper.AddItemDataToEntry("x1", i+1);
		helper.AddItemDataToEntry("x2", i+2);
		helper.AddItemDataToEntry("x3", i+3);
		helper.AddItemDataToEntry("x4", i+4);

		helper.PassEntryDataToLogger();
	}
}


