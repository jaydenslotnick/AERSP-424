#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>


int main()
{

    bool asleep = false;
    bool incomingAircraft = false;
    bool pilotATCCheck = false;
    int numberAircraft = 10;

    if (incomingAircraft == false) 
    {
        asleep = true;
    }
        
    if (incomingAircraft == true)
    {
        std::cout << "Number of aircraft: " << numberAircraft << std::endl;
        std::cout << "ATC is talking to another pilot: " << pilotATCCheck << std::endl;
        if (pilotATCCheck == false)
        {
            asleep = false;
        }
    }



    return 0;
}
