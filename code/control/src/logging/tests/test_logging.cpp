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


