#pragma once

/** @file nmath/operators/quaternion_quaternion.hpp
*
*   Implement operators between quaternion and quaternion.
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

#include <nmath/types/quaternion.hpp>
#include <nmath/functions/data4_functions.hpp>
#include <nmath/operators/helper.hpp>

#pragma endregion



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////
//  nmath::F_quaternion_f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NCPP_FORCE_INLINE F_quaternion_f32 NMATH_CALL_CNV minus(PA_quaternion_f32 a) noexcept
    {

        return quaternion_forward(
            data4_minus(data_forward(a))
        );
    }
    NCPP_FORCE_INLINE F_quaternion_f32 NMATH_CALL_CNV add(PA_quaternion_f32 a, PA_quaternion_f32 b) noexcept
    {

        return quaternion_forward(
            data4_add(data_forward(b), data_forward(a))
        );
    }
    NCPP_FORCE_INLINE F_quaternion_f32 NMATH_CALL_CNV subtract(PA_quaternion_f32 a, PA_quaternion_f32 b) noexcept
    {

        return quaternion_forward(
            data4_subtract(data_forward(b), data_forward(a))
        );
    }

    NCPP_FORCE_INLINE F_quaternion_f32 NMATH_CALL_CNV multiply(PA_quaternion_f32 a, PA_quaternion_f32 b) noexcept
    {
    
        return quaternion_forward(
            data4_complex_multiply(data_forward(b), data_forward(a))
        );
    }

}

NMATH_DEFINE_PLUS_OPERATOR(nmath::PA_quaternion_f32, nmath::F_quaternion_f32);
NMATH_DEFINE_MINUS_OPERATOR(nmath::PA_quaternion_f32, nmath::F_quaternion_f32);

NMATH_DEFINE_ADD_OPERATOR(nmath::PA_quaternion_f32, nmath::PA_quaternion_f32, nmath::F_quaternion_f32);
NMATH_DEFINE_SELF_ADD_OPERATOR(nmath::F_quaternion_f32, nmath::PA_quaternion_f32);

NMATH_DEFINE_SUBTRACT_OPERATOR(nmath::PA_quaternion_f32, nmath::PA_quaternion_f32, nmath::F_quaternion_f32);
NMATH_DEFINE_SELF_SUBTRACT_OPERATOR(nmath::F_quaternion_f32, nmath::PA_quaternion_f32);

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_quaternion_f32, nmath::PA_quaternion_f32, nmath::F_quaternion_f32);
NMATH_DEFINE_SELF_MULTIPLY_OPERATOR(nmath::F_quaternion_f32, nmath::PA_quaternion_f32);
