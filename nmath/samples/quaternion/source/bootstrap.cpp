
#include <nmath/.hpp>

using namespace nmath;



int main() {
    
	F_quaternion q1 = F_quaternion{ 1.0f, 2.0f, 3.0f, 4.0f};
	F_quaternion q2 = F_quaternion{ -1.0f, 6.0f, 0.0f, -2.0f};

	F_quaternion q3 = q1 * q2;

    F_quaternion q4 = T_make_rotation(F_vector3{0, 0.5_pi, 0});
    F_quaternion q5 = T_make_rotation(F_vector3{0, 0, 0.5_pi});

    F_vector3 v1 = q5 * q4 * F_vector3{0, 0, 1};
    F_vector3 v2 = (q5 * q4) * F_vector3{0, 0, 1};

    F_quaternion q6 = T_make_rotation(F_vector3{-0.2_pi, 0.5_pi, 1.0_pi});

    F_matrix3x3 m4 = T_convert<F_quaternion, F_matrix3x3>(q6);
    F_quaternion q7 = T_convert<F_matrix3x3, F_quaternion>(m4);

    F_matrix4x4 m1 = T_identity<F_matrix4x4>();
    m1.translation = F_vector4{1,0,0,1};
    F_matrix4x4 m2 = m1 * q4;
    F_matrix4x4 m3 = q4 * m1;

    F_quaternion q8 = T_rotation_look_at(
        F_vector3::up(),
        F_vector3::right()
    );
    F_vector3 q8_test = q8 * F_vector3::up();

    F_vector3 q8_euler_angles = euler_angles(q8);
    F_vector4 q8_axis_and_angle = axis_and_angle(q8);

	ncpp::pause_console();

	return 0;
}
