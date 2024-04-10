#pragma once

/** @file nmath/functions/decompose_transform.hpp
*
*   Implement decompose_transform.
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
#include <nmath/types/quaternion.hpp>
#include <nmath/functions/cross.hpp>
#include <nmath/functions/normalize.hpp>
#include <nmath/functions/dot.hpp>
#include <nmath/functions/normal_tangent_bitangent.hpp>
#include <nmath/functions/element_sign.hpp>

#pragma endregion



namespace nmath {

    template<typename F_element__ = NMATH_DEFAULT_FP_TYPE>
    struct TF_decompose_transform {

        using F_element = F_element__;

        TF_vector3<F_element__> scale;
        TF_vector3<F_element__> translation;
        TF_matrix3x3<F_element__> rotation_matrix;

    };



    ////////////////////////////////////////////////////////////////////////////////////
    //  f32
    ////////////////////////////////////////////////////////////////////////////////////
    inline TF_decompose_transform<f32> NMATH_CALL_CNV decompose_transform(PA_matrix3x3_f32 transform) noexcept {

        F_vector3_f32 scale = {
            length(transform.a),
            length(transform.b),
            length(transform.c)
        };

        F_matrix3x3_f32 dir3x3;
        F_matrix3x3_f32 normalized_axes = {
            transform.a / scale.x,
            transform.b / scale.y,
            transform.c / scale.z,
        };

        u8 is_zero_scale_x = (scale.x < NMATH_DEFAULT_TOLERANCE_F32);
        u8 is_zero_scale_y = (scale.y < NMATH_DEFAULT_TOLERANCE_F32);
        u8 is_zero_scale_z = (scale.z < NMATH_DEFAULT_TOLERANCE_F32);
        u8 zero_case_index = (
            is_zero_scale_x
            | (is_zero_scale_y << 1)
            | (is_zero_scale_z << 2)
        );

        switch(zero_case_index) {

            case(0b111):
                dir3x3 = T_identity<F_matrix3x3_f32>();
                break;

            case(0b101):
                dir3x3 = T_normal_to_rotation<F_matrix3x3_f32>(normalized_axes.b);
                break;

            case(0b110):
                dir3x3 = T_bitangent_to_rotation<F_matrix3x3_f32>(normalized_axes.a);
                break;

            case(0b100):
                dir3x3 = normalized_axes;
                dir3x3.c = cross(
                    normalized_axes.a,
                    normalized_axes.b
                );
                break;

            case(0b011):
                dir3x3 = T_tangent_to_rotation<F_matrix3x3_f32>(normalized_axes.c);
                break;

            case(0b001):
                dir3x3 = normalized_axes;
                dir3x3.a = cross(
                    normalized_axes.b,
                    normalized_axes.c
                );
                break;

            case(0b010):
                dir3x3 = normalized_axes;
                dir3x3.b = cross(
                    normalized_axes.c,
                    normalized_axes.a
                );
                break;

            case(0b000):
                dir3x3 = normalized_axes;
                if(
                    dot(
                        normalized_axes.c,
                        cross(normalized_axes.a, normalized_axes.b)
                    ) < 0.0f
                ) {
                    scale.z *= -1.0f;
                    dir3x3.c *= -1.0f;
                }
                break;

        }

        return {
            .scale = scale,
            .translation = F_vector3_f32::zero(),
            .rotation_matrix = F_matrix3x3_f32 {
                dir3x3.a,
                dir3x3.b,
                dir3x3.c
            }
        };
    }
    inline TF_decompose_transform<f32> NMATH_CALL_CNV decompose_transform(PA_matrix4x4_f32 transform) noexcept {

        F_matrix3x3_f32 transform3x3 = transform.tl3x3();

        F_vector3_f32 scale = {
            length(transform3x3.a),
            length(transform3x3.b),
            length(transform3x3.c)
        };

        F_vector3_f32 positive_z_vector = cross(transform3x3.a, transform3x3.b);

        if(
            dot(transform3x3.c, positive_z_vector)
            <= 0.0f
        ) {
            scale.z *= -1.0f;
        }

        return {
            .scale = scale,
            .translation = transform.translation.xyz(),
            .rotation_matrix = F_matrix3x3_f32 {
                (scale.x == 0.0f) ? F_vector3_f32::zero() : (transform3x3.a / scale.x),
                (scale.y == 0.0f) ? F_vector3_f32::zero() : (transform3x3.b / scale.y),
                (scale.z == 0.0f) ? F_vector3_f32::zero() : (transform3x3.c / scale.z)
            }
        };
    }

}
