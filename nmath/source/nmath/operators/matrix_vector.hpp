#pragma once

/** @file nmath/operators/matrix_vector.hpp
*
*   Implement operators between matrix and vector.
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

#include <nmath/types/data_forward.hpp>
#include <nmath/types/matrix.hpp>
#include <nmath/types/vector.hpp>
#include <nmath/functions/data_functions.hpp>
#include <nmath/operators/vector_scalar.hpp>
#include <nmath/operators/vector_vector.hpp>
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
//  nmath::F_matrix2x2_f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {
    
    NCPP_FORCE_INLINE F_vector2_f32 multiply(PA_matrix2x2_f32 a, PA_vector2_f32 b) noexcept
    {
        return b.x * a.a + b.y * a.b;
    }

}

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_matrix2x2_f32, nmath::PA_vector2_f32, nmath::F_vector2_f32);



////////////////////////////////////////////////////////////////////////////////////
//  nmath::F_matrix3x3_f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {
    
    NCPP_FORCE_INLINE F_vector3_f32 multiply(PA_matrix3x3_f32 a, PA_vector3_f32 b) noexcept
    {
        return b.x * a.a + b.y * a.b + b.z * a.c;
    }

}

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_matrix3x3_f32, nmath::PA_vector3_f32, nmath::F_vector3_f32);



////////////////////////////////////////////////////////////////////////////////////
//  nmath::F_matrix4x4_f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {
    
    NCPP_FORCE_INLINE F_vector4_f32 multiply(PA_matrix4x4_f32 a, PA_vector4_f32 b) noexcept
    {
        return b.x * a.a + b.y * a.b + b.z * a.c + b.w * a.d;
    }

}

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_matrix4x4_f32, nmath::PA_vector4_f32, nmath::F_vector4_f32);
