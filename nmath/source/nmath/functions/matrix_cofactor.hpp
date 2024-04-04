#pragma once

/** @file nmath/functions/matrix_cofactor.hpp
*
*   Implement cofactor function for matrix.
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

#include <nmath/functions/matrix_determinant.hpp>

#pragma endregion



////////////////////////////////////////////////////////////////////////////////////
//  f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NCPP_FORCE_INLINE F_matrix2x2_f32 NMATH_CALL_CNV cofactor(PA_matrix2x2_f32 a) noexcept {

        return F_matrix2x2_f32(
            F_vector2_f32(a.b.y, -a.b.x),
            F_vector2_f32(-a.a.y, a.a.x)
        );
    }

    NCPP_FORCE_INLINE F_matrix3x3_f32 NMATH_CALL_CNV cofactor(PA_matrix3x3_f32 a) noexcept {

        F_matrix2x2_f32 aax = {
            a.b.yz(),
            a.c.yz()
        };
        F_matrix2x2_f32 abx = {
            a.a.yz(),
            a.c.yz()
        };
        F_matrix2x2_f32 acx = {
            a.a.yz(),
            a.b.yz()
        };

        F_matrix2x2_f32 aay = {
            a.b.xz(),
            a.c.xz()
        };
        F_matrix2x2_f32 aby = {
            a.a.xz(),
            a.c.xz()
        };
        F_matrix2x2_f32 acy = {
            a.a.xz(),
            a.b.xz()
        };

        F_matrix2x2_f32 aaz = {
            a.b.xy(),
            a.c.xy()
        };
        F_matrix2x2_f32 abz = {
            a.a.xy(),
            a.c.xy()
        };
        F_matrix2x2_f32 acz = {
            a.a.xy(),
            a.b.xy()
        };

        return F_matrix3x3_f32(
            F_vector3_f32(
                determinant(aax),
                - determinant(aay),
                determinant(aaz)
            ),
            F_vector3_f32(
                - determinant(abx),
                + determinant(aby),
                - determinant(abz)
            ),
            F_vector3_f32(
                determinant(acx),
                - determinant(acy),
                determinant(acz)
            )
        );
    }

    NCPP_FORCE_INLINE F_matrix4x4_f32 NMATH_CALL_CNV cofactor(PA_matrix4x4_f32 a) noexcept {

        F_matrix3x3_f32 aax = {
            a.b.yzw(),
            a.c.yzw(),
            a.d.yzw()
        };
        F_matrix3x3_f32 abx = {
            a.a.yzw(),
            a.c.yzw(),
            a.d.yzw()
        };
        F_matrix3x3_f32 acx = {
            a.a.yzw(),
            a.b.yzw(),
            a.d.yzw()
        };
        F_matrix3x3_f32 adx = {
            a.a.yzw(),
            a.b.yzw(),
            a.c.yzw()
        };

        F_matrix3x3_f32 aay = {
            a.b.xzw(),
            a.c.xzw(),
            a.d.xzw()
        };
        F_matrix3x3_f32 aby = {
            a.a.xzw(),
            a.c.xzw(),
            a.d.xzw()
        };
        F_matrix3x3_f32 acy = {
            a.a.xzw(),
            a.b.xzw(),
            a.d.xzw()
        };
        F_matrix3x3_f32 ady = {
            a.a.xzw(),
            a.b.xzw(),
            a.c.xzw()
        };

        F_matrix3x3_f32 aaz = {
            a.b.xyw(),
            a.c.xyw(),
            a.d.xyw()
        };
        F_matrix3x3_f32 abz = {
            a.a.xyw(),
            a.c.xyw(),
            a.d.xyw()
        };
        F_matrix3x3_f32 acz = {
            a.a.xyw(),
            a.b.xyw(),
            a.d.xyw()
        };
        F_matrix3x3_f32 adz = {
            a.a.xyw(),
            a.b.xyw(),
            a.c.xyw()
        };

        F_matrix3x3_f32 aaw = {
            a.b.xyz(),
            a.c.xyz(),
            a.d.xyz()
        };
        F_matrix3x3_f32 abw = {
            a.a.xyz(),
            a.c.xyz(),
            a.d.xyz()
        };
        F_matrix3x3_f32 acw = {
            a.a.xyz(),
            a.b.xyz(),
            a.d.xyz()
        };
        F_matrix3x3_f32 adw = {
            a.a.xyz(),
            a.b.xyz(),
            a.c.xyz()
        };

        return F_matrix4x4_f32(
            F_vector4_f32(
                determinant(aax),
                - determinant(aay),
                determinant(aaz),
                - determinant(aaw)
            ),
            F_vector4_f32(
                - determinant(abx),
                + determinant(aby),
                - determinant(abz),
                + determinant(abw)
            ),
            F_vector4_f32(
                determinant(acx),
                - determinant(acy),
                determinant(acz),
                - determinant(acw)
            ),
            F_vector4_f32(
                - determinant(adx),
                + determinant(ady),
                - determinant(adz),
                + determinant(adw)
            )
        );
    }

}