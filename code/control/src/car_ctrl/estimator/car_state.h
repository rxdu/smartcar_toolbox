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
 * car_state.h
 *
 *  Created on: Sep 2, 2016
 *      Author: rdu
 */

#ifndef ROBOT_STATE_CAR_STATE_H_
#define ROBOT_STATE_CAR_STATE_H_

#include <cstdint>
#include "car_sim/car_sim_data.h"

namespace smartcar
{
class CarState
{
public:
	CarState();
	~CarState();

private:
	float driving_velocity_;
	uint8_t mono_image_[IMG_RES_Y][IMG_RES_X];

public:
	void UpdateRobotState(const DataFromSimCar &new_data);
};

}

#endif /* ROBOT_STATE_CAR_STATE_H_ */
