#pragma once

/** @file nmath/functions/element_atan2.hpp
*
*   Implement element_atan2.
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
#include <nmath/types/matrix.hpp>

#pragma endregion



namespace nmath {

    NCPP_FORCE_INLINE f32 element_atan2(f32 a, f32 b) noexcept {

        return atan2(a, b);
    }
    NCPP_FORCE_INLINE f64 element_atan2(f64 a, f64 b) noexcept {

        return atan2(a, b);
    }

    NCPP_FORCE_INLINE F_vector2_f32 NMATH_CALL_CNV element_atan2(PA_vector2_f32 a, PA_vector2_f32 b) noexcept {

        return {
            element_atan2(a.x, b.x),
            element_atan2(a.x, b.x)
        };
    }

    NCPP_FORCE_INLINE F_vector3_f32 NMATH_CALL_CNV element_atan2(PA_vector3_f32 a, PA_vector3_f32 b) noexcept {

        return {
            element_atan2(a.x, b.x),
            element_atan2(a.y, b.y),
            element_atan2(a.z, b.z)
        };
    }

    NCPP_FORCE_INLINE F_vector4_f32 NMATH_CALL_CNV element_atan2(PA_vector4_f32 a, PA_vector4_f32 b) noexcept {

        return {
            element_atan2(a.x, b.x),
            element_atan2(a.y, b.y),
            element_atan2(a.z, b.z),
            element_atan2(a.w, b.w)
        };
    }

}
