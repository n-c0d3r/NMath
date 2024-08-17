#pragma once

/** @file nmath/functions/element_clamp.hpp
*
*   Implement element_clamp.
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

    NCPP_FORCE_INLINE f32 element_clamp(f32 a, f32 min, f32 max) noexcept {

        return eastl::clamp<f32>(a, min, max);
    }
    NCPP_FORCE_INLINE f64 element_clamp(f64 a, f64 min, f64 max) noexcept {

        return eastl::clamp<f64>(a, min, max);
    }
    NCPP_FORCE_INLINE i8 element_clamp(i8 a, i8 min, i8 max) noexcept {

        return eastl::clamp<i8>(a, min, max);
    }
    NCPP_FORCE_INLINE i16 element_clamp(i16 a, i16 min, i16 max) noexcept {

        return eastl::clamp<i16>(a, min, max);
    }
    NCPP_FORCE_INLINE i32 element_clamp(i32 a, i32 min, i32 max) noexcept {

        return eastl::clamp<i32>(a, min, max);
    }
    NCPP_FORCE_INLINE i64 element_clamp(i64 a, i64 min, i64 max) noexcept {

        return eastl::clamp<i64>(a, min, max);
    }
    NCPP_FORCE_INLINE u8 element_clamp(u8 a, u8 min, u8 max) noexcept {

        return eastl::clamp<u8>(a, min, max);
    }
    NCPP_FORCE_INLINE u16 element_clamp(u16 a, u16 min, u16 max) noexcept {

        return eastl::clamp<u16>(a, min, max);
    }
    NCPP_FORCE_INLINE u32 element_clamp(u32 a, u32 min, u32 max) noexcept {

        return eastl::clamp<u32>(a, min, max);
    }
    NCPP_FORCE_INLINE u64 element_clamp(u64 a, u64 min, u64 max) noexcept {

        return eastl::clamp<u64>(a, min, max);
    }

    NCPP_FORCE_INLINE F_vector2_f32 NMATH_CALL_CNV element_clamp(PA_vector2_f32 a, PA_vector2_f32 min, PA_vector2_f32 max) noexcept {

        return {
            element_clamp(a.x, min.x, max.x),
            element_clamp(a.y, min.y, max.y)
        };
    }
    NCPP_FORCE_INLINE F_vector2_i32 NMATH_CALL_CNV element_clamp(PA_vector2_i32 a, PA_vector2_i32 min, PA_vector2_i32 max) noexcept {

        return {
            element_clamp(a.x, min.x, max.x),
            element_clamp(a.y, min.y, max.y)
        };
    }
    NCPP_FORCE_INLINE F_vector2_u32 NMATH_CALL_CNV element_clamp(PA_vector2_u32 a, PA_vector2_u32 min, PA_vector2_u32 max) noexcept {

        return {
            element_clamp(a.x, min.x, max.x),
            element_clamp(a.y, min.y, max.y)
        };
    }

    NCPP_FORCE_INLINE F_vector3_f32 NMATH_CALL_CNV element_clamp(PA_vector3_f32 a, PA_vector3_f32 min, PA_vector3_f32 max) noexcept {

        return {
            element_clamp(a.x, min.x, max.x),
            element_clamp(a.y, min.y, max.y),
            element_clamp(a.z, min.z, max.z)
        };
    }
    NCPP_FORCE_INLINE F_vector3_i32 NMATH_CALL_CNV element_clamp(PA_vector3_i32 a, PA_vector3_i32 min, PA_vector3_i32 max) noexcept {

        return {
            element_clamp(a.x, min.x, max.x),
            element_clamp(a.y, min.y, max.y),
            element_clamp(a.z, min.z, max.z)
        };
    }
    NCPP_FORCE_INLINE F_vector3_u32 NMATH_CALL_CNV element_clamp(PA_vector3_u32 a, PA_vector3_u32 min, PA_vector3_u32 max) noexcept {

        return {
            element_clamp(a.x, min.x, max.x),
            element_clamp(a.y, min.y, max.y),
            element_clamp(a.z, min.z, max.z)
        };
    }

    NCPP_FORCE_INLINE F_vector4_f32 NMATH_CALL_CNV element_clamp(PA_vector4_f32 a, PA_vector4_f32 min, PA_vector4_f32 max) noexcept {

        return {
            element_clamp(a.x, min.x, max.x),
            element_clamp(a.y, min.y, max.y),
            element_clamp(a.z, min.z, max.z),
            element_clamp(a.w, min.w, max.w)
        };
    }

}
