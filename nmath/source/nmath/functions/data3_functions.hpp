#pragma once

/** @file nmath/functions/data_functions.hpp
*
*   Implement data functions.
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

#include <nmath/types/data3.hpp>
#include <nmath/types/data4.hpp>
#include <nmath/types/data_constants.hpp>
#include <nmath/types/data_helper.hpp>
#include <nmath/utilities/basic_arithmetic.hpp>

#pragma endregion



////////////////////////////////////////////////////////////////////////////////////
//  D3 selectors
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    static constexpr u32 D3_SELECT_X0 = 0;
    static constexpr u32 D3_SELECT_Y0 = 1;
    static constexpr u32 D3_SELECT_Z0 = 2;

    static constexpr u32 D3_SELECT_X1 = 4;
    static constexpr u32 D3_SELECT_Y1 = 5;
    static constexpr u32 D3_SELECT_Z1 = 6;

}



////////////////////////////////////////////////////////////////////////////////////
//  F32 declares
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    ////////////////////////////////////////////////////////////////////////////////////
    //  Basic arithmetic functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data3_f32 NCPP_VECTOR_CALL data3_minus(PA_data3_f32 a) noexcept;

    F_data3_f32 NCPP_VECTOR_CALL data3_multiply(PA_data3_f32 a, f32 b) noexcept;
    F_data3_f32 NCPP_VECTOR_CALL data3_divide(PA_data3_f32 a, f32 b) noexcept;

    F_data3_f32 NCPP_VECTOR_CALL data3_add(PA_data3_f32 a, PA_data3_f32 b) noexcept;
    F_data3_f32 NCPP_VECTOR_CALL data3_subtract(PA_data3_f32 a, PA_data3_f32 b) noexcept;

    F_data3_f32 NCPP_VECTOR_CALL data3_multiply(PA_data3_f32 a, PA_data3_f32 b) noexcept;
    F_data3_f32 NCPP_VECTOR_CALL data3_divide(PA_data3_f32 a, PA_data3_f32 b) noexcept;

    F_data3_f32 NCPP_VECTOR_CALL data3_round(PA_data3_f32 a) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  Entry manipulate functions
    ////////////////////////////////////////////////////////////////////////////////////
    template<
        u32 x_selector__,
        u32 y_selector__,
        u32 z_selector__
    >
    F_data3_f32 NCPP_VECTOR_CALL T_data3_static_permute(
        PA_data3_f32 a,
        PA_data3_f32 b
    ) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  FMA functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data3_f32 NCPP_VECTOR_CALL data3_multiply_add(
        PA_data3_f32 a,
        PA_data3_f32 b,
        PA_data3_f32 c
    ) noexcept;

    F_data3_f32 NCPP_VECTOR_CALL data3_multiply_addsub(
        PA_data3_f32 a,
        PA_data3_f32 b,
        PA_data3_f32 c
    ) noexcept;

    F_data3_f32 NCPP_VECTOR_CALL data3_multiply_sub(
        PA_data3_f32 a,
        PA_data3_f32 b,
        PA_data3_f32 c
    ) noexcept;

    F_data3_f32 NCPP_VECTOR_CALL data3_multiply_subadd(
        PA_data3_f32 a,
        PA_data3_f32 b,
        PA_data3_f32 c
    ) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  Dot, cross product, length, etc.
    ////////////////////////////////////////////////////////////////////////////////////
    f32 NCPP_VECTOR_CALL data3_dot(PA_data3_f32 a, PA_data3_f32 b) noexcept;

    F_data3_f32 NCPP_VECTOR_CALL data3_cross(PA_data3_f32 a, PA_data3_f32 b) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  Trigonometry functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data3_f32 NCPP_VECTOR_CALL data3_mod_angles(PA_data3_f32 a) noexcept;

    F_data3_f32 NCPP_VECTOR_CALL data3_sin_angles(PA_data3_f32 a) noexcept;

    F_data3_f32 NCPP_VECTOR_CALL data3_cos_angles(PA_data3_f32 a) noexcept;

    void NCPP_VECTOR_CALL data3_sin_cos_angles(PA_data3_f32 a, F_data3_f32& out_sin, F_data3_f32& out_cos) noexcept;

}



////////////////////////////////////////////////////////////////////////////////////
//  F32 defines
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    ////////////////////////////////////////////////////////////////////////////////////
    //  Basic arithmetic functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_minus(PA_data3_f32 a) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        return _mm_mul_ps(a.xyz_, simd_f32x4_1111_negative);
#else
        return {

            -a.x,
            -a.y,
            -a.z

        };
#endif
    }

    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_multiply(PA_data3_f32 a, f32 b) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        return _mm_mul_ps(a.xyz_, _mm_set1_ps(b));
#else
        return {

            a.x * b,
            a.y * b,
            a.z * b

        };
#endif
    }
    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_divide(PA_data3_f32 a, f32 b) noexcept
    {

#ifdef NCPP_ENABLE_SSE
        return _mm_div_ps(a.xyz_, _mm_set1_ps(b));
#else
        return {

            a.x / b,
            a.y / b,
            a.z / b

        };
#endif
    }
    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_add(PA_data3_f32 a, PA_data3_f32 b) noexcept
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
    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_subtract(PA_data3_f32 a, PA_data3_f32 b) noexcept
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

    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_multiply(PA_data3_f32 a, PA_data3_f32 b) noexcept
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
    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_divide(PA_data3_f32 a, PA_data3_f32 b) noexcept
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
    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_round(PA_data3_f32 a) noexcept {

#ifdef NCPP_ENABLE_SSE4
        return _mm_round_ps(a.xyz_, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
#elif defined(NCPP_ENABLE_SSE)
        __m128 sign = _mm_and_ps(a.xyz_, negative_zero_x4.xyzw_);
        __m128 sMagic = _mm_or_ps(no_fraction_x4.xyzw_, sign);
        __m128 R1 = _mm_add_ps(a.xyz_, sMagic);
        R1 = _mm_sub_ps(R1, sMagic);
        __m128 R2 = _mm_and_ps(a.xyz_, abs_mask_x4.xyzw_);
        __m128 mask = _mm_cmple_ps(R2, no_fraction_x4.xyzw_);
        R2 = _mm_andnot_ps(mask, a.xyz_);
        R1 = _mm_and_ps(R1, mask);
        F_data3_f32 vResult = _mm_xor_ps(R1, R2);
        return vResult;
#else
        return {
            round_to_nearest(a.x),
            round_to_nearest(a.y),
            round_to_nearest(a.z)
        };
#endif
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Entry manipulate functions
    ////////////////////////////////////////////////////////////////////////////////////
#ifdef NCPP_ENABLE_SSE
    namespace internal {

        template<uint32_t shuffle, bool which_x, bool which_y, bool which_z> struct T_data3_simd_static_permute_helper
        {
            static NCPP_FORCE_INLINE F_simd_f32x4 NCPP_VECTOR_CALL permute(F_simd_f32x4 v1, F_simd_f32x4 v2) noexcept
            {
                static const F_simd_f32x4 selectMask = make_simd_f32x4(
                    which_x ? 0xFFFFFFFF : 0,
                    which_y ? 0xFFFFFFFF : 0,
                    which_z ? 0xFFFFFFFF : 0,
                    0
                );

                F_simd_f32x4 shuffled1 = _mm_permute_ps(v1, shuffle);
                F_simd_f32x4 shuffled2 = _mm_permute_ps(v2, shuffle);

                F_simd_f32x4 masked1 = _mm_andnot_ps(selectMask, shuffled1);
                F_simd_f32x4 masked2 = _mm_and_ps(selectMask, shuffled2);

                return _mm_or_ps(masked1, masked2);
            }
        };

        // Fast path for permutes that only read from the first vector.
        template<uint32_t shuffle> struct T_data3_simd_static_permute_helper<shuffle, false, false, false>
        {
            static NCPP_FORCE_INLINE F_simd_f32x4 NCPP_VECTOR_CALL permute(F_simd_f32x4 v1, F_simd_f32x4) noexcept { return _mm_permute_ps(v1, shuffle); }
        };

        // Fast path for permutes that only read from the second vector.
        template<uint32_t shuffle> struct T_data3_simd_static_permute_helper<shuffle, true, true, true>
        {
            static NCPP_FORCE_INLINE F_simd_f32x4 NCPP_VECTOR_CALL permute(F_simd_f32x4, F_simd_f32x4 v2) noexcept { return _mm_permute_ps(v2, shuffle); }
        };

        // Fast path for permutes that read XY from the first vector, Z from the second.
        template<uint32_t shuffle> struct T_data3_simd_static_permute_helper<shuffle, false, false, true>
        {
            static NCPP_FORCE_INLINE F_simd_f32x4 NCPP_VECTOR_CALL permute(F_simd_f32x4 v1, F_simd_f32x4 v2) noexcept { return _mm_shuffle_ps(v1, v2, shuffle); }
        };

        // Fast path for permutes that read XY from the second vector, Z from the first.
        template<uint32_t shuffle> struct T_data3_simd_static_permute_helper<shuffle, true, true, false>
        {
            static NCPP_FORCE_INLINE F_simd_f32x4 NCPP_VECTOR_CALL permute(F_simd_f32x4 v1, F_simd_f32x4 v2) noexcept { return _mm_shuffle_ps(v2, v1, shuffle); }
        };
        
    }
#endif

    template<
        u32 x_selector__,
        u32 y_selector__,
        u32 z_selector__
    >
    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL T_data3_static_permute(
        PA_data3_f32 a,
        PA_data3_f32 b
    ) noexcept {
        
#ifdef NCPP_ENABLE_SSE
        constexpr u32 shuffle = _MM_SHUFFLE(0, z_selector__ & 3, y_selector__ & 3, x_selector__ & 3);

        constexpr bool which_x = x_selector__ > 3;
        constexpr bool which_y = y_selector__ > 3;
        constexpr bool which_z = z_selector__ > 3;

        return internal::T_data3_simd_static_permute_helper<shuffle, which_x, which_y, which_z>::permute(a.xyz_, b.xyz_);
#else
        return {
          
            a[(u32)x_selector__ & 3],
            a[(u32)y_selector__ & 3],
            a[(u32)z_selector__ & 3]
            
        };
#endif
        
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  FMA functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_multiply_add(
        PA_data3_f32 a,
        PA_data3_f32 b,
        PA_data3_f32 c
    ) noexcept {
                   
#ifdef NCPP_ENABLE_FMA3
        return _mm_fmadd_ps(a.xyz_, b.xyz_, c.xyz_);
#else
        return {
          
            a.x * b.x + c.x,
            a.y * b.y + c.y,
            a.z * b.z + c.z
            
        };
#endif
        
    }
    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_multiply_addsub(
        PA_data3_f32 a,
        PA_data3_f32 b,
        PA_data3_f32 c
    ) noexcept {
        
#ifdef NCPP_ENABLE_FMA3
        return _mm_fmsubadd_ps(a.xyz_, b.xyz_, c.xyz_);
#else
        return {
          
            a.x * b.x + c.x,
            a.y * b.y - c.y,
            a.z * b.z + c.z
            
        };
#endif
        
    }
    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_multiply_sub(
        PA_data3_f32 a,
        PA_data3_f32 b,
        PA_data3_f32 c
    ) noexcept {
    
#ifdef NCPP_ENABLE_FMA3
        return _mm_fmsub_ps(a.xyz_, b.xyz_, c.xyz_);
#else
        return {
          
            a.x * b.x - c.x,
            a.y * b.y - c.y,
            a.z * b.z - c.z
            
        };
#endif
        
    }
    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_multiply_subadd(
        PA_data3_f32 a,
        PA_data3_f32 b,
        PA_data3_f32 c
    ) noexcept {
    
#ifdef NCPP_ENABLE_FMA3
        return _mm_fmaddsub_ps(a.xyz_, b.xyz_, c.xyz_);
#else
        return {
          
            a.x * b.x - c.x,
            a.y * b.y + c.y,
            a.z * b.z - c.z
            
        };
#endif
        
    }
    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_negative_multiply_add(
        PA_data3_f32 a,
        PA_data3_f32 b,
        PA_data3_f32 c
    ) noexcept {

#ifdef NCPP_ENABLE_FMA3
        return _mm_fnmadd_ps(a.xyz_, b.xyz_, c.xyz_);
#else
        return {

            a.x * -b.x + c.x,
            a.y * -b.y + c.y,
            a.z * -b.z + c.z

        };
#endif

    }
    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_negative_multiply_sub(
        PA_data3_f32 a,
        PA_data3_f32 b,
        PA_data3_f32 c
    ) noexcept {

#ifdef NCPP_ENABLE_FMA3
        return _mm_fnmsub_ps(a.xyz_, b.xyz_, c.xyz_);
#else
        return {

            a.x * -b.x - c.x,
            a.y * -b.y - c.y,
            a.z * -b.z - c.z

        };
#endif

    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Dot, cross product, length, etc.
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE f32 NCPP_VECTOR_CALL data3_dot(PA_data3_f32 a, PA_data3_f32 b) noexcept {

#ifdef NCPP_ENABLE_SSE4
        return _mm_cvtss_f32(_mm_dp_ps(a.xyz_, b.xyz_, 0x71));
#elif defined(NCPP_ENABLE_SSE3)
        __m128 mul_res, shuf_reg, sums_reg;
        mul_res = _mm_mul_ps(a.xyz_, b.xyz_);
        mul_res = _mm_mul_ps(mul_res, simd_f32x4_1110);

        shuf_reg = _mm_movehdup_ps(mul_res);
        sums_reg = _mm_add_ps(mul_res, shuf_reg);
        shuf_reg = _mm_movehl_ps(shuf_reg, sums_reg);
        sums_reg = _mm_add_ss(sums_reg, shuf_reg);

        return  _mm_cvtss_f32(sums_reg);
#elif defined(NCPP_ENABLE_SSE)
        __m128 mul_res, shuf_reg, sums_reg;
        mul_res = _mm_mul_ps(a.xyz_, b.xyz_);
        mul_res = _mm_mul_ps(mul_res, simd_f32x4_1110);

        // Replacing _mm_movehdup_ps(mul_res)
        shuf_reg = _mm_permute_ps(mul_res, _MM_SHUFFLE(3, 3, 1, 1));
        sums_reg = _mm_add_ps(mul_res, shuf_reg);

        // Replacing _mm_movehl_ps(shuf_reg, sums_reg)
        shuf_reg = _mm_shuffle_ps(shuf_reg, sums_reg, _MM_SHUFFLE(3, 1, 2, 0));
        sums_reg = _mm_add_ss(sums_reg, shuf_reg);

        return  _mm_cvtss_f32(sums_reg);
#else
        return a.x * a.x + a.y * a.y + a.z * a.z;
#endif
    }
    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_cross(PA_data3_f32 a, PA_data3_f32 b) noexcept {

#ifdef NCPP_ENABLE_FMA3
        // y1,z1,x1,w1
        __m128 vTemp1 = _mm_permute_ps(a.xyz_, _MM_SHUFFLE(3, 0, 2, 1));
        // z2,x2,y2,w2
        __m128 vTemp2 = _mm_permute_ps(b.xyz_, _MM_SHUFFLE(3, 1, 0, 2));
        // Perform the left operation
        __m128 vResult = _mm_mul_ps(vTemp1, vTemp2);
        // z1,x1,y1,w1
        vTemp1 = _mm_permute_ps(vTemp1, _MM_SHUFFLE(3, 0, 2, 1));
        // y2,z2,x2,w2
        vTemp2 = _mm_permute_ps(vTemp2, _MM_SHUFFLE(3, 1, 0, 2));
        // Perform the right operation
        vResult = _mm_fnmadd_ps(vTemp1, vTemp2, vResult);

        return vResult;// _mm_and_ps(vResult, simd_f32x4_FFF0);
#else
        return {

            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x

        };
#endif
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Trigonometry functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_mod_angles(PA_data3_f32 a) noexcept {

#ifdef NCPP_ENABLE_SSE
        F_data3_f32 vResult = _mm_mul_ps(a.xyz_, reciprocal_two_pi_x3.xyz_);
        // Use the inline function due to complexity for rounding
        vResult = data3_round(vResult);
        return _mm_fnmadd_ps(vResult.xyz_, two_pi_x3.xyz_, a.xyz_);
#else
        F_data3_f32 V;
        F_data3_f32 Result;

        // Modulo the range of the given angles such that -XM_PI <= Angles < XM_PI
        V = data3_multiply(a, reciprocal_two_pi_x3);
        V = data3_round(V);
        Result = data3_negative_multiply_sub(two_pi_x3, V, a);
        return Result;
#endif
    }

    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_sin_angles(PA_data3_f32 a) noexcept {

#ifdef NCPP_ENABLE_SSE
        // Force the value within the bounds of pi
        F_data3_f32 x = data3_mod_angles(a);

        // Map in [-pi/2,pi/2] with sin(y) = sin(x).
        __m128 sign = _mm_and_ps(x.xyz_, negative_zero_x4.xyzw_);
        __m128 c = _mm_or_ps(two_pi_x4.xyzw_, sign);  // pi when x >= 0, -pi when x < 0
        __m128 absx = _mm_andnot_ps(sign, x.xyz_);  // |x|
        __m128 rflx = _mm_sub_ps(c, x.xyz_);
        __m128 comp = _mm_cmple_ps(absx, half_pi_x4.xyzw_);
        __m128 select0 = _mm_and_ps(comp, x.xyz_);
        __m128 select1 = _mm_andnot_ps(comp, rflx);
        x = _mm_or_ps(select0, select1);

        __m128 x2 = _mm_mul_ps(x.xyz_, x.xyz_);

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
        Result = _mm_mul_ps(Result, x.xyz_);
        return Result;
#else
        return {

            sinf(a.x),
            sinf(a.y),
            sinf(a.z)

        };
#endif
    }

    NCPP_FORCE_INLINE F_data3_f32 NCPP_VECTOR_CALL data3_cos_angles(PA_data3_f32 a) noexcept {

#ifdef NCPP_ENABLE_SSE
        // Map V to x in [-pi,pi].
        F_data3_f32 x = data3_mod_angles(a);

        // Map in [-pi/2,pi/2] with cos(y) = sign*cos(x).
        F_data3_f32 sign = _mm_and_ps(x.xyz_, negative_zero_x4.xyzw_);
        __m128 c = _mm_or_ps(pi_x4.xyzw_, sign.xyz_);  // pi when x >= 0, -pi when x < 0
        __m128 absx = _mm_andnot_ps(sign.xyz_, x.xyz_);  // |x|
        __m128 rflx = _mm_sub_ps(c, x.xyz_);
        __m128 comp = _mm_cmple_ps(absx, half_pi_x4.xyzw_);
        __m128 select0 = _mm_and_ps(comp, x.xyz_);
        __m128 select1 = _mm_andnot_ps(comp, rflx);
        x = _mm_or_ps(select0, select1);
        select0 = _mm_and_ps(comp, simd_f32x4_1111);
        select1 = _mm_andnot_ps(comp, simd_f32x4_1111_negative);
        sign = _mm_or_ps(select0, select1);

        __m128 x2 = _mm_mul_ps(x.xyz_, x.xyz_);

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
        Result = _mm_mul_ps(Result, sign.xyz_);
        return Result;
#else
        return {

            cosf(a.x),
            cosf(a.y),
            cosf(a.z)

        };
#endif
    }

    NCPP_FORCE_INLINE void NCPP_VECTOR_CALL data3_sin_cos_angles(PA_data3_f32 a, F_data3_f32& out_sin, F_data3_f32& out_cos) noexcept {

#ifdef NCPP_ENABLE_SSE    // Force the value within the bounds of pi
        F_data3_f32 x = data3_mod_angles(a.xyz_);

        // Map in [-pi/2,pi/2] with sin(y) = sin(x), cos(y) = sign*cos(x).
        F_data3_f32 sign = _mm_and_ps(x.xyz_, negative_zero_x4.xyzw_);
        __m128 c = _mm_or_ps(pi_x4.xyzw_, sign.xyz_);  // pi when x >= 0, -pi when x < 0
        __m128 absx = _mm_andnot_ps(sign.xyz_, x.xyz_);  // |x|
        __m128 rflx = _mm_sub_ps(c, x.xyz_);
        __m128 comp = _mm_cmple_ps(absx, half_pi_x4.xyzw_);
        __m128 select0 = _mm_and_ps(comp, x.xyz_);
        __m128 select1 = _mm_andnot_ps(comp, rflx);
        x = _mm_or_ps(select0, select1);
        select0 = _mm_and_ps(comp, simd_f32x4_1111);
        select1 = _mm_andnot_ps(comp, simd_f32x4_1111_negative);
        sign = _mm_or_ps(select0, select1);

        __m128 x2 = _mm_mul_ps(x.xyz_, x.xyz_);

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
        Result = _mm_mul_ps(Result, x.xyz_);
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
        Result = _mm_mul_ps(Result, sign.xyz_);
        out_cos = Result;
#else
        out_sin = data3_sin_angles(a);
        out_cos = data3_cos_angles(a);
#endif
    }

}
