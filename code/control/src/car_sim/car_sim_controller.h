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
 * car_sim_controller.h
 *
 *  Created on: Sep 2, 2016
 *      Author: rdu
 */

#ifndef CONTROL_SRC_CAR_SIM_CAR_SIM_CONTROLLER_H_
#define CONTROL_SRC_CAR_SIM_CAR_SIM_CONTROLLER_H_

#include <memory>

// headers for g3log
#ifdef ENABLE_LOG
#include "g3log/g3log.hpp"
#include "g3log/logworker.hpp"
#include "g3log/std2_make_unique.hpp"
#endif

#include "vrep_sim/vrep_interface/robot_sim_controller.h"
#include "car_sim/car_sim_data.h"
#include "car_ctrl/controller/car_types.h"
#include "car_ctrl/estimator/car_state.h"

namespace smartcar {

class CarSimController : public RobotSimController<DataFromSimCar, DataToSimCar,CarState, CarCmd>
{
public:
	CarSimController();
	~CarSimController();

public:
	virtual DataToSimCar ConvertRobotCmdToSimCmd(const CarCmd& cmd);
	virtual void UpdateRobotState(const DataFromSimCar& data);
	virtual CarCmd UpdateCtrlLoop();
};

}



#endif /* CONTROL_SRC_CAR_SIM_CAR_SIM_CONTROLLER_H_ */
