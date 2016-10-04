/*
 * car_sim_config.h
 *
 *  Created on: Oct 3, 2016
 *      Author: rdu
 */

#ifndef CONTROL_SRC_CAR_SIM_CAR_SIM_CONFIG_H_
#define CONTROL_SRC_CAR_SIM_CAR_SIM_CONFIG_H_

namespace smartcar {

// resolution of the main vision sensor
#define IMG_RES_X 160
#define IMG_RES_Y 90

const double max_steer_angle = 30.0;	// in degree
const double max_drive_speed = 100.0;	// in round/s

}

#endif /* CONTROL_SRC_CAR_SIM_CAR_SIM_CONFIG_H_ */
