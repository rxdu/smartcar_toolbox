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
 * car_sim_client.h
 *
 *  Created on: Sep 2, 2016
 *      Author: rdu
 */

#ifndef CONTROL_SRC_CAR_SIM_CAR_SIM_CLIENT_H_
#define CONTROL_SRC_CAR_SIM_CAR_SIM_CLIENT_H_

#include <cstdint>

extern "C" {
#include "extApi.h"
/*	#include "extApiCustom.h" // custom remote API functions */
}

#include "common/control_types.h"
#include "car_sim/car_sim_data.h"
#include "vrep_sim/vrep_interface/robot_sim_client.h"

namespace smartcar {

class CarSimClient : public RobotSimClient<DataFromSimCar, DataToSimCar>
{
public:
	CarSimClient();
	~CarSimClient();

private:
	virtual void ConfigDataStreaming(void);

public:
	virtual bool ReceiveDataFromRobot(DataFromSimCar& rstate);
	virtual void SendDataToRobot(const DataToSimCar& rcmd);

	bool GetCarDrivingVel(float& rvel, float& lvel, float& body_vel);
	bool GetCarSteeringAngle(float& data);
	bool GetVisionImage(simxUChar img[IMG_RES_Y][IMG_RES_X]);

	void SetCarSteeringAngle(float cmd);
	void SetCarSteeringVelocity(float cmd);
	void SetCarDrivingVel(float rcmd, float lcmd);

private:
	simxInt car_handle_;
	simxInt camera_handle_;
	simxInt steering_right_;
	simxInt steering_left_;
	simxInt driving_front_right_;
	simxInt	driving_front_left_;
	simxInt driving_rear_right_;
	simxInt driving_rear_left_;

	float body_lin_vel_[3];
	float body_ang_vel_[3];
	float body_vel_;

	float driving_right_vel_;
	float driving_left_vel_;
	float steering_angle_;
	float steering_vel_;

	simxUChar *image_raw_;
	int img_res[2];
};

}

#endif /* CONTROL_SRC_CAR_SIM_CAR_SIM_CLIENT_H_ */
