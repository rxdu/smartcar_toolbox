/* 
 * rccar_sim_control.hpp
 * 
 * Created on: Jul 25, 2018 23:39
 * Description: 
 * 
 * Copyright (c) 2018 Ruixiang Du (rdu)
 */

#ifndef RCCAR_SIM_CONTROL_HPP
#define RCCAR_SIM_CONTROL_HPP

#include <memory>

#include "rccar_sim/rccar_sim_types.hpp"

namespace librav
{

class RCCarSimControl
{
  public:
	RCCarSimControl() = default;

	// DataToRCCarSim ConvertRobotCmdToSimCmd(const RCCarCmd &cmd);
	void UpdateRobotState(const DataFromRCCarSim &data);
	DataToRCCarSim UpdateCtrlLoop();

	void SetInitPose(float x, float y, float yaw);
	void InitLogger(std::string log_name_prefix, std::string log_save_path);
};
} // namespace librav

#endif /* RCCAR_SIM_CONTROL_HPP */
