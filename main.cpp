/*!
Name : Alphonsa George
Assignment  PROG 1203-HW5 Cities
*/

#include<iostream>
#include<map>
#include<vector>
#include"city.h"
#include"city_io.h"


int main()
{
	nwacc::city our_city("calcutta", 22.56666667, 88.4);
	nwacc::city city_one("Budapest", 47.5, 19.08333333);
	nwacc::city city_two("Cairo", 30.03333333, 31.35);
	nwacc::city city_three("Cape Town", -33.91666667, 18.36666667);
	nwacc::city city_four("Kuala Lumpur", 3.133333333, 101.7);
	nwacc::city city_five("Lima", -12, -77.03333333);
	nwacc::city city_six("Panama City", 8.966666667, -79.53333333);
	nwacc::city city_seven("Santiago", -33.46666667, -70.75);
	nwacc::city city_eight("Singapore", 1.233333333, 103.9166667);
	nwacc::city city_nine("Venice", 45.43333333, 12.33333333);
	nwacc::city city_ten("Zurich", 47.35, 8.516666667);
	
	
	auto distance_one = our_city.harversine_distance(city_one);
	auto distance_two = our_city.harversine_distance(city_two);
	auto distance_three = our_city.harversine_distance(city_three);
	auto distance_four= our_city.harversine_distance(city_four);
	auto distance_five = our_city.harversine_distance(city_five);
	auto distance_six = our_city.harversine_distance(city_six);
	auto distance_seven = our_city.harversine_distance(city_seven);
	auto distance_eight = our_city.harversine_distance(city_eight);
	auto distance_nine= our_city.harversine_distance(city_nine);
	auto distance_ten = our_city.harversine_distance(city_ten);
	
	std::map<double, std::string>distances;
	distances.emplace(distance_one, "Budapest");
	distances.emplace(distance_two, "Cairo");
	distances.emplace(distance_three, "Cape Town");
	distances.emplace(distance_four, "Kuala Lumpur");
	distances.emplace(distance_five, "Lima");
	distances.emplace(distance_six, "Panama City");
	distances.emplace(distance_seven, "Santiago");
	distances.emplace(distance_eight, "Singapore");
	distances.emplace(distance_nine, "Venice");
	distances.emplace(distance_ten, "Zurich");

	std::cout << "Distances to other cities from Calcutta in ascending order" << std::endl;

	for (const auto& a_distance : distances)
	{
		std::cout << a_distance.first << "-" << a_distance.second << std::endl;
	}

	return 0;

}