
#include <nmath/.hpp>

using namespace nmath;



int main() {

    F_vector3 right = { 1, 0, 0 };
    F_vector3 up = { 0, 2, 0 };
    F_vector3 forward = { 0, 0, 4 };
    F_vector3 translation = { 1, 5, 0 };

    F_matrix4x4 transform;
    transform.right = { right, 0 };
    transform.up = { up, 0 };
    transform.forward = { forward, 0 };
    transform.translation = { translation, 1 };

    F_matrix2x2 identity_transform2x2 = T_identity<F_matrix2x2>();
    F_matrix3x3 identity_transform3x3 = T_identity<F_matrix3x3>();
    F_matrix4x4 identity_transform4x4 = T_identity<F_matrix4x4>();

    auto pm = perspective_projection_matrix(
        0.5_pi,
        1.0f,
        1.0f,
        100.0f
    );

    F_matrix3x3 scale = {
        { 1.0f, 0.0f, 0.0f },
        { 0.0f, 2.0f, 0.0f },
        { 0.0f, 0.0f, -3.0f }
    };
    F_matrix3x3 rotation_matrix = T_convert<F_matrix3x3>(
        quaternion_from_euler_angles(
            F_vector3 { 5_pi, 0.5_pi, -1_pi }
        )
    );
    F_matrix3x3 transform2 = rotation_matrix * scale;

    auto dt = T_decompose_transform(transform2);

	ncpp::pause_console();

	return 0;
}
