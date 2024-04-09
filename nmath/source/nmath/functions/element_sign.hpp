#pragma once

/** @file nmath/functions/element_sign.hpp
*
*   Implement element_sign.
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

    NCPP_FORCE_INLINE f32 element_sign(f32 a) noexcept {

        return (a < 0.0f) ? -1.0f : ((a == 0.0f) ? 0.0f : 1.0f);
    }
    NCPP_FORCE_INLINE f64 element_sign(f64 a) noexcept {

        return (a < 0.0) ? -1.0 : ((a == 0.0) ? 0.0 : 1.0);
    }
    NCPP_FORCE_INLINE i8 element_sign(i8 a) noexcept {

        return (a < 0) ? -1 : ((a == 0) ? 0 : 1);
    }
    NCPP_FORCE_INLINE i16 element_sign(i16 a) noexcept {

        return (a < 0) ? -1 : ((a == 0) ? 0 : 1);
    }
    NCPP_FORCE_INLINE i32 element_sign(i32 a) noexcept {

        return (a < 0) ? -1 : ((a == 0) ? 0 : 1);
    }
    NCPP_FORCE_INLINE i64 element_sign(i64 a) noexcept {

        return (a < 0) ? -1 : ((a == 0) ? 0 : 1);
    }
    NCPP_FORCE_INLINE u8 element_sign(u8 a) noexcept {

        return (a < 0) ? -1 : ((a == 0) ? 0 : 1);
    }
    NCPP_FORCE_INLINE u16 element_sign(u16 a) noexcept {

        return (a < 0) ? -1 : ((a == 0) ? 0 : 1);
    }
    NCPP_FORCE_INLINE u32 element_sign(u32 a) noexcept {

        return (a < 0) ? -1 : ((a == 0) ? 0 : 1);
    }
    NCPP_FORCE_INLINE u64 element_sign(u64 a) noexcept {

        return (a < 0) ? -1 : ((a == 0) ? 0 : 1);
    }

    NCPP_FORCE_INLINE F_vector2_f32 NMATH_CALL_CNV element_sign(PA_vector2_f32 a) noexcept {

        return {
            element_sign(a.x),
            element_sign(a.x)
        };
    }
    NCPP_FORCE_INLINE F_vector2_i32 NMATH_CALL_CNV element_sign(PA_vector2_i32 a) noexcept {

        return {
            element_sign(a.x),
            element_sign(a.y)
        };
    }
    NCPP_FORCE_INLINE F_vector2_u32 NMATH_CALL_CNV element_sign(PA_vector2_u32 a) noexcept {

        return {
            element_sign(a.x),
            element_sign(a.y)
        };
    }

    NCPP_FORCE_INLINE F_vector3_f32 NMATH_CALL_CNV element_sign(PA_vector3_f32 a) noexcept {

        return {
            element_sign(a.x),
            element_sign(a.y),
            element_sign(a.z)
        };
    }

    NCPP_FORCE_INLINE F_vector4_f32 NMATH_CALL_CNV element_sign(PA_vector4_f32 a) noexcept {

        return {
            element_sign(a.x),
            element_sign(a.y),
            element_sign(a.z),
            element_sign(a.w)
        };
    }

}