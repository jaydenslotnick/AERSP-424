#include <iostream>
#include <thread>

void createRobot(int id)
{

}

int main()
{

    // creates threads for each robot
    std::thread robot1(createRobot, 1);
    std::thread robot2(createRobot, 2);
    std::thread robot3(createRobot, 3);
    std::thread robot4(createRobot, 4);
    std::thread robot5(createRobot, 5);

    // attaches robots to main thread
    robot1.join();
    robot2.join();
    robot3.join();
    robot4.join();
    robot5.join();

    return 0;
}
