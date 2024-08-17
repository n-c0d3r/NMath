#pragma once

/** @file nmath/functions/element_if_equal.hpp
*
*   Implement element_if_equal.
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

    NCPP_FORCE_INLINE f32 element_if_equal(f32 a, f32 expect, f32 desire) noexcept {

        return (a == expect) ? a : desire;
    }
    NCPP_FORCE_INLINE f64 element_if_equal(f64 a, f64 expect, f64 desire) noexcept {

        return (a == expect) ? a : desire;
    }
    NCPP_FORCE_INLINE i8 element_if_equal(i8 a, i8 expect, i8 desire) noexcept {

        return (a == expect) ? a : desire;
    }
    NCPP_FORCE_INLINE i16 element_if_equal(i16 a, i16 expect, i16 desire) noexcept {

        return (a == expect) ? a : desire;
    }
    NCPP_FORCE_INLINE i32 element_if_equal(i32 a, i32 expect, i32 desire) noexcept {

        return (a == expect) ? a : desire;
    }
    NCPP_FORCE_INLINE i64 element_if_equal(i64 a, i64 expect, i64 desire) noexcept {

        return (a == expect) ? a : desire;
    }
    NCPP_FORCE_INLINE u8 element_if_equal(u8 a, u8 expect, u8 desire) noexcept {

        return (a == expect) ? a : desire;
    }
    NCPP_FORCE_INLINE u16 element_if_equal(u16 a, u16 expect, u16 desire) noexcept {

        return (a == expect) ? a : desire;
    }
    NCPP_FORCE_INLINE u32 element_if_equal(u32 a, u32 expect, u32 desire) noexcept {

        return (a == expect) ? a : desire;
    }
    NCPP_FORCE_INLINE u64 element_if_equal(u64 a, u64 expect, u64 desire) noexcept {

        return (a == expect) ? a : desire;
    }

    NCPP_FORCE_INLINE F_vector2_f32 NMATH_CALL_CNV element_if_equal(PA_vector2_f32 a, PA_vector2_f32 expect, PA_vector2_f32 desire) noexcept {

        return {
            element_if_equal(a.x, expect.x, desire.x),
            element_if_equal(a.y, expect.y, desire.y)
        };
    }
    NCPP_FORCE_INLINE F_vector2_i32 NMATH_CALL_CNV element_if_equal(PA_vector2_i32 a, PA_vector2_i32 expect, PA_vector2_i32 desire) noexcept {

        return {
            element_if_equal(a.x, expect.x, desire.x),
            element_if_equal(a.y, expect.y, desire.y)
        };
    }
    NCPP_FORCE_INLINE F_vector2_u32 NMATH_CALL_CNV element_if_equal(PA_vector2_u32 a, PA_vector2_u32 expect, PA_vector2_u32 desire) noexcept {

        return {
            element_if_equal(a.x, expect.x, desire.x),
            element_if_equal(a.y, expect.y, desire.y)
        };
    }

    NCPP_FORCE_INLINE F_vector3_f32 NMATH_CALL_CNV element_if_equal(PA_vector3_f32 a, PA_vector3_f32 expect, PA_vector3_f32 desire) noexcept {

        return {
            element_if_equal(a.x, expect.x, desire.x),
            element_if_equal(a.y, expect.y, desire.y),
            element_if_equal(a.z, expect.z, desire.z)
        };
    }
    NCPP_FORCE_INLINE F_vector3_i32 NMATH_CALL_CNV element_if_equal(PA_vector3_i32 a, PA_vector3_i32 expect, PA_vector3_i32 desire) noexcept {

        return {
            element_if_equal(a.x, expect.x, desire.x),
            element_if_equal(a.y, expect.y, desire.y),
            element_if_equal(a.z, expect.z, desire.z)
        };
    }
    NCPP_FORCE_INLINE F_vector3_u32 NMATH_CALL_CNV element_if_equal(PA_vector3_u32 a, PA_vector3_u32 expect, PA_vector3_u32 desire) noexcept {

        return {
            element_if_equal(a.x, expect.x, desire.x),
            element_if_equal(a.y, expect.y, desire.y),
            element_if_equal(a.z, expect.z, desire.z)
        };
    }

    NCPP_FORCE_INLINE F_vector4_f32 NMATH_CALL_CNV element_if_equal(PA_vector4_f32 a, PA_vector4_f32 expect, PA_vector4_f32 desire) noexcept {

        return {
            element_if_equal(a.x, expect.x, desire.x),
            element_if_equal(a.y, expect.y, desire.y),
            element_if_equal(a.z, expect.z, desire.z),
            element_if_equal(a.w, expect.w, desire.w)
        };
    }

}
