#include <STSL/RJRobot.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    RJRobot robot(RobotType::REAL);
    const int kBlackThresh = 2000;

    vector<int> line_samples;

    robot.SetDriveMotors(127, 127);

    // find the median element's value (which algorithm can do this efficiently?)

    // back up until you see a value close to the median
}
