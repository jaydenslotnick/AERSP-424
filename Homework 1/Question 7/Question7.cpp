#include <iostream>
#include <map>
#include <string>
#include "Plane.h"
#include "Pilot.h"




int main()
{
	Plane Q5("SCE", "PHL"); // set locations

	Q5.setVel(450); // set velocity
	double dt = 15; // set timestep
	dt = dt / 3600; // convertion to hours

	// sets iterations
	int max_iterations;
	max_iterations = 1500; // set iterations
	int* null_pointer = nullptr; // null pointer for a memory address of 0x00000000, old style pointer

	Pilot Alpha("Alpha", &Q5);
	Pilot Bravo("Bravo", nullptr); // null pointer for a memory address of 0x00000000

	for (int i = 0; i < max_iterations; ++i)
	{
		// calls operate function
		if (i == 0) // makes it so that the first timestep is zero seconds
			Q5.operate(dt * 0);
		else
			Q5.operate(dt * 1);

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
			std::swap(Alpha.myPlane, Bravo.myPlane); // switches memory address
			std::cout << "Pilot " << Alpha.getName() << " with certificate number " << &Alpha << " is in control of plane " << Alpha.myPlane << std::endl;
			std::cout << "Pilot " << Bravo.getName() << " with certificate number " << &Bravo << " is in control of plane " << Bravo.myPlane << std::endl;
			std::cout << "\n";
		}
	}


	// deletes old style pointer
	delete(null_pointer);

	return 0;
}