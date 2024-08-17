#pragma once

/** @file nmath/functions/vector_to_vector.hpp
*
*   Implement vector-to-vector convert functions.
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

#include <nmath/types/vector.hpp>
#include <nmath/functions/convert_template.hpp>

#pragma endregion



////////////////////////////////////////////////////////////////////////////////////
//  f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    template<>
    NCPP_FORCE_INLINE F_vector3_f32 NMATH_CALL_CNV T_convert<F_vector2_f32, F_vector3_f32>(PA_vector2_f32 m) noexcept {

        return {
            m.x,
            m.y,
            0.0f
        };
    }

    template<>
    NCPP_FORCE_INLINE F_vector4_f32 NMATH_CALL_CNV T_convert<F_vector3_f32, F_vector4_f32>(PA_vector3_f32 m) noexcept {

    #ifdef NCPP_ENABLE_SSE
        return { _mm_and_ps(m.xyz_, simd_f32x4_FFF0) };
    #else
        return {
            m,
            0.0f
        };
    #endif
    }

}



////////////////////////////////////////////////////////////////////////////////////
//  u32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    template<>
    NCPP_FORCE_INLINE F_vector3_u32 NMATH_CALL_CNV T_convert<F_vector2_u32, F_vector3_u32>(PA_vector2_u32 m) noexcept {

        return {
            m.x,
            m.y,
            0
        };
    }

}