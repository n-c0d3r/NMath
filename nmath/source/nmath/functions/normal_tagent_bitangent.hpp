#pragma once

/** @file nmath/functions/normal_tangent_bitangent.hpp
*
*   Implement functions for normal, tangent, bitangent calculations.
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
#include <nmath/types/vector.hpp>
#include <nmath/operators/vector_vector.hpp>
#include <nmath/functions/normalize.hpp>
#include <nmath/functions/cross.hpp>
#include <nmath/functions/matrix_identity.hpp>

#pragma endregion



namespace nmath {

    ////////////////////////////////////////////////////////////////////////////////////
    //  f32
    ////////////////////////////////////////////////////////////////////////////////////
    inline F_matrix3x3_f32 NMATH_CALL_CNV normal_to_direction_matrix(PA_vector3_f32 normal) noexcept {

        if (normal.z <= 0.999f) {

            F_vector3_f32 bitangent = normalize(
                cross(normal, F_vector3_f32::forward())
            );

            return {
                bitangent,
                normal,
                cross(bitangent, normal)
            };
        }
        else
            return T_identity<F_matrix3x3_f32>();

    }
    inline F_vector3_f32 NMATH_CALL_CNV normal_to_tangent(PA_vector3_f32 normal) noexcept {

        return (
            (normal.x <= 0.999f)
            ? normalize(
                cross(F_vector3_f32::right(), normal)
            )
            : F_vector3_f32::forward()
        );
    }
    inline F_vector3_f32 NMATH_CALL_CNV normal_to_bitangent(PA_vector3_f32 normal) noexcept {

        return (
            (normal.z <= 0.999f)
            ? normalize(
                cross(normal, F_vector3_f32::forward())
            )
            : F_vector3_f32::right()
        );
    }

}
