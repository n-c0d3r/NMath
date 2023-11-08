#pragma once

/** @file nmath/functions/data4x4_functions.hpp
*
*   Implement data4x4 functions.
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

#include <nmath/types/data4x4.hpp>
#include <nmath/types/data_constants.hpp>
#include <nmath/types/data_helper.hpp>
#include <nmath/utilities/basic_arithmetic.hpp>

#include <nmath/functions/data4_functions.hpp>

#pragma endregion



////////////////////////////////////////////////////////////////////////////////////
//  F32 declares
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    ////////////////////////////////////////////////////////////////////////////////////
    //  Basic arithmetic functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data4x4_f32 NCPP_VECTOR_CALL data4x4_minus(PA_data4x4_f32 a) noexcept;

    F_data4x4_f32 NCPP_VECTOR_CALL data4x4_multiply(PA_data4x4_f32 a, f32 b) noexcept;
    F_data4x4_f32 NCPP_VECTOR_CALL data4x4_divide(PA_data4x4_f32 a, f32 b) noexcept;

    F_data4x4_f32 NCPP_VECTOR_CALL data4x4_add(PA_data4x4_f32 a, PA_data4x4_f32 b) noexcept;
    F_data4x4_f32 NCPP_VECTOR_CALL data4x4_subtract(PA_data4x4_f32 a, PA_data4x4_f32 b) noexcept;

    F_data4x4_f32 NCPP_VECTOR_CALL data4x4_multiply(PA_data4x4_f32 a, PA_data4x4_f32 b) noexcept;
    F_data4x4_f32 NCPP_VECTOR_CALL data4x4_divide(PA_data4x4_f32 a, PA_data4x4_f32 b) noexcept;

    F_data4x4_f32 NCPP_VECTOR_CALL data4x4_round(PA_data4x4_f32 a) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  FMA functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data4x4_f32 NCPP_VECTOR_CALL data4x4_multiply_add(
        PA_data4x4_f32 a,
        PA_data4x4_f32 b,
        PA_data4x4_f32 c
    ) noexcept;

    F_data4x4_f32 NCPP_VECTOR_CALL data4x4_multiply_addsub(
        PA_data4x4_f32 a,
        PA_data4x4_f32 b,
        PA_data4x4_f32 c
   ) noexcept;

    F_data4x4_f32 NCPP_VECTOR_CALL data4x4_multiply_sub(
        PA_data4x4_f32 a,
        PA_data4x4_f32 b,
        PA_data4x4_f32 c
    ) noexcept;

    F_data4x4_f32 NCPP_VECTOR_CALL data4x4_multiply_subadd(
        PA_data4x4_f32 a,
        PA_data4x4_f32 b,
        PA_data4x4_f32 c
   ) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  Trigonometry functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data4x4_f32 NCPP_VECTOR_CALL data4x4_mod_angles(PA_data4x4_f32 a) noexcept;

    F_data4x4_f32 NCPP_VECTOR_CALL data4x4_sin(PA_data4x4_f32 a) noexcept;

    F_data4x4_f32 NCPP_VECTOR_CALL data4x4_cos(PA_data4x4_f32 a) noexcept;

    void NCPP_VECTOR_CALL data4x4_sin_cos(PA_data4x4_f32 a, F_data4x4_f32& out_sin, F_data4x4_f32& out_cos) noexcept;

}



////////////////////////////////////////////////////////////////////////////////////
//  F32 defines
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    ////////////////////////////////////////////////////////////////////////////////////
    //  Basic arithmetic functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_minus(PA_data4x4_f32 a) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_mul_ps(a.ab_, simd_f32x8_11111111_negative),
            _mm256_mul_ps(a.cd_, simd_f32x8_11111111_negative)
            
        };
#else
        return {

            data4_minus(a.a),
            data4_minus(a.b),
            data4_minus(a.c),
            data4_minus(a.d)

        };
#endif
    }

    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_multiply(PA_data4x4_f32 a, f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        __m256 bx8 = _mm256_set1_ps(b);
        
        return {
            
            _mm256_mul_ps(a.ab_, bx8),
            _mm256_mul_ps(a.cd_, bx8)
            
        };
#else
        return {

            data4_multiply(a.a, b),
            data4_multiply(a.b, b),
            data4_multiply(a.c, b),
            data4_multiply(a.d, b)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_divide(PA_data4x4_f32 a, f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        __m256 bx8 = _mm256_set1_ps(b);
        
        return {
            
            _mm256_div_ps(a.ab_, bx8),
            _mm256_div_ps(a.cd_, bx8)
            
        };
#else
        return {

            data4_divide(a.a, b),
            data4_divide(a.b, b),
            data4_divide(a.c, b),
            data4_divide(a.d, b)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_add(PA_data4x4_f32 a, PA_data4x4_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_add_ps(a.ab_, b.ab_),
            _mm256_add_ps(a.cd_, b.cd_)
            
        };
#else
        return {

            data4_add(a.a, b.a),
            data4_add(a.b, b.b),
            data4_add(a.c, b.c),
            data4_add(a.d, b.d)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_subtract(PA_data4x4_f32 a, PA_data4x4_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_sub_ps(a.ab_, b.ab_),
            _mm256_sub_ps(a.cd_, b.cd_)
            
        };
#else
        return {

            data4_subtract(a.a, b.a),
            data4_subtract(a.b, b.b),
            data4_subtract(a.c, b.c),
            data4_subtract(a.d, b.d)

        };
#endif
    }

    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_multiply(PA_data4x4_f32 a, PA_data4x4_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_mul_ps(a.ab_, b.ab_),
            _mm256_mul_ps(a.cd_, b.cd_)
            
        };
#else
        return {

            data4_multiply(a.a, b.a),
            data4_multiply(a.b, b.b),
            data4_multiply(a.c, b.c),
            data4_multiply(a.d, b.d)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_divide(PA_data4x4_f32 a, PA_data4x4_f32 b) noexcept
    {

#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_div_ps(a.ab_, b.ab_),
            _mm256_div_ps(a.cd_, b.cd_)
            
        };
#else
        return {

            data4_divide(a.a, b.a),
            data4_divide(a.b, b.b),
            data4_divide(a.c, b.c),
            data4_divide(a.d, b.d)

        };
#endif
    }
    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_round(PA_data4x4_f32 a) noexcept {

#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_round_ps(a.ab_, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC),
            _mm256_round_ps(a.cd_, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)
            
        };
#else
        return {

            data4_round(a.a),
            data4_round(a.b),
            data4_round(a.c),
            data4_round(a.d)

        };
#endif
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  FMA functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_multiply_add(
        PA_data4x4_f32 a,
        PA_data4x4_f32 b,
        PA_data4x4_f32 c
    ) noexcept {
                   
#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_fmadd_ps(a.ab_, b.ab_, c.ab_),
            _mm256_fmadd_ps(a.cd_, b.cd_, c.cd_)
            
        };
#else
        return {
          
            data4_multiply_add(a.a, b.a, c.a),
            data4_multiply_add(a.b, b.b, c.b),
            data4_multiply_add(a.c, b.c, c.c),
            data4_multiply_add(a.d, b.d, c.d)
            
        };
#endif
        
    }
    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_multiply_addsub(
        PA_data4x4_f32 a,
        PA_data4x4_f32 b,
        PA_data4x4_f32 c
   ) noexcept {
        
#ifdef NCPP_ENABLE_AVX
       return {
           
           _mm256_fmsubadd_ps(a.ab_, b.ab_, c.ab_),
           _mm256_fmsubadd_ps(a.cd_, b.cd_, c.cd_)
           
       };
#else
        return {
          
            data4_multiply_addsub(a.a, b.a, c.a),
            data4_multiply_addsub(a.b, b.b, c.b),
            data4_multiply_addsub(a.c, b.c, c.c),
            data4_multiply_addsub(a.d, b.d, c.d)
            
        };
#endif
        
    }
    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_multiply_sub(
        PA_data4x4_f32 a,
        PA_data4x4_f32 b,
        PA_data4x4_f32 c
    ) noexcept {
    
#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_fmsub_ps(a.ab_, b.ab_, c.ab_),
            _mm256_fmsub_ps(a.cd_, b.cd_, c.cd_)
            
        };
#else
        return {
          
            data4_multiply_sub(a.a, b.a, c.a),
            data4_multiply_sub(a.b, b.b, c.b),
            data4_multiply_sub(a.c, b.c, c.c),
            data4_multiply_sub(a.d, b.d, c.d)
            
        };
#endif
        
    }
    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_multiply_subadd(
        PA_data4x4_f32 a,
        PA_data4x4_f32 b,
        PA_data4x4_f32 c
   ) noexcept {
    
#ifdef NCPP_ENABLE_AVX
       return {
           
           _mm256_fmaddsub_ps(a.ab_, b.ab_, c.ab_),
           _mm256_fmaddsub_ps(a.cd_, b.cd_, c.cd_)
           
       };
#else
        return {
          
            data4_multiply_subadd(a.a, b.a, c.a),
            data4_multiply_subadd(a.b, b.b, c.b),
            data4_multiply_subadd(a.c, b.c, c.c),
            data4_multiply_subadd(a.d, b.d, c.d)
            
        };
#endif
        
    }
    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_negative_multiply_add(
        PA_data4x4_f32 a,
        PA_data4x4_f32 b,
        PA_data4x4_f32 c
    ) noexcept {

#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_fnmadd_ps(a.ab_, b.ab_, c.ab_),
            _mm256_fnmadd_ps(a.cd_, b.cd_, c.cd_)
            
        };
#else
        return {

            data4_negative_multiply_add(a.a, b.a, c.a),
            data4_negative_multiply_add(a.b, b.b, c.b),
            data4_negative_multiply_add(a.c, b.c, c.c),
            data4_negative_multiply_add(a.d, b.d, c.d)

        };
#endif

    }
    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_negative_multiply_sub(
        PA_data4x4_f32 a,
        PA_data4x4_f32 b,
        PA_data4x4_f32 c
    ) noexcept {

#ifdef NCPP_ENABLE_AVX
        return {
            
            _mm256_fnmsub_ps(a.ab_, b.ab_, c.ab_),
            _mm256_fnmsub_ps(a.cd_, b.cd_, c.cd_)
            
        };
#else
        return {

            data4_negative_multiply_sub(a.a, b.a, c.a),
            data4_negative_multiply_sub(a.b, b.b, c.b),
            data4_negative_multiply_sub(a.c, b.c, c.c),
            data4_negative_multiply_sub(a.d, b.d, c.d)

        };
#endif

    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Trigonometry functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_mod_angles(PA_data4x4_f32 a) noexcept {

#ifdef NCPP_ENABLE_AVX
        F_data4x4_f32 vResult = {
            
            _mm256_mul_ps(a.ab_, reciprocal_two_pi_4x4.ab_),
            _mm256_mul_ps(a.cd_, reciprocal_two_pi_4x4.ab_)
            
        };
        // Use the inline function due to complexity for rounding
        vResult = data4x4_round(vResult);
        return {
            
            _mm256_fnmadd_ps(vResult.ab_, two_pi_4x4.ab_, a.ab_),
            _mm256_fnmadd_ps(vResult.cd_, two_pi_4x4.cd_, a.cd_)
            
        };
#else
        F_data4x4_f32 V;
        F_data4x4_f32 Result;

        // Modulo the range of the given angles such that -XM_PI <= Angles < XM_PI
        V.a = data4_multiply(a.a, reciprocal_two_pi_x4);
        V.b = data4_multiply(a.b, reciprocal_two_pi_x4);
        V.c = data4_multiply(a.c, reciprocal_two_pi_x4);
        V.d = data4_multiply(a.d, reciprocal_two_pi_x4);
        V = data4x4_round(V);
        Result = data4x4_negative_multiply_sub(two_pi_4x4, V, a);
        return Result;
#endif
    }

    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_sin(PA_data4x4_f32 a) noexcept {

#ifdef NCPP_ENABLE_AVX
        // Assuming 'a' is your input of type F_data4x4_f32
        F_data4x4_f32 x = data4x4_mod_angles(a);

        // Map in [-pi/2,pi/2] with sin(y) = sin(x).
        __m256 sign_ab = _mm256_and_ps(x.ab_, negative_zero_4x4.ab_);
        __m256 sign_c = _mm256_and_ps(x.cd_, negative_zero_4x4.cd_);
        __m256 c_ab = _mm256_or_ps(two_pi_4x4.ab_, sign_ab);  // pi when x >= 0, -pi when x < 0
        __m256 c_c = _mm256_or_ps(two_pi_4x4.cd_, sign_c);  // pi when x >= 0, -pi when x < 0
        __m256 absx_ab = _mm256_andnot_ps(sign_ab, x.ab_);  // |x|
        __m256 absx_c = _mm256_andnot_ps(sign_c, x.cd_);  // |x|
        __m256 rflx_ab = _mm256_sub_ps(c_ab, x.ab_);
        __m256 rflx_c = _mm256_sub_ps(c_c, x.cd_);
        __m256 comp_ab = _mm256_cmp_ps(absx_ab, half_pi_4x4.ab_, _CMP_LE_OS);
        __m256 comp_c = _mm256_cmp_ps(absx_c, half_pi_4x4.cd_, _CMP_LE_OS);
        __m256 select0_ab = _mm256_and_ps(comp_ab, x.ab_);
        __m256 select0_c = _mm256_and_ps(comp_c, x.cd_);
        __m256 select1_ab = _mm256_andnot_ps(comp_ab, rflx_ab);
        __m256 select1_c = _mm256_andnot_ps(comp_c, rflx_c);
        x.ab_ = _mm256_or_ps(select0_ab, select1_ab);
        x.cd_ = _mm256_or_ps(select0_c, select1_c);

        __m256 x2_ab = _mm256_mul_ps(x.ab_, x.ab_);
        __m256 x2_c = _mm256_mul_ps(x.cd_, x.cd_);

        // Compute polynomial approximation
        __m256 vConstantsB_ab = _mm256_permute_ps(sin_coefficient_s1_4x4.ab_, _MM_SHUFFLE(0, 0, 0, 0));
        __m256 vConstantsB_c = _mm256_permute_ps(sin_coefficient_s1_4x4.cd_, _MM_SHUFFLE(0, 0, 0, 0));
        __m256 vConstants_ab = _mm256_permute_ps(sin_coefficient_s0_4x4.ab_, _MM_SHUFFLE(3, 3, 3, 3));
        __m256 vConstants_c = _mm256_permute_ps(sin_coefficient_s0_4x4.cd_, _MM_SHUFFLE(3, 3, 3, 3));
        __m256 Result_ab = _mm256_fmadd_ps(vConstantsB_ab, x2_ab, vConstants_ab);
        __m256 Result_c = _mm256_fmadd_ps(vConstantsB_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(sin_coefficient_s0_4x4.ab_, _MM_SHUFFLE(2, 2, 2, 2));
        vConstants_c = _mm256_permute_ps(sin_coefficient_s0_4x4.cd_, _MM_SHUFFLE(2, 2, 2, 2));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(sin_coefficient_s0_4x4.ab_, _MM_SHUFFLE(1, 1, 1, 1));
        vConstants_c = _mm256_permute_ps(sin_coefficient_s0_4x4.cd_, _MM_SHUFFLE(1, 1, 1, 1));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(sin_coefficient_s0_4x4.ab_, _MM_SHUFFLE(0, 0, 0, 0));
        vConstants_c = _mm256_permute_ps(sin_coefficient_s0_4x4.cd_, _MM_SHUFFLE(0, 0, 0, 0));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, simd_f32x8_11111111);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, simd_f32x8_11111111);
        Result_ab = _mm256_mul_ps(Result_ab, x.ab_);
        Result_c = _mm256_mul_ps(Result_c, x.cd_);

        return { Result_ab, Result_c };
#else
        return {

            data4_sin(a.a),
            data4_sin(a.b),
            data4_sin(a.c),
            data4_sin(a.d)

        };
#endif
    }

    NCPP_FORCE_INLINE F_data4x4_f32 NCPP_VECTOR_CALL data4x4_cos(PA_data4x4_f32 a) noexcept {

#ifdef NCPP_ENABLE_AVX
        // Assuming 'a' is your input of type F_data4x4_f32
        F_data4x4_f32 x = data4x4_mod_angles(a);

        // Map in [-pi/2,pi/2] with cos(y) = sign*cos(x).
        F_data4x4_f32 sign = {_mm256_and_ps(x.ab_, negative_zero_4x4.ab_), _mm256_and_ps(x.cd_, negative_zero_4x4.cd_)};
        __m256 c_ab = _mm256_or_ps(pi_4x4.ab_, sign.ab_);  // pi when x >= 0, -pi when x < 0
        __m256 c_c = _mm256_or_ps(pi_4x4.cd_, sign.cd_);  // pi when x >= 0, -pi when x < 0
        __m256 absx_ab = _mm256_andnot_ps(sign.ab_, x.ab_);  // |x|
        __m256 absx_c = _mm256_andnot_ps(sign.cd_, x.cd_);  // |x|
        __m256 rflx_ab = _mm256_sub_ps(c_ab, x.ab_);
        __m256 rflx_c = _mm256_sub_ps(c_c, x.cd_);
        __m256 comp_ab = _mm256_cmp_ps(absx_ab, half_pi_4x4.ab_, _CMP_LE_OS);
        __m256 comp_c = _mm256_cmp_ps(absx_c, half_pi_4x4.cd_, _CMP_LE_OS);
        __m256 select0_ab = _mm256_and_ps(comp_ab, x.ab_);
        __m256 select0_c = _mm256_and_ps(comp_c, x.cd_);
        __m256 select1_ab = _mm256_andnot_ps(comp_ab, rflx_ab);
        __m256 select1_c = _mm256_andnot_ps(comp_c, rflx_c);
        x.ab_ = _mm256_or_ps(select0_ab, select1_ab);
        x.cd_ = _mm256_or_ps(select0_c, select1_c);
        select0_ab = _mm256_and_ps(comp_ab, simd_f32x8_11111111);
        select0_c = _mm256_and_ps(comp_c, simd_f32x8_11111111);
        select1_ab = _mm256_andnot_ps(comp_ab, simd_f32x8_11111111_negative);
        select1_c = _mm256_andnot_ps(comp_c, simd_f32x8_11111111_negative);
        sign.ab_ = _mm256_or_ps(select0_ab, select1_ab);
        sign.cd_ = _mm256_or_ps(select0_c, select1_c);

        __m256 x2_ab = _mm256_mul_ps(x.ab_, x.ab_);
        __m256 x2_c = _mm256_mul_ps(x.cd_, x.cd_);

        // Compute polynomial approximation
        __m256 vConstantsB_ab = _mm256_permute_ps(cos_coefficient_s1_4x4.ab_, _MM_SHUFFLE(0, 0, 0, 0));
        __m256 vConstantsB_c = _mm256_permute_ps(cos_coefficient_s1_4x4.cd_, _MM_SHUFFLE(0, 0, 0, 0));
        __m256 vConstants_ab = _mm256_permute_ps(cos_coefficient_s0_4x4.ab_, _MM_SHUFFLE(3, 3, 3, 3));
        __m256 vConstants_c = _mm256_permute_ps(cos_coefficient_s0_4x4.cd_, _MM_SHUFFLE(3, 3, 3, 3));
        __m256 Result_ab = _mm256_fmadd_ps(vConstantsB_ab, x2_ab, vConstants_ab);
        __m256 Result_c = _mm256_fmadd_ps(vConstantsB_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(cos_coefficient_s0_4x4.ab_, _MM_SHUFFLE(2, 2, 2, 2));
        vConstants_c = _mm256_permute_ps(cos_coefficient_s0_4x4.cd_, _MM_SHUFFLE(2, 2, 2, 2));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(cos_coefficient_s0_4x4.ab_, _MM_SHUFFLE(1, 1, 1, 1));
        vConstants_c = _mm256_permute_ps(cos_coefficient_s0_4x4.cd_, _MM_SHUFFLE(1, 1, 1, 1));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(cos_coefficient_s0_4x4.ab_, _MM_SHUFFLE(0, 0, 0, 0));
        vConstants_c = _mm256_permute_ps(cos_coefficient_s0_4x4.cd_, _MM_SHUFFLE(0, 0, 0, 0));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, simd_f32x8_11111111);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, simd_f32x8_11111111);
        Result_ab = _mm256_mul_ps(Result_ab, sign.ab_);
        Result_c = _mm256_mul_ps(Result_c, sign.cd_);

        return { Result_ab, Result_c };
#else
        return {

            data4_cos(a.a),
            data4_cos(a.b),
            data4_cos(a.c),
            data4_cos(a.d)

        };
#endif
    }

    NCPP_FORCE_INLINE void NCPP_VECTOR_CALL data4x4_sin_cos(PA_data4x4_f32 a, F_data4x4_f32& out_sin, F_data4x4_f32& out_cos) noexcept {

#ifdef NCPP_ENABLE_AVX    // Force the value within the bounds of pi
        // Assuming 'a' is your input of type F_data4x4_f32
        F_data4x4_f32 x = data4x4_mod_angles(a);

        // Map in [-pi/2,pi/2] with sin(y) = sin(x), cos(y) = sign*cos(x).
        F_data4x4_f32 sign = {_mm256_and_ps(x.ab_, negative_zero_4x4.ab_), _mm256_and_ps(x.cd_, negative_zero_4x4.cd_)};
        __m256 c_ab = _mm256_or_ps(pi_4x4.ab_, sign.ab_);  // pi when x >= 0, -pi when x < 0
        __m256 c_c = _mm256_or_ps(pi_4x4.cd_, sign.cd_);  // pi when x >= 0, -pi when x < 0
        __m256 absx_ab = _mm256_andnot_ps(sign.ab_, x.ab_);  // |x|
        __m256 absx_c = _mm256_andnot_ps(sign.cd_, x.cd_);  // |x|
        __m256 rflx_ab = _mm256_sub_ps(c_ab, x.ab_);
        __m256 rflx_c = _mm256_sub_ps(c_c, x.cd_);
        __m256 comp_ab = _mm256_cmp_ps(absx_ab, half_pi_4x4.ab_, _CMP_LE_OS);
        __m256 comp_c = _mm256_cmp_ps(absx_c, half_pi_4x4.cd_, _CMP_LE_OS);
        __m256 select0_ab = _mm256_and_ps(comp_ab, x.ab_);
        __m256 select0_c = _mm256_and_ps(comp_c, x.cd_);
        __m256 select1_ab = _mm256_andnot_ps(comp_ab, rflx_ab);
        __m256 select1_c = _mm256_andnot_ps(comp_c, rflx_c);
        x.ab_ = _mm256_or_ps(select0_ab, select1_ab);
        x.cd_ = _mm256_or_ps(select0_c, select1_c);
        select0_ab = _mm256_and_ps(comp_ab, simd_f32x8_11111111);
        select0_c = _mm256_and_ps(comp_c, simd_f32x8_11111111);
        select1_ab = _mm256_andnot_ps(comp_ab, simd_f32x8_11111111_negative);
        select1_c = _mm256_andnot_ps(comp_c, simd_f32x8_11111111_negative);
        sign.ab_ = _mm256_or_ps(select0_ab, select1_ab);
        sign.cd_ = _mm256_or_ps(select0_c, select1_c);

        __m256 x2_ab = _mm256_mul_ps(x.ab_, x.ab_);
        __m256 x2_c = _mm256_mul_ps(x.cd_, x.cd_);

        // Compute polynomial approximation of sine
        __m256 vConstantsB_ab = _mm256_permute_ps(sin_coefficient_s1_4x4.ab_, _MM_SHUFFLE(0, 0, 0, 0));
        __m256 vConstantsB_c = _mm256_permute_ps(sin_coefficient_s1_4x4.cd_, _MM_SHUFFLE(0, 0, 0, 0));
        __m256 vConstants_ab = _mm256_permute_ps(sin_coefficient_s0_4x4.ab_, _MM_SHUFFLE(3, 3, 3, 3));
        __m256 vConstants_c = _mm256_permute_ps(sin_coefficient_s0_4x4.cd_, _MM_SHUFFLE(3, 3, 3, 3));
        __m256 Result_ab = _mm256_fmadd_ps(vConstantsB_ab, x2_ab, vConstants_ab);
        __m256 Result_c = _mm256_fmadd_ps(vConstantsB_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(sin_coefficient_s0_4x4.ab_, _MM_SHUFFLE(2, 2, 2, 2));
        vConstants_c = _mm256_permute_ps(sin_coefficient_s0_4x4.cd_, _MM_SHUFFLE(2, 2, 2, 2));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(sin_coefficient_s0_4x4.ab_, _MM_SHUFFLE(1, 1, 1, 1));
        vConstants_c = _mm256_permute_ps(sin_coefficient_s0_4x4.cd_, _MM_SHUFFLE(1, 1, 1, 1));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(sin_coefficient_s0_4x4.ab_, _MM_SHUFFLE(0, 0, 0, 0));
        vConstants_c = _mm256_permute_ps(sin_coefficient_s0_4x4.cd_, _MM_SHUFFLE(0, 0, 0, 0));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, simd_f32x8_11111111);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, simd_f32x8_11111111);
        Result_ab = _mm256_mul_ps(Result_ab, x.ab_);
        Result_c = _mm256_mul_ps(Result_c, x.cd_);
        
        out_sin = {Result_ab, Result_c};

        // Compute polynomial approximation of cosine
        vConstantsB_ab = _mm256_permute_ps(cos_coefficient_s1_4x4.ab_, _MM_SHUFFLE(0, 0, 0, 0));
        vConstantsB_c = _mm256_permute_ps(cos_coefficient_s1_4x4.cd_, _MM_SHUFFLE(0, 0, 0, 0));
        vConstants_ab = _mm256_permute_ps(cos_coefficient_s0_4x4.ab_, _MM_SHUFFLE(3, 3, 3, 3));
        vConstants_c = _mm256_permute_ps(cos_coefficient_s0_4x4.cd_, _MM_SHUFFLE(3, 3, 3, 3));
        Result_ab = _mm256_fmadd_ps(vConstantsB_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(vConstantsB_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(cos_coefficient_s0_4x4.ab_, _MM_SHUFFLE(2, 2, 2, 2));
        vConstants_c = _mm256_permute_ps(cos_coefficient_s0_4x4.cd_, _MM_SHUFFLE(2, 2, 2, 2));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(cos_coefficient_s0_4x4.ab_, _MM_SHUFFLE(1, 1, 1, 1));
        vConstants_c = _mm256_permute_ps(cos_coefficient_s0_4x4.cd_, _MM_SHUFFLE(1, 1, 1, 1));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        vConstants_ab = _mm256_permute_ps(cos_coefficient_s0_4x4.ab_, _MM_SHUFFLE(0, 0, 0, 0));
        vConstants_c = _mm256_permute_ps(cos_coefficient_s0_4x4.cd_, _MM_SHUFFLE(0, 0, 0, 0));
        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, vConstants_ab);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, vConstants_c);

        Result_ab = _mm256_fmadd_ps(Result_ab, x2_ab, simd_f32x8_11111111);
        Result_c = _mm256_fmadd_ps(Result_c, x2_c, simd_f32x8_11111111);
        Result_ab = _mm256_mul_ps(Result_ab, sign.ab_);
        Result_c = _mm256_mul_ps(Result_c, sign.cd_);
        
        out_cos = {Result_ab, Result_c};
#else
        out_sin = data4x4_sin(a);
        out_cos = data4x4_cos(a);
#endif
    }

}
