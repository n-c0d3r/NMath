#pragma once

/** @file nmath/functions/data2x2_functions.hpp
*
*   Implement data2x2 functions.
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

#include <nmath/types/data2x2.hpp>
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
    F_data2x2_f32 NCPP_VECTOR_CALL data2x2_minus(PA_data2x2_f32 a) noexcept;

    F_data2x2_f32 NCPP_VECTOR_CALL data2x2_multiply(PA_data2x2_f32 a, f32 b) noexcept;
    F_data2x2_f32 NCPP_VECTOR_CALL data2x2_divide(PA_data2x2_f32 a, f32 b) noexcept;

    F_data2x2_f32 NCPP_VECTOR_CALL data2x2_add(PA_data2x2_f32 a, PA_data2x2_f32 b) noexcept;
    F_data2x2_f32 NCPP_VECTOR_CALL data2x2_subtract(PA_data2x2_f32 a, PA_data2x2_f32 b) noexcept;

    F_data2x2_f32 NCPP_VECTOR_CALL data2x2_multiply(PA_data2x2_f32 a, PA_data2x2_f32 b) noexcept;
    F_data2x2_f32 NCPP_VECTOR_CALL data2x2_divide(PA_data2x2_f32 a, PA_data2x2_f32 b) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  FMA functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data2x2_f32 NCPP_VECTOR_CALL data2x2_multiply_add(
        PA_data2x2_f32 a,
        PA_data2x2_f32 b,
        PA_data2x2_f32 c
    ) noexcept;

    F_data2x2_f32 NCPP_VECTOR_CALL data2x2_multiply_addsub(
        PA_data2x2_f32 a,
        PA_data2x2_f32 b,
        PA_data2x2_f32 c
    ) noexcept;

    F_data2x2_f32 NCPP_VECTOR_CALL data2x2_multiply_sub(
        PA_data2x2_f32 a,
        PA_data2x2_f32 b,
        PA_data2x2_f32 c
    ) noexcept;

    F_data2x2_f32 NCPP_VECTOR_CALL data2x2_multiply_subadd(
        PA_data2x2_f32 a,
        PA_data2x2_f32 b,
        PA_data2x2_f32 c
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
    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_minus(PA_data2x2_f32 a) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return _mm_mul_ps(a.ab_, simd_f32x4_1111_negative);
#else
        return {

            data2_minus(a.a),
            data2_minus(a.b)

        };
#endif
    }

    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_multiply(PA_data2x2_f32 a, f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        __m128 bx4 = _mm_set1_ps(b);

        return _mm_mul_ps(a.ab_, bx4);
#else
        return {

            data2_multiply(a.a, b),
            data2_multiply(a.b, b)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_divide(PA_data2x2_f32 a, f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        __m128 bx4 = _mm_set1_ps(b);

        return _mm_div_ps(a.ab_, bx4);
#else
        return {

            data2_divide(a.a, b),
            data2_divide(a.b, b)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_add(PA_data2x2_f32 a, PA_data2x2_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return _mm_add_ps(a.ab_, b.ab_);
#else
        return {

            data2_add(a.a, b.a),
            data2_add(a.b, b.b)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_subtract(PA_data2x2_f32 a, PA_data2x2_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return _mm_sub_ps(a.ab_, b.ab_);
#else
        return {

            data2_subtract(a.a, b.a),
            data2_subtract(a.b, b.b)

        };
#endif
    }

    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_multiply(PA_data2x2_f32 a, PA_data2x2_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return _mm_mul_ps(a.ab_, b.ab_);
#else
        return {

            data2_multiply(a.a, b.a),
            data2_multiply(a.b, b.b)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_divide(PA_data2x2_f32 a, PA_data2x2_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return _mm_div_ps(a.ab_, b.ab_);
#else
        return {

            data2_divide(a.a, b.a),
            data2_divide(a.b, b.b)

        };
#endif
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  FMA functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_multiply_add(
        PA_data2x2_f32 a,
        PA_data2x2_f32 b,
        PA_data2x2_f32 c
    ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return _mm_fmadd_ps(a.ab_, b.ab_, c.ab_);
#else
        return {

            data2_multiply_add(a.a, b.a, c.a),
            data2_multiply_add(a.b, b.b, c.b)

        };
#endif        
    }
    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_multiply_addsub(
        PA_data2x2_f32 a,
        PA_data2x2_f32 b,
        PA_data2x2_f32 c
    ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return _mm_fmsubadd_ps(a.ab_, b.ab_, c.ab_);
#else
        return {

            data2_multiply_addsub(a.a, b.a, c.a),
            data2_multiply_addsub(a.b, b.b, c.b)

        };
#endif   
    }
    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_multiply_sub(
        PA_data2x2_f32 a,
        PA_data2x2_f32 b,
        PA_data2x2_f32 c
    ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return _mm_fmsub_ps(a.ab_, b.ab_, c.ab_);
#else
        return {

            data2_multiply_sub(a.a, b.a, c.a),
            data2_multiply_sub(a.b, b.b, c.b)

        };
#endif    
    }
    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_multiply_subadd(
        PA_data2x2_f32 a,
        PA_data2x2_f32 b,
        PA_data2x2_f32 c
    ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return _mm_fmaddsub_ps(a.ab_, b.ab_, c.ab_);
#else
        return {

            data2_multiply_subadd(a.a, b.a, c.a),
            data2_multiply_subadd(a.b, b.b, c.b)

        };
#endif  
    }
    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_negative_multiply_add(
        PA_data2x2_f32 a,
        PA_data2x2_f32 b,
        PA_data2x2_f32 c
    ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return _mm_fnmadd_ps(a.ab_, b.ab_, c.ab_);
#else
        return {

            data2_negative_multiply_add(a.a, b.a, c.a),
            data2_negative_multiply_add(a.b, b.b, c.b)

        };
#endif   
    }
    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_negative_multiply_sub(
        PA_data2x2_f32 a,
        PA_data2x2_f32 b,
        PA_data2x2_f32 c
    ) noexcept {

#if defined(NCPP_ENABLE_FMA3) && defined(NCPP_ENABLE_AVX)
        return _mm_fnmsub_ps(a.ab_, b.ab_, c.ab_);
#else
        return {

            data2_negative_multiply_sub(a.a, b.a, c.a),
            data2_negative_multiply_sub(a.b, b.b, c.b)

        };
#endif   
    }

}
