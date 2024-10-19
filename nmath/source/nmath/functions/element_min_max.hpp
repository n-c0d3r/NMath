#pragma once

/** @file nmath/functions/element_min_max.hpp
*
*   Implement element_min and element_max.
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

    NCPP_FORCE_INLINE f32 element_max(f32 a, f32 b) noexcept {

        return (a > b) ? a : b;
    }
    NCPP_FORCE_INLINE f64 element_max(f64 a, f64 b) noexcept {

        return (a > b) ? a : b;
    }
    NCPP_FORCE_INLINE i8 element_max(i8 a, i8 b) noexcept {

        return (a > b) ? a : b;
    }
    NCPP_FORCE_INLINE i16 element_max(i16 a, i16 b) noexcept {

        return (a > b) ? a : b;
    }
    NCPP_FORCE_INLINE i32 element_max(i32 a, i32 b) noexcept {

        return (a > b) ? a : b;
    }
    NCPP_FORCE_INLINE i64 element_max(i64 a, i64 b) noexcept {

        return (a > b) ? a : b;
    }
    NCPP_FORCE_INLINE u8 element_max(u8 a, u8 b) noexcept {

        return (a > b) ? a : b;
    }
    NCPP_FORCE_INLINE u16 element_max(u16 a, u16 b) noexcept {

        return (a > b) ? a : b;
    }
    NCPP_FORCE_INLINE u32 element_max(u32 a, u32 b) noexcept {

        return (a > b) ? a : b;
    }
    NCPP_FORCE_INLINE u64 element_max(u64 a, u64 b) noexcept {

        return (a > b) ? a : b;
    }

    NCPP_FORCE_INLINE F_vector2_f32 NMATH_CALL_CNV element_max(PA_vector2_f32 a, PA_vector2_f32 b) noexcept {

        return {
            element_max(a.x, b.x),
            element_max(a.y, b.y)
        };
    }
    NCPP_FORCE_INLINE F_vector2_i32 NMATH_CALL_CNV element_max(PA_vector2_i32 a, PA_vector2_i32 b) noexcept {

        return {
            element_max(a.x, b.x),
            element_max(a.y, b.y)
        };
    }
    NCPP_FORCE_INLINE F_vector2_u32 NMATH_CALL_CNV element_max(PA_vector2_u32 a, PA_vector2_u32 b) noexcept {

        return {
            element_max(a.x, b.x),
            element_max(a.y, b.y)
        };
    }

    NCPP_FORCE_INLINE F_vector3_f32 NMATH_CALL_CNV element_max(PA_vector3_f32 a, PA_vector3_f32 b) noexcept {

        return {
            element_max(a.x, b.x),
            element_max(a.y, b.y),
            element_max(a.z, b.z)
        };
    }
    NCPP_FORCE_INLINE F_vector3_i32 NMATH_CALL_CNV element_max(PA_vector3_i32 a, PA_vector3_i32 b) noexcept {

        return {
            element_max(a.x, b.x),
            element_max(a.y, b.y),
            element_max(a.z, b.z)
        };
    }
    NCPP_FORCE_INLINE F_vector3_u32 NMATH_CALL_CNV element_max(PA_vector3_u32 a, PA_vector3_u32 b) noexcept {

        return {
            element_max(a.x, b.x),
            element_max(a.y, b.y),
            element_max(a.z, b.z)
        };
    }

    NCPP_FORCE_INLINE F_vector4_f32 NMATH_CALL_CNV element_max(PA_vector4_f32 a, PA_vector4_f32 b) noexcept {

        return {
            element_max(a.x, b.x),
            element_max(a.y, b.y),
            element_max(a.z, b.z),
            element_max(a.w, b.w)
        };
    }

    

    NCPP_FORCE_INLINE f32 element_min(f32 a, f32 b) noexcept {

        return (a < b) ? a : b;
    }
    NCPP_FORCE_INLINE f64 element_min(f64 a, f64 b) noexcept {

        return (a < b) ? a : b;
    }
    NCPP_FORCE_INLINE i8 element_min(i8 a, i8 b) noexcept {

        return (a < b) ? a : b;
    }
    NCPP_FORCE_INLINE i16 element_min(i16 a, i16 b) noexcept {

        return (a < b) ? a : b;
    }
    NCPP_FORCE_INLINE i32 element_min(i32 a, i32 b) noexcept {

        return (a < b) ? a : b;
    }
    NCPP_FORCE_INLINE i64 element_min(i64 a, i64 b) noexcept {

        return (a < b) ? a : b;
    }
    NCPP_FORCE_INLINE u8 element_min(u8 a, u8 b) noexcept {

        return (a < b) ? a : b;
    }
    NCPP_FORCE_INLINE u16 element_min(u16 a, u16 b) noexcept {

        return (a < b) ? a : b;
    }
    NCPP_FORCE_INLINE u32 element_min(u32 a, u32 b) noexcept {

        return (a < b) ? a : b;
    }
    NCPP_FORCE_INLINE u64 element_min(u64 a, u64 b) noexcept {

        return (a < b) ? a : b;
    }

    NCPP_FORCE_INLINE F_vector2_f32 NMATH_CALL_CNV element_min(PA_vector2_f32 a, PA_vector2_f32 b) noexcept {

        return {
            element_min(a.x, b.x),
            element_min(a.x, b.x)
        };
    }
    NCPP_FORCE_INLINE F_vector2_i32 NMATH_CALL_CNV element_min(PA_vector2_i32 a, PA_vector2_i32 b) noexcept {

        return {
            element_min(a.x, b.x),
            element_min(a.y, b.y)
        };
    }
    NCPP_FORCE_INLINE F_vector2_u32 NMATH_CALL_CNV element_min(PA_vector2_u32 a, PA_vector2_u32 b) noexcept {

        return {
            element_min(a.x, b.x),
            element_min(a.y, b.y)
        };
    }

    NCPP_FORCE_INLINE F_vector3_f32 NMATH_CALL_CNV element_min(PA_vector3_f32 a, PA_vector3_f32 b) noexcept {

        return {
            element_min(a.x, b.x),
            element_min(a.y, b.y),
            element_min(a.z, b.z)
        };
    }
    NCPP_FORCE_INLINE F_vector3_i32 NMATH_CALL_CNV element_min(PA_vector3_i32 a, PA_vector3_i32 b) noexcept {

        return {
            element_min(a.x, b.x),
            element_min(a.y, b.y),
            element_min(a.z, b.z)
        };
    }
    NCPP_FORCE_INLINE F_vector3_u32 NMATH_CALL_CNV element_min(PA_vector3_u32 a, PA_vector3_u32 b) noexcept {

        return {
            element_min(a.x, b.x),
            element_min(a.y, b.y),
            element_min(a.z, b.z)
        };
    }

    NCPP_FORCE_INLINE F_vector4_f32 NMATH_CALL_CNV element_min(PA_vector4_f32 a, PA_vector4_f32 b) noexcept {

        return {
            element_min(a.x, b.x),
            element_min(a.y, b.y),
            element_min(a.z, b.z),
            element_min(a.w, b.w)
        };
    }

}
