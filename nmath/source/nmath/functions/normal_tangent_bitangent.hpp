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
#include <nmath/functions/matrix_to_quaternion.hpp>
#include <nmath/functions/rotation_look_at.hpp>

#pragma endregion



namespace nmath {

    ////////////////////////////////////////////////////////////////////////////////////
    //  f32
    ////////////////////////////////////////////////////////////////////////////////////
    template<typename F_rotation__ = F_quaternion_f32>
    F_rotation__ NMATH_CALL_CNV T_normal_to_rotation(auto normal) noexcept;

    template<>
    inline F_matrix3x3_f32 NMATH_CALL_CNV T_normal_to_rotation<F_matrix3x3_f32>(PA_vector3_f32 normal) noexcept {

        if (abs(normal.z) <= 0.999f) {

            F_vector3_f32 bitangent = normalize(
                cross(normal, F_vector3_f32::forward())
            );

            return {
                bitangent,
                normal,
                cross(bitangent, normal)
            };
        }
        else {

            F_vector3_f32 tangent = normalize(
                cross(F_vector3_f32::right(), normal)
            );

            return {
                cross(normal, tangent),
                normal,
                tangent
            };
        }

    }
    template<>
    NCPP_FORCE_INLINE F_quaternion_f32 NMATH_CALL_CNV T_normal_to_rotation<F_quaternion_f32>(PA_vector3_f32 normal) noexcept {

        return T_rotation_look_at<F_quaternion_f32>(
            F_vector3_f32::up(),
            normal
        );
    }
    inline F_vector3_f32 NMATH_CALL_CNV normal_to_tangent(PA_vector3_f32 normal) noexcept {

        if (abs(normal.x) <= 0.999f) {

            return normalize(
                cross(F_vector3_f32::right(), normal)
            );
        }
        else {

            F_vector3_f32 bitangent = normalize(
                cross(normal, F_vector3_f32::forward())
            );

            return cross(bitangent, normal);
        }
    }
    inline F_vector3_f32 NMATH_CALL_CNV normal_to_bitangent(PA_vector3_f32 normal) noexcept {

        if (abs(normal.z) <= 0.999f) {

            return normalize(
                cross(normal, F_vector3_f32::forward())
            );
        }
        else {

            F_vector3_f32 tangent = normalize(
                cross(F_vector3_f32::right(), normal)
            );

            return cross(normal, tangent);
        }
    }

}



namespace nmath {

    ////////////////////////////////////////////////////////////////////////////////////
    //  f32
    ////////////////////////////////////////////////////////////////////////////////////
    template<typename F_rotation__ = F_quaternion_f32>
    F_rotation__ NMATH_CALL_CNV T_tangent_to_rotation(auto tangent) noexcept;

    template<>
    inline F_matrix3x3_f32 NMATH_CALL_CNV T_tangent_to_rotation<F_matrix3x3_f32>(PA_vector3_f32 tangent) noexcept {

        if (abs(tangent.x) <= 0.999f) {

            F_vector3_f32 normal = normalize(
                cross(tangent, F_vector3_f32::right())
            );

            return {
                cross(normal, tangent),
                normal,
                tangent
            };
        }
        else {

            F_vector3_f32 bitangent = normalize(
                cross(F_vector3_f32::up(), tangent)
            );

            return {
                bitangent,
                cross(tangent, bitangent),
                tangent
            };
        }

    }
    template<>
    NCPP_FORCE_INLINE F_quaternion_f32 NMATH_CALL_CNV T_tangent_to_rotation<F_quaternion_f32>(PA_vector3_f32 tangent) noexcept {

        return T_rotation_look_at<F_quaternion_f32>(
            F_vector3_f32::forward(),
            tangent
        );
    }
    inline F_vector3_f32 NMATH_CALL_CNV tangent_to_bitangent(PA_vector3_f32 tangent) noexcept {

        if (abs(tangent.y) <= 0.999f) {

            return normalize(
                cross(F_vector3_f32::up(), tangent)
            );
        }
        else {

            F_vector3_f32 normal = normalize(
                cross(tangent, F_vector3_f32::right())
            );

            return cross(normal, tangent);
        }
    }
    inline F_vector3_f32 NMATH_CALL_CNV tangent_to_normal(PA_vector3_f32 tangent) noexcept {

        if (abs(tangent.x) <= 0.999f) {

            return normalize(
                cross(tangent, F_vector3_f32::right())
            );
        }
        else {

            F_vector3_f32 bitangent = normalize(
                cross(F_vector3_f32::up(), tangent)
            );

            return cross(tangent, bitangent);
        }
    }

}



namespace nmath {

    ////////////////////////////////////////////////////////////////////////////////////
    //  f32
    ////////////////////////////////////////////////////////////////////////////////////
    template<typename F_rotation__ = F_quaternion_f32>
    F_rotation__ NMATH_CALL_CNV T_bitangent_to_rotation(auto normal) noexcept;

    template<>
    inline F_matrix3x3_f32 NMATH_CALL_CNV T_bitangent_to_rotation<F_matrix3x3_f32>(PA_vector3_f32 bitangent) noexcept {

        if (abs(bitangent.y) <= 0.999f) {

            F_vector3_f32 tangent = normalize(
                cross(bitangent, F_vector3_f32::up())
            );

            return {
                bitangent,
                cross(tangent, bitangent),
                tangent
            };
        }
        else {

            F_vector3_f32 normal = normalize(
                cross(F_vector3_f32::forward(), bitangent)
            );

            return {
                bitangent,
                normal,
                cross(bitangent, normal)
            };
        }

    }
    template<>
    NCPP_FORCE_INLINE F_quaternion_f32 NMATH_CALL_CNV T_bitangent_to_rotation<F_quaternion_f32>(PA_vector3_f32 bitangent) noexcept {

        return T_rotation_look_at<F_quaternion_f32>(
            F_vector3_f32::right(),
            bitangent
        );
    }
    inline F_vector3_f32 NMATH_CALL_CNV bitangent_to_normal(PA_vector3_f32 bitangent) noexcept {

        if (abs(bitangent.z) <= 0.999f) {

            return normalize(
                cross(F_vector3_f32::forward(), bitangent)
            );
        }
        else {

            F_vector3_f32 tangent = normalize(
                cross(bitangent, F_vector3_f32::up())
            );

            return cross(tangent, bitangent);
        }
    }
    inline F_vector3_f32 NMATH_CALL_CNV bitangent_to_tangent(PA_vector3_f32 bitangent) noexcept {

        if (abs(bitangent.y) <= 0.999f) {

            return normalize(
                cross(bitangent, F_vector3_f32::up())
            );
        }
        else {

            F_vector3_f32 normal = normalize(
                cross(F_vector3_f32::forward(), bitangent)
            );

            return cross(bitangent, normal);
        }
    }

}
