#include <iostream>
#include <map>
#include <string>
#include "Plane.h"
#include "Pilot.h"




int main()
{
	Plane Q5("SCE", "PHL");

	Q5.setVel(400); // 400 mph plane speed
	double dt = 15; // timestep of 10 seconds
	dt = dt / 3600; // convertion to hours

	// sets iterations
	int max_iterations;
	max_iterations = 1000; 
	int* null_pointer = nullptr;

	Pilot Alpha("Alpha", &Q5);
	Pilot Bravo("Bravo", nullptr);

	for (int i = 0; i < max_iterations; ++i)
	{
		// calls operate function
		Q5.operate(dt);

		// initally if plane is at State college and prints Alpha is in control of the plane if it is
		if (i == 0)
		{
			std::cout << "Pilot " << Alpha.getName() << " with certificate number " << &Alpha << " is in control of plane " << Alpha.myPlane << std::endl;
			std::cout << "Pilot " << Bravo.getName() << " with certificate number " << &Bravo << " is in control of plane " << Bravo.myPlane << std::endl;
			std::cout << "\n";
		}

		// checks if the plan is at state college and swaps Alpha and Bravo
		if (Q5.getAt_SCE())
		{
			std::cout << "The plane "<< &Q5 << "is at SCE " << std::endl;
			std::swap(Alpha, Bravo); // switches names of pilots
			std::swap(Alpha.myPlane, Bravo.myPlane); // switches memory address
			std::cout << "Pilot " << Alpha.getName() << " with certificate number " << &Alpha << " is in control of plane " << Alpha.myPlane << std::endl;
			std::cout << "Pilot " << Bravo.getName() << " with certificate number " << &Bravo << " is in control of plane " << Bravo.myPlane << std::endl;
			std::cout << "\n";
		}
	}


	return 0;
}