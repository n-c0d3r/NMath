#pragma once

/** @file nmath/functions/lerp.hpp
*
*   Implement lerp.
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
#include <nmath/types/quaternion.hpp>
#include <nmath/types/matrix.hpp>
#include <nmath/operators/vector_scalar.hpp>
#include <nmath/operators/quaternion_scalar.hpp>
#include <nmath/operators/matrix_scalar.hpp>
#include <nmath/functions/data2_functions.hpp>
#include <nmath/functions/data3_functions.hpp>
#include <nmath/functions/data4_functions.hpp>
#include <nmath/functions/data2x2_functions.hpp>
#include <nmath/functions/data3x3_functions.hpp>
#include <nmath/functions/data4x4_functions.hpp>

#pragma endregion



namespace nmath {

    NCPP_FORCE_INLINE f32 lerp(f32 a, f32 b, f32 t) noexcept {

        return a * (1.0f - t) + b * t;
    }

    NCPP_FORCE_INLINE F_vector2_f32 lerp(PA_vector2_f32 a, PA_vector2_f32 b, PA_vector2_f32 t) noexcept {

        return a * (F_vector2_f32::one() - t) + b * t;
    }
    NCPP_FORCE_INLINE F_vector2_f32 lerp(PA_vector2_f32 a, PA_vector2_f32 b, f32 t) noexcept {

        return lerp(
            a,
            b,
            F_vector2_f32::one() * t
        );
    }
    NCPP_FORCE_INLINE F_vector3_f32 lerp(PA_vector3_f32 a, PA_vector3_f32 b, PA_vector3_f32 t) noexcept {

        return a * (F_vector3_f32::one() - t) + b * t;
    }
    NCPP_FORCE_INLINE F_vector3_f32 lerp(PA_vector3_f32 a, PA_vector3_f32 b, f32 t) noexcept {

        return lerp(
            a,
            b,
            F_vector3_f32::one() * t
        );
    }
    NCPP_FORCE_INLINE F_vector4_f32 lerp(PA_vector4_f32 a, PA_vector4_f32 b, PA_vector4_f32 t) noexcept {

        return a * (F_vector4_f32::one() - t) + b * t;
    }
    NCPP_FORCE_INLINE F_vector4_f32 lerp(PA_vector4_f32 a, PA_vector4_f32 b, f32 t) noexcept {

        return lerp(
            a,
            b,
            F_vector4_f32::one() * t
        );
    }

    NCPP_FORCE_INLINE F_quaternion_f32 lerp(PA_quaternion_f32 a, PA_quaternion_f32 b, PA_vector4_f32 t) noexcept {

        return quaternion_forward(
            data4_add(
                data4_multiply(
                    data_forward(a),
                    data_forward(F_vector4_f32::one() - t)
                ),
                data4_multiply(
                    data_forward(b),
                    data_forward(t)
                )
            )
        );
    }
    NCPP_FORCE_INLINE F_quaternion_f32 lerp(PA_quaternion_f32 a, PA_quaternion_f32 b, f32 t) noexcept {

        return lerp(
            a,
            b,
            F_vector4_f32::one() * t
        );
    }

    NCPP_FORCE_INLINE F_matrix2x2_f32 lerp(PA_matrix2x2_f32 a, PA_matrix2x2_f32 b, PA_matrix2x2_f32 t) noexcept {

        return vecma_forward(
            data2x2_add(
                data2x2_multiply(
                    data_forward(a),
                    data_forward(F_matrix2x2_f32::one() - t)
                ),
                data2x2_multiply(
                    data_forward(b),
                    data_forward(t)
                )
            )
        );
    }
    NCPP_FORCE_INLINE F_matrix2x2_f32 lerp(PA_matrix2x2_f32 a, PA_matrix2x2_f32 b, f32 t) noexcept {

        return lerp(
            a,
            b,
            F_matrix2x2_f32::one() * t
        );
    }
    NCPP_FORCE_INLINE F_matrix3x3_f32 lerp(PA_matrix3x3_f32 a, PA_matrix3x3_f32 b, PA_matrix3x3_f32 t) noexcept {

        return vecma_forward(
            data3x3_add(
                data3x3_multiply(
                    data_forward(a),
                    data_forward(F_matrix3x3_f32::one() - t)
                ),
                data3x3_multiply(
                    data_forward(b),
                    data_forward(t)
                )
            )
        );
    }
    NCPP_FORCE_INLINE F_matrix3x3_f32 lerp(PA_matrix3x3_f32 a, PA_matrix3x3_f32 b, f32 t) noexcept {

        return lerp(
            a,
            b,
            F_matrix3x3_f32::one() * t
        );
    }
    NCPP_FORCE_INLINE F_matrix4x4_f32 lerp(PA_matrix4x4_f32 a, PA_matrix4x4_f32 b, PA_matrix4x4_f32 t) noexcept {

        return vecma_forward(
            data4x4_add(
                data4x4_multiply(
                    data_forward(a),
                    data_forward(F_matrix4x4_f32::one() - t)
                ),
                data4x4_multiply(
                    data_forward(b),
                    data_forward(t)
                )
            )
        );
    }
    NCPP_FORCE_INLINE F_matrix4x4_f32 lerp(PA_matrix4x4_f32 a, PA_matrix4x4_f32 b, f32 t) noexcept {

        return lerp(
            a,
            b,
            F_matrix4x4_f32::one() * t
        );
    }

}