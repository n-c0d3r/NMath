
#include <nmath/.hpp>

using namespace nmath;



int main() {
    
	F_quaternion q1 = F_quaternion{ 1.0f, 2.0f, 3.0f, 4.0f};
	F_quaternion q2 = F_quaternion{ -1.0f, 6.0f, 0.0f, -2.0f};

	F_quaternion q3 = q1 * q2;

    F_quaternion q4 = quaternion_rotation_roll_pitch_yaw(F_vector3{0, 0.5_pi, 0});
    F_quaternion q5 = quaternion_rotation_roll_pitch_yaw(F_vector3{0, 0, 0.5_pi});

    F_vector3 v1 = q5 * q4 * F_vector3{0, 0, 1};
    F_vector3 v2 = (q5 * q4) * F_vector3{0, 0, 1};

	ncpp::pause_console();

	return 0;
}
