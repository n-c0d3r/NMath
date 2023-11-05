#pragma once

/** @file nmath/functions/data4x3_functions.hpp
*
*   Implement data4x3 functions.
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

#include <nmath/types/data4x3.hpp>
#include <nmath/types/data_constants.hpp>
#include <nmath/types/data_helper.hpp>
#include <nmath/utilities/basic_arithmetic.hpp>

#include <nmath/functions/data3_functions.hpp>

#pragma endregion



////////////////////////////////////////////////////////////////////////////////////
//  F32 declares
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    ////////////////////////////////////////////////////////////////////////////////////
    //  Basic arithmetic functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data4x3_f32 NCPP_VECTOR_CALL data4x3_minus(PA_data4x3_f32 a) noexcept;

    F_data4x3_f32 NCPP_VECTOR_CALL data4x3_multiply(PA_data4x3_f32 a, f32 b) noexcept;
    F_data4x3_f32 NCPP_VECTOR_CALL data4x3_divide(PA_data4x3_f32 a, f32 b) noexcept;

    F_data4x3_f32 NCPP_VECTOR_CALL data4x3_add(PA_data4x3_f32 a, PA_data4x3_f32 b) noexcept;
    F_data4x3_f32 NCPP_VECTOR_CALL data4x3_subtract(PA_data4x3_f32 a, PA_data4x3_f32 b) noexcept;

    F_data4x3_f32 NCPP_VECTOR_CALL data4x3_multiply(PA_data4x3_f32 a, PA_data4x3_f32 b) noexcept;
    F_data4x3_f32 NCPP_VECTOR_CALL data4x3_divide(PA_data4x3_f32 a, PA_data4x3_f32 b) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  FMA functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data4x3_f32 NCPP_VECTOR_CALL data4x3_multiply_add(
        PA_data4x3_f32 a,
        PA_data4x3_f32 b,
        PA_data4x3_f32 c
    ) noexcept;

    F_data4x3_f32 NCPP_VECTOR_CALL data4x3_multiply_addsub(
        PA_data4x3_f32 a,
        PA_data4x3_f32 b,
        PA_data4x3_f32 c
   ) noexcept;

    F_data4x3_f32 NCPP_VECTOR_CALL data4x3_multiply_sub(
        PA_data4x3_f32 a,
        PA_data4x3_f32 b,
        PA_data4x3_f32 c
    ) noexcept;

    F_data4x3_f32 NCPP_VECTOR_CALL data4x3_multiply_subadd(
        PA_data4x3_f32 a,
        PA_data4x3_f32 b,
        PA_data4x3_f32 c
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
    NCPP_FORCE_INLINE F_data4x3_f32 NCPP_VECTOR_CALL data4x3_minus(PA_data4x3_f32 a) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return {
    
            _mm256_mul_ps(a.ab_, simd_f32x8_11111111_negative),
            _mm256_mul_ps(a.cd_, simd_f32x8_11111111_negative)
    
        };
#else
        return {

            data3_minus(a.a),
            data3_minus(a.b),
            data3_minus(a.c),
            data3_minus(a.d)

        };
#endif
    }

    NCPP_FORCE_INLINE F_data4x3_f32 NCPP_VECTOR_CALL data4x3_multiply(PA_data4x3_f32 a, f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        __m256 bx8 = _mm256_set1_ps(b);
        
        return {

            _mm256_mul_ps(a.ab_, bx8),
            _mm256_mul_ps(a.cd_, bx8)

        };
#else
        return {

            data3_multiply(a.a, b),
            data3_multiply(a.b, b),
            data3_multiply(a.c, b),
            data3_multiply(a.d, b)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data4x3_f32 NCPP_VECTOR_CALL data4x3_divide(PA_data4x3_f32 a, f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        __m256 bx8 = _mm256_set1_ps(b);

        return {

            _mm256_div_ps(a.ab_, bx8),
            _mm256_div_ps(a.cd_, bx8)

        };
#else
        return {

            data3_divide(a.a, b),
            data3_divide(a.b, b),
            data3_divide(a.c, b),
            data3_divide(a.d, b)

    };
#endif
    }
    NCPP_FORCE_INLINE F_data4x3_f32 NCPP_VECTOR_CALL data4x3_add(PA_data4x3_f32 a, PA_data4x3_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return {

            _mm256_add_ps(a.ab_, b.ab_),
            _mm256_add_ps(a.cd_, b.cd_)

        };
#else
        return {

            data3_add(a.a, b.a),
            data3_add(a.b, b.b),
            data3_add(a.c, b.c),
            data3_add(a.d, b.d)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data4x3_f32 NCPP_VECTOR_CALL data4x3_subtract(PA_data4x3_f32 a, PA_data4x3_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return {

            _mm256_sub_ps(a.ab_, b.ab_),
            _mm256_sub_ps(a.cd_, b.cd_)

        };
#else
        return {

            data3_subtract(a.a, b.a),
            data3_subtract(a.b, b.b),
            data3_subtract(a.c, b.c),
            data3_subtract(a.d, b.d)

        };
#endif
    }

    NCPP_FORCE_INLINE F_data4x3_f32 NCPP_VECTOR_CALL data4x3_multiply(PA_data4x3_f32 a, PA_data4x3_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return {

            _mm256_mul_ps(a.ab_, b.ab_),
            _mm256_mul_ps(a.cd_, b.cd_)

        };
#else
        return {

            data3_multiply(a.a, b.a),
            data3_multiply(a.b, b.b),
            data3_multiply(a.c, b.c),
            data3_multiply(a.d, b.d)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data4x3_f32 NCPP_VECTOR_CALL data4x3_divide(PA_data4x3_f32 a, PA_data4x3_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return {

            _mm256_div_ps(a.ab_, b.ab_),
            _mm256_div_ps(a.cd_, b.cd_)

        };
#else
        return {

            data3_divide(a.a, b.a),
            data3_divide(a.b, b.b),
            data3_divide(a.c, b.c),
            data3_divide(a.d, b.d)

        };
#endif
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  FMA functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data4x3_f32 NCPP_VECTOR_CALL data4x3_multiply_add(
        PA_data4x3_f32 a,
        PA_data4x3_f32 b,
        PA_data4x3_f32 c
    ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return {

            _mm256_fmadd_ps(a.ab_, b.ab_, c.ab_),
            _mm256_fmadd_ps(a.cd_, b.cd_, c.cd_)

        };
#else
        return {
          
            data3_multiply_add(a.a, b.a, c.a),
            data3_multiply_add(a.b, b.b, c.b),
            data3_multiply_add(a.c, b.c, c.c),
            data3_multiply_add(a.d, b.d, c.d)
            
        };
#endif        
    }
    NCPP_FORCE_INLINE F_data4x3_f32 NCPP_VECTOR_CALL data4x3_multiply_addsub(
        PA_data4x3_f32 a,
        PA_data4x3_f32 b,
        PA_data4x3_f32 c
   ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return {

            _mm256_fmsubadd_ps(a.ab_, b.ab_, c.ab_),
            _mm256_fmsubadd_ps(a.cd_, b.cd_, c.cd_)

        };
#else
        return {

            data3_multiply_addsub(a.a, b.a, c.a),
            data3_multiply_addsub(a.b, b.b, c.b),
            data3_multiply_addsub(a.c, b.c, c.c),
            data3_multiply_addsub(a.d, b.d, c.d)

        };
#endif   
    }
    NCPP_FORCE_INLINE F_data4x3_f32 NCPP_VECTOR_CALL data4x3_multiply_sub(
        PA_data4x3_f32 a,
        PA_data4x3_f32 b,
        PA_data4x3_f32 c
    ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return {

            _mm256_fmsub_ps(a.ab_, b.ab_, c.ab_),
            _mm256_fmsub_ps(a.cd_, b.cd_, c.cd_)

        };
#else
        return {

            data3_multiply_sub(a.a, b.a, c.a),
            data3_multiply_sub(a.b, b.b, c.b),
            data3_multiply_sub(a.c, b.c, c.c),
            data3_multiply_sub(a.d, b.d, c.d)

        };
#endif    
    }
    NCPP_FORCE_INLINE F_data4x3_f32 NCPP_VECTOR_CALL data4x3_multiply_subadd(
        PA_data4x3_f32 a,
        PA_data4x3_f32 b,
        PA_data4x3_f32 c
   ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return {

            _mm256_fmaddsub_ps(a.ab_, b.ab_, c.ab_),
            _mm256_fmaddsub_ps(a.cd_, b.cd_, c.cd_)

        };
#else
        return {

            data3_multiply_subadd(a.a, b.a, c.a),
            data3_multiply_subadd(a.b, b.b, c.b),
            data3_multiply_subadd(a.c, b.c, c.c),
            data3_multiply_subadd(a.d, b.d, c.d)

        };
#endif  
    }
    NCPP_FORCE_INLINE F_data4x3_f32 NCPP_VECTOR_CALL data4x3_negative_multiply_add(
        PA_data4x3_f32 a,
        PA_data4x3_f32 b,
        PA_data4x3_f32 c
    ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return {

            _mm256_fnmadd_ps(a.ab_, b.ab_, c.ab_),
            _mm256_fnmadd_ps(a.cd_, b.cd_, c.cd_)

        };
#else
        return {

            data3_negative_multiply_add(a.a, b.a, c.a),
            data3_negative_multiply_add(a.b, b.b, c.b),
            data3_negative_multiply_add(a.c, b.c, c.c),
            data3_negative_multiply_add(a.d, b.d, c.d)

        };
#endif   
    }
    NCPP_FORCE_INLINE F_data4x3_f32 NCPP_VECTOR_CALL data4x3_negative_multiply_sub(
        PA_data4x3_f32 a,
        PA_data4x3_f32 b,
        PA_data4x3_f32 c
    ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return {

            _mm256_fnmsub_ps(a.ab_, b.ab_, c.ab_),
            _mm256_fnmsub_ps(a.cd_, b.cd_, c.cd_)

        };
#else
        return {

            data3_negative_multiply_sub(a.a, b.a, c.a),
            data3_negative_multiply_sub(a.b, b.b, c.b),
            data3_negative_multiply_sub(a.c, b.c, c.c),
            data3_negative_multiply_sub(a.d, b.d, c.d)

        };
#endif   
    }

}
