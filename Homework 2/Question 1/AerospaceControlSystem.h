#ifndef AEROSPACECONTROLSYSTEM_H
#define AEROSPACECONTROLSYSTEM_H

#include <iostream>
#include <string>
#include <vector>
#include "Sensor.h"
#include "Temperature.h"
#include "Pressure.h"
#include "Velocity.h"


class AerospaceControlSystem {
private:
	std::vector<Sensor*> sensors;

public:

	// adds each desired sensor
	void addSensor(Sensor* sensor)
	{
		sensors.push_back(sensor);
	}

	// this function calls the gather and process data functions for each sensor
	void monitorAndAdjust() {
		std::cout << "" << std::endl;
		for (Sensor* sensor : sensors)
		{
			sensor->gatherData();
			sensor->processData();
			std::cout << "Adjusting controls based on sensor data" << std::endl;
			std::cout << "" << std::endl;
		}

	}
		// Destructor to release memory allocated for sensors
		~AerospaceControlSystem() {
			for (Sensor* sensor : sensors) {
				delete sensor;
			}
		}


};



#endif