#pragma once

/** @file nmath/operators/vector_vector.hpp
*
*   Implement operators between vector and vector.
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
    
    inline F_vector2_f32 minus(nmath::PA_vector2_f32 a) noexcept
    {
        return {

            -a.x,
            -a.y

        };
    }
    inline F_vector2_f32 add(nmath::PA_vector2_f32 a, nmath::PA_vector2_f32 b) noexcept
    {
        return {

            a.x + b.x,
            a.y + b.y

        };
    }
    inline F_vector2_f32 subtract(nmath::PA_vector2_f32 a, nmath::PA_vector2_f32 b) noexcept
    {
        return {

            a.x - b.x,
            a.y - b.y

        };
    }

    inline F_vector2_f32 multiply(nmath::PA_vector2_f32 a, nmath::PA_vector2_f32 b) noexcept
    {
        return {

            a.x * b.x,
            a.y * b.y

        };
    }
    inline F_vector2_f32 divide(nmath::PA_vector2_f32 a, nmath::PA_vector2_f32 b) noexcept
    {
        return {

            a.x / b.x,
            a.y / b.y

        };
    }

}

NMATH_DEFINE_PLUS_OPERATOR(nmath::PA_vector2_f32, nmath::F_vector2_f32);
NMATH_DEFINE_MINUS_OPERATOR(nmath::PA_vector2_f32, nmath::F_vector2_f32);

NMATH_DEFINE_ADD_OPERATOR(nmath::PA_vector2_f32, nmath::PA_vector2_f32, nmath::F_vector2_f32);
NMATH_DEFINE_SELF_ADD_OPERATOR(nmath::F_vector2_f32, nmath::PA_vector2_f32);

NMATH_DEFINE_SUBTRACT_OPERATOR(nmath::PA_vector2_f32, nmath::PA_vector2_f32, nmath::F_vector2_f32);
NMATH_DEFINE_SELF_SUBTRACT_OPERATOR(nmath::F_vector2_f32, nmath::PA_vector2_f32);

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_vector2_f32, nmath::PA_vector2_f32, nmath::F_vector2_f32);
NMATH_DEFINE_SELF_MULTIPLY_OPERATOR(nmath::F_vector2_f32, nmath::PA_vector2_f32);

NMATH_DEFINE_DIVIDE_OPERATOR(nmath::PA_vector2_f32, nmath::PA_vector2_f32, nmath::F_vector2_f32);
NMATH_DEFINE_SELF_DIVIDE_OPERATOR(nmath::F_vector2_f32, nmath::PA_vector2_f32);



////////////////////////////////////////////////////////////////////////////////////
//  nmath::F_vector3_f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    inline F_vector3_f32 minus(nmath::PA_vector3_f32 a) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        return _mm_mul_ps(a.xyz_, simd_f32x4_1111_negative);
#else
        return {

            -a.x,
            -a.y,
            -a.z,

        };
#endif
    }
    inline F_vector3_f32 add(nmath::PA_vector3_f32 a, nmath::PA_vector3_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        return _mm_add_ps(a.xyz_, b.xyz_);
#else
        return {

            a.x + b.x,
            a.y + b.y,
            a.z + b.z

        };
#endif
    }
    inline F_vector3_f32 subtract(nmath::PA_vector3_f32 a, nmath::PA_vector3_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        return _mm_sub_ps(a.xyz_, b.xyz_);
#else
        return {

            a.x - b.x,
            a.y - b.y,
            a.z - b.z

        };
#endif
    }

    inline F_vector3_f32 multiply(nmath::PA_vector3_f32 a, nmath::PA_vector3_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        return _mm_mul_ps(a.xyz_, b.xyz_);
#else
        return {

            a.x * b.x,
            a.y * b.y,
            a.z * b.z

        };
#endif
    }
    inline F_vector3_f32 divide(nmath::PA_vector3_f32 a, nmath::PA_vector3_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        return _mm_div_ps(a.xyz_, b.xyz_);
#else
        return {

            a.x / b.x,
            a.y / b.y,
            a.z / b.z

        };
#endif
    }

}

NMATH_DEFINE_PLUS_OPERATOR(nmath::PA_vector3_f32, nmath::F_vector3_f32);
NMATH_DEFINE_MINUS_OPERATOR(nmath::PA_vector3_f32, nmath::F_vector3_f32);

NMATH_DEFINE_ADD_OPERATOR(nmath::PA_vector3_f32, nmath::PA_vector3_f32, nmath::F_vector3_f32);
NMATH_DEFINE_SELF_ADD_OPERATOR(nmath::F_vector3_f32, nmath::PA_vector3_f32);

NMATH_DEFINE_SUBTRACT_OPERATOR(nmath::PA_vector3_f32, nmath::PA_vector3_f32, nmath::F_vector3_f32);
NMATH_DEFINE_SELF_SUBTRACT_OPERATOR(nmath::F_vector3_f32, nmath::PA_vector3_f32);

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_vector3_f32, nmath::PA_vector3_f32, nmath::F_vector3_f32);
NMATH_DEFINE_SELF_MULTIPLY_OPERATOR(nmath::F_vector3_f32, nmath::PA_vector3_f32);

NMATH_DEFINE_DIVIDE_OPERATOR(nmath::PA_vector3_f32, nmath::PA_vector3_f32, nmath::F_vector3_f32);
NMATH_DEFINE_SELF_DIVIDE_OPERATOR(nmath::F_vector3_f32, nmath::PA_vector3_f32);



////////////////////////////////////////////////////////////////////////////////////
//  nmath::F_vector4_f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    inline F_vector4_f32 minus(nmath::PA_vector4_f32 a) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        return _mm_mul_ps(a.xyzw_, simd_f32x4_1111_negative);
#else
        return {

            -a.x,
            -a.y,
            -a.z,
            -a.w

        };
#endif
    }
    inline F_vector4_f32 add(nmath::PA_vector4_f32 a, nmath::PA_vector4_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        return _mm_add_ps(a.xyzw_, b.xyzw_);
#else
        return {

            a.x + b.x,
            a.y + b.y,
            a.z + b.z,
            a.w + b.w

        };
#endif
    }
    inline F_vector4_f32 subtract(nmath::PA_vector4_f32 a, nmath::PA_vector4_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        return _mm_sub_ps(a.xyzw_, b.xyzw_);
#else
        return {

            a.x - b.x,
            a.y - b.y,
            a.z - b.z,
            a.w - b.w

        };
#endif
    }

    inline F_vector4_f32 multiply(nmath::PA_vector4_f32 a, nmath::PA_vector4_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        return _mm_mul_ps(a.xyzw_, b.xyzw_);
#else
        return {

            a.x * b.x,
            a.y * b.y,
            a.z * b.z,
            a.w * b.w

        };
#endif
    }
    inline F_vector4_f32 divide(nmath::PA_vector4_f32 a, nmath::PA_vector4_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        return _mm_div_ps(a.xyzw_, b.xyzw_);
#else
        return {

            a.x / b.x,
            a.y / b.y,
            a.z / b.z,
            a.w / b.w

        };
#endif
    }

}

NMATH_DEFINE_PLUS_OPERATOR(nmath::PA_vector4_f32, nmath::F_vector4_f32);
NMATH_DEFINE_MINUS_OPERATOR(nmath::PA_vector4_f32, nmath::F_vector4_f32);

NMATH_DEFINE_ADD_OPERATOR(nmath::PA_vector4_f32, nmath::PA_vector4_f32, nmath::F_vector4_f32);
NMATH_DEFINE_SELF_ADD_OPERATOR(nmath::F_vector4_f32, nmath::PA_vector4_f32);

NMATH_DEFINE_SUBTRACT_OPERATOR(nmath::PA_vector4_f32, nmath::PA_vector4_f32, nmath::F_vector4_f32);
NMATH_DEFINE_SELF_SUBTRACT_OPERATOR(nmath::F_vector4_f32, nmath::PA_vector4_f32);

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_vector4_f32, nmath::PA_vector4_f32, nmath::F_vector4_f32);
NMATH_DEFINE_SELF_MULTIPLY_OPERATOR(nmath::F_vector4_f32, nmath::PA_vector4_f32);

NMATH_DEFINE_DIVIDE_OPERATOR(nmath::PA_vector4_f32, nmath::PA_vector4_f32, nmath::F_vector4_f32);
NMATH_DEFINE_SELF_DIVIDE_OPERATOR(nmath::F_vector4_f32, nmath::PA_vector4_f32);