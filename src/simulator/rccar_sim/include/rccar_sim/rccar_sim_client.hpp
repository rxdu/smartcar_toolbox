/* 
 * rccar_sim_client.hpp
 * 
 * Created on: Jul 25, 2018 23:40
 * Description: 
 * 
 * Copyright (c) 2018 Ruixiang Du (rdu)
 */

#ifndef RCCAR_SIM_CLIENT_HPP
#define RCCAR_SIM_CLIENT_HPP

#include <cstdint>

#include "rccar_sim/rccar_sim_types.hpp"
#include "vrep_interface/vrep_sim_client.hpp"

namespace librav
{

class RCCarSimClient : public VrepSimClient<DataFromRCCarSim, DataToRCCarSim>
{
  public:
	RCCarSimClient();
	~RCCarSimClient();

	virtual bool ReceiveDataFromSimRobot(DataFromRCCarSim *rdata) override;
	virtual void UpdateCtrlLoop(const DataFromRCCarSim &rdata, DataToRCCarSim *rcmd) override;
	virtual void SendDataToSimRobot(const DataToRCCarSim &rcmd) override;

  private:
	simxInt car_handle_;
	simxInt camera_handle_;
	simxInt steering_right_;
	simxInt steering_left_;
	simxInt driving_front_right_;
	simxInt driving_front_left_;
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

	virtual void ConfigDataStreaming(void) override;

	bool GetCarDrivingVel(float &rvel, float &lvel, float &body_vel);
	bool GetCarSteeringAngle(float &data);
	bool GetVisionImage(simxUChar img[IMG_RES_Y][IMG_RES_X]);

	void SetCarSteeringAngle(float cmd);
	void SetCarSteeringVelocity(float cmd);
	void SetCarDrivingVel(float cmd);
};
} // namespace librav

#endif /* RCCAR_SIM_CLIENT_HPP */
