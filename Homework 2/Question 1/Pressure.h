#ifndef PRESSURE_H
#define PRESSURE_H

#include <iostream>
#include <string>
#include "Sensor.h"



class pressure_sensor : public Sensor
{
private:
	std::string sensorName = "Pressure";
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