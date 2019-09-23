/*!
Name : Alphonsa George
Assignment  PROG 1203-HW5 Cities
*/

#ifndef CITY_H_
#define CITY_H_

#include<iostream>
#include<string>

/**
 * \brief The standard nwacc namespace.
 *
 * The namespace used for all nwacc application code.
 */
namespace nwacc
{
	/*!
	\brief Represents a city with its name country and location.

	A city with its name, the country it belongs to and the latitude and longitude values which determines the location of the city.
	*/
	class city
	{
	public:
		/*!
		This represents radius of earth which is 6371.0 km.
		*/
		static const double k_earth_radius;

		/*!
		 Represents a mathematical constant PI- defined as the ratio of circle's circumference to the diameter, which equals to 3.1415962
		*/
		static const double k_pi;

		/*!
		Represents the angle in degrees which we need to use to convert an angle in degrees to radian , which equals to 180deg
		*/
		static const double k_degree ;

		/*!
		Represents the integer value we use in the great distance formula which is used as a multiplier and a divisor,value equals to 2
		*/
		static const int k_squared ;

		/*!
		\brief creates an instance of a city.
		*/
		city();

		/*!
		\brief creates an instance of city with it's name latitude and longitude
		\param city_name name of the city
		\param latitude latitudinal coordinate of the city
		\param longitudinal coordinate of the city.
		*/
		city(const std::string& city_name, const double latitude, const double longitude);

		/*!
		\brief Gets the city name of this instance
		\return the name of this instance
		*/

		std::string get_city_name()const;
		/*!
		\brief Gets the country name of this instance
		\return returns the name of the country city belongs to
		*/
		std::string get_country_name()const;
		/*!
		\brief Gets the latitude of this instance
		\return returns the latitude value of this instance
		*/
		double get_latitude() const;

		/*!
		\brief gets the longitude of this instance
		\return returns the longitude value of this instance
		*/
		double get_longitude() const;

		/*!
		\brief Converts the degrees to radian
		calculates the angle which is in degree to radian, one angle can be converted from degree to radian by multiplying it with pi/180
		\param angle value of the angle which is in degrees.
		\return returns the radian value of the angle in degrees.
		*/
		double degree_to_radian(double angle)const;

		/*!
		\brief Calculates the Harversine distance between two cities
		‘haversine’ formula to calculate the great-circle distance between two points – that is, the shortest distance over the earth’s surface -giving
		an ‘as-the-crow-flies’ distance between the points
		\param city this is the city with its latitude and longitude values
		\param other_city other city with it's latitude and longitude values
		\return returns the distance between city and other_city
		*/
		double harversine_distance(const city& other_city) const;

		/*!
		\brief friend function to let the ostream give acces to all city attributes
		here << operator gets overloaded
		\param out ostream variable
		\param value our city variable
		*/
		friend std::ostream& operator<<(std::ostream& out, const city& value);

		/*!
		\brief  friend function to let the istream give acces to all city attributes
		here >> operator gets overloaded
		\param in istream variable
		\param value our city variable
		*/
		friend std::istream& operator>>(std::istream& in, city& value);


	private:
		/*!
		\brief The city name of this instance
		*/
		std::string city_name_;

		/*!
		\brief the country name of this instance
		*/
		std::string country_;

		/*!
		\brief the latitude coordinate  of this instance
		*/
		double latitude_{};

		/*!
		\brief the longitude coordinate  of this instance
		*/
		double longitude_{};
	
	};
}


#endif
