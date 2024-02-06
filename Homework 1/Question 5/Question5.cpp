#include <iostream>
#include <map>
#include <string>
#include "Plane.h"



int main()
{
	Plane Q5("SCE", "PHL");

	Q5.setVel(400); // 400 mph plane speed
	double dt = 15; // timestep of 15 seconds
	dt = dt / 3600; // convertion to hours

	// sets iterations
	int max_iterations;
	max_iterations = 1000; 

	for (int i = 0; i < max_iterations; ++i)
	{
		// calls operate function
		if (i == 0) // makes it so that the first timestep is zero seconds
			Q5.operate(dt*0);
		else
			Q5.operate(dt * 1);
		std::cout << "Time: " << dt *3600* i << " seconds, Position: " << Q5.getPos() << "miles." << std::endl;
	}


	return 0;
}