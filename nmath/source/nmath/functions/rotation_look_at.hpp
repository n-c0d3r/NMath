#pragma once

/** @file nmath/functions/rotation_look_at.hpp
*
*   Implement rotation_look_at.
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

#include <nmath/types/vector.hpp>
#include <nmath/types/quaternion.hpp>
#include <nmath/functions/length.hpp>
#include <nmath/functions/cross.hpp>
#include <nmath/functions/dot.hpp>
#include <nmath/functions/normalize.hpp>
#include <nmath/functions/quaternion_identity.hpp>
#include <nmath/operators/vector_scalar.hpp>
#include <nmath/operators/quaternion_scalar.hpp>

#pragma endregion



namespace nmath {

    template<typename F__ = F_quaternion_f32, b8 with_qlength = false>
    F__ NMATH_CALL_CNV T_rotation_look_at(auto from, auto to) noexcept;

    template<>
    inline F_quaternion_f32 NMATH_CALL_CNV T_rotation_look_at<F_quaternion_f32, false>(PA_vector3_f32 from_direction, PA_vector3_f32 to_direction) noexcept {

        NCPP_ASSERT(is_normalized(from_direction)) << "invalid from_direction, it have to be normalized";
        NCPP_ASSERT(is_normalized(to_direction)) << "invalid to_direction, it have to be normalized";

        // equal to axis * sin(angle)
        F_vector3_f32 axis_sin_angle = cross(from_direction, to_direction);

        // if from_direction is equal to to_direction, returns identity quaternion
        if(length_sq(axis_sin_angle) <= NMATH_DEFAULT_TOLERANCE_F32)
            return T_identity<F_quaternion_f32>();

        // cos(angle) = [cos(angle/2)]^2 - [sin(angle/2)]^2
        //            = 2[cos(angle/2)]^2 - 1
        //
        // <=> cos(angle/2) = sqrt(1/2 + cos(angle)/2)
        f32 dot_half = dot(from_direction, to_direction) * 0.5f;
        f32 cos_half_angle = sqrt(0.5f + dot_half);

        // this variable will be multiplied with axis_sin_angle to get axis * sin(angle/2)
        //
        // axis_sin_angle * axis_sin_angle_multiplier = axis * sin(angle/2)
        //
        // <=> axis * sin(angle) * axis_sin_angle_multiplier = axis * sin(angle/2)
        //
        // <=> axis_sin_angle_multiplier = axis * sin(angle/2) / sin(angle)
        //
        // <=> axis_sin_angle_multiplier = sin(angle/2) / [2sin(angle/2)cos(angle/2)]
        // <=> axis_sin_angle_multiplier = (1 / 2) / cos(angle/2)
        f32 axis_sin_angle_multiplier = 0.5f / cos_half_angle;

        // xyz = axis * sin(angle/2)
        // w = cos(angle/2)
        return quaternion_forward(
            F_data4_f32 {
                data_forward(axis_sin_angle * axis_sin_angle_multiplier),
                cos_half_angle
            }
        );
    }

    template<>
    inline F_quaternion_f32 NMATH_CALL_CNV T_rotation_look_at<F_quaternion_f32, true>(PA_vector3_f32 from, PA_vector3_f32 to) noexcept {

        f32 from_length = length(from);
        f32 to_length = length(to);

        F_vector3_f32 from_direction = from / from_length;
        F_vector3_f32 to_direction = to / to_length;

        // equal to axis * sin(angle)
        F_vector3_f32 axis_sin_angle = cross(from_direction, to_direction);

        // if from_direction is equal to to_direction, returns identity quaternion
        if(length_sq(axis_sin_angle) <= NMATH_DEFAULT_TOLERANCE_F32)
        return T_identity<F_quaternion_f32>();

        // cos(angle) = [cos(angle/2)]^2 - [sin(angle/2)]^2
        //            = 2[cos(angle/2)]^2 - 1
        //
        // <=> cos(angle/2) = sqrt(1/2 + cos(angle)/2)
        f32 dot_half = dot(from_direction, to_direction) * 0.5f;
        f32 cos_half_angle = sqrt(0.5f + dot_half);

        // this variable will be multiplied with axis_sin_angle to get axis * sin(angle/2)
        //
        // axis_sin_angle * axis_sin_angle_multiplier = axis * sin(angle/2)
        //
        // <=> axis * sin(angle) * axis_sin_angle_multiplier = axis * sin(angle/2)
        //
        // <=> axis_sin_angle_multiplier = axis * sin(angle/2) / sin(angle)
        //
        // <=> axis_sin_angle_multiplier = sin(angle/2) / [2sin(angle/2)cos(angle/2)]
        // <=> axis_sin_angle_multiplier = (1 / 2) * cos(angle/2)
        f32 axis_sin_angle_multiplier = 0.5f / cos_half_angle;

        // xyz = axis * sin(angle/2)
        // w = cos(angle/2)
        return quaternion_forward(
            F_data4_f32 {
                data_forward(axis_sin_angle * axis_sin_angle_multiplier),
                cos_half_angle
            }
        );
    }

}
