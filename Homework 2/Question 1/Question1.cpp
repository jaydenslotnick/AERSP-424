#include <iostream>
#include "Sensor.h"
#include "Temperature.h"
#include "Pressure.h"
#include "Velocity.h"
#include "SensorFactory.h"
#include "AerospaceControlSystem.h"

int main()
{

	// tests the SensorFactory class with a user input
	std::string sensorTempUser;
	std::string sensorPressUser;
	std::string sensorVelUser;

	// Get sensor type from user input, 3 times for each sensor
	std::cout << "Enter sensor type (Temperature, Pressure, Velocity): ";
	std::cin >> sensorTempUser;

	std::cout << "Enter sensor type (Temperature, Pressure, Velocity): ";
	std::cin >> sensorPressUser;

	std::cout << "Enter sensor type (Temperature, Pressure, Velocity): ";
	std::cin >> sensorVelUser;

	// Create sensor object using SensorFactory
	Sensor* sensorTemp = SensorFactory::createSensor(sensorTempUser);
	Sensor* sensorPress = SensorFactory::createSensor(sensorPressUser);
	Sensor* sensorVel = SensorFactory::createSensor(sensorVelUser);



	// use the control system class to add the sensor, and call the monitor and adjust function
	AerospaceControlSystem ctrlSys; // control system object
	ctrlSys.addSensor(sensorTemp);
	ctrlSys.addSensor(sensorPress);
	ctrlSys.addSensor(sensorVel);

	ctrlSys.monitorAndAdjust();

	// delete pointers
	delete sensorTemp;
	delete sensorPress;
	delete sensorVel;


	return 0;

}