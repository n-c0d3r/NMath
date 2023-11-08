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

    F_data2x2_f32 NCPP_VECTOR_CALL data2x2_round(PA_data2x2_f32 a) noexcept;



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



    ////////////////////////////////////////////////////////////////////////////////////
    //  Trigonometry functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data2x2_f32 NCPP_VECTOR_CALL data2x2_mod_angles(PA_data2x2_f32 a) noexcept;

    F_data2x2_f32 NCPP_VECTOR_CALL data2x2_sin(PA_data2x2_f32 a) noexcept;

    F_data2x2_f32 NCPP_VECTOR_CALL data2x2_cos(PA_data2x2_f32 a) noexcept;

    void NCPP_VECTOR_CALL data2x2_sin_cos(PA_data2x2_f32 a, F_data2x2_f32& out_sin, F_data2x2_f32& out_cos) noexcept;

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

#ifdef NCPP_ENABLE_SSE
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

#ifdef NCPP_ENABLE_SSE
        return _mm_mul_ps(a.ab_, _mm_set1_ps(b));
#else
        return {

            data2_multiply(a.a, b),
            data2_multiply(a.b, b)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_divide(PA_data2x2_f32 a, f32 b) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        return _mm_div_ps(a.ab_, _mm_set1_ps(b));
#else
        return {

            data2_divide(a.a, b),
            data2_divide(a.b, b)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_add(PA_data2x2_f32 a, PA_data2x2_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_SSE
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

#ifdef NCPP_ENABLE_SSE
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

#ifdef NCPP_ENABLE_SSE
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

#ifdef NCPP_ENABLE_SSE
        return _mm_div_ps(a.ab_, b.ab_);
#else
        return {

            data2_divide(a.a, b.a),
            data2_divide(a.b, b.b)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_round(PA_data2x2_f32 a) noexcept {

#ifdef NCPP_ENABLE_SSE4
        return _mm_round_ps(a.ab_, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
#elif defined(NCPP_ENABLE_SSE)
        __m128 sign = _mm_and_ps(a.ab_, negative_zero_x4.xyzw_);
        __m128 sMagic = _mm_or_ps(no_fraction_x4.ab_, sign);
        __m128 R1 = _mm_add_ps(a.ab_, sMagic);
        R1 = _mm_sub_ps(R1, sMagic);
        __m128 R2 = _mm_and_ps(a.ab_, abs_mask_x4.ab_);
        __m128 mask = _mm_cmple_ps(R2, no_fraction_x4.ab_);
        R2 = _mm_andnot_ps(mask, a.ab_);
        R1 = _mm_and_ps(R1, mask);
        F_data2x2_f32 vResult = _mm_xor_ps(R1, R2);
        return vResult;
#else
        return {

            data2_round(a.a),
            data2_round(a.b)

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
                   
#ifdef NCPP_ENABLE_FMA3
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
        
#ifdef NCPP_ENABLE_FMA3
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
    
#ifdef NCPP_ENABLE_FMA3
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
    
#ifdef NCPP_ENABLE_FMA3
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

#ifdef NCPP_ENABLE_FMA3
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

#ifdef NCPP_ENABLE_FMA3
        return _mm_fnmsub_ps(a.ab_, b.ab_, c.ab_);
#else
        return {

            data2_negative_multiply_sub(a.a, b.a, c.a),
            data2_negative_multiply_sub(a.b, b.b, c.b)

        };
#endif

    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Trigonometry functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_mod_angles(PA_data2x2_f32 a) noexcept {

#ifdef NCPP_ENABLE_SSE
        F_data2x2_f32 vResult = _mm_mul_ps(a.ab_, reciprocal_two_pi_x4.xyzw_);
        // Use the inline function due to complexity for rounding
        vResult = data2x2_round(vResult);
        return _mm_fnmadd_ps(vResult.ab_, two_pi_x4.xyzw_, a.ab_);
#else
        F_data2x2_f32 V;
        F_data2x2_f32 Result;

        // Modulo the range of the given angles such that -XM_PI <= Angles < XM_PI
        V.a = data2_multiply(a.a, reciprocal_two_pi_x2);
        V.b = data2_multiply(a.b, reciprocal_two_pi_x2);
        V = data2x2_round(V);
        Result = data2x2_negative_multiply_sub( two_pi_2x2, V, a);
        return Result;
#endif
    }

    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_sin(PA_data2x2_f32 a) noexcept {

#ifdef NCPP_ENABLE_SSE
        // Force the value within the bounds of pi
        F_data2x2_f32 x = data2x2_mod_angles(a);

        // Map in [-pi/2,pi/2] with sin(y) = sin(x).
        __m128 sign = _mm_and_ps(x.ab_, negative_zero_x4.xyzw_);
        __m128 c = _mm_or_ps(two_pi_x4.xyzw_, sign);  // pi when x >= 0, -pi when x < 0
        __m128 absx = _mm_andnot_ps(sign, x.ab_);  // |x|
        __m128 rflx = _mm_sub_ps(c, x.ab_);
        __m128 comp = _mm_cmple_ps(absx, half_pi_x4.xyzw_);
        __m128 select0 = _mm_and_ps(comp, x.ab_);
        __m128 select1 = _mm_andnot_ps(comp, rflx);
        x = _mm_or_ps(select0, select1);

        __m128 x2 = _mm_mul_ps(x.ab_, x.ab_);

        // Compute polynomial approximation
        __m128 vConstantsB = _mm_permute_ps(sin_coefficient_s1_x4.xyzw_, _MM_SHUFFLE(0, 0, 0, 0));
        __m128 vConstants = _mm_permute_ps(sin_coefficient_s0_x4.xyzw_, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 Result = _mm_fmadd_ps(vConstantsB, x2, vConstants);

        vConstants = _mm_permute_ps(sin_coefficient_s0_x4.xyzw_, _MM_SHUFFLE(2, 2, 2, 2));
        Result = _mm_fmadd_ps(Result, x2, vConstants);

        vConstants = _mm_permute_ps(sin_coefficient_s0_x4.xyzw_, _MM_SHUFFLE(1, 1, 1, 1));
        Result = _mm_fmadd_ps(Result, x2, vConstants);

        vConstants = _mm_permute_ps(sin_coefficient_s0_x4.xyzw_, _MM_SHUFFLE(0, 0, 0, 0));
        Result = _mm_fmadd_ps(Result, x2, vConstants);

        Result = _mm_fmadd_ps(Result, x2, simd_f32x4_1111);
        Result = _mm_mul_ps(Result, x.ab_);
        return Result;
#else
        return {

            data2_sin(a.a),
            data2_sin(a.b)

        };
#endif
    }

    NCPP_FORCE_INLINE F_data2x2_f32 NCPP_VECTOR_CALL data2x2_cos(PA_data2x2_f32 a) noexcept {

#ifdef NCPP_ENABLE_SSE
        // Map V to x in [-pi,pi].
        F_data2x2_f32 x = data2x2_mod_angles(a);

        // Map in [-pi/2,pi/2] with cos(y) = sign*cos(x).
        F_data2x2_f32 sign = _mm_and_ps(x.ab_, negative_zero_x4.xyzw_);
        __m128 c = _mm_or_ps(pi_x4.xyzw_, sign.ab_);  // pi when x >= 0, -pi when x < 0
        __m128 absx = _mm_andnot_ps(sign.ab_, x.ab_);  // |x|
        __m128 rflx = _mm_sub_ps(c, x.ab_);
        __m128 comp = _mm_cmple_ps(absx, half_pi_x4.xyzw_);
        __m128 select0 = _mm_and_ps(comp, x.ab_);
        __m128 select1 = _mm_andnot_ps(comp, rflx);
        x = _mm_or_ps(select0, select1);
        select0 = _mm_and_ps(comp, simd_f32x4_1111);
        select1 = _mm_andnot_ps(comp, simd_f32x4_1111_negative);
        sign = _mm_or_ps(select0, select1);

        __m128 x2 = _mm_mul_ps(x.ab_, x.ab_);

        // Compute polynomial approximation
        __m128 vConstantsB = _mm_permute_ps(cos_coefficient_s1_x4.xyzw_, _MM_SHUFFLE(0, 0, 0, 0));
        __m128 vConstants = _mm_permute_ps(cos_coefficient_s0_x4.xyzw_, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 Result = _mm_fmadd_ps(vConstantsB, x2, vConstants);

        vConstants = _mm_permute_ps(cos_coefficient_s0_x4.xyzw_, _MM_SHUFFLE(2, 2, 2, 2));
        Result = _mm_fmadd_ps(Result, x2, vConstants);

        vConstants = _mm_permute_ps(cos_coefficient_s0_x4.xyzw_, _MM_SHUFFLE(1, 1, 1, 1));
        Result = _mm_fmadd_ps(Result, x2, vConstants);

        vConstants = _mm_permute_ps(cos_coefficient_s0_x4.xyzw_, _MM_SHUFFLE(0, 0, 0, 0));
        Result = _mm_fmadd_ps(Result, x2, vConstants);

        Result = _mm_fmadd_ps(Result, x2, simd_f32x4_1111);
        Result = _mm_mul_ps(Result, sign.ab_);
        return Result;
#else
        return {

            data2_cos(a.a),
            data2_cos(a.b)

        };
#endif
    }

    NCPP_FORCE_INLINE void NCPP_VECTOR_CALL data2x2_sin_cos(PA_data2x2_f32 a, F_data2x2_f32& out_sin, F_data2x2_f32& out_cos) noexcept {

#ifdef NCPP_ENABLE_SSE    // Force the value within the bounds of pi
        F_data2x2_f32 x = data2x2_mod_angles(a.ab_);

        // Map in [-pi/2,pi/2] with sin(y) = sin(x), cos(y) = sign*cos(x).
        F_data2x2_f32 sign = _mm_and_ps(x.ab_, negative_zero_x4.xyzw_);
        __m128 c = _mm_or_ps(pi_x4.xyzw_, sign.ab_);  // pi when x >= 0, -pi when x < 0
        __m128 absx = _mm_andnot_ps(sign.ab_, x.ab_);  // |x|
        __m128 rflx = _mm_sub_ps(c, x.ab_);
        __m128 comp = _mm_cmple_ps(absx, half_pi_x4.xyzw_);
        __m128 select0 = _mm_and_ps(comp, x.ab_);
        __m128 select1 = _mm_andnot_ps(comp, rflx);
        x = _mm_or_ps(select0, select1);
        select0 = _mm_and_ps(comp, simd_f32x4_1111);
        select1 = _mm_andnot_ps(comp, simd_f32x4_1111_negative);
        sign = _mm_or_ps(select0, select1);

        __m128 x2 = _mm_mul_ps(x.ab_, x.ab_);

        // Compute polynomial approximation of sine
        __m128 vConstantsB = _mm_permute_ps(sin_coefficient_s1_x4.xyzw_, _MM_SHUFFLE(0, 0, 0, 0));
        __m128 vConstants = _mm_permute_ps(sin_coefficient_s0_x4.xyzw_, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 Result = _mm_fmadd_ps(vConstantsB, x2, vConstants);

        vConstants = _mm_permute_ps(sin_coefficient_s0_x4.xyzw_, _MM_SHUFFLE(2, 2, 2, 2));
        Result = _mm_fmadd_ps(Result, x2, vConstants);

        vConstants = _mm_permute_ps(sin_coefficient_s0_x4.xyzw_, _MM_SHUFFLE(1, 1, 1, 1));
        Result = _mm_fmadd_ps(Result, x2, vConstants);

        vConstants = _mm_permute_ps(sin_coefficient_s0_x4.xyzw_, _MM_SHUFFLE(0, 0, 0, 0));
        Result = _mm_fmadd_ps(Result, x2, vConstants);

        Result = _mm_fmadd_ps(Result, x2, simd_f32x4_1111);
        Result = _mm_mul_ps(Result, x.ab_);
        out_sin = Result;

        // Compute polynomial approximation of cosine
        vConstantsB = _mm_permute_ps(cos_coefficient_s1_x4.xyzw_, _MM_SHUFFLE(0, 0, 0, 0));
        vConstants = _mm_permute_ps(cos_coefficient_s0_x4.xyzw_, _MM_SHUFFLE(3, 3, 3, 3));
        Result = _mm_fmadd_ps(vConstantsB, x2, vConstants);

        vConstants = _mm_permute_ps(cos_coefficient_s0_x4.xyzw_, _MM_SHUFFLE(2, 2, 2, 2));
        Result = _mm_fmadd_ps(Result, x2, vConstants);

        vConstants = _mm_permute_ps(cos_coefficient_s0_x4.xyzw_, _MM_SHUFFLE(1, 1, 1, 1));
        Result = _mm_fmadd_ps(Result, x2, vConstants);

        vConstants = _mm_permute_ps(cos_coefficient_s0_x4.xyzw_, _MM_SHUFFLE(0, 0, 0, 0));
        Result = _mm_fmadd_ps(Result, x2, vConstants);

        Result = _mm_fmadd_ps(Result, x2, simd_f32x4_1111);
        Result = _mm_mul_ps(Result, sign.ab_);
        out_cos = Result;
#else
        out_sin = data2x2_sin(a);
        out_cos = data2x2_cos(a);
#endif
    }

}
