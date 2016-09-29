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
 * line_detector.h
 *
 *  Created on: Aug 6, 2015
 *      Author: rdu
 */

#ifndef PERCEPTION_LINE_DETECTOR_H_
#define PERCEPTION_LINE_DETECTOR_H_

#include "car_sim/car_sim_data.h"

namespace RobotToolkitRIVeR
{
class LineDetector
{
public:
	LineDetector();
	~LineDetector();

public:
	void GetCentralRefLine();

public:
	void BinarizeImage(unsigned char mono_image[IMG_RES_Y][IMG_RES_X]);
	void ExtractRefLine();

private:
	const unsigned char bin_threshold_ = 140;

public:
	unsigned char bin_image_[IMG_RES_Y][IMG_RES_X];
	unsigned char ref_line_[IMG_RES_Y][IMG_RES_X];

};
}

#endif /* PERCEPTION_LINE_DETECTOR_H_ */
