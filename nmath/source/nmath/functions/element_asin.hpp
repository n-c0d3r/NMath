#pragma once

/** @file nmath/functions/element_asin.hpp
*
*   Implement element_asin.
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

    NCPP_FORCE_INLINE f32 element_asin(f32 a) noexcept {

        return asin(a);
    }
    NCPP_FORCE_INLINE f64 element_asin(f64 a) noexcept {

        return asin(a);
    }

    NCPP_FORCE_INLINE F_vector2_f32 NMATH_CALL_CNV element_asin(PA_vector2_f32 a) noexcept {

        return {
            element_asin(a.x),
            element_asin(a.y)
        };
    }

    NCPP_FORCE_INLINE F_vector3_f32 NMATH_CALL_CNV element_asin(PA_vector3_f32 a) noexcept {

        return {
            element_asin(a.x),
            element_asin(a.y),
            element_asin(a.z)
        };
    }

    NCPP_FORCE_INLINE F_vector4_f32 NMATH_CALL_CNV element_asin(PA_vector4_f32 a) noexcept {

        return {
            element_asin(a.x),
            element_asin(a.y),
            element_asin(a.z),
            element_asin(a.w)
        };
    }

}
