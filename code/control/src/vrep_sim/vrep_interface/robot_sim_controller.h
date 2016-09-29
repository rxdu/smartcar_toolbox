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
 * robot_sim_controller.h
 *
 *  Created on: Sep 1, 2016
 *      Author: rdu
 */

#ifndef CONTROL_SRC_VREP_SIM_VREP_INTERFACE_ROBOT_SIM_CONTROLLER_H_
#define CONTROL_SRC_VREP_SIM_VREP_INTERFACE_ROBOT_SIM_CONTROLLER_H_

//extern "C" {
//    #include "extApi.h"
///*	#include "extApiCustom.h" // custom remote API functions */
//}
//
//#include "common/robot_state_base.h"

#include <cstdint>

namespace srcl_ctrl
{

template<typename DataFromSimType, typename DataToSimType, typename RobotStateType, typename RobotCmdType>
class RobotSimController
{
protected:
	RobotSimController():ctrl_loop_count_(0){};
	virtual ~RobotSimController(){};

protected:
	RobotStateType rs_;
	RobotStateType est_rs_;
	uint64_t ctrl_loop_count_;

public:
	virtual const RobotStateType& GetRobotState() { return rs_;};
	virtual DataToSimType ConvertRobotCmdToSimCmd(const RobotCmdType& cmd) = 0;

	virtual void UpdateRobotState(const DataFromSimType& data) = 0;
	virtual RobotCmdType UpdateCtrlLoop() = 0;
};

}

#endif /* CONTROL_SRC_VREP_SIM_VREP_INTERFACE_ROBOT_SIM_CONTROLLER_H_ */
