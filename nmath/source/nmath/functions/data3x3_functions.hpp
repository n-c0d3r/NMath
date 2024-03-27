#pragma once

/** @file nmath/functions/data3x3_functions.hpp
*
*   Implement data3x3 functions.
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

#include <nmath/types/data3x3.hpp>
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
    F_data3x3_f32 NMATH_CALL_CNV data3x3_minus(PA_data3x3_f32 a) noexcept;

    F_data3x3_f32 NMATH_CALL_CNV data3x3_multiply(PA_data3x3_f32 a, f32 b) noexcept;
    F_data3x3_f32 NMATH_CALL_CNV data3x3_divide(PA_data3x3_f32 a, f32 b) noexcept;

    F_data3x3_f32 NMATH_CALL_CNV data3x3_add(PA_data3x3_f32 a, PA_data3x3_f32 b) noexcept;
    F_data3x3_f32 NMATH_CALL_CNV data3x3_subtract(PA_data3x3_f32 a, PA_data3x3_f32 b) noexcept;

    F_data3x3_f32 NMATH_CALL_CNV data3x3_multiply(PA_data3x3_f32 a, PA_data3x3_f32 b) noexcept;
    F_data3x3_f32 NMATH_CALL_CNV data3x3_divide(PA_data3x3_f32 a, PA_data3x3_f32 b) noexcept;

    F_data3x3_f32 NMATH_CALL_CNV data3x3_round(PA_data3x3_f32 a) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  FMA functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data3x3_f32 NMATH_CALL_CNV data3x3_multiply_add(
        PA_data3x3_f32 a,
        PA_data3x3_f32 b,
        PA_data3x3_f32 c
    ) noexcept;

    F_data3x3_f32 NMATH_CALL_CNV data3x3_multiply_addsub(
        PA_data3x3_f32 a,
        PA_data3x3_f32 b,
        PA_data3x3_f32 c
   ) noexcept;

    F_data3x3_f32 NMATH_CALL_CNV data3x3_multiply_sub(
        PA_data3x3_f32 a,
        PA_data3x3_f32 b,
        PA_data3x3_f32 c
    ) noexcept;

    F_data3x3_f32 NMATH_CALL_CNV data3x3_multiply_subadd(
        PA_data3x3_f32 a,
        PA_data3x3_f32 b,
        PA_data3x3_f32 c
   ) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  Trigonometry functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data3x3_f32 NMATH_CALL_CNV data3x3_mod_angles(PA_data3x3_f32 a) noexcept;

    F_data3x3_f32 NMATH_CALL_CNV data3x3_sin(PA_data3x3_f32 a) noexcept;

    F_data3x3_f32 NMATH_CALL_CNV data3x3_cos(PA_data3x3_f32 a) noexcept;

    void NMATH_CALL_CNV data3x3_sin_cos(PA_data3x3_f32 a, F_data3x3_f32& out_sin, F_data3x3_f32& out_cos) noexcept;

}



////////////////////////////////////////////////////////////////////////////////////
//  F32 defines
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    ////////////////////////////////////////////////////////////////////////////////////
    //  Basic arithmetic functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_minus(PA_data3x3_f32 a) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_mul_ps(a.ab_, simd_f32x8_11111111_negative),
            _mm256_mul_ps(a.c_, simd_f32x8_11111111_negative)
            
        };
#else
        return {

            data3_minus(a.a),
            data3_minus(a.b),
            data3_minus(a.c)

        };
#endif
    }

    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_multiply(PA_data3x3_f32 a, f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        __m256 bx8 = _mm256_set1_ps(b);
        
        return {
            
            _mm256_mul_ps(a.ab_, bx8),
            _mm256_mul_ps(a.c_, bx8)
            
        };
#else
        return {

            data3_multiply(a.a, b),
            data3_multiply(a.b, b),
            data3_multiply(a.c, b)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_divide(PA_data3x3_f32 a, f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        __m256 bx8 = _mm256_set1_ps(b);
        
        return {
            
            _mm256_div_ps(a.ab_, bx8),
            _mm256_div_ps(a.c_, bx8)
            
        };
#else
        return {

            data3_divide(a.a, b),
            data3_divide(a.b, b),
            data3_divide(a.c, b)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_add(PA_data3x3_f32 a, PA_data3x3_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_add_ps(a.ab_, b.ab_),
            _mm256_add_ps(a.c_, b.c_)
            
        };
#else
        return {

            data3_add(a.a, b.a),
            data3_add(a.b, b.b),
            data3_add(a.c, b.c)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_subtract(PA_data3x3_f32 a, PA_data3x3_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_sub_ps(a.ab_, b.ab_),
            _mm256_sub_ps(a.c_, b.c_)
            
        };
#else
        return {

            data3_subtract(a.a, b.a),
            data3_subtract(a.b, b.b),
            data3_subtract(a.c, b.c)

        };
#endif
    }

    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_multiply(PA_data3x3_f32 a, PA_data3x3_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_mul_ps(a.ab_, b.ab_),
            _mm256_mul_ps(a.c_, b.c_)
            
        };
#else
        return {

            data3_multiply(a.a, b.a),
            data3_multiply(a.b, b.b),
            data3_multiply(a.c, b.c)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_divide(PA_data3x3_f32 a, PA_data3x3_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_div_ps(a.ab_, b.ab_),
            _mm256_div_ps(a.c_, b.c_)
            
        };
#else
        return {

            data3_divide(a.a, b.a),
            data3_divide(a.b, b.b),
            data3_divide(a.c, b.c)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_round(PA_data3x3_f32 a) noexcept {

#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_round_ps(a.ab_, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC),
            _mm256_round_ps(a.c_, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)
            
        };
#else
        return {

            data3_round(a.a),
            data3_round(a.b),
            data3_round(a.c)

        };
#endif
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  FMA functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_multiply_add(
        PA_data3x3_f32 a,
        PA_data3x3_f32 b,
        PA_data3x3_f32 c
    ) noexcept {
                   
#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_fmadd_ps(a.ab_, b.ab_, c.ab_),
            _mm256_fmadd_ps(a.c_, b.c_, c.c_)
            
        };
#else
        return {
          
            data3_multiply_add(a.a, b.a, c.a),
            data3_multiply_add(a.b, b.b, c.b),
            data3_multiply_add(a.c, b.c, c.c)
            
        };
#endif
        
    }
    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_multiply_addsub(
        PA_data3x3_f32 a,
        PA_data3x3_f32 b,
        PA_data3x3_f32 c
   ) noexcept {
        
#ifdef NCPP_ENABLE_AVX
       return {
           
           _mm256_fmsubadd_ps(a.ab_, b.ab_, c.ab_),
           _mm256_fmsubadd_ps(a.c_, b.c_, c.c_)
           
       };
#else
        return {
          
            data3_multiply_addsub(a.a, b.a, c.a),
            data3_multiply_addsub(a.b, b.b, c.b),
            data3_multiply_addsub(a.c, b.c, c.c)
            
        };
#endif
        
    }
    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_multiply_sub(
        PA_data3x3_f32 a,
        PA_data3x3_f32 b,
        PA_data3x3_f32 c
    ) noexcept {
    
#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_fmsub_ps(a.ab_, b.ab_, c.ab_),
            _mm256_fmsub_ps(a.c_, b.c_, c.c_)
            
        };
#else
        return {
          
            data3_multiply_sub(a.a, b.a, c.a),
            data3_multiply_sub(a.b, b.b, c.b),
            data3_multiply_sub(a.c, b.c, c.c)
            
        };
#endif
        
    }
    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_multiply_subadd(
        PA_data3x3_f32 a,
        PA_data3x3_f32 b,
        PA_data3x3_f32 c
   ) noexcept {
    
#ifdef NCPP_ENABLE_AVX
       return {
           
           _mm256_fmaddsub_ps(a.ab_, b.ab_, c.ab_),
           _mm256_fmaddsub_ps(a.c_, b.c_, c.c_)
           
       };
#else
        return {
          
            data3_multiply_subadd(a.a, b.a, c.a),
            data3_multiply_subadd(a.b, b.b, c.b),
            data3_multiply_subadd(a.c, b.c, c.c)
            
        };
#endif
        
    }
    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_negative_multiply_add(
        PA_data3x3_f32 a,
        PA_data3x3_f32 b,
        PA_data3x3_f32 c
    ) noexcept {

#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_fnmadd_ps(a.ab_, b.ab_, c.ab_),
            _mm256_fnmadd_ps(a.c_, b.c_, c.c_)
            
        };
#else
        return {

            data3_negative_multiply_add(a.a, b.a, c.a),
            data3_negative_multiply_add(a.b, b.b, c.b),
            data3_negative_multiply_add(a.c, b.c, c.c)

        };
#endif

    }
    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_negative_multiply_sub(
        PA_data3x3_f32 a,
        PA_data3x3_f32 b,
        PA_data3x3_f32 c
    ) noexcept {

#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_fnmsub_ps(a.ab_, b.ab_, c.ab_),
            _mm256_fnmsub_ps(a.c_, b.c_, c.c_)
            
        };
#else
        return {

            data3_negative_multiply_sub(a.a, b.a, c.a),
            data3_negative_multiply_sub(a.b, b.b, c.b),
            data3_negative_multiply_sub(a.c, b.c, c.c)

        };
#endif

    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Trigonometry functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_mod_angles(PA_data3x3_f32 a) noexcept {

#ifdef NCPP_ENABLE_AVX
        F_data3x3_f32 vResult = {
            
            _mm256_mul_ps(a.ab_, reciprocal_two_pi_f32x4x4.ab_),
            _mm256_mul_ps(a.c_, reciprocal_two_pi_f32x4x4.ab_)
            
        };
        // Use the inline function due to complexity for rounding
        vResult = data3x3_round(vResult);
        return {
            
            _mm256_fnmadd_ps(vResult.ab_, two_pi_f32x4x4.ab_, a.ab_),
            _mm256_fnmadd_ps(vResult.c_, two_pi_f32x4x4.cd_, a.c_)
            
        };
#else
        F_data3x3_f32 V;
        F_data3x3_f32 Result;

        // Modulo the range of the given angles such that -XM_PI <= Angles < XM_PI
        V.a = data3_multiply(a.a, reciprocal_two_pi_f32x3);
        V.b = data3_multiply(a.b, reciprocal_two_pi_f32x3);
        V.c = data3_multiply(a.c, reciprocal_two_pi_f32x3);
        V = data3x3_round(V);
        Result = data3x3_negative_multiply_sub( two_pi_f32x3x3, V, a);
        return Result;
#endif
    }

    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_sin(PA_data3x3_f32 a) noexcept {

#ifdef NCPP_ENABLE_AVX
        // Assuming 'a' is your input of type F_data3x3_f32
        F_data3x3_f32 x = data3x3_mod_angles(a);

        // Map in [-pi/2,pi/2] with sin(y) = sin(x).
        __m256 sign_ab = _mm256_and_ps(x.ab_, negative_zero_f32x4x4.ab_);
        __m256 sign_c = _mm256_and_ps(x.c_, negative_zero_f32x4x4.cd_);
        __m256 c_ab = _mm256_or_ps(two_pi_f32x4x4.ab_, sign_ab);  // pi when x >= 0, -pi when x < 0
        __m256 c_c = _mm256_or_ps(two_pi_f32x4x4.cd_, sign_c);  // pi when x >= 0, -pi when x < 0
        __m256 absx_ab = _mm256_andnot_ps(sign_ab, x.ab_);  // |x|
        __m256 absx_c = _mm256_andnot_ps(sign_c, x.c_);  // |x|
        __m256 rflx_ab = _mm256_sub_ps(c_ab, x.ab_);
        __m256 rflx_c = _mm256_sub_ps(c_c, x.c_);
        __m256 comp_ab = _mm256_cmp_ps(absx_ab, half_pi_f32x4x4.ab_, _CMP_LE_OS);
        __m256 comp_c = _mm256_cmp_ps(absx_c, half_pi_f32x4x4.cd_, _CMP_LE_OS);
        __m256 select0_ab = _mm256_and_ps(comp_ab, x.ab_);
        __m256 select0_c = _mm256_and_ps(comp_c, x.c_);
        __m256 select1_ab = _mm256_andnot_ps(comp_ab, rflx_ab);
        __m256 select1_c = _mm256_andnot_ps(comp_c, rflx_c);
        x.ab_ = _mm256_or_ps(select0_ab, select1_ab);
        x.c_ = _mm256_or_ps(select0_c, select1_c);

        __m256 x2_ab = _mm256_mul_ps(x.ab_, x.ab_);
        __m256 x2_c = _mm256_mul_ps(x.c_, x.c_);

        // Compute polynomial approximation
        __m256 vConstantsB_ab = _mm256_permute_ps(sin_coefficient_s1_f32x4x4.ab_, _MM_SHUFFLE(0, 0, 0, 0));
        __m256 vConstantsB_c = _mm256_permute_ps(sin_coefficient_s1_f32x4x4.cd_, _MM_SHUFFLE(0, 0, 0, 0));
        __m256 vConstants_ab = _mm256_permute_ps(sin_coefficient_s0_f32x4x4.ab_, _MM_SHUFFLE(3, 3, 3, 3));
        __m256 vConstants_c = _mm256_permute_ps(sin_coefficient_s0_f32x4x4.cd_, _MM_SHUFFLE(3, 3, 3, 3));
        __m256 Result_ab = _mm256_fmadd_ps(vConstantsB_ab, x2_ab, vConstants_ab);
        __m256 Result_c = _mm256_fmadd_ps(vConstantsB_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(sin_coefficient_s0_f32x4x4.ab_, _MM_SHUFFLE(2, 2, 2, 2));
        vConstants_c = _mm256_permute_ps(sin_coefficient_s0_f32x4x4.cd_, _MM_SHUFFLE(2, 2, 2, 2));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(sin_coefficient_s0_f32x4x4.ab_, _MM_SHUFFLE(1, 1, 1, 1));
        vConstants_c = _mm256_permute_ps(sin_coefficient_s0_f32x4x4.cd_, _MM_SHUFFLE(1, 1, 1, 1));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(sin_coefficient_s0_f32x4x4.ab_, _MM_SHUFFLE(0, 0, 0, 0));
        vConstants_c = _mm256_permute_ps(sin_coefficient_s0_f32x4x4.cd_, _MM_SHUFFLE(0, 0, 0, 0));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, simd_f32x8_11111111);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, simd_f32x8_11111111);
        Result_ab = _mm256_mul_ps(Result_ab, x.ab_);
        Result_c = _mm256_mul_ps(Result_c, x.c_);

        return { Result_ab, Result_c };
#else
        return {

            data3_sin(a.a),
            data3_sin(a.b),
            data3_sin(a.c)

        };
#endif
    }

    NCPP_FORCE_INLINE F_data3x3_f32 NMATH_CALL_CNV data3x3_cos(PA_data3x3_f32 a) noexcept {

#ifdef NCPP_ENABLE_AVX
        // Assuming 'a' is your input of type F_data3x3_f32
        F_data3x3_f32 x = data3x3_mod_angles(a);

        // Map in [-pi/2,pi/2] with cos(y) = sign*cos(x).
        F_data3x3_f32 sign = {_mm256_and_ps(x.ab_, negative_zero_f32x4x4.ab_), _mm256_and_ps(x.c_, negative_zero_f32x4x4.cd_)};
        __m256 c_ab = _mm256_or_ps(pi_f32x4x4.ab_, sign.ab_);  // pi when x >= 0, -pi when x < 0
        __m256 c_c = _mm256_or_ps(pi_f32x4x4.cd_, sign.c_);  // pi when x >= 0, -pi when x < 0
        __m256 absx_ab = _mm256_andnot_ps(sign.ab_, x.ab_);  // |x|
        __m256 absx_c = _mm256_andnot_ps(sign.c_, x.c_);  // |x|
        __m256 rflx_ab = _mm256_sub_ps(c_ab, x.ab_);
        __m256 rflx_c = _mm256_sub_ps(c_c, x.c_);
        __m256 comp_ab = _mm256_cmp_ps(absx_ab, half_pi_f32x4x4.ab_, _CMP_LE_OS);
        __m256 comp_c = _mm256_cmp_ps(absx_c, half_pi_f32x4x4.cd_, _CMP_LE_OS);
        __m256 select0_ab = _mm256_and_ps(comp_ab, x.ab_);
        __m256 select0_c = _mm256_and_ps(comp_c, x.c_);
        __m256 select1_ab = _mm256_andnot_ps(comp_ab, rflx_ab);
        __m256 select1_c = _mm256_andnot_ps(comp_c, rflx_c);
        x.ab_ = _mm256_or_ps(select0_ab, select1_ab);
        x.c_ = _mm256_or_ps(select0_c, select1_c);
        select0_ab = _mm256_and_ps(comp_ab, simd_f32x8_11111111);
        select0_c = _mm256_and_ps(comp_c, simd_f32x8_11111111);
        select1_ab = _mm256_andnot_ps(comp_ab, simd_f32x8_11111111_negative);
        select1_c = _mm256_andnot_ps(comp_c, simd_f32x8_11111111_negative);
        sign.ab_ = _mm256_or_ps(select0_ab, select1_ab);
        sign.c_ = _mm256_or_ps(select0_c, select1_c);

        __m256 x2_ab = _mm256_mul_ps(x.ab_, x.ab_);
        __m256 x2_c = _mm256_mul_ps(x.c_, x.c_);

        // Compute polynomial approximation
        __m256 vConstantsB_ab = _mm256_permute_ps(cos_coefficient_s1_f32x4x4.ab_, _MM_SHUFFLE(0, 0, 0, 0));
        __m256 vConstantsB_c = _mm256_permute_ps(cos_coefficient_s1_f32x4x4.cd_, _MM_SHUFFLE(0, 0, 0, 0));
        __m256 vConstants_ab = _mm256_permute_ps(cos_coefficient_s0_f32x4x4.ab_, _MM_SHUFFLE(3, 3, 3, 3));
        __m256 vConstants_c = _mm256_permute_ps(cos_coefficient_s0_f32x4x4.cd_, _MM_SHUFFLE(3, 3, 3, 3));
        __m256 Result_ab = _mm256_fmadd_ps(vConstantsB_ab, x2_ab, vConstants_ab);
        __m256 Result_c = _mm256_fmadd_ps(vConstantsB_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(cos_coefficient_s0_f32x4x4.ab_, _MM_SHUFFLE(2, 2, 2, 2));
        vConstants_c = _mm256_permute_ps(cos_coefficient_s0_f32x4x4.cd_, _MM_SHUFFLE(2, 2, 2, 2));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(cos_coefficient_s0_f32x4x4.ab_, _MM_SHUFFLE(1, 1, 1, 1));
        vConstants_c = _mm256_permute_ps(cos_coefficient_s0_f32x4x4.cd_, _MM_SHUFFLE(1, 1, 1, 1));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(cos_coefficient_s0_f32x4x4.ab_, _MM_SHUFFLE(0, 0, 0, 0));
        vConstants_c = _mm256_permute_ps(cos_coefficient_s0_f32x4x4.cd_, _MM_SHUFFLE(0, 0, 0, 0));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, simd_f32x8_11111111);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, simd_f32x8_11111111);
        Result_ab = _mm256_mul_ps(Result_ab, sign.ab_);
        Result_c = _mm256_mul_ps(Result_c, sign.c_);

        return { Result_ab, Result_c };
#else
        return {

            data3_cos(a.a),
            data3_cos(a.b),
            data3_cos(a.c)

        };
#endif
    }

    NCPP_FORCE_INLINE void NMATH_CALL_CNV data3x3_sin_cos(PA_data3x3_f32 a, F_data3x3_f32& out_sin, F_data3x3_f32& out_cos) noexcept {

#ifdef NCPP_ENABLE_AVX    // Force the value within the bounds of pi
        // Assuming 'a' is your input of type F_data3x3_f32
        F_data3x3_f32 x = data3x3_mod_angles(a);

        // Map in [-pi/2,pi/2] with sin(y) = sin(x), cos(y) = sign*cos(x).
        F_data3x3_f32 sign = {_mm256_and_ps(x.ab_, negative_zero_f32x4x4.ab_), _mm256_and_ps(x.c_, negative_zero_f32x4x4.cd_)};
        __m256 c_ab = _mm256_or_ps(pi_f32x4x4.ab_, sign.ab_);  // pi when x >= 0, -pi when x < 0
        __m256 c_c = _mm256_or_ps(pi_f32x4x4.cd_, sign.c_);  // pi when x >= 0, -pi when x < 0
        __m256 absx_ab = _mm256_andnot_ps(sign.ab_, x.ab_);  // |x|
        __m256 absx_c = _mm256_andnot_ps(sign.c_, x.c_);  // |x|
        __m256 rflx_ab = _mm256_sub_ps(c_ab, x.ab_);
        __m256 rflx_c = _mm256_sub_ps(c_c, x.c_);
        __m256 comp_ab = _mm256_cmp_ps(absx_ab, half_pi_f32x4x4.ab_, _CMP_LE_OS);
        __m256 comp_c = _mm256_cmp_ps(absx_c, half_pi_f32x4x4.cd_, _CMP_LE_OS);
        __m256 select0_ab = _mm256_and_ps(comp_ab, x.ab_);
        __m256 select0_c = _mm256_and_ps(comp_c, x.c_);
        __m256 select1_ab = _mm256_andnot_ps(comp_ab, rflx_ab);
        __m256 select1_c = _mm256_andnot_ps(comp_c, rflx_c);
        x.ab_ = _mm256_or_ps(select0_ab, select1_ab);
        x.c_ = _mm256_or_ps(select0_c, select1_c);
        select0_ab = _mm256_and_ps(comp_ab, simd_f32x8_11111111);
        select0_c = _mm256_and_ps(comp_c, simd_f32x8_11111111);
        select1_ab = _mm256_andnot_ps(comp_ab, simd_f32x8_11111111_negative);
        select1_c = _mm256_andnot_ps(comp_c, simd_f32x8_11111111_negative);
        sign.ab_ = _mm256_or_ps(select0_ab, select1_ab);
        sign.c_ = _mm256_or_ps(select0_c, select1_c);

        __m256 x2_ab = _mm256_mul_ps(x.ab_, x.ab_);
        __m256 x2_c = _mm256_mul_ps(x.c_, x.c_);

        // Compute polynomial approximation of sine
        __m256 vConstantsB_ab = _mm256_permute_ps(sin_coefficient_s1_f32x4x4.ab_, _MM_SHUFFLE(0, 0, 0, 0));
        __m256 vConstantsB_c = _mm256_permute_ps(sin_coefficient_s1_f32x4x4.cd_, _MM_SHUFFLE(0, 0, 0, 0));
        __m256 vConstants_ab = _mm256_permute_ps(sin_coefficient_s0_f32x4x4.ab_, _MM_SHUFFLE(3, 3, 3, 3));
        __m256 vConstants_c = _mm256_permute_ps(sin_coefficient_s0_f32x4x4.cd_, _MM_SHUFFLE(3, 3, 3, 3));
        __m256 Result_ab = _mm256_fmadd_ps(vConstantsB_ab, x2_ab, vConstants_ab);
        __m256 Result_c = _mm256_fmadd_ps(vConstantsB_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(sin_coefficient_s0_f32x4x4.ab_, _MM_SHUFFLE(2, 2, 2, 2));
        vConstants_c = _mm256_permute_ps(sin_coefficient_s0_f32x4x4.cd_, _MM_SHUFFLE(2, 2, 2, 2));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(sin_coefficient_s0_f32x4x4.ab_, _MM_SHUFFLE(1, 1, 1, 1));
        vConstants_c = _mm256_permute_ps(sin_coefficient_s0_f32x4x4.cd_, _MM_SHUFFLE(1, 1, 1, 1));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(sin_coefficient_s0_f32x4x4.ab_, _MM_SHUFFLE(0, 0, 0, 0));
        vConstants_c = _mm256_permute_ps(sin_coefficient_s0_f32x4x4.cd_, _MM_SHUFFLE(0, 0, 0, 0));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, simd_f32x8_11111111);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, simd_f32x8_11111111);
        Result_ab = _mm256_mul_ps(Result_ab, x.ab_);
        Result_c = _mm256_mul_ps(Result_c, x.c_);
        
        out_sin = {Result_ab, Result_c};

        // Compute polynomial approximation of cosine
        vConstantsB_ab = _mm256_permute_ps(cos_coefficient_s1_f32x4x4.ab_, _MM_SHUFFLE(0, 0, 0, 0));
        vConstantsB_c = _mm256_permute_ps(cos_coefficient_s1_f32x4x4.cd_, _MM_SHUFFLE(0, 0, 0, 0));
        vConstants_ab = _mm256_permute_ps(cos_coefficient_s0_f32x4x4.ab_, _MM_SHUFFLE(3, 3, 3, 3));
        vConstants_c = _mm256_permute_ps(cos_coefficient_s0_f32x4x4.cd_, _MM_SHUFFLE(3, 3, 3, 3));
        Result_ab = _mm256_fmadd_ps(vConstantsB_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(vConstantsB_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(cos_coefficient_s0_f32x4x4.ab_, _MM_SHUFFLE(2, 2, 2, 2));
        vConstants_c = _mm256_permute_ps(cos_coefficient_s0_f32x4x4.cd_, _MM_SHUFFLE(2, 2, 2, 2));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(cos_coefficient_s0_f32x4x4.ab_, _MM_SHUFFLE(1, 1, 1, 1));
        vConstants_c = _mm256_permute_ps(cos_coefficient_s0_f32x4x4.cd_, _MM_SHUFFLE(1, 1, 1, 1));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(cos_coefficient_s0_f32x4x4.ab_, _MM_SHUFFLE(0, 0, 0, 0));
        vConstants_c = _mm256_permute_ps(cos_coefficient_s0_f32x4x4.cd_, _MM_SHUFFLE(0, 0, 0, 0));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, simd_f32x8_11111111);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, simd_f32x8_11111111);
        Result_ab = _mm256_mul_ps(Result_ab, sign.ab_);
        Result_c = _mm256_mul_ps(Result_c, sign.c_);
        
        out_cos = {Result_ab, Result_c};
#else
        out_sin = data3x3_sin(a);
        out_cos = data3x3_cos(a);
#endif
    }

}
