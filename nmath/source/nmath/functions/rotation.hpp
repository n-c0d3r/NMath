#pragma once

/** @file nmath/functions/quaternion_creator.hpp
*
*   Implement quaternion creators.
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

#pragma endregion



namespace nmath {

    NCPP_FORCE_INLINE F_quaternion_f32 NMATH_CALL_CNV quaternion_rotation_roll_pitch_yaw(F_vector3_f32 roll_pitch_yaw) noexcept {

#ifdef NCPP_ENABLE_SSE
        static const F_data4_f32 sign = F_data4_f32{ 1.0f, -1.0f, -1.0f, 1.0f };
        static const F_data4_f32 one_half = F_data4_f32{ 0.5f, 0.5f, 0.5f, 0.5f };

        F_data4_f32 HalfAngles = data4_multiply(data_forward(F_vector4_f32(roll_pitch_yaw)), one_half);

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
        const float halfpitch = roll_pitch_yaw.x * 0.5f;
        float cp = cosf(halfpitch);
        float sp = sinf(halfpitch);

        const float halfyaw = roll_pitch_yaw.y * 0.5f;
        float cy = cosf(halfyaw);
        float sy = sinf(halfyaw);

        const float halfroll = roll_pitch_yaw.z * 0.5f;
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

    NCPP_FORCE_INLINE F_quaternion_f32 NMATH_CALL_CNV quaternion_from_euler_angles(F_vector3_f32 euler_angles) noexcept {

        return quaternion_rotation_roll_pitch_yaw(euler_angles);
    }

}
