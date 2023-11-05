#pragma once

/** @file nmath/functions/data4x2_functions.hpp
*
*   Implement data4x2 functions.
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

#include <nmath/types/data4x2.hpp>
#include <nmath/types/data_constants.hpp>
#include <nmath/types/data_helper.hpp>
#include <nmath/utilities/basic_arithmetic.hpp>

#include <nmath/functions/data2_functions.hpp>

#pragma endregion



////////////////////////////////////////////////////////////////////////////////////
//  F32 declares
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    ////////////////////////////////////////////////////////////////////////////////////
    //  Basic arithmetic functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data4x2_f32 NCPP_VECTOR_CALL data4x2_minus(PA_data4x2_f32 a) noexcept;

    F_data4x2_f32 NCPP_VECTOR_CALL data4x2_multiply(PA_data4x2_f32 a, f32 b) noexcept;
    F_data4x2_f32 NCPP_VECTOR_CALL data4x2_divide(PA_data4x2_f32 a, f32 b) noexcept;

    F_data4x2_f32 NCPP_VECTOR_CALL data4x2_add(PA_data4x2_f32 a, PA_data4x2_f32 b) noexcept;
    F_data4x2_f32 NCPP_VECTOR_CALL data4x2_subtract(PA_data4x2_f32 a, PA_data4x2_f32 b) noexcept;

    F_data4x2_f32 NCPP_VECTOR_CALL data4x2_multiply(PA_data4x2_f32 a, PA_data4x2_f32 b) noexcept;
    F_data4x2_f32 NCPP_VECTOR_CALL data4x2_divide(PA_data4x2_f32 a, PA_data4x2_f32 b) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  FMA functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data4x2_f32 NCPP_VECTOR_CALL data4x2_multiply_add(
        PA_data4x2_f32 a,
        PA_data4x2_f32 b,
        PA_data4x2_f32 c
    ) noexcept;

    F_data4x2_f32 NCPP_VECTOR_CALL data4x2_multiply_addsub(
        PA_data4x2_f32 a,
        PA_data4x2_f32 b,
        PA_data4x2_f32 c
   ) noexcept;

    F_data4x2_f32 NCPP_VECTOR_CALL data4x2_multiply_sub(
        PA_data4x2_f32 a,
        PA_data4x2_f32 b,
        PA_data4x2_f32 c
    ) noexcept;

    F_data4x2_f32 NCPP_VECTOR_CALL data4x2_multiply_subadd(
        PA_data4x2_f32 a,
        PA_data4x2_f32 b,
        PA_data4x2_f32 c
   ) noexcept;

}



////////////////////////////////////////////////////////////////////////////////////
//  F32 defines
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    ////////////////////////////////////////////////////////////////////////////////////
    //  Basic arithmetic functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data4x2_f32 NCPP_VECTOR_CALL data4x2_minus(PA_data4x2_f32 a) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return _mm256_mul_ps(a.abcd_, simd_f32x8_11111111_negative);
#else
        return {

            data2_minus(a.a),
            data2_minus(a.b),
            data2_minus(a.c),
            data2_minus(a.d)

        };
#endif
    }

    NCPP_FORCE_INLINE F_data4x2_f32 NCPP_VECTOR_CALL data4x2_multiply(PA_data4x2_f32 a, f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        __m256 bx8 = _mm256_set1_ps(b);
        
        return _mm256_mul_ps(a.abcd_, bx8);
#else
        return {

            data2_multiply(a.a, b),
            data2_multiply(a.b, b),
            data2_multiply(a.c, b),
            data2_multiply(a.d, b)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data4x2_f32 NCPP_VECTOR_CALL data4x2_divide(PA_data4x2_f32 a, f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        __m256 bx8 = _mm256_set1_ps(b);

        return _mm256_div_ps(a.abcd_, bx8);
#else
        return {

            data2_divide(a.a, b),
            data2_divide(a.b, b),
            data2_divide(a.c, b),
            data2_divide(a.d, b)

    };
#endif
    }
    NCPP_FORCE_INLINE F_data4x2_f32 NCPP_VECTOR_CALL data4x2_add(PA_data4x2_f32 a, PA_data4x2_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return _mm256_add_ps(a.abcd_, b.abcd_);
#else
        return {

            data2_add(a.a, b.a),
            data2_add(a.b, b.b),
            data2_add(a.c, b.c),
            data2_add(a.d, b.d)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data4x2_f32 NCPP_VECTOR_CALL data4x2_subtract(PA_data4x2_f32 a, PA_data4x2_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return _mm256_sub_ps(a.abcd_, b.abcd_);
#else
        return {

            data2_subtract(a.a, b.a),
            data2_subtract(a.b, b.b),
            data2_subtract(a.c, b.c),
            data2_subtract(a.d, b.d)

        };
#endif
    }

    NCPP_FORCE_INLINE F_data4x2_f32 NCPP_VECTOR_CALL data4x2_multiply(PA_data4x2_f32 a, PA_data4x2_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return _mm256_mul_ps(a.abcd_, b.abcd_);
#else
        return {

            data2_multiply(a.a, b.a),
            data2_multiply(a.b, b.b),
            data2_multiply(a.c, b.c),
            data2_multiply(a.d, b.d)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data4x2_f32 NCPP_VECTOR_CALL data4x2_divide(PA_data4x2_f32 a, PA_data4x2_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return _mm256_div_ps(a.abcd_, b.abcd_);
#else
        return {

            data2_divide(a.a, b.a),
            data2_divide(a.b, b.b),
            data2_divide(a.c, b.c),
            data2_divide(a.d, b.d)

        };
#endif
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  FMA functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data4x2_f32 NCPP_VECTOR_CALL data4x2_multiply_add(
        PA_data4x2_f32 a,
        PA_data4x2_f32 b,
        PA_data4x2_f32 c
    ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return _mm256_fmadd_ps(a.abcd_, b.abcd_, c.abcd_);
#else
        return {
          
            data2_multiply_add(a.a, b.a, c.a),
            data2_multiply_add(a.b, b.b, c.b),
            data2_multiply_add(a.c, b.c, c.c),
            data2_multiply_add(a.d, b.d, c.d)
            
        };
#endif        
    }
    NCPP_FORCE_INLINE F_data4x2_f32 NCPP_VECTOR_CALL data4x2_multiply_addsub(
        PA_data4x2_f32 a,
        PA_data4x2_f32 b,
        PA_data4x2_f32 c
   ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return _mm256_fmsubadd_ps(a.abcd_, b.abcd_, c.abcd_);
#else
        return {

            data2_multiply_addsub(a.a, b.a, c.a),
            data2_multiply_addsub(a.b, b.b, c.b),
            data2_multiply_addsub(a.c, b.c, c.c),
            data2_multiply_addsub(a.d, b.d, c.d)

        };
#endif   
    }
    NCPP_FORCE_INLINE F_data4x2_f32 NCPP_VECTOR_CALL data4x2_multiply_sub(
        PA_data4x2_f32 a,
        PA_data4x2_f32 b,
        PA_data4x2_f32 c
    ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return _mm256_fmsub_ps(a.abcd_, b.abcd_, c.abcd_);
#else
        return {

            data2_multiply_sub(a.a, b.a, c.a),
            data2_multiply_sub(a.b, b.b, c.b),
            data2_multiply_sub(a.c, b.c, c.c),
            data2_multiply_sub(a.d, b.d, c.d)

        };
#endif    
    }
    NCPP_FORCE_INLINE F_data4x2_f32 NCPP_VECTOR_CALL data4x2_multiply_subadd(
        PA_data4x2_f32 a,
        PA_data4x2_f32 b,
        PA_data4x2_f32 c
   ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return _mm256_fmaddsub_ps(a.abcd_, b.abcd_, c.abcd_);
#else
        return {

            data2_multiply_subadd(a.a, b.a, c.a),
            data2_multiply_subadd(a.b, b.b, c.b),
            data2_multiply_subadd(a.c, b.c, c.c),
            data2_multiply_subadd(a.d, b.d, c.d)

        };
#endif  
    }
    NCPP_FORCE_INLINE F_data4x2_f32 NCPP_VECTOR_CALL data4x2_negative_multiply_add(
        PA_data4x2_f32 a,
        PA_data4x2_f32 b,
        PA_data4x2_f32 c
    ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return _mm256_fnmadd_ps(a.abcd_, b.abcd_, c.abcd_);
#else
        return {

            data2_negative_multiply_add(a.a, b.a, c.a),
            data2_negative_multiply_add(a.b, b.b, c.b),
            data2_negative_multiply_add(a.c, b.c, c.c),
            data2_negative_multiply_add(a.d, b.d, c.d)

        };
#endif   
    }
    NCPP_FORCE_INLINE F_data4x2_f32 NCPP_VECTOR_CALL data4x2_negative_multiply_sub(
        PA_data4x2_f32 a,
        PA_data4x2_f32 b,
        PA_data4x2_f32 c
    ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return _mm256_fnmsub_ps(a.abcd_, b.abcd_, c.abcd_);
#else
        return {

            data2_negative_multiply_sub(a.a, b.a, c.a),
            data2_negative_multiply_sub(a.b, b.b, c.b),
            data2_negative_multiply_sub(a.c, b.c, c.c),
            data2_negative_multiply_sub(a.d, b.d, c.d)

        };
#endif   
    }

}
