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
    
    inline F_vector2_f32 multiply(nmath::PA_vector2_f32 a, float b) noexcept
    {
        return {

            a.x * b,
            a.y * b

        };
    }
    inline F_vector2_f32 multiply(float b, nmath::PA_vector2_f32 a) noexcept
    {
        return {

            a.x * b,
            a.y * b

        };
    }

    inline F_vector2_f32 divide(nmath::PA_vector2_f32 a, float b) noexcept
    {
        return {

            a.x / b,
            a.y / b

        };
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

    inline F_vector3_f32 multiply(nmath::F_vector3_f32 a, float b) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        __m128 bbbb = _mm_set1_ps(b);
        
        return _mm_mul_ps(a.xyz_, bbbb);
#else
        return {

            a.x * b,
            a.y * b,
            a.z * b

        };
#endif
    }
    inline F_vector3_f32 multiply(float b, nmath::F_vector3_f32 a) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        __m128 bbbb = _mm_set1_ps(b);

        return _mm_mul_ps(a.xyz_, bbbb);
#else
        return {

            a.x * b,
            a.y * b,
            a.z * b

        };
#endif
    }

    inline F_vector3_f32 divide(nmath::F_vector3_f32 a, float b) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        __m128 bbbb = _mm_set1_ps(b);

        return _mm_div_ps(a.xyz_, bbbb);
#else
        return {

            a.x / b,
            a.y / b,
            a.z / b

        };
#endif
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
//  nmath::F_vector3_f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    inline F_vector4_f32 multiply(nmath::F_vector4_f32 a, float b) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        __m128 bbbb = _mm_set1_ps(b);

        return _mm_mul_ps(a.xyzw_, bbbb);
#else
        return {

            a.x * b,
            a.y * b,
            a.z * b,
            a.w * b

        };
#endif
    }
    inline F_vector4_f32 multiply(float b, nmath::F_vector4_f32 a) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        __m128 bbbb = _mm_set1_ps(b);

        return _mm_mul_ps(a.xyzw_, bbbb);
#else
        return {

            a.x * b,
            a.y * b,
            a.z * b,
            a.w * b

        };
#endif
    }

    inline F_vector4_f32 divide(nmath::F_vector4_f32 a, float b) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        __m128 bbbb = _mm_set1_ps(b);

        return _mm_div_ps(a.xyzw_, bbbb);
#else
        return {

            a.x / b,
            a.y / b,
            a.z / b,
            a.w / b

        };
#endif
    }

}

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_vector4_f32, float, nmath::F_vector4_f32);
NMATH_DEFINE_MULTIPLY_OPERATOR(float, nmath::PA_vector4_f32, nmath::F_vector4_f32);
NMATH_DEFINE_SELF_MULTIPLY_OPERATOR(nmath::F_vector4_f32, float);

NMATH_DEFINE_DIVIDE_OPERATOR(nmath::PA_vector4_f32, float, nmath::F_vector4_f32);
NMATH_DEFINE_SELF_DIVIDE_OPERATOR(nmath::F_vector4_f32, float);