/*!
Name : Alphonsa George
Assignment  PROG 1203-HW5 Cities
*/
#include "menu_util.h"

namespace nwacc
{
	/*!
		\brief creates an instance of the menu_utility class
	*/
	menu_util::menu_util() {}
	/*!
		\brief Gets the string value from the prompt
		\param prompt we prompt to the user accordingly
		\return returns the string value entered by the user
	*/
	std::string menu_util::get_string(const std::string& prompt)
	{
		std::cout << prompt;
		std::string input;
		std::cin >> input;
		return input;
	}
	/*!
		\brief Gets the distance from the city picked by the user to other city
		\param city_one city entered by the user
		\return returns the distance
	*/
	double menu_util::distance(const nwacc::city& city_one)
	{
		city city;
		
		return city.harversine_distance(city_one);
	}

	/*!
	\brief Displays the container of city objects
	Iterate through the container and display the contents.
	*/
	void menu_util::display()
	{
		nwacc::city_io city;
		std::cout << city << std::endl;
	}
}
