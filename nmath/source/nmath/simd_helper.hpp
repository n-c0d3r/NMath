#pragma once

/** @file nmath/simd_helper.hpp
*
*   Implement simd helper.
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



namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



#ifdef NCPP_ENABLE_SSE
#define NMATH_ENABLE_SIMD_F32X4
#endif

#ifdef NCPP_ENABLE_SSE2
#define NMATH_ENABLE_SIMD_I32X4
#endif



#ifdef NCPP_ENABLE_SSE
    using F_simd_f32x4 = __m128;

    NCPP_FORCE_INLINE F_simd_f32x4 make_simd_f32x4(f32 x, f32 y, f32 z, f32 w) {

        return _mm_set_ps(w, z, y, x);
    }
    NCPP_FORCE_INLINE F_simd_f32x4 make_simd_f32x4(u32 x, u32 y, u32 z, u32 w) {

        union {
            u32 u[4];
            F_simd_f32x4 f32x4;
        } t;
        
        t.u[0] = x;
        t.u[1] = y;
        t.u[2] = z;
        t.u[3] = w;
        
        return t.f32x4;
    }
#endif

#ifdef NCPP_ENABLE_SSE2
    using F_simd_i32x4 = __m128i;

    NCPP_FORCE_INLINE F_simd_i32x4 make_simd_i32x4(i32 x, i32 y, i32 z, i32 w) {

        return _mm_set_epi32(w, z, y, x);
    }
#endif



#ifdef NMATH_ENABLE_SIMD_F32X4
    extern const F_simd_f32x4 simd_f32x4_0000;

    extern const F_simd_f32x4 simd_f32x4_FFFF;

    extern const F_simd_f32x4 simd_f32x4_000F;
    extern const F_simd_f32x4 simd_f32x4_00F0;
    extern const F_simd_f32x4 simd_f32x4_0F00;
    extern const F_simd_f32x4 simd_f32x4_F000;

    extern const F_simd_f32x4 simd_f32x4_FFF0;
    extern const F_simd_f32x4 simd_f32x4_FF0F;
    extern const F_simd_f32x4 simd_f32x4_F0FF;
    extern const F_simd_f32x4 simd_f32x4_0FFF;

    extern const F_simd_f32x4 simd_f32x4_FF00;
    extern const F_simd_f32x4 simd_f32x4_F00F;
    extern const F_simd_f32x4 simd_f32x4_00FF;
    extern const F_simd_f32x4 simd_f32x4_0FF0;
    extern const F_simd_f32x4 simd_f32x4_0F0F;
    extern const F_simd_f32x4 simd_f32x4_F0F0;

    extern const F_simd_f32x4 simd_f32x4_1111;

    extern const F_simd_f32x4 simd_f32x4_0001;
    extern const F_simd_f32x4 simd_f32x4_0010;
    extern const F_simd_f32x4 simd_f32x4_0100;
    extern const F_simd_f32x4 simd_f32x4_1000;

    extern const F_simd_f32x4 simd_f32x4_1110;
    extern const F_simd_f32x4 simd_f32x4_1101;
    extern const F_simd_f32x4 simd_f32x4_1011;
    extern const F_simd_f32x4 simd_f32x4_0111;

    extern const F_simd_f32x4 simd_f32x4_1100;
    extern const F_simd_f32x4 simd_f32x4_1001;
    extern const F_simd_f32x4 simd_f32x4_0011;
    extern const F_simd_f32x4 simd_f32x4_0110;
    extern const F_simd_f32x4 simd_f32x4_0101;
    extern const F_simd_f32x4 simd_f32x4_1010;

    extern const F_simd_f32x4 simd_f32x4_1111_negative;

    extern const F_simd_f32x4 simd_f32x4_0001_negative;
    extern const F_simd_f32x4 simd_f32x4_0010_negative;
    extern const F_simd_f32x4 simd_f32x4_0100_negative;
    extern const F_simd_f32x4 simd_f32x4_1000_negative;

    extern const F_simd_f32x4 simd_f32x4_1110_negative;
    extern const F_simd_f32x4 simd_f32x4_1101_negative;
    extern const F_simd_f32x4 simd_f32x4_1011_negative;
    extern const F_simd_f32x4 simd_f32x4_0111_negative;

    extern const F_simd_f32x4 simd_f32x4_1100_negative;
    extern const F_simd_f32x4 simd_f32x4_1001_negative;
    extern const F_simd_f32x4 simd_f32x4_0011_negative;
    extern const F_simd_f32x4 simd_f32x4_0110_negative;
    extern const F_simd_f32x4 simd_f32x4_0101_negative;
    extern const F_simd_f32x4 simd_f32x4_1010_negative;
#endif

#ifdef NMATH_ENABLE_SIMD_I32X4
    extern const F_simd_i32x4 simd_i32x4_0000;

    extern const F_simd_i32x4 simd_i32x4_FFFF;

    extern const F_simd_i32x4 simd_i32x4_000F;
    extern const F_simd_i32x4 simd_i32x4_00F0;
    extern const F_simd_i32x4 simd_i32x4_0F00;
    extern const F_simd_i32x4 simd_i32x4_F000;

    extern const F_simd_i32x4 simd_i32x4_FFF0;
    extern const F_simd_i32x4 simd_i32x4_FF0F;
    extern const F_simd_i32x4 simd_i32x4_F0FF;
    extern const F_simd_i32x4 simd_i32x4_0FFF;

    extern const F_simd_i32x4 simd_i32x4_FF00;
    extern const F_simd_i32x4 simd_i32x4_F00F;
    extern const F_simd_i32x4 simd_i32x4_00FF;
    extern const F_simd_i32x4 simd_i32x4_0FF0;
    extern const F_simd_i32x4 simd_i32x4_0F0F;
    extern const F_simd_i32x4 simd_i32x4_F0F0;

    extern const F_simd_i32x4 simd_i32x4_1111;

    extern const F_simd_i32x4 simd_i32x4_0001;
    extern const F_simd_i32x4 simd_i32x4_0010;
    extern const F_simd_i32x4 simd_i32x4_0100;
    extern const F_simd_i32x4 simd_i32x4_1000;

    extern const F_simd_i32x4 simd_i32x4_1110;
    extern const F_simd_i32x4 simd_i32x4_1101;
    extern const F_simd_i32x4 simd_i32x4_1011;
    extern const F_simd_i32x4 simd_i32x4_0111;

    extern const F_simd_i32x4 simd_i32x4_1100;
    extern const F_simd_i32x4 simd_i32x4_1001;
    extern const F_simd_i32x4 simd_i32x4_0011;
    extern const F_simd_i32x4 simd_i32x4_0110;
    extern const F_simd_i32x4 simd_i32x4_0101;
    extern const F_simd_i32x4 simd_i32x4_1010;

    extern const F_simd_i32x4 simd_i32x4_1111_negative;

    extern const F_simd_i32x4 simd_i32x4_0001_negative;
    extern const F_simd_i32x4 simd_i32x4_0010_negative;
    extern const F_simd_i32x4 simd_i32x4_0100_negative;
    extern const F_simd_i32x4 simd_i32x4_1000_negative;

    extern const F_simd_i32x4 simd_i32x4_1110_negative;
    extern const F_simd_i32x4 simd_i32x4_1101_negative;
    extern const F_simd_i32x4 simd_i32x4_1011_negative;
    extern const F_simd_i32x4 simd_i32x4_0111_negative;

    extern const F_simd_i32x4 simd_i32x4_1100_negative;
    extern const F_simd_i32x4 simd_i32x4_1001_negative;
    extern const F_simd_i32x4 simd_i32x4_0011_negative;
    extern const F_simd_i32x4 simd_i32x4_0110_negative;
    extern const F_simd_i32x4 simd_i32x4_0101_negative;
    extern const F_simd_i32x4 simd_i32x4_1010_negative;
#endif

}
