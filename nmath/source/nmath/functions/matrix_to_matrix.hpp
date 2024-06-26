#pragma once

/** @file nmath/functions/matrix_to_matrix.hpp
*
*   Implement matrix-to-matrix convert functions.
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

#include <nmath/types/matrix.hpp>

#pragma endregion



////////////////////////////////////////////////////////////////////////////////////
//  f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    template<>
    NCPP_FORCE_INLINE F_matrix3x3_f32 NMATH_CALL_CNV T_convert<F_matrix2x2_f32, F_matrix3x3_f32>(PA_matrix2x2_f32 m) noexcept {

        return {
            m.a,
            m.b,
            F_vector3_f32::forward()
        };
    }

    template<>
    NCPP_FORCE_INLINE F_matrix4x4_f32 NMATH_CALL_CNV T_convert<F_matrix3x3_f32, F_matrix4x4_f32>(PA_matrix3x3_f32 m) noexcept {

#ifdef NCPP_ENABLE_AVX
        return {
            (
                _mm256_blend_ps(m.ab_, simd_f32x8_00000000, 0b10001000)
            ),
            (
                _mm256_blend_ps(m.c_, simd_f32x8_00000001, 0b11111000)
            )
        };
#else
        return {
            m.a,
            m.b,
            m.c,
            F_vector4_f32::future()
        };
#endif
    }

}