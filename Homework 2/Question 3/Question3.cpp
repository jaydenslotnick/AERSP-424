#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

int maxAircraft = 3;
int numAircraft = 0;
std::mutex m1; 
std::mutex m2;
std::mutex m3;
bool atcTalking = false; // atc is not talking




void plane(int planeid)
{

    // incoming aircraft, pilot checks if aircraft control are talking to another pilot and the number of aircraft

        {
        std::unique_lock<std::mutex> lock(m1);
        m1.unlock();


        if (numAircraft == 0)
        {
           // std::cout << "ATC is asleep" << std::endl;
        }

        if (atcTalking == false) 
        {
            atcTalking = true; // Set to true because atc is now talking to someone

            // establishes a connection
            std::cout << "Aircraft " << planeid << " is requesting landing clearance." << std::endl;
            

            if (numAircraft >= maxAircraft) 
            {
                std::cout << "Approach pattern full. Aircraft " << planeid << " redirected to another airport" << std::endl;
                std::cout << "Aircraft " << planeid << " flying to another airport" << std::endl;

            }
            else 
            {
                std::cout << "Aircraft " << planeid << " is entering the traffic pattern." << std::endl;
                ++numAircraft; // Adds aircraft to the traffic pattern
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "Aircraft " << planeid << " has landed and exited the traffic pattern." << std::endl;
                --numAircraft;

            }

            atcTalking = false; // Set to false after handling the request

        }

        else // if air traffic control is talking to another pilot
        {
           // std::unique_lock<std::mutex> lock(m1);
            if (numAircraft < maxAircraft) 
            {
                std::cout << "Aircraft " << planeid << " is requesting landing clearance." << std::endl;
                std::cout << "Aircraft " << planeid << " is entering the traffic pattern." << std::endl;
                ++numAircraft; // adds aircraft to the traffic pattern
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "Aircraft " << planeid << " has landed and exited the traffic pattern." << std::endl;
                --numAircraft;

            }

            else
            {
                std::cout << "Approach pattern full. Aircraft " << planeid << " redirected to another airport" << std::endl;
                std::cout << "Aircraft " << planeid << " flying to another airport" << std::endl;

            }
            //lock.unlock();
        }


    }

}

int main()
{


    // vector of threads from the planes
    std::vector<std::thread> planeThreads;
    const int numberPlanes = 10;

    for (int i = 0; i < numberPlanes; ++i) 
    {
        planeThreads.push_back(std::thread(plane, i));
    }

    for (auto& thread : planeThreads)
    {
        thread.join();
    }

    return 0;
}
