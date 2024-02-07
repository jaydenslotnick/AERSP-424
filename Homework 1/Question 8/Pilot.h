#include <iostream>
#include <map>
#include <string>

#ifndef PILOT
#define PILOT

class Pilot {
private:

	// initializes private members
	std::string name;



public:
	// initalizes public members
	std::unique_ptr<Plane> myPlane; // pointer to an object of the plane class

	// constructor with variables and container
	Pilot(const std::string& pilotName, std::unique_ptr<Plane> &plane) : name(pilotName), myPlane(plane.get()) {
		std::cout << "Pilot: " << name << " Memory address: " << this << " is at the gate, ready to board the plane" << std::endl;
	}

	~Pilot() {
		std::cout << "Pilot " << name << " out of the plane" << std::endl;
	}



	// get functions for pos, origin, destination, and at_SCE
	std::string getName() {
		return name;
	}


};

#endif