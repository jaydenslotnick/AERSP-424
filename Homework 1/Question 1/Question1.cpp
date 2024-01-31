#include <iostream>
#include <cmath>

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
		std::cout << "Enter weight for front occupant " << i+1 << ": ";
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
		std::cout << "Enter weight for rear occupant " << i+1 << ": ";
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
	std::cin >> baggage_moment_arm;


	// Allocates variables for the gross weight and cg location
	double gross_weight = empty_weight;
	double total_moment = empty_weight_moment;

	// Sets limits for gross weight and cg location
	double max_gross_weight = 2950; // pounds
	double forward_cg_limit = 82.1; // inches
	double aft_cg_limit = 84.7; // inches

	for (int i = 0; i < front_occupants; ++i)
	{
		gross_weight += weight_front_occupants[i];
		total_moment += weight_front_occupants[i] * front_seat_moment_arm;
	}


	for (int i = 0; i < rear_occupants; ++i)
	{
		gross_weight += weight_rear_occupants[i];
		total_moment += weight_rear_occupants[i] * rear_seat_moment_arm;
	}

	double total_fuel_weight = usable_fuel * weight_usable_fuel;
	gross_weight += usable_fuel * weight_usable_fuel + baggage_weight;
	total_moment += total_fuel_weight * fuel_tank_moment_arm + baggage_weight * baggage_moment_arm;

	double cg_location;
	cg_location = total_moment / gross_weight;
	std::cout << "Inital gross weight (pounds): " << gross_weight << std::endl;
	std::cout << "Initial CG location: " << cg_location << std::endl;

	if (gross_weight < max_gross_weight && cg_location >= forward_cg_limit && cg_location <= aft_cg_limit)
	{
		std::cout << "The plane is within the given design limits" << std::endl;

	}
	else 
	{
		std::cout << "The plane is not within the given design limits" << std::endl;
	}


	double fuel_change = 0; // intermediate fuel change variable
	double initial_fuel_change;  // used if the weight is greater than the max weight
	double fuel_track; // keeps track of all fuel changes

	// Checks if gross weight is larger than max and subtracts it to the max if it is
	if (gross_weight > max_gross_weight)
	{
		initial_fuel_change = gross_weight - max_gross_weight;
		gross_weight = max_gross_weight;
		fuel_track = -initial_fuel_change;

		total_moment -= initial_fuel_change * fuel_tank_moment_arm;
		cg_location = total_moment / gross_weight;
	}

	// Runs while the cg location is not within limits
	while (cg_location < forward_cg_limit || cg_location > aft_cg_limit)
	{
		// If the cg location is less than the forward limit, it will add or substract fuel based on where the fuel moment arm is
		// If the fuel moment arm is less than the forward limit, fuel will need to be subtracted to shift the cg location backwards
		// If the fuel moment arm is greater than the forward limit, fuel will need to be added to shift the cg location backwards
		if (cg_location < forward_cg_limit)
		{
			if (fuel_tank_moment_arm < forward_cg_limit)
			{
				fuel_change -= 0.01;
			}
			else
			{
				fuel_change += 0.01;
			}
			
		}

		// If the cg location is greater than the aft limit, it will add or substract fuel based on where the fuel moment arm is
		// If the fuel moment arm is greater than the aft limit, fuel will need to be subtracted to shift the cg location forwards
		// If the fuel moment arm is less than the aft limit, fuel will need to be added to shift the cg location forwards
		else if (cg_location > aft_cg_limit)
		{
			if (fuel_tank_moment_arm > aft_cg_limit)
			{
				fuel_change -= 0.01;
			}
			else
			{
				fuel_change += 0.01;
			}
		}

		total_fuel_weight += fuel_change;
		fuel_track += fuel_change; // tracks total fuel change

		// modifies gross weight and total moment and cg location
		gross_weight = gross_weight + fuel_change; 
		total_moment += fuel_change*fuel_tank_moment_arm;
		cg_location = total_moment / gross_weight;
		fuel_change = 0; // resets fuel change for the next loop


	} 
	std::cout << " " << std::endl;
	std::cout << "The amount of fuel that needs to be added/drained is (pounds): " << fuel_track << std::endl;
	std::cout << "New gross weight (pounds): " << gross_weight << std::endl;
	std::cout << "New center of gravity location (inches): " << cg_location << std::endl;



	delete[] weight_front_occupants;
	delete[] weight_rear_occupants;
	return 0;

}