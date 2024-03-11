#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>




// base class sensor
class Sensor {

public:
	// virtual function gatherData()
	virtual void gatherData() = 0;

	// virtual function processData()
	virtual void processData() = 0;


};

#endif