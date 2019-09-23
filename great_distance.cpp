#include "great_distance.h"

namespace nwacc
{
	const double  great_distance::k_earth_radius = 6371.0;
	const double k_pi = 3.1415962;
	const double k_degree = 180.0;

	great_distance::great_distance(const double latitude, const double longitude) :city_latitude_{ latitude }, city_longitude_{ longitude } {}
	
	double great_distance::get_latitude() const
	{
		return this->city_latitude_;
	}

	double great_distance::get_longitude()const
	{
		return this->city_latitude_;
	}

	double great_distance::degree_to_radian(double angle)const
	{
		return k_pi * angle / k_degree;
	}

	double great_distance::harversine_distance(const great_distance& city_one, const great_distance& city_two)
	{
		double latitude_one_to_radian = great_distance::degree_to_radian(city_one.get_latitude());
		double latitude_two_to_radian = great_distance::degree_to_radian(city_two.get_latitude());
		double longitude_one_to_radian = great_distance::degree_to_radian(city_one.get_longitude());
		double longitude_two_to_radian = great_distance::degree_to_radian(city_two.get_longitude());

		double difference_in_latitude = latitude_two_to_radian - latitude_one_to_radian;
		double difference_in_longitude = longitude_two_to_radian - longitude_one_to_radian;

		double computation = std::asin(std::sqrt(std::sin(difference_in_latitude / 2) * std::sin(difference_in_latitude / 2) + std::cos(latitude_one_to_radian) *
			std::cos(latitude_two_to_radian) * std::sin(difference_in_longitude / 2) * std::sin(difference_in_longitude / 2)));

		return 2 * k_earth_radius * computation;
	}

}


