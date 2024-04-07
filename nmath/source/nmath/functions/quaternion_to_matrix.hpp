#pragma once

/** @file nmath/functions/quaternion_to_matrix.hpp
*
*   Implement to_matrix function for quaternions.
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

#include <nmath/operators/quaternion_matrix.hpp>
#include <nmath/functions/matrix_identity.hpp>
#include <nmath/functions/quaternion_convert_template.hpp>

#pragma endregion



////////////////////////////////////////////////////////////////////////////////////
//  f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NCPP_FORCE_INLINE F_matrix2x2_f32 NMATH_CALL_CNV to_matrix2x2_f32(PA_quaternion_f32 q) noexcept {

        return q * T_identity<F_matrix2x2_f32>();
    }
    NCPP_FORCE_INLINE F_matrix3x3_f32 NMATH_CALL_CNV to_matrix3x3_f32(PA_quaternion_f32 q) noexcept {

        return q * T_identity<F_matrix3x3_f32>();
    }
    NCPP_FORCE_INLINE F_matrix4x4_f32 NMATH_CALL_CNV to_matrix4x4_f32(PA_quaternion_f32 q) noexcept {

        return q * T_identity<F_matrix4x4_f32>();
    }

    template<>
    NCPP_FORCE_INLINE F_matrix2x2_f32 NMATH_CALL_CNV T_convert<F_quaternion_f32, F_matrix2x2_f32>(PA_quaternion_f32 q) noexcept {

        return to_matrix2x2_f32(q);
    }
    template<>
    NCPP_FORCE_INLINE F_matrix3x3_f32 NMATH_CALL_CNV T_convert<F_quaternion_f32, F_matrix3x3_f32>(PA_quaternion_f32 q) noexcept {

        return to_matrix3x3_f32(q);
    }
    template<>
    NCPP_FORCE_INLINE F_matrix4x4_f32 NMATH_CALL_CNV T_convert<F_quaternion_f32, F_matrix4x4_f32>(PA_quaternion_f32 q) noexcept {

        return to_matrix4x4_f32(q);
    }

}