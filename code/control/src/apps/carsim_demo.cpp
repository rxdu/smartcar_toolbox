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
 * quadsim_demo.cpp
 *
 *  Created on: Sep 1, 2016
 *      Author: rdu
 */

#include <iostream>
#include <memory>
#include <cmath>

#include "car_sim/car_sim_client.h"
#include "car_sim/car_sim_controller.h"
#include "vrep_sim/vrep_interface/robot_sim_process.h"

using namespace smartcar;

int main(int arc, char* argv[])
{
	std::shared_ptr<CarSimClient> client = std::make_shared<CarSimClient>();
	std::shared_ptr<CarSimController> controller = std::make_shared<CarSimController>();

	// create a simulation process
	RobotSimProcess<DataFromSimCar, DataToSimCar,CarState, CarCmd> process(client,controller);

	// run the simulation in synchronous mode
	if(process.ConnectToServer())
		process.StartSimLoop_Synchronous();

	return 1;
}


