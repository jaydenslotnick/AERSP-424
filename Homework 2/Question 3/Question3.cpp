#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>


int maxAircraft = 3;
int numAircraft = 0;
std::mutex m1; 
std::mutex m2;
std::mutex m3;
bool atcTalking = false; // atc is not talking
bool land = false;



void plane(int planeid)
{

    // Check if the traffic pattern is full
    {
        if (!atcTalking) 
        {
            std::lock_guard<std::mutex> lock(m1);
            // establishes a connection
            std::cout << "Aircraft " << planeid << " is requesting landing clearance." << std::endl;
            atcTalking = true; // Set to true because atc is now talking to someone

            if (numAircraft >= maxAircraft) 
            {
                std::cout << "Approach pattern full. Aircraft " << planeid << " redirected to another airport" << std::endl;
                std::cout << "Aircraft " << planeid << " flying to another airport" << std::endl;
                --numAircraft; // Subtract a plane since it is going to another airport
            }
            else 
            {
                std::cout << "Aircraft " << planeid << " is entering the traffic pattern." << std::endl;
                ++numAircraft; // Adds aircraft to the traffic pattern
                land = true;
            }

            atcTalking = false; // Set to false after handling the request
        }

        else if(numAircraft < maxAircraft && atcTalking == true)
        {
            std::cout << "Aircraft " << planeid << " is requesting landing clearance." << std::endl;
            std::cout << "Aircraft " << planeid << " is entering the traffic pattern." << std::endl;
            ++numAircraft; // adds aircraft to the traffic pattern
            land = true;
        }

        // Land and exit the traffic pattern after landing
        if (land == true)
        {
            //std::lock_guard<std::mutex> lock(m1);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Aircraft " << planeid << " has landed and exited the traffic pattern." << std::endl;
            --numAircraft;
        }

    }

}

int main()
{


    // vector of threads from the planes
    std::vector<std::thread> planeThreads;

    for (int i = 0; i < 10; ++i) 
    {
        planeThreads.push_back(std::thread(plane, i));
    }

    for (auto& thread : planeThreads)
    {
        thread.join();
    }

    return 0;
}
