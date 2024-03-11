#ifndef PRESSURE_H
#define PRESSURE_H

#include <iostream>
#include <string>
#include "Sensor.h"


// derived class
class pressure_sensor : public Sensor
{
private:
	std::string sensorName = "Pressure";
public:

	// prints gathering data from the pressure sensor
	void gatherData()
	{
		std::cout << "Gathering data from " << sensorName << " Sensor." << std::endl;
	}

	// prints processing data from the pressure sensor
	void processData()
	{
		std::cout << "Processing data from " << sensorName << " Sensor." << std::endl;
	}

};

#endif