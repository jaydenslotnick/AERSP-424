#include <iostream>
#include <map>
#include <string>

int main()
{
	// Creates a map container with the name of the flight as the key
	// and the flight distance as the value

	// The three flights and values were set as new elements
	std::map<std::string, std::map<std::string, double>> flights;
	flights["SCE"]["PHL"] = 160; // State college and Philly
	flights["SCE"]["ORD"] = 640; // State college and Chicago
	flights["SCE"]["EWR"] = 220; // State college and Newark

	return 0;
}