#include <iostream>

int main()
{
	// Establishes variables for all parameters
	double empty_weight; // pounds
	double empty_weight_moment; // pounds-inches
	int front_occupants; // number
	double weight_front_occupants; //pounds
	double front_seat_moment_arm; // inches
	int rear_occupants; // number
	double weight_rear_occupants; // pounds
	double rear_seat_moment_arm; //inches
	double usable_fuel; // gallons
	double weight_usable_fuel; //pounds
	double fuel_tank_moment_arm; // inches
	double baggage_weight;
	double baggage_moment_arm;

	std::cout << "Enter empty weight (pounds): " << std::endl;
	std::cin >>  empty_weight;
	std::cout << "Enter empty weight moment (pounds-inches): " << std::endl;
	std::cin >> empty_weight_moment;
	std::cout << "Enter number of front seat occupants: " << std::endl;
	std::cin >> front_occupants;
	std::cout << "Enter weight of front seat occupants (pounds): " << std::endl;
	std::cin >> weight_front_occupants;
	std::cout << "Enter front seat moment arm (inches): " << std::endl;
	std::cin >>  front_seat_moment_arm;
	std::cout << "Enter number of rear seat occupants: " << std::endl;
	std::cin >> rear_occupants;
	std::cout << "Enter weight of rear occupants (pounds): " << std::endl;
	std::cin >> weight_rear_occupants;
	std::cout << "Enter rear seat moment arm (inches): " << std::endl;
	std::cin >> rear_seat_moment_arm;
	std::cout << "Enter empty usable fuel (gallons): " << std::endl;
	std::cin >> usable_fuel;
	std::cout << "Enter usable fuel weight (pounds): " << std::endl;
	std::cin >> weight_usable_fuel;
	std::cout << "Enter fuel tank moment arm (inches): " << std::endl;
	std::cin >> fuel_tank_moment_arm;
	std::cout << "Enter baggage weight (pounds): " << std::endl;
	std::cin >> baggage_weight;
	std::cout << "Enter baggage moment arm: " << std::endl;
	std::cin >> baggage_weight;

	return 0;

}