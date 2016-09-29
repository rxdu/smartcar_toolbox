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
 * robot_state.cpp
 *
 *  Created on: Jul 29, 2015
 *      Author: rdu
 */

#include <cmath>
#include <iostream>

#include "car_ctrl/estimator/car_state.h"

using namespace srcl_ctrl;

CarState::CarState(void):
		driving_velocity_(0)
{
}

CarState::~CarState(void)
{

}

void CarState::UpdateRobotState(const DataFromSimCar &new_data)
{
	driving_velocity_ = new_data.body_vel;

	for(int i = 0; i < IMG_RES_Y; i++)
		for(int j = 0; j < IMG_RES_X; j++)
			mono_image_[i][j] = new_data.mono_image[i][j];
}
