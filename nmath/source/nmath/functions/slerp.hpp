#pragma once

/** @file nmath/functions/slerp.hpp
*
*   Implement slerp.
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
#include <nmath/functions/quaternion_invert.hpp>
#include <nmath/functions/axis_and_angle.hpp>
#include <nmath/functions/rotation.hpp>
#include <nmath/functions/lerp.hpp>
#include <nmath/operators/quaternion_quaternion.hpp>

#pragma endregion



namespace nmath {

    NCPP_FORCE_INLINE F_quaternion_f32 slerp(PA_quaternion_f32 a, PA_quaternion_f32 b, f32 t) noexcept {

        F_quaternion_f32 delta_q = b * invert(a);

        F_vector4_f32 aaa = axis_and_angle(delta_q);
        aaa.w = lerp(0.0f, aaa.w, t);

        F_quaternion_f32 add_q = T_make_rotation<
            E_rotation_axis::CUSTOM,
            F_quaternion_f32
        >(aaa);

        return add_q * a;
    }

}