
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

    auto pm = T_projection_matrix(
        F_vector2_f32{
            0.5_pi,
            1.0f
        },
        1.0f,
        100.0f
    );

    F_matrix3x3 scale = {
        { 1.0f, 0.0f, 0.0f },
        { 0.0f, 2.0f, 0.0f },
        { 0.0f, 0.0f, -3.0f }
    };
    F_matrix3x3 rotation_matrix = T_convert<F_quaternion, F_matrix3x3>(
        T_make_rotation(
            F_vector3 { 5_pi, 0.5_pi, -1_pi }
        )
    );
    F_matrix3x3 transform2 = rotation_matrix * scale;

    auto dt = T_decompose_transform(transform2);

    F_matrix4x4 transform3 = T_make_transform(
        F_vector3 { 1.0f, 2.0f, 3.0f },
        F_vector3 { 0.0f, 0.5_pi, 0.0f },
        F_vector3 { 5.0f, 2.0f, -1.0f }
    );

    F_matrix4x4 transform4 = T_make_transform<E_rotation_axis::X>(
        F_vector3 { 1.0f, 2.0f, 3.0f },
        0.5_pi,
        F_vector3 { 5.0f, 2.0f, -1.0f }
    );

    F_matrix4x4 transform5 = T_make_transform<E_rotation_axis::Y>(
        F_vector3 { 1.0f, 2.0f, 3.0f },
        0.5_pi,
        F_vector3 { 5.0f, 2.0f, -1.0f }
    );

    F_matrix4x4 transform6 = T_make_transform<E_rotation_axis::Z>(
        F_vector3 { 1.0f, 2.0f, 3.0f },
        0.5_pi,
        F_vector3 { 5.0f, 2.0f, -1.0f }
    );

    F_matrix4x4 transform7 = T_make_transform<E_rotation_axis::CUSTOM>(
        F_vector3 { 1.0f, 2.0f, 3.0f },
        F_vector4 {
            F_vector3::up(),
            0.5_pi
        },
        F_vector3 { 5.0f, 2.0f, -1.0f }
    );

	ncpp::pause_console();

	return 0;
}
