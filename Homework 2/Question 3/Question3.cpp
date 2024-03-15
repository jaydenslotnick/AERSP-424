#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int maxAircraft = 3;
int numAircraft = 0;
std::mutex m1;

// ATC is asleep while no planes are incoming
void atcFunc()
{
    std::cout << "ATC is asleep" << std::endl;
}


void plane(int planeid)
{
    while (true)
    {
   
        

        // Aircraft initiates communication with ATC
        {
            m1.lock();
            std::cout << "Aircraft " << planeid << " is requesting landing clearance." << std::endl;
            m1.unlock();
        }

        // Check if the traffic pattern is full
        {
            m1.lock();
            if (numAircraft >= maxAircraft) 
            {
                std::cout << "Aircraft " << planeid << " cannot land. Traffic pattern is full." << std::endl;
            }

            else 
            {
                std::cout << "Aircraft " << planeid << " is entering the traffic pattern." << std::endl;
                ++numAircraft;
            }
            m1.unlock();
        }


        // Exit the traffic pattern after landing
        {
            m1.lock();
            std::cout << "Aircraft " << planeid << " has landed and exited the traffic pattern." << std::endl;
            --numAircraft;
            m1.unlock();
        }

    }

}

int main()
{


    // thread for atc
    std::thread atc_thread(atcFunc);
    atc_thread.join();


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
