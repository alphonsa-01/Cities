/*!
Name : Alphonsa George
Assignment  PROG 1203-HW5 Cities
*/

#ifndef CITY_IO_H_
#define CITY_IO_H_

#include<fstream>
#include<iostream>
#include<string>
#include <vector>

#include "city.h"

/**
 * \brief The standard nwacc namespace.
 *
 * The namespace used for all nwacc application code.
 */
namespace nwacc
{
	/*!
	\brief a untility class to read a file and populate a container of city objects
	*/
	class city_io
	{
	public:
		/*!
		\brief creats an instance of city_io class
		*/
		city_io();
		/*!
		\brief creates an instance of city_io class with its city attribute
		\param city city of this instance
		*/
		city_io(const city& city);

		/*!
		\brief STL container vector to store the contents from the wordcities.csv file 
		*/
		std::vector<city>cities;

		/*!
		\brief Loads the vector from the csv file
		reads the csv file, parse line by line and store city name, latitude and longitude of each cities to the vector.
		\param  file_name .csv file which contains all the information about the cities
		*/
		void load_name(const std::string& file_name);
		/*!
		\brief friend function to let the ostream give acces to all city_io attributes
		here << operator gets overloaded
		\param out ostream variable
		\param value our city_io variable
		*/
		friend std::ostream& operator<<(std::ostream& out, const city_io& value);
		/*!
		\brief  friend function to let the istream give acces to all city_io attributes
		here >> operator gets overloaded
		\param in istream variable
		\param value our city_io variable
	   */
		friend std::istream& operator>>(std::istream& in, city_io& value);

	private:
		city city_;
	};
}
#endif