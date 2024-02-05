#include <iostream>
#include <map>
#include <string>


class Plane {
private:

	// initializes private members
	double pos;
	double vel;
	double distance;
	bool at_SCE;
	std::string origin;
	std::string destination;
	std::map<std::string, std::map<std::string, double>> flights;


public:
	// initalizes public members

	// constructor with variables and container
	Plane(const std::string& from, const std::string& to) : pos(0.0), vel(0.0), at_SCE(true), origin(from), destination(to) {

		// container from question 2
		flights["SCE"]["PHL"] = 160; // State college and Philly
		flights["SCE"]["ORD"] = 640; // State college and Chicago
		flights["SCE"]["EWR"] = 220; // State college and Newark

		// distance variable based on inputs from and to
		distance = flights[from][to];

		std::cout << "Plane created, memory address of object: " << this << std::endl;

	}
	~Plane() {
		std::cout << "Plane Destroyed"<< std::endl;

	}

	
	//function named operate that returns nothing, takes dt in and an input
	void operate(double dt)
	{
		if (pos < distance)
		{
			pos += vel * dt;
			at_SCE = false;
		}

		else
		{
			// follows logic of the flowchart in the problem statement in Question 4
			if (destination == "SCE")
			{
				// uses a temp variable to swap the origin and destination
				at_SCE = true;
				std::string temp;
				temp = origin;
				origin = destination;
				destination = temp;
				pos = 0;
			}
			else
			{
				// uses a temp variable to swap the origin and destination
				std::string temp2;
				temp2 = origin;
				origin = destination;
				destination = temp2;
				pos = 0;
			}
			
		}
	}

	// get functions for pos, origin, destination, and at_SCE
	double getPos() {
		return pos;
	}

	std::string getOrigin() {
		return origin;
	}

	std::string getDestination() {
		return destination;
	}
	bool getAt_SCE() {
		return at_SCE;
	}

	// get/set functions for vel
	double getVel() {
		return vel;
	}

	void setVel(double new_vel) {
		vel = new_vel;
	}



};

class Pilot {
private:

	// initializes private members
	std::string name;



public:
	// initalizes public members
	Plane* myPlane; // pointer to an object of the plane class

	// constructor with variables and container
	Pilot(const std::string& pilotName, Plane* plane) : name(pilotName), myPlane(plane) {
		std::cout << "Pilot: " << name << " Memory address: " << this <<  " is at the gate, ready to board the plane" << std::endl;
	}

	~Pilot() {
		std::cout << "Pilot " << name << " out of the plane" << std::endl;
	}



	// get functions for pos, origin, destination, and at_SCE
	std::string getName() {
		return name;
	}


};



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