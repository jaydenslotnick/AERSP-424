#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex m1;
std::mutex m2;
std::mutex m3;
std::mutex m4;
std::mutex m5;

void createRobot(int id, int toola, int toolb, int& time)
{
    std::cout << "Robot " << id << " is collecting data." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    time += 1;
    std::cout << "Robot " << id << " acquired tools and starts performing a task." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    time += 5;
    std::cout << "Robot " << id << " finished the task and is returning the tools." << std::endl;




    //if (toola == 1 || toolb == 2)
    //{
    //    m1.lock();
    //    std::cout << id << std::endl;
    //    std::cout << id << std::endl;
    //    m1.unlock();
    //}

    //if (toola == 2 || toolb == 3)
    //{
    //    m2.lock();
    //    std::cout << id << std::endl;
    //    m2.unlock();
    //}

    //if (toola == 3 || toolb == 4)
    //{
    //    m3.lock();
    //    std::cout << id << std::endl;
    //    m3.unlock();
    //}

    //if (toola == 4 || toolb == 5)
    //{
    //    m4.lock();
    //    std::cout << id << std::endl;
    //    m4.unlock();
    //}

    //if (toola == 5 || toolb == 1)
    //{
    //    m5.lock();
    //    std::cout << id << std::endl;
    //    m5.unlock();
    //}


}

int main()
{
    int totalTime = 0;

    int tool1 = 1;
    int tool2 = 2;
    int tool3 = 3;
    int tool4 = 4;
    int tool5 = 5;

    // creates threads for each robot
    std::thread robot0(createRobot, 0, tool1, tool2, std::ref(totalTime));
    std::thread robot1(createRobot, 1, tool2, tool3, std::ref(totalTime));
    std::thread robot2(createRobot, 2, tool3, tool4, std::ref(totalTime));
    std::thread robot3(createRobot, 3, tool4, tool5, std::ref(totalTime));
    std::thread robot4(createRobot, 4, tool5, tool1, std::ref(totalTime));

    // attaches robots to main thread
    robot0.join();
    robot1.join();
    robot2.join();
    robot3.join();
    robot4.join();

    std::cout << "Minimum time taken by all robots: " << totalTime << " seconds" << std::endl;

    return 0;
}
