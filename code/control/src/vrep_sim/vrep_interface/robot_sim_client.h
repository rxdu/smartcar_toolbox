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
 * robot_sim_client.h
 *
 *  Created on: Aug 4, 2015
 *      Author: rdu
 */

#ifndef VREP_CLIENT_ROBOT_SIM_CLIENT_H_
#define VREP_CLIENT_ROBOT_SIM_CLIENT_H_

extern "C" {
    #include "extApi.h"
/*	#include "extApiCustom.h" // custom remote API functions */
}

namespace srcl_ctrl
{

template<typename DataFromSimType, typename DataToSimType>
class RobotSimClient
{
protected:
	RobotSimClient(simxInt id):client_id_(id){};
	RobotSimClient():client_id_(-1){};
	virtual ~RobotSimClient(){};

public:
	simxInt client_id_;

	// the following functions need to be defined for a specific robot
	virtual void ConfigDataStreaming(void) = 0;
	virtual bool ReceiveDataFromRobot(DataFromSimType& state) = 0;
	virtual void SendDataToRobot(const DataToSimType& rcmd) = 0;
};

}

#endif /* VREP_CLIENT_ROBOT_SIM_CLIENT_H_ */
