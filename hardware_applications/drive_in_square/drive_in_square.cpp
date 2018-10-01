#include <STSL/RJRobot.h>

using namespace std;

int main()
{
    RJRobot robot(RobotType::REAL);
    
    robot.SetDriveMotors(127, 127);
    while(true) {
        for (int i = 0; i < 4; i++) {
            robot.SetDriveMotors(255, -255);
            robot.Wait(2000ms);
            robot.SetDriveMotors(127, 127);
            robot.Wait(2000ms);
        }
    }
    // here are some useful functions:
    //robot.SetDriveMotors(127, 127);
    //robot.Wait(1000ms);
    //robot.StopMotors();
}

