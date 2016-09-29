/*******************************************************************************
 *     Smart Car Toolbox
 *     
 *     Copyright (C) 2016 Ruixiang Du <http://rdu.im> 
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
 * utils_log.h
 *
 *  Created on: Mar 11, 2016
 *      Author: rdu
 */

#ifndef LIBRARY_LIBG3LOG_UTILS_LOG_UTILS_LOG_H_
#define LIBRARY_LIBG3LOG_UTILS_LOG_UTILS_LOG_H_

#include <string>
#include <sstream>

namespace srcl_ctrl {

class UtilsLog {
public:
	UtilsLog();
	~UtilsLog();

private:
	static std::string log_entry;

public:
	static void AppendLogMsgStr(std::string msg_str);
	static void AppendLogMsgTuple3f(float t1, float t2, float t3);
	static void AppendLogMsgTuple4f(float t1, float t2, float t3, float t4);

	static void EmptyLogMsgEntry();
	static std::string GetLogEntry();
};

}

#endif /* LIBRARY_LIBG3LOG_UTILS_LOG_UTILS_LOG_H_ */
