#include <iostream>
#include <map>

int main()
{
	// Creates a map container with the name of the flight as the key
	// and the flight distance as the value

	// The three flights and values were set as new elements
	std::map< std::string, double > flights;
	flights.insert(std::make_pair("SCE_PHL", 160)); // State college and Philly
	flights.insert(std::make_pair("SCE_ORD", 640)); // State college and Chicago
	flights.insert(std::make_pair("SCE_EWR", 220)); // State college and Newark

	return 0;
}