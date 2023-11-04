#pragma once

/** @file nmath/operators/vector_scalar.hpp
*
*   Implement operators between vector and scalar.
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
//  nmath::F_vector2_f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {
    
    NCPP_FORCE_INLINE F_vector2_f32 multiply(PA_vector2_f32 a, float b) noexcept
    {
        
        return vecma_forward(
            data2_multiply(data_forward(a), b)
        );
    }
    NCPP_FORCE_INLINE F_vector2_f32 multiply(float b, PA_vector2_f32 a) noexcept
    {

        return vecma_forward(
            data2_multiply(data_forward(a), b)
        );
    }

    NCPP_FORCE_INLINE F_vector2_f32 divide(PA_vector2_f32 a, float b) noexcept
    {

        return vecma_forward(
            data2_divide(data_forward(a), b)
        );
    }

}

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_vector2_f32, float, nmath::F_vector2_f32);
NMATH_DEFINE_MULTIPLY_OPERATOR(float, nmath::PA_vector2_f32, nmath::F_vector2_f32);
NMATH_DEFINE_SELF_MULTIPLY_OPERATOR(nmath::F_vector2_f32, float);

NMATH_DEFINE_DIVIDE_OPERATOR(nmath::PA_vector2_f32, float, nmath::F_vector2_f32);
NMATH_DEFINE_SELF_DIVIDE_OPERATOR(nmath::F_vector2_f32, float);



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
//  nmath::F_vector3_f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NCPP_FORCE_INLINE F_vector3_f32 NCPP_VECTOR_CALL multiply(nmath::F_vector3_f32 a, float b) noexcept
    {

        return vecma_forward(
            data3_multiply(data_forward(a), b)
        );
    }
    NCPP_FORCE_INLINE F_vector3_f32 NCPP_VECTOR_CALL multiply(float b, nmath::F_vector3_f32 a) noexcept
    {

        return vecma_forward(
            data3_multiply(data_forward(a), b)
        );
    }

    NCPP_FORCE_INLINE F_vector3_f32 NCPP_VECTOR_CALL divide(nmath::F_vector3_f32 a, float b) noexcept
    {

        return vecma_forward(
            data3_divide(data_forward(a), b)
        );
    }

}

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_vector3_f32, float, nmath::F_vector3_f32);
NMATH_DEFINE_MULTIPLY_OPERATOR(float, nmath::PA_vector3_f32, nmath::F_vector3_f32);
NMATH_DEFINE_SELF_MULTIPLY_OPERATOR(nmath::F_vector3_f32, float);

NMATH_DEFINE_DIVIDE_OPERATOR(nmath::PA_vector3_f32, float, nmath::F_vector3_f32);
NMATH_DEFINE_SELF_DIVIDE_OPERATOR(nmath::F_vector3_f32, float);



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
//  nmath::F_vector4_f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NCPP_FORCE_INLINE F_vector4_f32 NCPP_VECTOR_CALL multiply(nmath::F_vector4_f32 a, float b) noexcept
    {

        return vecma_forward(
            data4_multiply(data_forward(a), b)
        );
    }
    NCPP_FORCE_INLINE F_vector4_f32 NCPP_VECTOR_CALL multiply(float b, nmath::F_vector4_f32 a) noexcept
    {

        return vecma_forward(
            data4_multiply(data_forward(a), b)
        );
    }

    NCPP_FORCE_INLINE F_vector4_f32 NCPP_VECTOR_CALL divide(nmath::F_vector4_f32 a, float b) noexcept
    {

        return vecma_forward(
            data4_divide(data_forward(a), b)
        );
    }

}

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_vector4_f32, float, nmath::F_vector4_f32);
NMATH_DEFINE_MULTIPLY_OPERATOR(float, nmath::PA_vector4_f32, nmath::F_vector4_f32);
NMATH_DEFINE_SELF_MULTIPLY_OPERATOR(nmath::F_vector4_f32, float);

NMATH_DEFINE_DIVIDE_OPERATOR(nmath::PA_vector4_f32, float, nmath::F_vector4_f32);
NMATH_DEFINE_SELF_DIVIDE_OPERATOR(nmath::F_vector4_f32, float);