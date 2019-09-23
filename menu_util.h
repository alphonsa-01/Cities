/*!
Name : Alphonsa George
Assignment  PROG 1203-HW5 Cities
*/
#ifndef MENU_UTIL_H_
#define MENU_UTIL_H_

#include<iostream>
#include <string>

#include "city.h"
#include "city_io.h"
namespace nwacc
{
	class menu_util
	{
	public:
		/*!
		\brief creates an instance of the menu_utility class
		*/
		menu_util();
		/*!
		\brief Gets the string value from the prompt
		\param prompt we prompt to the user accordingly
		\return returns the string value entered by the user
		*/
		static std::string get_string(const std::string& prompt);
		
		/*!
		\brief Gets the distance from the city picked by the user to other city
		\param city_one city entered by the user
		\return returns the distance
		*/
		static double distance(const city& city_one);

		/*!
		\brief Displays the container of city objects
		Iterate through the container and display the contents.
		*/
		static void display();
	};
}
#endif