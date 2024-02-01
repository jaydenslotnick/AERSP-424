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
	Plane(const std::string& from, const std::string& to) :origin(from), destination(to) {

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

	void setVal(double new_vel) {
		vel = new_vel;
	}



};



int main()
{
	std::cout << "Test text" << std::endl;




	return 0;
}