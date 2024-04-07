#pragma once

/** @file nmath/functions/transform.hpp
*
*   Implement T_make_transform.
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

#include <nmath/types/data_helper.hpp>
#include <nmath/functions/rotation.hpp>
#include <nmath/functions/scale.hpp>
#include <nmath/functions/translation.hpp>
#include <nmath/functions/matrix_to_matrix.hpp>

#pragma endregion



namespace nmath {

    template<E_rotation_axis rotate_axis__ = E_rotation_axis::ALL, typename F_element__ = NMATH_DEFAULT_FP_TYPE>
    TF_matrix4x4<F_element__> NMATH_CALL_CNV T_make_transform(auto, auto, auto) noexcept;

    template<>
    F_matrix4x4_f32 NMATH_CALL_CNV T_make_transform<
        E_rotation_axis::ALL,
        f32
    >(
        PA_vector3_f32 scale_vector,
        PA_vector3_f32 euler_angles,
        PA_vector3_f32 translation_vector
    ) noexcept {

        F_matrix4x4_f32 scale_matrix = T_convert<F_matrix4x4_f32, F_matrix3x3_f32>(
            T_make_scale<f32>(scale_vector)
        );
        F_matrix4x4_f32 rotation_matrix = T_convert<F_matrix4x4_f32, F_matrix3x3_f32>(
            T_make_rotation<
                E_rotation_axis::ALL,
                F_matrix3x3_f32,
                f32
            >(euler_angles)
        );
        F_matrix4x4_f32 translation_matrix = T_make_translation<f32>(
            translation_vector
        );

        return (
            translation_matrix
            * rotation_matrix
            * scale_matrix
        );
    }

    template<>
    F_matrix4x4_f32 NMATH_CALL_CNV T_make_transform<
        E_rotation_axis::X,
        f32
    >(
        PA_vector3_f32 scale_vector,
        f32 single_euler_angle,
        PA_vector3_f32 translation_vector
    ) noexcept {

        F_matrix4x4_f32 scale_matrix = T_convert<F_matrix4x4_f32, F_matrix3x3_f32>(
            T_make_scale<f32>(scale_vector)
        );
        F_matrix4x4_f32 rotation_matrix = T_convert<F_matrix4x4_f32, F_matrix3x3_f32>(
            T_make_rotation<
                E_rotation_axis::X,
                F_matrix3x3_f32,
                f32
            >(single_euler_angle)
        );
        F_matrix4x4_f32 translation_matrix = T_make_translation<f32>(
            translation_vector
        );

        return (
            translation_matrix
            * rotation_matrix
            * scale_matrix
        );
    }

    template<>
    F_matrix4x4_f32 NMATH_CALL_CNV T_make_transform<
        E_rotation_axis::Y,
        f32
    >(
        PA_vector3_f32 scale_vector,
        f32 single_euler_angle,
        PA_vector3_f32 translation_vector
    ) noexcept {

        F_matrix4x4_f32 scale_matrix = T_convert<F_matrix4x4_f32, F_matrix3x3_f32>(
            T_make_scale<f32>(scale_vector)
        );
        F_matrix4x4_f32 rotation_matrix = T_convert<F_matrix4x4_f32, F_matrix3x3_f32>(
            T_make_rotation<
                E_rotation_axis::Y,
                F_matrix3x3_f32,
                f32
            >(single_euler_angle)
        );
        F_matrix4x4_f32 translation_matrix = T_make_translation<f32>(
            translation_vector
        );

        return (
            translation_matrix
            * rotation_matrix
            * scale_matrix
        );
    }

    template<>
    F_matrix4x4_f32 NMATH_CALL_CNV T_make_transform<
        E_rotation_axis::Z,
        f32
    >(
        PA_vector3_f32 scale_vector,
        f32 single_euler_angle,
        PA_vector3_f32 translation_vector
    ) noexcept {

        F_matrix4x4_f32 scale_matrix = T_convert<F_matrix4x4_f32, F_matrix3x3_f32>(
            T_make_scale<f32>(scale_vector)
        );
        F_matrix4x4_f32 rotation_matrix = T_convert<F_matrix4x4_f32, F_matrix3x3_f32>(
            T_make_rotation<
                E_rotation_axis::Z,
                F_matrix3x3_f32,
                f32
            >(single_euler_angle)
        );
        F_matrix4x4_f32 translation_matrix = T_make_translation<f32>(
            translation_vector
        );

        return (
            translation_matrix
            * rotation_matrix
            * scale_matrix
        );
    }

    template<>
    F_matrix4x4_f32 NMATH_CALL_CNV T_make_transform<
        E_rotation_axis::CUSTOM,
        f32
    >(
        PA_vector3_f32 scale_vector,
        PA_vector4_f32 axis_and_angle,
        PA_vector3_f32 translation_vector
    ) noexcept {

        F_matrix4x4_f32 scale_matrix = T_convert<F_matrix4x4_f32, F_matrix3x3_f32>(
            T_make_scale<f32>(scale_vector)
        );
        F_quaternion_f32 rotation_quaternion = T_make_rotation<
            E_rotation_axis::CUSTOM,
            F_quaternion_f32,
            f32
        >(axis_and_angle);
        F_matrix4x4_f32 translation_matrix = T_make_translation<f32>(
            translation_vector
        );

        return (
            translation_matrix
            * rotation_quaternion
            * scale_matrix
        );
    }

}
