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
	std::map< std::string, double > flights;


public:
	// initalizes public members

	// constructor with variables and container
	Plane(const std::string& from, const std::string& to) : pos(0.0), vel(0.0), at_SCE(true), origin(from), destination(to) {

		// container from question 2
		flights.insert(std::make_pair("SCE_PHL", 160)); // State college and Philly
		flights.insert(std::make_pair("SCE_ORD", 640)); // State college and Chicago
		flights.insert(std::make_pair("SCE_EWR", 220)); // State college and Newark

		// distance variable based on inputs from and to
		distance = flights[from] - flights[to];
		if (distance < 0)
			distance = -distance;

		std::cout << "Plane Created" << std::endl;
		std::cout << "Memory address of object: " << this << std::endl;

	}
	~Plane() {
		std::cout << "Plane Destroyed"<< std::endl;

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

	void setVal(double new_vel) {
		vel = new_vel;
	}



};

int operate() {

	


	return 0;
}



int main()
{

	return 0;
}