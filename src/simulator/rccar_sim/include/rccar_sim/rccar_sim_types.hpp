/* 
 * rccar_sim_types.hpp
 * 
 * Created on: Jul 25, 2018 23:37
 * Description: 
 * 
 * Copyright (c) 2018 Ruixiang Du (rdu)
 */ 

#ifndef RCCAR_SIM_TYPES_HPP
#define RCCAR_SIM_TYPES_HPP

#include <cstdint>
#include <iostream>

#include "rccar_sim/rccar_sim_config.hpp"

namespace librav
{
// time_stamp starts from 0 when system initialized, increases at step 1 ms
typedef uint64_t time_stamp;

template <typename T>
struct value2d
{
	value2d() : x(0), y(0) {}
	value2d(T _x, T _y) : x(_x), y(_y) {}

	T x;
	T y;

	bool operator==(const struct value2d &other) const
	{
		if (this->x == other.x && this->y == other.y)
			return true;
		else
			return false;
	}

	friend std::ostream &operator<<(std::ostream &os, const struct value2d &pos)
	{
		os << pos.x << " , " << pos.y;
		return os;
	}
};

template <typename T>
struct value3d
{
	value3d() : x(0), y(0), z(0) {}
	value3d(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}

	T x;
	T y;
	T z;

	bool operator==(const struct value3d &other) const
	{
		if (this->x == other.x && this->y == other.y && this->z == other.z)
			return true;
		else
			return false;
	}

	friend std::ostream &operator<<(std::ostream &os, const struct value3d &pos)
	{
		os << pos.x << " , " << pos.y << " , " << pos.z;
		return os;
	}
};

using Point3f = value3d<float>;
using Point3d = value3d<double>;
using Point3i = value3d<int32_t>;

using Position2Di = value2d<int32_t>;
using Position2Dd = value2d<double>;
using Position3Di = value3d<int32_t>;
using Position3Dd = value3d<double>;

using Velocity2Di = value2d<int32_t>;
using Velocity2Dd = value2d<double>;
using Velocity3Di = value3d<int32_t>;
using Velocity3Dd = value3d<double>;

struct IMUData
{
	time_stamp mtime;
	Point3f gyro;
	Point3f acc;
};

struct DataFromRCCarSim
{
	// sensor data
	unsigned char mono_image[IMG_RES_Y][IMG_RES_X];
	IMUData imu_data;

	float body_vel;
	float driving_vel_right;
	float driving_vel_left;
	float steering_ang;
};

struct DataToRCCarSim
{
	float driving_vel_cmd;
	float steering_ang_cmd;
};
} // namespace librav

#endif /* RCCAR_SIM_TYPES_HPP */
