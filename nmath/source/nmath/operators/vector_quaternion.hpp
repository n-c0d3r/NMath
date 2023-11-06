#pragma once

/** @file nmath/operators/vector_quaternion.hpp
*
*   Implement operators between vector and quaternion.
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
#include <nmath/types/vector.hpp>
#include <nmath/functions/data4_functions.hpp>
#include <nmath/functions/conjugate.hpp>
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
//  f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NCPP_FORCE_INLINE F_vector2_f32 NCPP_VECTOR_CALL multiply(PA_vector2_f32 a, PA_quaternion_f32 b) noexcept
    {

        return vecma_forward(
            data4_complex_multiply(
                data4_complex_multiply(
                    data_forward(conjugate(b)),
                    data_forward(F_vector4_f32(a, 0.0f, 0.0f))
                ),
                data_forward(b)
            ).xy()
        );
    }

    NCPP_FORCE_INLINE F_vector3_f32 NCPP_VECTOR_CALL multiply(PA_vector3_f32 a, PA_quaternion_f32 b) noexcept
    {

        return vecma_forward(
            data4_complex_multiply(
                data4_complex_multiply(
                    data_forward(conjugate(b)),
                    data_forward(F_vector4_f32(a))
                ),
                data_forward(b)
            ).xyz()
        );
    }

    NCPP_FORCE_INLINE F_vector4_f32 NCPP_VECTOR_CALL multiply(PA_vector4_f32 a, PA_quaternion_f32 b) noexcept
    {

        return vecma_forward(
            data4_complex_multiply(
                data4_complex_multiply(
                    data_forward(conjugate(b)),
                    data_forward(a)
                ),
                data_forward(b)
            )
        );
    }
    
}

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_vector2_f32, nmath::PA_quaternion_f32, nmath::F_vector2_f32);
NMATH_DEFINE_SELF_MULTIPLY_OPERATOR(nmath::F_vector2_f32, nmath::PA_quaternion_f32);

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_vector3_f32, nmath::PA_quaternion_f32, nmath::F_vector3_f32);
NMATH_DEFINE_SELF_MULTIPLY_OPERATOR(nmath::F_vector3_f32, nmath::PA_quaternion_f32);

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_vector4_f32, nmath::PA_quaternion_f32, nmath::F_vector4_f32);
NMATH_DEFINE_SELF_MULTIPLY_OPERATOR(nmath::F_vector4_f32, nmath::PA_quaternion_f32);
