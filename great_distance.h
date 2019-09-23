#ifndef GREAT_DISTANCE_H_
#define GREAT_DISTANCE_H_

#include<cmath>
#include<iostream>

#include "city.h"
namespace nwacc
{
	class great_distance
	{
	public:
		static const double k_earth_radius;

		great_distance(const double latitude = 0.0, const double longitude = 0.0);

		double get_latitude() const;

		double get_longitude() const;

		double degree_to_radian(double angle)const;
		double harversine_distance(const great_distance& city_one, const great_distance& city_two);

	private:
		double city_latitude_{};
		double city_longitude_{};

	};
}
#endif