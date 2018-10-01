#include <STSL/RJRobot.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    RJRobot robot(RobotType::REAL);
    const int kBlackThresh = 2000;
    const auto kSamplePeriod = 50ms;

    vector<int> line_samples;

    robot.SetDriveMotors(127, 127);

    while(true) {
        robot.Wait(kSamplePeriod);
        int val = robot.GetLineValue(LineSensor::CENTER);
        line_samples.push_back(val);
        if(val >= 2000)
            break;
    }

    Vector<int> copy(line_samples);
    copy.sort();
    int center = (int)line_samples.size() / 2;
    int inx = line_samples.find(copy[center]);

    robot.SetDriveMotors(-127, -127);
    wait((line_samples.size() - inx) * kSamplePeriod);
    robot.StopMotors();
}
