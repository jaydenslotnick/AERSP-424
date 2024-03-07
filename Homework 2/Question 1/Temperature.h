#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iostream>
#include <string>
#include "Sensor.h"



class temperature_sensor : public Sensor
{
private:
	std::string sensorName = "Temperature";
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