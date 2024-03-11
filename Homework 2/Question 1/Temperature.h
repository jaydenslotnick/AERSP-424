#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iostream>
#include <string>
#include "Sensor.h"


// derived class
class temperature_sensor : public Sensor
{
private:
	std::string sensorName = "Temperature";
public:

	// prints gathering data from the temperature sensor
	void gatherData() 
	{
		std::cout << "Gathering data from " << sensorName << " Sensor." << std::endl;
	}

	// prints processing data from the temperature sensor
	void processData()
	{
		std::cout << "Processing data from " << sensorName << " Sensor." << std::endl;
	}

};
#endif