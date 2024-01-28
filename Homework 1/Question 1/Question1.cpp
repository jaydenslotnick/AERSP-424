#include <iostream>

int main()
{
	// Establishes variables for all parameters except number of passenger and passenger weight
	double empty_weight; // pounds
	double empty_weight_moment; // pounds-inches
	double front_seat_moment_arm; // inches
	double rear_seat_moment_arm; //inches
	double usable_fuel; // gallons
	double weight_usable_fuel; //pounds
	double fuel_tank_moment_arm; // inches
	double baggage_weight; // pounds
	double baggage_moment_arm; // inches

	std::cout << "Enter empty weight (pounds): " << std::endl;
	std::cin >>  empty_weight;
	std::cout << "Enter empty weight moment (pounds-inches): " << std::endl;
	std::cin >> empty_weight_moment;
	std::cout << "Enter number of front occupants: ";

	// front passenger dynamic memory allocation
	int front_occupants;
	std::cin >> front_occupants;

	double* weight_front_occupants = new double[front_occupants]; //pounds

	// dynamic memory allocation
	for (int i = 0; i < front_occupants; ++i)
	{
		std::cout << "Enter weight for front occupant " << i << ": ";
		std::cin >> weight_front_occupants[i];
	}

	std::cout << "Enter front seat moment arm (inches): " << std::endl;
	std::cin >>  front_seat_moment_arm;

	// dynamic memory allocation for rear passengers
	std::cout << "Enter number of rear occupants: ";
	int rear_occupants;
	std::cin >> rear_occupants;

	double* weight_rear_occupants = new double[rear_occupants]; //pounds

	// dynamic memory allocation
	for (int i = 0; i < rear_occupants; ++i)
	{
		std::cout << "Enter weight for rear occupant " << i << ": ";
		std::cin >> weight_rear_occupants[i];
	}
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




	
















	delete[] weight_front_occupants;
	delete[] weight_rear_occupants;
	return 0;

}