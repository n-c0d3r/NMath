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

#include <nmath/types/data4.hpp>
#include <nmath/types/data_helper.hpp>
#include <nmath/utilities/basic_arithmetic.hpp>

#pragma endregion



////////////////////////////////////////////////////////////////////////////////////
//  D4 selectors
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    static constexpr u32 D4_SELECT_X0 = 0;
    static constexpr u32 D4_SELECT_Y0 = 1;
    static constexpr u32 D4_SELECT_Z0 = 2;
    static constexpr u32 D4_SELECT_W0 = 3;

    static constexpr u32 D4_SELECT_X1 = 4;
    static constexpr u32 D4_SELECT_Y1 = 5;
    static constexpr u32 D4_SELECT_Z1 = 6;
    static constexpr u32 D4_SELECT_W1 = 7;

}



////////////////////////////////////////////////////////////////////////////////////
//  F32 declares
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    ////////////////////////////////////////////////////////////////////////////////////
    //  Basic arithmetic functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data4_f32 NCPP_VECTOR_CALL data4_minus(PA_data4_f32 a) noexcept;

    F_data4_f32 NCPP_VECTOR_CALL data4_add(PA_data4_f32 a, PA_data4_f32 b) noexcept;
    F_data4_f32 NCPP_VECTOR_CALL data4_subtract(PA_data4_f32 a, PA_data4_f32 b) noexcept;

    F_data4_f32 NCPP_VECTOR_CALL data4_multiply(PA_data4_f32 a, PA_data4_f32 b) noexcept;
    F_data4_f32 NCPP_VECTOR_CALL data4_divide(PA_data4_f32 a, PA_data4_f32 b) noexcept;

    F_data4_f32 NCPP_VECTOR_CALL data4_round(PA_data4_f32 a) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  Entry manipulate functions
    ////////////////////////////////////////////////////////////////////////////////////
    template<
        u32 x_selector__,
        u32 y_selector__,
        u32 z_selector__,
        u32 w_selector__
    >
    F_data4_f32 NCPP_VECTOR_CALL T_data4_static_permute(
        PA_data4_f32 a,
        PA_data4_f32 b
    ) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  FMA functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data4_f32 NCPP_VECTOR_CALL data4_multiply_add(
        PA_data4_f32 a,
        PA_data4_f32 b,
        PA_data4_f32 c
    ) noexcept;

    F_data4_f32 NCPP_VECTOR_CALL data4_multiply_addsub(
        PA_data4_f32 a,
        PA_data4_f32 b,
        PA_data4_f32 c
   ) noexcept;

    F_data4_f32 NCPP_VECTOR_CALL data4_multiply_sub(
        PA_data4_f32 a,
        PA_data4_f32 b,
        PA_data4_f32 c
    ) noexcept;

    F_data4_f32 NCPP_VECTOR_CALL data4_multiply_subadd(
        PA_data4_f32 a,
        PA_data4_f32 b,
        PA_data4_f32 c
   ) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  Dot, cross product, length, etc.
    ////////////////////////////////////////////////////////////////////////////////////
    f32 NCPP_VECTOR_CALL data4_dot(PA_data4_f32 a, PA_data4_f32 b) noexcept;

    F_data4_f32 NCPP_VECTOR_CALL data4_cross(PA_data4_f32 a, PA_data4_f32 b, PA_data4_f32 c) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  Trigonometry functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data4_f32 NCPP_VECTOR_CALL data4_mod_angles(PA_data4_f32 a) noexcept;

    F_data4_f32 NCPP_VECTOR_CALL data4_sin_angles(PA_data4_f32 a) noexcept;

    F_data4_f32 NCPP_VECTOR_CALL data4_cos_angles(PA_data4_f32 a) noexcept;

    void NCPP_VECTOR_CALL data4_sin_cos_angles(PA_data4_f32 a, F_data4_f32& out_sin, F_data4_f32& out_cos) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  Complex number
    ////////////////////////////////////////////////////////////////////////////////////
    F_data4_f32 data4_complex_multiply(PA_data4_f32 a, PA_data4_f32 b) noexcept;

}



////////////////////////////////////////////////////////////////////////////////////
//  F32 defines
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    ////////////////////////////////////////////////////////////////////////////////////
    //  Basic arithmetic functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_minus(PA_data4_f32 a) noexcept
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
    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_add(PA_data4_f32 a, PA_data4_f32 b) noexcept
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
    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_subtract(PA_data4_f32 a, PA_data4_f32 b) noexcept
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

    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_multiply(PA_data4_f32 a, PA_data4_f32 b) noexcept
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
    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_divide(PA_data4_f32 a, PA_data4_f32 b) noexcept
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
    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_round(PA_data4_f32 a) noexcept {

#ifdef NCPP_ENABLE_SSE4
        return _mm_round_ps(a.xyzw_, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
#elif defined(NCPP_ENABLE_SSE)
        static const F_data4_f32 negative_zero_x4 = F_data4_f32(
            reinterpret_cast_u32_to_f32(0x80000000),
            reinterpret_cast_u32_to_f32(0x80000000),
            reinterpret_cast_u32_to_f32(0x80000000),
            reinterpret_cast_u32_to_f32(0x80000000)
        );
        static const F_data4_f32 abs_mask_x4 = F_data4_f32(
            reinterpret_cast_u32_to_f32(0x7FFFFFFF),
            reinterpret_cast_u32_to_f32(0x7FFFFFFF),
            reinterpret_cast_u32_to_f32(0x7FFFFFFF),
            reinterpret_cast_u32_to_f32(0x7FFFFFFF)
        );
        static const F_data4_f32 no_fraction_x4 = F_data4_f32{ 8388608.0f, 8388608.0f, 8388608.0f, 8388608.0f };

        __m128 sign = _mm_and_ps(a.xyzw_, negative_zero_x4.xyzw_);
        __m128 sMagic = _mm_or_ps(no_fraction_x4.xyzw_, sign);
        __m128 R1 = _mm_add_ps(a.xyzw_, sMagic);
        R1 = _mm_sub_ps(R1, sMagic);
        __m128 R2 = _mm_and_ps(a.xyzw_, abs_mask_x4.xyzw_);
        __m128 mask = _mm_cmple_ps(R2, no_fraction_x4.xyzw_);
        R2 = _mm_andnot_ps(mask, a.xyzw_);
        R1 = _mm_and_ps(R1, mask);
        F_data4_f32 vResult = _mm_xor_ps(R1, R2);
        return vResult;
#else
        return {

            round_to_nearest(a.x),
            round_to_nearest(a.y),
            round_to_nearest(a.z),
            round_to_nearest(a.w)

        };
#endif
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Entry manipulate functions
    ////////////////////////////////////////////////////////////////////////////////////
#ifdef NCPP_ENABLE_SSE
    namespace internal {
        
        template<uint32_t shuffle, bool which_x, bool which_y, bool which_z, bool which_w> struct T_data4_simd_static_permute_helper
        {
            static NCPP_FORCE_INLINE F_simd_f32x4 NCPP_VECTOR_CALL permute(F_simd_f32x4 v1, F_simd_f32x4 v2) noexcept
            {
                static const F_simd_f32x4 selectMask = make_simd_f32x4(
                    which_x ? 0xFFFFFFFF : 0,
                    which_y ? 0xFFFFFFFF : 0,
                    which_z ? 0xFFFFFFFF : 0,
                    which_w ? 0xFFFFFFFF : 0
                );

                F_simd_f32x4 shuffled1 = _mm_permute_ps(v1, shuffle);
                F_simd_f32x4 shuffled2 = _mm_permute_ps(v2, shuffle);

                F_simd_f32x4 masked1 = _mm_andnot_ps(selectMask, shuffled1);
                F_simd_f32x4 masked2 = _mm_and_ps(selectMask, shuffled2);

                return _mm_or_ps(masked1, masked2);
            }
        };

        // Fast path for permutes that only read from the first vector.
        template<uint32_t shuffle> struct T_data4_simd_static_permute_helper<shuffle, false, false, false, false>
        {
            static NCPP_FORCE_INLINE F_simd_f32x4 NCPP_VECTOR_CALL permute(F_simd_f32x4 v1, F_simd_f32x4) noexcept { return _mm_permute_ps(v1, shuffle); }
        };

        // Fast path for permutes that only read from the second vector.
        template<uint32_t shuffle> struct T_data4_simd_static_permute_helper<shuffle, true, true, true, true>
        {
            static NCPP_FORCE_INLINE F_simd_f32x4 NCPP_VECTOR_CALL permute(F_simd_f32x4, F_simd_f32x4 v2) noexcept { return _mm_permute_ps(v2, shuffle); }
        };

        // Fast path for permutes that read XY from the first vector, ZW from the second.
        template<uint32_t shuffle> struct T_data4_simd_static_permute_helper<shuffle, false, false, true, true>
        {
            static NCPP_FORCE_INLINE F_simd_f32x4 NCPP_VECTOR_CALL permute(F_simd_f32x4 v1, F_simd_f32x4 v2) noexcept { return _mm_shuffle_ps(v1, v2, shuffle); }
        };

        // Fast path for permutes that read XY from the second vector, ZW from the first.
        template<uint32_t shuffle> struct T_data4_simd_static_permute_helper<shuffle, true, true, false, false>
        {
            static NCPP_FORCE_INLINE F_simd_f32x4 NCPP_VECTOR_CALL permute(F_simd_f32x4 v1, F_simd_f32x4 v2) noexcept { return _mm_shuffle_ps(v2, v1, shuffle); }
        };
        
    }
#endif

    template<
        u32 x_selector__,
        u32 y_selector__,
        u32 z_selector__,
        u32 w_selector__
    >
    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL T_data4_static_permute(
        PA_data4_f32 a,
        PA_data4_f32 b
    ) noexcept {
        
#ifdef NCPP_ENABLE_SSE
        constexpr u32 shuffle = _MM_SHUFFLE(w_selector__ & 3, z_selector__ & 3, y_selector__ & 3, x_selector__ & 3);

        constexpr bool which_x = x_selector__ > 3;
        constexpr bool which_y = y_selector__ > 3;
        constexpr bool which_z = z_selector__ > 3;
        constexpr bool which_w = w_selector__ > 3;

        return internal::T_data4_simd_static_permute_helper<shuffle, which_x, which_y, which_z, which_w>::permute(a.xyzw_, b.xyzw_);
#else
        return {
          
            a[(u32)x_selector__ & 3],
            a[(u32)y_selector__ & 3],
            a[(u32)z_selector__ & 3],
            a[(u32)w_selector__ & 3]
            
        };
#endif
        
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  FMA functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_multiply_add(
        PA_data4_f32 a,
        PA_data4_f32 b,
        PA_data4_f32 c
    ) noexcept {
                   
#ifdef NCPP_ENABLE_FMA3
        return _mm_fmadd_ps(a.xyzw_, b.xyzw_, c.xyzw_);
#else
        return {
          
            a.x * b.x + c.x,
            a.y * b.y + c.y,
            a.z * b.z + c.z,
            a.w * b.w + c.w
            
        };
#endif
        
    }
    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_multiply_addsub(
        PA_data4_f32 a,
        PA_data4_f32 b,
        PA_data4_f32 c
   ) noexcept {
        
#ifdef NCPP_ENABLE_FMA3
        return _mm_fmsubadd_ps(a.xyzw_, b.xyzw_, c.xyzw_);
#else
        return {
          
            a.x * b.x + c.x,
            a.y * b.y - c.y,
            a.z * b.z + c.z,
            a.w * b.w - c.w
            
        };
#endif
        
    }
    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_multiply_sub(
        PA_data4_f32 a,
        PA_data4_f32 b,
        PA_data4_f32 c
    ) noexcept {
    
#ifdef NCPP_ENABLE_FMA3
        return _mm_fmsub_ps(a.xyzw_, b.xyzw_, c.xyzw_);
#else
        return {
          
            a.x * b.x - c.x,
            a.y * b.y - c.y,
            a.z * b.z - c.z,
            a.w * b.w - c.w
            
        };
#endif
        
    }
    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_multiply_subadd(
        PA_data4_f32 a,
        PA_data4_f32 b,
        PA_data4_f32 c
   ) noexcept {
    
#ifdef NCPP_ENABLE_FMA3
        return _mm_fmaddsub_ps(a.xyzw_, b.xyzw_, c.xyzw_);
#else
        return {
          
            a.x * b.x - c.x,
            a.y * b.y + c.y,
            a.z * b.z - c.z,
            a.w * b.w + c.w
            
        };
#endif
        
    }
    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_negative_multiply_add(
        PA_data4_f32 a,
        PA_data4_f32 b,
        PA_data4_f32 c
    ) noexcept {

#ifdef NCPP_ENABLE_FMA3
        return _mm_fnmadd_ps(a.xyzw_, b.xyzw_, c.xyzw_);
#else
        return {

            a.x * -b.x + c.x,
            a.y * -b.y + c.y,
            a.z * -b.z + c.z,
            a.w * -b.w + c.w

        };
#endif

    }
    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_negative_multiply_sub(
        PA_data4_f32 a,
        PA_data4_f32 b,
        PA_data4_f32 c
    ) noexcept {

#ifdef NCPP_ENABLE_FMA3
        return _mm_fnmsub_ps(a.xyzw_, b.xyzw_, c.xyzw_);
#else
        return {

            a.x * -b.x - c.x,
            a.y * -b.y - c.y,
            a.z * -b.z - c.z,
            a.w * -b.w - c.w

        };
#endif

    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Dot, cross product, length, etc.
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE f32 NCPP_VECTOR_CALL data4_dot(PA_data4_f32 a, PA_data4_f32 b) noexcept {
    
#ifdef NCPP_ENABLE_SSE4
        return _mm_cvtss_f32(_mm_dp_ps(a.xyzw_, b.xyzw_, 0xFF));
#elif defined(NCPP_ENABLE_SSE3)
        __m128 mul_res, shuf_reg, sums_reg;
        mul_res = _mm_mul_ps(a.xyzw_, b.xyzw_);

        shuf_reg = _mm_movehdup_ps(mul_res);
        sums_reg = _mm_add_ps(mul_res, shuf_reg);
        shuf_reg = _mm_movehl_ps(shuf_reg, sums_reg);
        sums_reg = _mm_add_ss(sums_reg, shuf_reg);

        return  _mm_cvtss_f32(sums_reg);
#elif defined(NCPP_ENABLE_SSE)
        __m128 mul_res, shuf_reg, sums_reg;
        mul_res = _mm_mul_ps(a.xyzw_, b.xyzw_);

        // Replacing _mm_movehdup_ps(mul_res)
        shuf_reg = _mm_permute_ps(mul_res, _MM_SHUFFLE(3, 3, 1, 1));
        sums_reg = _mm_add_ps(mul_res, shuf_reg);

        // Replacing _mm_movehl_ps(shuf_reg, sums_reg)
        shuf_reg = _mm_shuffle_ps(shuf_reg, sums_reg, _MM_SHUFFLE(3, 1, 2, 0));
        sums_reg = _mm_add_ss(sums_reg, shuf_reg);

        return  _mm_cvtss_f32(sums_reg);
#else
        return a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
#endif
    }
    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_cross(PA_data4_f32 a, PA_data4_f32 b, PA_data4_f32 c) noexcept {
    
#ifdef NCPP_ENABLE_FMA3
        // V2zwyz * V3wzwy
        __m128 vResult = _mm_permute_ps(b.xyzw_, _MM_SHUFFLE(2, 1, 3, 2));
        __m128 vTemp3 = _mm_permute_ps(c.xyzw_, _MM_SHUFFLE(1, 3, 2, 3));
        vResult = _mm_mul_ps(vResult, vTemp3);
        // - V2wzwy * V3zwyz
        __m128 vTemp2 = _mm_permute_ps(b.xyzw_, _MM_SHUFFLE(1, 3, 2, 3));
        vTemp3 = _mm_permute_ps(vTemp3, _MM_SHUFFLE(1, 3, 0, 1));
        vResult = _mm_fnmadd_ps(vTemp2, vTemp3, vResult);
        // term1 * V1yxxx
        __m128 vTemp1 = _mm_permute_ps(a.xyzw_, _MM_SHUFFLE(0, 0, 0, 1));
        vResult = _mm_mul_ps(vResult, vTemp1);

        // V2ywxz * V3wxwx
        vTemp2 = _mm_permute_ps(b.xyzw_, _MM_SHUFFLE(2, 0, 3, 1));
        vTemp3 = _mm_permute_ps(c.xyzw_, _MM_SHUFFLE(0, 3, 0, 3));
        vTemp3 = _mm_mul_ps(vTemp3, vTemp2);
        // - V2wxwx * V3ywxz
        vTemp2 = _mm_permute_ps(vTemp2, _MM_SHUFFLE(2, 1, 2, 1));
        vTemp1 = _mm_permute_ps(c.xyzw_, _MM_SHUFFLE(2, 0, 3, 1));
        vTemp3 = _mm_fnmadd_ps(vTemp2, vTemp1, vTemp3);
        // vResult - temp * V1zzyy
        vTemp1 = _mm_permute_ps(a.xyzw_, _MM_SHUFFLE(1, 1, 2, 2));
        vResult = _mm_fnmadd_ps(vTemp1, vTemp3, vResult);

        // V2yzxy * V3zxyx
        vTemp2 = _mm_permute_ps(b.xyzw_, _MM_SHUFFLE(1, 0, 2, 1));
        vTemp3 = _mm_permute_ps(c.xyzw_, _MM_SHUFFLE(0, 1, 0, 2));
        vTemp3 = _mm_mul_ps(vTemp3, vTemp2);
        // - V2zxyx * V3yzxy
        vTemp2 = _mm_permute_ps(vTemp2, _MM_SHUFFLE(2, 0, 2, 1));
        vTemp1 = _mm_permute_ps(c.xyzw_, _MM_SHUFFLE(1, 0, 2, 1));
        vTemp3 = _mm_fnmadd_ps(vTemp1, vTemp2, vTemp3);
        // vResult + term * V1wwwz
        vTemp1 = _mm_permute_ps(a.xyzw_, _MM_SHUFFLE(2, 3, 3, 3));
        vResult = _mm_fmadd_ps(vTemp3, vTemp1, vResult);
        return vResult;
#else
        return {

            (b.z * c.w - b.w * c.z)* a.y - (b.y * c.w - b.w * c.y) * a.z + (b.y * c.z - b.z * c.y) * a.w,
            (b.w * c.z - b.z * c.w)* a.x - (b.w * c.x - b.x * c.w) * a.z + (b.z * c.x - b.x * c.z) * a.w,
            (b.y * c.w - b.w * c.y)* a.x - (b.x * c.w - b.w * c.x) * a.y + (b.x * c.y - b.y * c.x) * a.w,
            (b.z * c.y - b.y * c.z)* a.x - (b.z * c.x - b.x * c.z) * a.y + (b.y * c.x - b.x * c.y) * a.z

        };
#endif
        
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Trigonometry functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_mod_angles(PA_data4_f32 a) noexcept {

        static const F_data4_f32 reciprocal_two_pi_x4 = F_data4_f32(1.0f / 2pi, 1.0f / 2pi, 1.0f / 2pi, 1.0f / 2pi);
        static const F_data4_f32 two_pi_x4 = F_data4_f32(2pi, 2pi, 2pi, 2pi);

#ifdef NCPP_ENABLE_SSE
        F_data4_f32 vResult = _mm_mul_ps(a.xyzw_, reciprocal_two_pi_x4.xyzw_);
        // Use the inline function due to complexity for rounding
        vResult = data4_round(vResult);
        return _mm_fnmadd_ps(vResult.xyzw_, two_pi_x4.xyzw_, a.xyzw_);
#else
        F_data4_f32 V;
        F_data4_f32 Result;

        // Modulo the range of the given angles such that -XM_PI <= Angles < XM_PI
        V = data4_multiply(a, reciprocal_two_pi_x4);
        V = data4_round(V);
        Result = data4_negative_multiply_sub(two_pi_x4, V, a);
        return Result;
#endif
    }

    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_sin_angles(PA_data4_f32 a) noexcept {

        static const F_data4_f32 two_pi_x4 = F_data4_f32(2pi, 2pi, 2pi, 2pi);
        static const F_data4_f32 half_pi_x4 = F_data4_f32(0.5pi, 0.5pi, 0.5pi, 0.5pi);
        static const F_data4_f32 negative_zero_x4 = F_data4_f32(
            reinterpret_cast_u32_to_f32(0x80000000), 
            reinterpret_cast_u32_to_f32(0x80000000), 
            reinterpret_cast_u32_to_f32(0x80000000), 
            reinterpret_cast_u32_to_f32(0x80000000)
        );
        static const F_data4_f32 sin_coefficient_s1_x4 = F_data4_f32(-2.3889859e-08f, -0.16665852f /*Est1*/, +0.0083139502f /*Est2*/, -0.00018524670f /*Est3*/);
        static const F_data4_f32 sin_coefficient_s0_x4 = F_data4_f32(-0.16666667f, +0.0083333310f, -0.00019840874f, +2.7525562e-06f);

#ifdef NCPP_ENABLE_SSE
        // Force the value within the bounds of pi
        F_data4_f32 x = data4_mod_angles(a);

        // Map in [-pi/2,pi/2] with sin(y) = sin(x).
        __m128 sign = _mm_and_ps(x.xyzw_, negative_zero_x4.xyzw_);
        __m128 c = _mm_or_ps(two_pi_x4.xyzw_, sign);  // pi when x >= 0, -pi when x < 0
        __m128 absx = _mm_andnot_ps(sign, x.xyzw_);  // |x|
        __m128 rflx = _mm_sub_ps(c, x.xyzw_);
        __m128 comp = _mm_cmple_ps(absx, half_pi_x4.xyzw_);
        __m128 select0 = _mm_and_ps(comp, x.xyzw_);
        __m128 select1 = _mm_andnot_ps(comp, rflx);
        x = _mm_or_ps(select0, select1);

        __m128 x2 = _mm_mul_ps(x.xyzw_, x.xyzw_);

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
        Result = _mm_mul_ps(Result, x.xyzw_);
        return Result;
#else
        return {

            sinf(a.x),
            sinf(a.y),
            sinf(a.z),
            sinf(a.w)

        };
#endif
    }

    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_cos_angles(PA_data4_f32 a) noexcept {

        static const F_data4_f32 pi_x4 = F_data4_f32(1pi, 1pi, 1pi, 1pi);
        static const F_data4_f32 half_pi_x4 = F_data4_f32(0.5pi, 0.5pi, 0.5pi, 0.5pi);
        static const F_data4_f32 negative_zero_x4 = F_data4_f32(
            reinterpret_cast_u32_to_f32(0x80000000),
            reinterpret_cast_u32_to_f32(0x80000000),
            reinterpret_cast_u32_to_f32(0x80000000),
            reinterpret_cast_u32_to_f32(0x80000000)
        );
        static const F_data4_f32 cos_coefficient_s1_x4 = F_data4_f32(-2.6051615e-07f, -0.49992746f /*Est1*/, +0.041493919f /*Est2*/, -0.0012712436f /*Est3*/);
        static const F_data4_f32 cos_coefficient_s0_x4 = F_data4_f32(-0.5f, +0.041666638f, -0.0013888378f, +2.4760495e-05f);

#ifdef NCPP_ENABLE_SSE
        // Map V to x in [-pi,pi].
        F_data4_f32 x = data4_mod_angles(a);

        // Map in [-pi/2,pi/2] with cos(y) = sign*cos(x).
        F_data4_f32 sign = _mm_and_ps(x.xyzw_, negative_zero_x4.xyzw_);
        __m128 c = _mm_or_ps(pi_x4.xyzw_, sign.xyzw_);  // pi when x >= 0, -pi when x < 0
        __m128 absx = _mm_andnot_ps(sign.xyzw_, x.xyzw_);  // |x|
        __m128 rflx = _mm_sub_ps(c, x.xyzw_);
        __m128 comp = _mm_cmple_ps(absx, half_pi_x4.xyzw_);
        __m128 select0 = _mm_and_ps(comp, x.xyzw_);
        __m128 select1 = _mm_andnot_ps(comp, rflx);
        x = _mm_or_ps(select0, select1);
        select0 = _mm_and_ps(comp, simd_f32x4_1111);
        select1 = _mm_andnot_ps(comp, simd_f32x4_1111_negative);
        sign = _mm_or_ps(select0, select1);

        __m128 x2 = _mm_mul_ps(x.xyzw_, x.xyzw_);

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
        Result = _mm_mul_ps(Result, sign.xyzw_);
        return Result;
#else
        return {

            cosf(a.x),
            cosf(a.y),
            cosf(a.z),
            cosf(a.w)

        };
#endif
    }

    NCPP_FORCE_INLINE void NCPP_VECTOR_CALL data4_sin_cos_angles(PA_data4_f32 a, F_data4_f32& out_sin, F_data4_f32& out_cos) noexcept {

        static const F_data4_f32 pi_x4 = F_data4_f32(1pi, 1pi, 1pi, 1pi);
        static const F_data4_f32 half_pi_x4 = F_data4_f32(0.5pi, 0.5pi, 0.5pi, 0.5pi);
        static const F_data4_f32 negative_zero_x4 = F_data4_f32(
            reinterpret_cast_u32_to_f32(0x80000000),
            reinterpret_cast_u32_to_f32(0x80000000),
            reinterpret_cast_u32_to_f32(0x80000000),
            reinterpret_cast_u32_to_f32(0x80000000)
        );
        static const F_data4_f32 sin_coefficient_s1_x4 = F_data4_f32(-2.3889859e-08f, -0.16665852f /*Est1*/, +0.0083139502f /*Est2*/, -0.00018524670f /*Est3*/);
        static const F_data4_f32 sin_coefficient_s0_x4 = F_data4_f32(-0.16666667f, +0.0083333310f, -0.00019840874f, +2.7525562e-06f);
        static const F_data4_f32 cos_coefficient_s1_x4 = F_data4_f32(-2.6051615e-07f, -0.49992746f /*Est1*/, +0.041493919f /*Est2*/, -0.0012712436f /*Est3*/);
        static const F_data4_f32 cos_coefficient_s0_x4 = F_data4_f32(-0.5f, +0.041666638f, -0.0013888378f, +2.4760495e-05f);

#ifdef NCPP_ENABLE_SSE    // Force the value within the bounds of pi
        F_data4_f32 x = data4_mod_angles(a.xyzw_);

        // Map in [-pi/2,pi/2] with sin(y) = sin(x), cos(y) = sign*cos(x).
        F_data4_f32 sign = _mm_and_ps(x.xyzw_, negative_zero_x4.xyzw_);
        __m128 c = _mm_or_ps(pi_x4.xyzw_, sign.xyzw_);  // pi when x >= 0, -pi when x < 0
        __m128 absx = _mm_andnot_ps(sign.xyzw_, x.xyzw_);  // |x|
        __m128 rflx = _mm_sub_ps(c, x.xyzw_);
        __m128 comp = _mm_cmple_ps(absx, half_pi_x4.xyzw_);
        __m128 select0 = _mm_and_ps(comp, x.xyzw_);
        __m128 select1 = _mm_andnot_ps(comp, rflx);
        x = _mm_or_ps(select0, select1);
        select0 = _mm_and_ps(comp, simd_f32x4_1111);
        select1 = _mm_andnot_ps(comp, simd_f32x4_1111_negative);
        sign = _mm_or_ps(select0, select1);

        __m128 x2 = _mm_mul_ps(x.xyzw_, x.xyzw_);

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
        Result = _mm_mul_ps(Result, x.xyzw_);
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
        Result = _mm_mul_ps(Result, sign.xyzw_);
        out_cos = Result;
#else
        out_sin = data4_sin_angles(a);
        out_cos = data4_cos_angles(a);
#endif
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Complex number
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data4_f32 data4_complex_multiply(PA_data4_f32 a, PA_data4_f32 b) noexcept {

#ifdef NCPP_ENABLE_FMA3
        static const F_simd_f32x4 ControlWZYX = make_simd_f32x4(1.0f, -1.0f, 1.0f, -1.0f);
        static const F_simd_f32x4 ControlZWXY = make_simd_f32x4(1.0f, 1.0f, -1.0f, -1.0f);
        static const F_simd_f32x4 ControlYXWZ = make_simd_f32x4(-1.0f, 1.0f, 1.0f, -1.0f);
        // Copy to SSE registers and use as few as possible for x86
        __m128 Q2X = b.xyzw_;
        __m128 Q2Y = b.xyzw_;
        __m128 Q2Z = b.xyzw_;
        __m128 vResult = b.xyzw_;
        // Splat with one instruction
        vResult = _mm_permute_ps(vResult, _MM_SHUFFLE(3, 3, 3, 3));
        Q2X = _mm_permute_ps(Q2X, _MM_SHUFFLE(0, 0, 0, 0));
        Q2Y = _mm_permute_ps(Q2Y, _MM_SHUFFLE(1, 1, 1, 1));
        Q2Z = _mm_permute_ps(Q2Z, _MM_SHUFFLE(2, 2, 2, 2));
        // Retire Q1 and perform Q1*Q2W
        vResult = _mm_mul_ps(vResult, a.xyzw_);
        __m128 Q1Shuffle = a.xyzw_;
        // Shuffle the copies of Q1
        Q1Shuffle = _mm_permute_ps(Q1Shuffle, _MM_SHUFFLE(0, 1, 2, 3));
        // Mul by Q1WZYX
        Q2X = _mm_mul_ps(Q2X, Q1Shuffle);
        Q1Shuffle = _mm_permute_ps(Q1Shuffle, _MM_SHUFFLE(2, 3, 0, 1));
        // Flip the signs on y and z
        vResult = _mm_fmadd_ps(Q2X, ControlWZYX, vResult);
        // Mul by Q1ZWXY
        Q2Y = _mm_mul_ps(Q2Y, Q1Shuffle);
        Q1Shuffle = _mm_permute_ps(Q1Shuffle, _MM_SHUFFLE(0, 1, 2, 3));
        // Flip the signs on z and w
        Q2Y = _mm_mul_ps(Q2Y, ControlZWXY);
        // Mul by Q1YXWZ
        Q2Z = _mm_mul_ps(Q2Z, Q1Shuffle);
        // Flip the signs on x and w
        Q2Y = _mm_fmadd_ps(Q2Z, ControlYXWZ, Q2Y);
        vResult = _mm_add_ps(vResult, Q2Y);
        return vResult;
#else
        return {
            (b.w * a.x) + (b.x * a.w) + (b.y * a.z) - (b.z * a.y),
            (b.w * a.y) - (b.x * a.z) + (b.y * a.w) + (b.z * a.x),
            (b.w * a.z) + (b.x * a.y) - (b.y * a.x) + (b.z * a.w),
            (b.w * a.w) - (b.x * a.x) - (b.y * a.y) - (b.z * a.z)
        };
#endif

	}

}
