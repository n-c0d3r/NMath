
#include <nmath/.hpp>

using namespace nmath;



int main() {
    
	F_quaternion q1 = F_quaternion{ 1.0f, 2.0f, 3.0f, 4.0f};
	F_quaternion q2 = F_quaternion{ -1.0f, 6.0f, 0.0f, -2.0f};

	F_quaternion q3 = q1 * q2;
    
	ncpp::pause_console();

	return 0;
}
