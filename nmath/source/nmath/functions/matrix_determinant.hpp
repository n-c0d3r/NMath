#pragma once

/** @file nmath/functions/matrix_determinant.hpp
*
*   Implement determinant function for matrix.
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

#pragma endregion



////////////////////////////////////////////////////////////////////////////////////
//  f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NCPP_FORCE_INLINE f32 NMATH_CALL_CNV determinant(PA_matrix2x2_f32 a) noexcept {

        return (
            (a.a.x * a.b.y)
            - (a.b.x * a.a.y)
        );
    }

    NCPP_FORCE_INLINE f32 NMATH_CALL_CNV determinant(PA_matrix3x3_f32 a) noexcept {

        F_matrix2x2_f32 aa = {
            a.b.yz(),
            a.c.yz()
        };
        F_matrix2x2_f32 ab = {
            a.a.yz(),
            a.c.yz()
        };
        F_matrix2x2_f32 ac = {
            a.a.yz(),
            a.b.yz()
        };

        return (
            a.a.x * determinant(aa)
            - a.b.x * determinant(ab)
            + a.c.x * determinant(ac)
        );
    }

    NCPP_FORCE_INLINE f32 NMATH_CALL_CNV determinant(PA_matrix4x4_f32 a) noexcept {

        F_matrix3x3_f32 aa = {
            a.b.yzw(),
            a.c.yzw(),
            a.d.yzw()
        };
        F_matrix3x3_f32 ab = {
            a.a.yzw(),
            a.c.yzw(),
            a.d.yzw()
        };
        F_matrix3x3_f32 ac = {
            a.a.yzw(),
            a.b.yzw(),
            a.d.yzw()
        };
        F_matrix3x3_f32 ad = {
            a.a.yzw(),
            a.b.yzw(),
            a.c.yzw()
        };

        return (
            a.a.x * determinant(aa)
            - a.b.x * determinant(ab)
            + a.c.x * determinant(ac)
            - a.d.x * determinant(ad)
        );
    }

}