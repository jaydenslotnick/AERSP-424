#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include "time.h"

int maxAircraft = 3; // max aircraft in a pattern
int numAircraft = 0; // current number of aircraft in a pattern
std::mutex m1; // lock
bool atcTalking = false; // atc is not talking inititally

void plane(int planeid)
{
    // if there are no other incoming aircraft, ATC falls asleep, commented out to make the output cleaner
    if (numAircraft == 0)
    {
        // std::cout << "ATC is asleep" << std::endl;
    }


    // if ATC is not talking to another pilot, a thread will enter this code block
    if (atcTalking == false) 
    {
        // initializes a connection and sets atcTalking to be true
        {
            std::unique_lock<std::mutex> lock(m1); // locks ATC
            atcTalking = true; // Set to true because atc is now talking to someone
        }

        printf("Aircraft %i is requesting landing clearance. \n", planeid);
            
        // if there are too many aircraft in the traffic pattern, this aircraft is directed to another airport
        if (numAircraft >= maxAircraft) 
        {
            printf("Approach pattern full. Aircraft %i redirected to another airport. \n", planeid);
            printf("Aircraft %i flying to another airport. \n", planeid);
        }

        // if there are not too many aircraft, adds to the pattern, lands, and subtracts from the pattern
        else 
        {
            ++numAircraft; // Adds aircraft to the traffic pattern
            std::unique_lock<std::mutex> lock(m1); // locks runway while plane lands
            printf("Aircraft %i is cleared to land and entering the traffic pattern. \n", planeid);
            std::this_thread::sleep_for(std::chrono::seconds(1)); // simulates landing
            printf("Aircraft %i has landed. \n", planeid);
            printf("Runway is free. \n");
            --numAircraft; // subtracts from pattern
        }

        atcTalking = false; // Set to false after handling the request
    }

    // if air traffic control is talking to another pilot, a thread enters this code block
    else 
    {
        printf("Aircraft %i is requesting landing clearance. \n", planeid);

        // if there are not too many aircraft, adds to the pattern, lands, and subtracts from the pattern
        if (numAircraft < maxAircraft) 
        {
            ++numAircraft; // adds aircraft to the traffic pattern
            std::unique_lock<std::mutex> lock(m1); // locks runway while plane lands
            printf("Aircraft %i is cleared to land and entering the traffic pattern. \n", planeid);
            std::this_thread::sleep_for(std::chrono::seconds(1)); // simulates landing
            printf("Aircraft %i has landed. \n", planeid);
            printf("Runway is free. \n");
            --numAircraft; // subtracts from pattern
        }

        // if there are too many aircraft in the traffic pattern, this aircraft is directed to another airport
        else
        {
            printf("Approach pattern full. Aircraft %i redirected to another airport. \n", planeid);
            printf("Aircraft %i flying to another airport. \n", planeid);
        }
    }
}

int main()
{
    clock_t totalTime = clock(); // keeps track of total time
    // vector of threads from the planes
    std::vector<std::thread> planeThreads;
    const int numberPlanes = 10;

    // creates threads for 10 planes and calls the plane function
    for (int i = 0; i < numberPlanes; ++i) 
    {
        planeThreads.push_back(std::thread(plane, i));
    }

    // joins threads back together
    for (auto& thread : planeThreads)
    {
        thread.join();
    }
    std::cout << "Duration: " << (double)(clock() - totalTime) / 1000 << " seconds" << std::endl; // prints out time

    return 0;
}
