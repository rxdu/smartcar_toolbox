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
 * car_sim_data.h
 *
 *  Created on: Sep 2, 2016
 *      Author: rdu
 */

#ifndef CONTROL_SRC_CAR_SIM_CAR_SIM_DATA_H_
#define CONTROL_SRC_CAR_SIM_CAR_SIM_DATA_H_

#include "common/control_types.h"
#include "car_ctrl/controller/car_types.h"

namespace smartcar {

#define IMG_RES_X 160
#define IMG_RES_Y 90

typedef struct
{
	// sensor data
	unsigned char mono_image[IMG_RES_Y][IMG_RES_X];
	IMUData imu_data;

	float body_vel;
	float driving_vel_right;
	float driving_vel_left;
	float steering_ang;
} DataFromSimCar;

typedef struct
{
	CarCmd cmd;
} DataToSimCar;

}

#endif /* CONTROL_SRC_CAR_SIM_CAR_SIM_DATA_H_ */
