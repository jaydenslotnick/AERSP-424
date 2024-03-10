#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1;
std::mutex m2;
std::mutex m3;
std::mutex m4;
std::mutex m5;

void createRobot(int id, int toola, int toolb)
{


    if (toola == 1 || toolb == 2)
    {
        m1.lock();
        std::cout << id << std::endl;
        m1.unlock();
    }

    if (toola == 2 || toolb == 3)
    {
        m2.lock();
        std::cout << id << std::endl;
        m2.unlock();
    }

    if (toola == 3 || toolb == 4)
    {
        m3.lock();
        std::cout << id << std::endl;
        m3.unlock();
    }

    if (toola == 4 || toolb == 5)
    {
        m4.lock();
        std::cout << id << std::endl;
        m4.unlock();
    }

    if (toola == 5 || toolb == 1)
    {
        m5.lock();
        std::cout << id << std::endl;
        m5.unlock();
    }


}

int main()
{

    int tool1 = 1;
    int tool2 = 2;
    int tool3 = 3;
    int tool4 = 4;
    int tool5 = 5;

    // creates threads for each robot
    std::thread robot0(createRobot, 0, tool1, tool2);
    std::thread robot1(createRobot, 1, tool2, tool3);
    std::thread robot2(createRobot, 2, tool3, tool4);
    std::thread robot3(createRobot, 3, tool4, tool5);
    std::thread robot4(createRobot, 4, tool5, tool1);

    // attaches robots to main thread
    robot0.join();
    robot1.join();
    robot2.join();
    robot3.join();
    robot4.join();

    return 0;
}
