#ifndef SENSORFACTORY_H
#define SENSORFACTORY_H

#include <iostream>
#include <string>
#include "Sensor.h"
#include "Temperature.h"
#include "Pressure.h"
#include "Velocity.h"



class SensorFactory {
public:
    // creatSensor function, takes string as an input, checks the sensor type and returns appropriate information
	static Sensor* createSensor(const std::string& sensorType) {

        // checks the Temperature, Pressure, and Velocity
        if (sensorType == "Temperature") {
            return new temperature_sensor(); // new keyword allocates the heap memory and returns the pointer
        }
        else if (sensorType == "Pressure") {
            return new pressure_sensor();
        }
        else if (sensorType == "Velocity") {
            return new velocity_sensor();
        }
        else {
            std::cout << "Unknown sensor type: " << sensorType << std::endl;
            return nullptr; // returns null pointer if the senor type does not match
        }
	}


};



#endif