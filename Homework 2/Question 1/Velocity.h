#ifndef VELOCITY_H
#define VELOCITY_H

#include <iostream>
#include <string>
#include "Sensor.h"



class velocity_sensor : public Sensor
{
private:
	std::string sensorName = "Velocity";
public:
	void gatherData()
	{
		std::cout << "Gathering data from " << sensorName << " Sensor." << std::endl;
	}

	void processData()
	{
		std::cout << "Processing data from " << sensorName << " Sensor." << std::endl;
	}

};
#endif