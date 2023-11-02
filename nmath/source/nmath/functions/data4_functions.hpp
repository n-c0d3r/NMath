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

#pragma endregion



////////////////////////////////////////////////////////////////////////////////////
//  F32
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



    ////////////////////////////////////////////////////////////////////////////////////
    //  Basic algorithmic functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_round(PA_data4_f32 a) noexcept {

        return {};
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Entry manipulate functions
    ////////////////////////////////////////////////////////////////////////////////////
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
        mul_res = _mm_mul_ps(a.xyz_, b.xyz_);

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

        return {};
    }

    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_sin_angles(PA_data4_f32 a) noexcept {

        return {};
    }

    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_cos_angles(PA_data4_f32 a) noexcept {

        return {};
    }

    NCPP_FORCE_INLINE F_data4_f32 NCPP_VECTOR_CALL data4_sin_cos_angles(PA_data4_f32 a) noexcept {

        return {};
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Complex number
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data4_f32 data4_complex_multiply(PA_data4_f32 a, PA_data4_f32 b) {

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
