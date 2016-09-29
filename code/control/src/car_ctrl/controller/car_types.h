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
 * quad_types.h
 *
 *  Created on: Aug 9, 2016
 *      Author: rdu
 */

#ifndef CONTROL_SRC_QUAD_CTRL_CONTROLLER_QUAD_TYPES_H_
#define CONTROL_SRC_QUAD_CTRL_CONTROLLER_QUAD_TYPES_H_

#include "eigen3/Eigen/Core"
#include "eigen3/Eigen/Geometry"

#include <common/control_types.h>

namespace srcl_ctrl
{

typedef struct
{
	// input of position controller
	float pos_d[3];
	float vel_d[3];
	float acc_d[3];
	float yaw_d;
	float yaw_rate_d;

	// input of attitude controller (using Euler)
	float euler_d[3];
	float rot_rate_d[3];
	float delta_w_F;

	// input of attitude controller (using Quaternion)
	Eigen::Quaterniond quat_d;
	float ftotal_d;

}ControlInput;

typedef struct{
	// output of position controller (using Euler)
	float euler_d[3];
	float delta_w_F;

	// output of position controller (using Quaternion)
	Eigen::Quaterniond quat_d;
	float ftotal_d;

	// output of attitude controller
	float motor_ang_vel_d[3];
}ControlOutput;


typedef struct
{
	float driving_vel_rcmd;
	float driving_vel_lcmd;
	float steering_ang_cmd;
} CarCmd;

}

#endif /* CONTROL_SRC_QUAD_CTRL_CONTROLLER_QUAD_TYPES_H_ */
