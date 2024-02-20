#include <iostream>
#include <map>
#include <string>

#ifndef PLANE
#define PLANE
class Plane {
private:

	// initializes private members
	double pos;
	double vel;
	double distance;
	bool at_SCE;
	std::string origin;
	std::string destination;
	std::map<std::string, std::map<std::string, double>> flights; // container from question 2


public:
	// initalizes public members

	// constructor with variables and container
	Plane(const std::string& from, const std::string& to) :origin(from), destination(to) {

		// sets values of container
		flights["SCE"]["PHL"] = 160; // State college and Philly
		flights["SCE"]["ORD"] = 640; // State college and Chicago
		flights["SCE"]["EWR"] = 220; // State college and Newark
	}
	~Plane() {

	}


	//function named operate that returns nothing, takes dt in and an input
	void operate(double dt)
	{

	}

	// get functions for pos, origin, destination, and at_SCE
	double getPos() {
		return pos;
	}

	double getOrigin() {
		return pos;
	}

	double getDestination() {
		return pos;
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
#endif