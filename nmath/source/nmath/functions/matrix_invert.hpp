#pragma once

/** @file nmath/functions/matrix_invert.hpp
*
*   Implement invert function for matrix.
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

#include <nmath/types/matrix2x2.hpp>
#include <nmath/types/matrix3x3.hpp>
#include <nmath/types/matrix4x4.hpp>

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#include <nmath/functions/matrix_transpose.hpp>
#include <nmath/functions/matrix_determinant.hpp>
#include <nmath/functions/matrix_cofactor.hpp>
#include <nmath/operators/matrix_scalar.hpp>

#pragma endregion



////////////////////////////////////////////////////////////////////////////////////
//  f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NCPP_FORCE_INLINE F_matrix2x2_f32 NMATH_CALL_CNV invert(PA_matrix2x2_f32 a, f32 determinant) noexcept {

        return transpose(cofactor(a)) / determinant;
    }

    NCPP_FORCE_INLINE F_matrix3x3_f32 NMATH_CALL_CNV invert(PA_matrix3x3_f32 a, f32 determinant) noexcept {

        return transpose(cofactor(a)) / determinant;
    }

    NCPP_FORCE_INLINE F_matrix4x4_f32 NMATH_CALL_CNV invert(PA_matrix4x4_f32 a, f32 determinant) noexcept {

        return transpose(cofactor(a)) / determinant;
    }



    NCPP_FORCE_INLINE F_matrix2x2_f32 NMATH_CALL_CNV invert(PA_matrix2x2_f32 a) noexcept {

        return invert(a, determinant(a));
    }

    NCPP_FORCE_INLINE F_matrix3x3_f32 NMATH_CALL_CNV invert(PA_matrix3x3_f32 a) noexcept {

        return invert(a, determinant(a));
    }

    NCPP_FORCE_INLINE F_matrix4x4_f32 NMATH_CALL_CNV invert(PA_matrix4x4_f32 a) noexcept {

        return invert(a, determinant(a));
    }

}