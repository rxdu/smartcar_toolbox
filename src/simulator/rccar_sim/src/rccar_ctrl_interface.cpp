/* 
 * rccar_ctrl_interface.cpp
 * 
 * Created on: Jul 25, 2018 23:54
 * Description: 
 * 
 * Copyright (c) 2018 Ruixiang Du (rdu)
 */ 

#include "rccar_sim/rccar_ctrl_interface.hpp"

#include <iostream>

#include "logging/logger.hpp"

using namespace librav;

void RCCarSimControl::InitLogger(std::string log_name_prefix, std::string log_save_path)
{
	CtrlLogger &logging_helper = CtrlLogger::GetLogger(log_name_prefix, log_save_path);

	logging_helper.AddItemNameToEntryHead("pos_x");
	logging_helper.AddItemNameToEntryHead("pos_y");
	logging_helper.AddItemNameToEntryHead("pos_z");
	logging_helper.AddItemNameToEntryHead("pos_d_x");
	logging_helper.AddItemNameToEntryHead("pos_d_y");
	logging_helper.AddItemNameToEntryHead("pos_d_z");
	logging_helper.AddItemNameToEntryHead("pos_e_x");
	logging_helper.AddItemNameToEntryHead("pos_e_y");
	logging_helper.AddItemNameToEntryHead("pos_e_z");

	logging_helper.PassEntryHeaderToLogger();
}

void RCCarSimControl::SetInitPose(float x, float y, float yaw)
{
}

void RCCarSimControl::UpdateRobotState(const DataFromRCCarSim &data)
{
	// RCCarSensorData sensor_data;
	// rs_.UpdateRobotState(sensor_data);
}

DataToRCCarSim RCCarSimControl::UpdateCtrlLoop()
{
	DataToRCCarSim cmd;

	// process image

	// plan

	// control

	// set control variables
	cmd.driving_vel_cmd = 50;
	cmd.steering_ang_cmd = 45.0f;// * 3.1415f / 180.0f;

	return cmd;
}
