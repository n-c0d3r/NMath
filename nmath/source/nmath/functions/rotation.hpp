#pragma once

/** @file nmath/functions/rotation.hpp
*
*   Implement T_make_rotation.
*/



 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#pragma region Includes

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#include <nmath/prerequisites.hpp>

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#include <nmath/types/data_helper.hpp>
#include <nmath/types/vector.hpp>
#include <nmath/types/quaternion.hpp>
#include <nmath/types/matrix.hpp>
#include <nmath/operators/vector_scalar.hpp>

#pragma endregion



namespace nmath {

    enum class E_rotation_axis {

        ALL,
        X,
        Y,
        Z,
        CUSTOM

    };



    template<E_rotation_axis rotate_axis__ = E_rotation_axis::ALL, typename F__ = F_quaternion_f32>
    F__ NMATH_CALL_CNV T_make_rotation(auto) noexcept;

    template<>
    inline F_quaternion_f32 NMATH_CALL_CNV T_make_rotation<E_rotation_axis::ALL, F_quaternion_f32>(PA_vector3_f32 euler_angles) noexcept {

#ifdef NCPP_ENABLE_SSE
        static const F_data4_f32 sign = F_data4_f32{ 1.0f, -1.0f, -1.0f, 1.0f };
        static const F_data4_f32 one_half = F_data4_f32{ 0.5f, 0.5f, 0.5f, 0.5f };

        F_data4_f32 HalfAngles = data4_multiply(
            data_forward(
                T_convert<F_vector3_f32, F_vector4_f32>(euler_angles)
            ),
            one_half
        );

        F_data4_f32 SinAngles, CosAngles;
        data4_sin_cos(HalfAngles, SinAngles, CosAngles);

        F_data4_f32 P0 = T_data4_static_permute<D4_SELECT_X0, D4_SELECT_X1, D4_SELECT_X1, D4_SELECT_X1>(SinAngles, CosAngles);
        F_data4_f32 Y0 = T_data4_static_permute<D4_SELECT_Y1, D4_SELECT_Y0, D4_SELECT_Y1, D4_SELECT_Y1>(SinAngles, CosAngles);
        F_data4_f32 R0 = T_data4_static_permute<D4_SELECT_Z1, D4_SELECT_Z1, D4_SELECT_Z0, D4_SELECT_Z1>(SinAngles, CosAngles);
        F_data4_f32 P1 = T_data4_static_permute<D4_SELECT_X0, D4_SELECT_X1, D4_SELECT_X1, D4_SELECT_X1>(CosAngles, SinAngles);
        F_data4_f32 Y1 = T_data4_static_permute<D4_SELECT_Y1, D4_SELECT_Y0, D4_SELECT_Y1, D4_SELECT_Y1>(CosAngles, SinAngles);
        F_data4_f32 R1 = T_data4_static_permute<D4_SELECT_Z1, D4_SELECT_Z1, D4_SELECT_Z0, D4_SELECT_Z1>(CosAngles, SinAngles);

        F_data4_f32 Q1 = data4_multiply(P1, sign);
        F_data4_f32 Q0 = data4_multiply(P0, Y0);
        Q1 = data4_multiply(Q1, Y1);
        Q0 = data4_multiply(Q0, R0);
        F_data4_f32 Q = data4_multiply_add(Q1, R1, Q0);

        return quaternion_forward(Q);
#else
        const float halfpitch = euler_angles.x * 0.5f;
        float cp = cosf(halfpitch);
        float sp = sinf(halfpitch);

        const float halfyaw = euler_angles.y * 0.5f;
        float cy = cosf(halfyaw);
        float sy = sinf(halfyaw);

        const float halfroll = euler_angles.z * 0.5f;
        float cr = cosf(halfroll);
        float sr = sinf(halfroll);

        return {

            cr * sp * cy + sr * cp * sy,
            cr * cp * sy - sr * sp * cy,
            sr * cp * cy - cr * sp * sy,
            cr * cp * cy + sr * sp * sy

        };
#endif
    }
    template<>
    NCPP_FORCE_INLINE F_quaternion_f32 NMATH_CALL_CNV T_make_rotation<E_rotation_axis::X, F_quaternion_f32>(f32 single_euler_angle) noexcept {

        return T_make_rotation<E_rotation_axis::ALL, F_quaternion_f32>(
            F_vector3_f32 {
                single_euler_angle,
                0.0f,
                0.0f
            }
        );
    }
    template<>
    NCPP_FORCE_INLINE F_quaternion_f32 NMATH_CALL_CNV T_make_rotation<E_rotation_axis::Y, F_quaternion_f32>(f32 single_euler_angle) noexcept {

        return T_make_rotation<E_rotation_axis::ALL, F_quaternion_f32>(
            F_vector3_f32 {
                0.0f,
                single_euler_angle,
                0.0f
            }
        );
    }
    template<>
    NCPP_FORCE_INLINE F_quaternion_f32 NMATH_CALL_CNV T_make_rotation<E_rotation_axis::Z, F_quaternion_f32>(f32 single_euler_angle) noexcept {

        return T_make_rotation<E_rotation_axis::ALL, F_quaternion_f32>(
            F_vector3_f32 {
                0.0f,
                0.0f,
                single_euler_angle
            }
        );
    }
    template<>
    NCPP_FORCE_INLINE F_quaternion_f32 NMATH_CALL_CNV T_make_rotation<E_rotation_axis::CUSTOM, F_quaternion_f32>(PA_vector4_f32 axis_and_angle) noexcept {

        return quaternion_forward(
            F_data4_f32 {
                data_forward(
                    axis_and_angle.xyz()
                    * sinf(axis_and_angle.w * 0.5f)
                ),
                cosf(axis_and_angle.w * 0.5f)
            }
        );
    }

    template<>
    inline F_matrix3x3_f32 NMATH_CALL_CNV T_make_rotation<E_rotation_axis::ALL, F_matrix3x3_f32>(PA_vector3_f32 euler_angles) noexcept {

        f32 sx = sinf(euler_angles.x);
        f32 cx = cosf(euler_angles.x);
        f32 sy = sinf(euler_angles.y);
        f32 cy = cosf(euler_angles.y);
        f32 sz = sinf(euler_angles.z);
        f32 cz = cosf(euler_angles.z);

        return {
            {
                cy * cz,
                cy * sz,
                -sy
            },
            {
                sx * sy * cz - cx * sz,
                sx * sy * sz + cx * cz,
                sx * cy
            },
            {
                cx * sy * cz + sx * sz,
                cx * sy * sz - sx * cz,
                cx * cy
            },
        };
    }
    template<>
    inline F_matrix3x3_f32 NMATH_CALL_CNV T_make_rotation<E_rotation_axis::X, F_matrix3x3_f32>(f32 single_euler_angle) noexcept {

        f32 s = sinf(single_euler_angle);
        f32 c = cosf(single_euler_angle);

        return {
            { 1.0f, 0.0f, 0.0f },
            { 0.0f, c, s },
            { 0.0f, -s, c }
        };
    }
    template<>
    inline F_matrix3x3_f32 NMATH_CALL_CNV T_make_rotation<E_rotation_axis::Y, F_matrix3x3_f32>(f32 single_euler_angle) noexcept {

        f32 s = sinf(single_euler_angle);
        f32 c = cosf(single_euler_angle);

        return {
            { c, 0.0f, -s },
            { 0.0f, 1.0f, 0.0f },
            { s, 0.0f, c }
        };
    }
    template<>
    inline F_matrix3x3_f32 NMATH_CALL_CNV T_make_rotation<E_rotation_axis::Z, F_matrix3x3_f32>(f32 single_euler_angle) noexcept {

        f32 s = sinf(single_euler_angle);
        f32 c = cosf(single_euler_angle);

        return {
            { c, s, 0.0f },
            { -s, c, 0.0f },
            { 0.0f, 0.0f, 1.0f }
        };
    }

}
