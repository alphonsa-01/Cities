/*!
Name : Alphonsa George
Assignment  PROG 1203-HW5 Cities
*/

#include "city_io.h"

/**
 * \brief The standard nwacc namespace.
 *
 * The namespace used for all nwacc application code.
 */
namespace nwacc
{
	/*!
		\brief creats an instance of city_io class
	*/
	city_io::city_io() {}

	/*!
		\brief creates an instance of city_io class with its city attribute
		\param city city of this instance
	*/
	city_io::city_io(const city& city)
	{
		this->city_ = city;
	}

	/*!
		\brief STL container vector to store the contents from the wordcities.csv file
	*/
	std::vector<city>cities;

	/*!
		\brief Loads the vector from the csv file
		reads the csv file, parse line by line and store city name, latitude and longitude of each cities to the vector.
		\param  file_name .csv file which contains all the information about the cities
	*/
	void city_io::load_name(const std::string& file_name)
	{
		std::ifstream fin;
		fin.open(file_name);

		if (fin)
		{
			std::string city_name;
			auto latitude=0.0;
			auto longitude = 0.0;

			while (!fin.eof())
			{
				std::string line;
				std::getline(fin,line);

				auto first_comma = line.find(",");
				auto second_comma = line.find(",", first_comma + 1);
				std::string city_name;

				if (first_comma != std::string::npos&& second_comma!=std::string::npos)
				{
					city_name = line.substr(first_comma + 1, second_comma - first_comma - 1);
				}
				else
				{
					city_name = "";
				}

				auto third_comma = line.find(",", second_comma + 1);

				std::string latitude_value;
				if (second_comma != std::string::npos && third_comma != std::string::npos)
				{
					latitude_value = line.substr(second_comma + 1, third_comma - second_comma - 1);
				}
				else
				{
					latitude_value = "";
				}
				
				 latitude = std::stod(latitude_value);

				auto index = line.find(' ');

				std::string longitude_value;

				if (third_comma != std::string::npos && index != std::string::npos)
				{
					longitude_value = line.substr(third_comma + 1, index - third_comma - 1);
				}
				else
				{
					longitude_value = "";
				}
				longitude = std::stod(longitude_value);
			}
			cities.emplace_back(city_name, latitude, longitude);
		}//else , the file is failed to open,leave the vector empty, do.nothing();

		fin.close();

	}

	/*!
		\brief friend function to let the ostream give acces to all city_io attributes
		here << operator gets overloaded
		\param out ostream variable
		\param value our city_io variable
	*/
	std::ostream& operator<<(std::ostream& out, const city_io& value)
	{
		for (const auto& a_city : value.cities)
		{
			out << a_city << std::endl;
		}
		return out;
	}

	/*!
		\brief  friend function to let the istream give acces to all city_io attributes
		here >> operator gets overloaded
		\param in istream variable
		\param value our city_io variable
	*/
	std::istream& operator>>(std::istream& in, city_io& value)
	{
		in >> value.city_;

		return in;
	}
}