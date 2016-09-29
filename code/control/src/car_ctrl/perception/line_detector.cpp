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
 * line_detector.cpp
 *
 *  Created on: Aug 6, 2015
 *      Author: rdu
 */

#include "perception/line_detector.h"

using namespace RobotToolkitRIVeR;

LineDetector::LineDetector(void)
{

}

LineDetector::~LineDetector(void)
{

}

void LineDetector::BinarizeImage(unsigned char mono_image[IMG_RES_Y][IMG_RES_X])
{
	int row, col;

	for(row = 0; row < 90; row++)
	{
		for(col = 0; col < 160; col++)
		{
			if(mono_image[row][col] > bin_threshold_)
				bin_image_[row][col] = 255;
			else
				bin_image_[row][col] = 0;
		}
	}
}

void LineDetector::ExtractRefLine()
{
	int row, col;

	for(row = 0; row < 90; row++)
	{
		unsigned char right_index;
		unsigned char left_index;

		for(col = 0; col < 80; col++)
		{
			if(bin_image_[row][80-col] > bin_image_[row][80-col-1])
			{
				ref_line_[row][80-col] = 0;
				left_index = 81-col;
			}
		}

		for(col = 81; col < 159; col++)
		{
			if(bin_image_[row][col] > bin_image_[row][col+1])
			{
				ref_line_[row][col] = 0;
				right_index = col;
			}
		}

		if((right_index - left_index)%2 == 0)
			bin_image_[row][(right_index - left_index)/2] = 0;
	}
}
