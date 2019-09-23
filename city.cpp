/*!
Name : Alphonsa George
Assignment  PROG 1203-HW5 Cities
*/

#include "city.h"

/**
 * \brief The standard nwacc namespace.
 *
 * The namespace used for all nwacc application code.
 */
namespace nwacc
{
	/*!
		This represents radius of earth which is 6371.0 km.
	*/
	const double  city::k_earth_radius = 6371.0;
	/*!
		 Represents a mathematical constant PI- defined as the ratio of circle's circumference to the diameter, which equals to 3.1415962
	*/
	const double city::k_pi = 3.1415962;

	/*!
	Represents the angle in degrees which we need to use to convert an angle in degrees to radian , which equals to 180deg
	*/
	const double city::k_degree = 180.0;

	/*!
		Represents the integer value we use in the great distance formula which is used as a multiplier and a divisor,value equals to 2
	*/
	 const int city::k_squared=2;

	/*!
		\brief creates an instance of a unit circle.
	*/
	city::city() {}

	/*!
		\brief creates an instance of city with it's name latitude and longitude
		\param city_name name of the city
		\param latitude latitudinal coordinate of the city
		\param longitudinal coordinate of the city.
	*/
	city::city(const std::string& city_name, const double latitude, const double longitude)
	{
		this->city_name_ = city_name;
		this->latitude_ = latitude;
		this->longitude_ = longitude;
	}

	/*!
		\brief Gets the city name of this instance
		\return the name of this instance
	*/
	std::string city::get_city_name()const
	{
		return this->city_name_;
	}
	/*!
		\brief Gets the country name of this instance
		\return returns the name of the country city belongs to
	*/
	std::string city::get_country_name()const
	{
		return this->country_;
	}

	/*!
		\brief Gets the latitude of this instance
		\return returns the latitude value of this instance
	*/
	double city::get_latitude() const
	{
		return this->latitude_;
	}

	/*!
		\brief gets the longitude of this instance
		\return returns the longitude value of this instance
	*/
	double city::get_longitude() const
	{
		return this->longitude_;
	}

	/*!
		\brief Converts the degrees to radian
		calculates the angle which is in degree to radian, one angle can be converted from degree to radian by multiplying it with pi/180
		\param angle value of the angle which is in degrees.
		\return returns the radian value of the angle in degrees.
	*/
	double city::degree_to_radian(double angle)const
	{
		return k_pi * angle / k_degree;
	}

	/*!
		\brief Calculates the Harversine distance between two cities
		‘haversine’ formula to calculate the great-circle distance between two points – that is, the shortest distance over the earth’s surface -giving
		an ‘as-the-crow-flies’ distance between the points
		\param city this is the city with its latitude and longitude values
		\param other_city other city with it's latitude and longitude values
		\return returns the distance between city and other_city
	*/
	double city::harversine_distance(const city& other_city) const
	{
		double latitude_one_to_radian = city::degree_to_radian(this->get_latitude());
		double latitude_two_to_radian = city::degree_to_radian(other_city.get_latitude());
		double longitude_one_to_radian = city::degree_to_radian(this->get_longitude());
		double longitude_two_to_radian = city::degree_to_radian(other_city.get_longitude());

		double difference_in_latitude = latitude_two_to_radian - latitude_one_to_radian;
		double difference_in_longitude = longitude_two_to_radian - longitude_one_to_radian;

		double computation = std::asin(std::sqrt(std::sin(difference_in_latitude / k_squared) * std::sin(difference_in_latitude / k_squared) + std::cos(latitude_one_to_radian) *
			std::cos(latitude_two_to_radian) * std::sin(difference_in_longitude / k_squared) * std::sin(difference_in_longitude / k_squared)));

		return k_squared * k_earth_radius * computation;
	}

	/*!
		\brief friend function to let the ostream give acces to all city attributes
		here << operator gets overloaded
		\param out ostream variable
		\param value our city variable
	*/
	std::ostream& operator<<(std::ostream& out, const city& value)
	{
		out << value.city_name_ << std::endl;
		out << value.country_ << std::endl;
		out << value.latitude_ << std::endl;
		out << value.longitude_ << std::endl;

		return out;
	}

	/*!
		\brief  friend function to let the istream give acces to all city attributes
		here >> operator gets overloaded
		\param in istream variable
		\param value our city variable
	*/
	std::istream& operator>>(std::istream& in, city& value)
	{
		in >> value.city_name_ >> value.country_;
		in >> value.latitude_ >> value.longitude_;

		return in;
	}
}