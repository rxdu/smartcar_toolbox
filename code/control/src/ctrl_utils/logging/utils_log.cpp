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
 * utils_log.cpp
 *
 *  Created on: Mar 11, 2016
 *      Author: rdu
 */

#include "ctrl_utils/logging/utils_log.h"

using namespace smartcar;

std::string UtilsLog::log_entry = "";

UtilsLog::UtilsLog()
{
}

UtilsLog::~UtilsLog()
{
}

void UtilsLog::AppendLogMsgTuple3f(float t1, float t2, float t3)
{
	std::ostringstream log_stream;

	if(!UtilsLog::log_entry.empty())
		log_stream << " , ";

	log_stream << std::to_string(t1);
	log_stream << " , ";
	log_stream << std::to_string(t2);
	log_stream << " , ";
	log_stream << std::to_string(t3);
	log_entry += log_stream.str();
}

void UtilsLog::AppendLogMsgTuple4f(float t1, float t2, float t3, float t4)
{
	std::ostringstream log_stream;

	if(!UtilsLog::log_entry.empty())
		log_stream << " , ";

	log_stream << std::to_string(t1);
	log_stream << " , ";
	log_stream << std::to_string(t2);
	log_stream << " , ";
	log_stream << std::to_string(t3);
	log_stream << " , ";
	log_stream << std::to_string(t4);
	log_entry += log_stream.str();
}

void UtilsLog::AppendLogMsgStr(std::string msg_str)
{
	std::ostringstream log_stream;

	if(!UtilsLog::log_entry.empty())
		log_stream << " , ";
	log_stream << msg_str;
	log_entry += log_stream.str();
}

void UtilsLog::EmptyLogMsgEntry()
{
	UtilsLog::log_entry.clear();
}

std::string UtilsLog::GetLogEntry()
{
	return log_entry;
}
