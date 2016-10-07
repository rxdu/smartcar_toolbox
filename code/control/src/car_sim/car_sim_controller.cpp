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
 * car_sim_controller.cpp
 *
 *  Created on: Sep 2, 2016
 *      Author: rdu
 */

#include "car_sim/car_sim_controller.h"

using namespace smartcar;

CarSimController::CarSimController()
{
#ifdef ENABLE_G3LOG
	logging_helper_ = std::make_shared<LoggingHelper>("car_sim", "/home/rdu/Workspace/smartcar_toolbox/code/control/log/car");
#endif
}

CarSimController::~CarSimController()
{

}

DataToSimCar CarSimController::ConvertRobotCmdToSimCmd(const CarCmd& cmd)
{
	DataToSimCar sim_cmd;

	sim_cmd.cmd.driving_vel_lcmd = cmd.driving_vel_lcmd;
	sim_cmd.cmd.driving_vel_rcmd = cmd.driving_vel_rcmd;
	sim_cmd.cmd.steering_ang_cmd = cmd.steering_ang_cmd;

	return sim_cmd;
}

void CarSimController::UpdateRobotState(const DataFromSimCar& data)
{
	rs_.UpdateRobotState(data);
}

CarCmd CarSimController::UpdateCtrlLoop()
{
	CarCmd cmd;

	// process image

	// plan

	// control

	// set control variables
	cmd.driving_vel_lcmd = 100;
	cmd.driving_vel_rcmd = 100;
	cmd.steering_ang_cmd = 0.0f*3.1415f/180.0f;

	return cmd;
}



