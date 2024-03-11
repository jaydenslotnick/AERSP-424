#ifndef VELOCITY_H
#define VELOCITY_H

#include <iostream>
#include <string>
#include "Sensor.h"


// derived class
class velocity_sensor : public Sensor
{
private:
	std::string sensorName = "Velocity";
public:

	// prints gathering data from the velocity sensor
	void gatherData()
	{
		std::cout << "Gathering data from " << sensorName << " Sensor." << std::endl;
	}


	// prints processing data from the velocity sensor
	void processData()
	{
		std::cout << "Processing data from " << sensorName << " Sensor." << std::endl;
	}

};
#endif