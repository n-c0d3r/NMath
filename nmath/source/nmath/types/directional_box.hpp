#pragma once

/** @file nmath/types/directional_box.hpp
*
*   Implement directional_box.
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

#include <nmath/types/box.hpp>
#include <nmath/types/quaternion.hpp>
#include <nmath/functions/identity_template.hpp>
#include <nmath/operators/matrix_matrix.hpp>
#include <nmath/operators/quaternion_quaternion.hpp>
#include <nmath/operators/quaternion_vector.hpp>

#pragma endregion



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



namespace nmath {

    template<typename F_element__ = NMATH_DEFAULT_FP_TYPE, typename F_rotation__ = TF_quaternion<F_element__>>
    class TF_directional_box
    {
    private:
        using F_box = TF_box<F_element__>;



    public:
        using F_element = F_element__;

        using F_value = TF_vector3<F_element>;
        using PA_value = TPA_vector3<F_element>;

        using F_rotation = F_rotation__;
        using PA_rotation = TPA<F_rotation>;



    public:
        F_box box;
        F_rotation rotation;



    public:
        NCPP_FORCE_INLINE TF_directional_box() noexcept = default;
        NCPP_FORCE_INLINE TF_directional_box(const F_box& box) noexcept :
            box(box),
            rotation(T_identity<F_rotation>())
        {}
        NCPP_FORCE_INLINE TF_directional_box(const F_box& box, PA_rotation rotation) noexcept :
            box(box),
            rotation(rotation)
        {}
        NCPP_FORCE_INLINE TF_directional_box(const TF_directional_box& x) noexcept :
            TF_directional_box(x.box, x.rotation)
        {}
        NCPP_FORCE_INLINE TF_directional_box& operator = (const TF_directional_box& x) noexcept {

            box = x.box;
            rotation = x.rotation;

            return *this;
        }

    public:
        F_element volume() const noexcept {

            return box.volume();
        }
        F_element volume_sq() const noexcept {

            return box.volume_sq();
        }

    public:
        TG_array<F_value, 6> corners() const noexcept {

            auto result = box.corners();

            result[0] = rotation * result[0];
            result[1] = rotation * result[1];
            result[2] = rotation * result[2];
            result[3] = rotation * result[3];
            result[4] = rotation * result[4];
            result[5] = rotation * result[5];

            return result;
        }

    public:
        static TF_directional_box one() noexcept
        {
            return {
                { F_value::one() }
            };
        }
        static TF_directional_box zero() noexcept
        {
            return {
                { F_value::zero() }
            };
        }
        static TF_directional_box one(PA_rotation rotation) noexcept
        {
            return {
                { F_value::one() },
                rotation
            };
        }
        static TF_directional_box zero(PA_rotation rotation) noexcept
        {
            return {
                { F_value::zero() },
                rotation
            };
        }
    };



    using F_directional_box = TF_directional_box<>;

    using F_directional_box_f32 = TF_directional_box<f32>;
    using F_directional_box_i32 = TF_directional_box<i32>;
    using F_directional_box_u32 = TF_directional_box<u32>;



    template<typename F_element__ = NMATH_DEFAULT_FP_TYPE, typename F_rotation__ = TF_quaternion<F_element__>>
    NCPP_FORCE_INLINE TF_directional_box<F_element__, F_rotation__> NMATH_CALL_CNV T_directional_box_multiply(
        TPA<F_rotation__> rotation,
        const TF_directional_box<F_element__, F_rotation__>& directional_box
    ) noexcept
    {
        return {
            directional_box.box,
            rotation * directional_box.rotation
        };
    }

    template<typename F_element__ = NMATH_DEFAULT_FP_TYPE, typename F_rotation__ = TF_quaternion<F_element__>>
    NCPP_FORCE_INLINE TF_directional_box<F_element__, F_rotation__> NMATH_CALL_CNV T_directional_box_multiply(
        const TF_directional_box<F_element__, F_rotation__>& directional_box,
        TPA<F_rotation__> rotation
    ) noexcept
    {
        return {
            directional_box.box,
            directional_box.rotation * rotation
        };
    }

    NCPP_FORCE_INLINE TF_directional_box<f32, F_matrix3x3_f32> NMATH_CALL_CNV multiply(
        PA_matrix3x3_f32 rotation,
        const TF_directional_box<f32, F_matrix3x3_f32>& directional_box
    ) noexcept
    {
        return T_directional_box_multiply<f32, F_matrix3x3_f32>(
            rotation,
            directional_box
        );
    }
    NCPP_FORCE_INLINE TF_directional_box<f32, F_matrix4x4_f32> NMATH_CALL_CNV multiply(
        PA_matrix4x4_f32 rotation,
        const TF_directional_box<f32, F_matrix4x4_f32>& directional_box
    ) noexcept
    {
        return T_directional_box_multiply<f32, F_matrix4x4_f32>(
            rotation,
            directional_box
        );
    }
    NCPP_FORCE_INLINE TF_directional_box<f32, F_quaternion_f32> NMATH_CALL_CNV multiply(
        PA_quaternion_f32 rotation,
        const TF_directional_box<f32, F_quaternion_f32>& directional_box
    ) noexcept
    {
        return T_directional_box_multiply<f32, F_quaternion_f32>(
            rotation,
            directional_box
        );
    }

    NCPP_FORCE_INLINE TF_directional_box<f32, F_matrix3x3_f32> NMATH_CALL_CNV multiply(
        const TF_directional_box<f32, F_matrix3x3_f32>& directional_box,
        PA_matrix3x3_f32 rotation
    ) noexcept
    {
        return T_directional_box_multiply<f32, F_matrix3x3_f32>(
            directional_box,
            rotation
        );
    }
    NCPP_FORCE_INLINE TF_directional_box<f32, F_matrix4x4_f32> NMATH_CALL_CNV multiply(
        const TF_directional_box<f32, F_matrix4x4_f32>& directional_box,
        PA_matrix4x4_f32 rotation
    ) noexcept
    {
        return T_directional_box_multiply<f32, F_matrix4x4_f32>(
            directional_box,
            rotation
        );
    }
    NCPP_FORCE_INLINE TF_directional_box<f32, F_quaternion_f32> NMATH_CALL_CNV multiply(
        const TF_directional_box<f32, F_quaternion_f32>& directional_box,
        PA_quaternion_f32 rotation
    ) noexcept
    {
        return T_directional_box_multiply<f32, F_quaternion_f32>(
            directional_box,
            rotation
        );
    }
}



NMATH_DEFINE_MULTIPLY_OPERATOR(
    nmath::PA_matrix3x3_f32,
    const NCPP_MA(nmath::TF_directional_box<ncpp::f32, nmath::F_matrix3x3_f32>)&,
    nmath::NCPP_MA(TF_directional_box<ncpp::f32, nmath::F_matrix3x3_f32>)
);
NCPP_FORCE_INLINE nmath::TF_directional_box<ncpp::f32, nmath::F_matrix3x3_f32> NMATH_CALL_CNV operator *= (
    nmath::F_matrix3x3_f32& a,
    const nmath::TF_directional_box<ncpp::f32, nmath::F_matrix3x3_f32>& b
) noexcept
{
   return nmath::multiply(a, b);
}

NMATH_DEFINE_MULTIPLY_OPERATOR(
    nmath::PA_matrix4x4_f32,
    const NCPP_MA(nmath::TF_directional_box<ncpp::f32, nmath::F_matrix4x4_f32>)&,
    nmath::NCPP_MA(TF_directional_box<ncpp::f32, nmath::F_matrix4x4_f32>)
);
NCPP_FORCE_INLINE nmath::TF_directional_box<ncpp::f32, nmath::F_matrix4x4_f32> NMATH_CALL_CNV operator *= (
    nmath::F_matrix4x4_f32& a,
    const nmath::TF_directional_box<ncpp::f32, nmath::F_matrix4x4_f32>& b
) noexcept
{
    return nmath::multiply(a, b);
}

NMATH_DEFINE_MULTIPLY_OPERATOR(
    nmath::PA_quaternion_f32,
    const NCPP_MA(nmath::TF_directional_box<ncpp::f32, nmath::F_quaternion_f32>)&,
    nmath::NCPP_MA(TF_directional_box<ncpp::f32, nmath::F_quaternion_f32>)
);
NCPP_FORCE_INLINE nmath::TF_directional_box<ncpp::f32, nmath::F_quaternion_f32> NMATH_CALL_CNV operator *= (
    nmath::F_quaternion_f32& a,
    const nmath::TF_directional_box<ncpp::f32, nmath::F_quaternion_f32>& b
) noexcept
{
    return nmath::multiply(a, b);
}



NMATH_DEFINE_MULTIPLY_OPERATOR(
    const NCPP_MA(nmath::TF_directional_box<ncpp::f32, nmath::F_matrix3x3_f32>)&,
    nmath::PA_matrix3x3_f32,
    nmath::NCPP_MA(TF_directional_box<ncpp::f32, nmath::F_matrix3x3_f32>)
);
NCPP_FORCE_INLINE nmath::TF_directional_box<ncpp::f32, nmath::F_matrix3x3_f32>& NMATH_CALL_CNV operator *= (
    nmath::TF_directional_box<ncpp::f32, nmath::F_matrix3x3_f32>& a,
    nmath::PA_matrix3x3_f32 b
) noexcept
{
    a = nmath::multiply(a, b);

    return a;
}

NMATH_DEFINE_MULTIPLY_OPERATOR(
    const NCPP_MA(nmath::TF_directional_box<ncpp::f32, nmath::F_matrix4x4_f32>)&,
    nmath::PA_matrix4x4_f32,
    nmath::NCPP_MA(TF_directional_box<ncpp::f32, nmath::F_matrix4x4_f32>)
);
NCPP_FORCE_INLINE nmath::TF_directional_box<ncpp::f32, nmath::F_matrix4x4_f32>& NMATH_CALL_CNV operator *= (
    nmath::TF_directional_box<ncpp::f32, nmath::F_matrix4x4_f32>& a,
    nmath::PA_matrix4x4_f32 b
) noexcept
{
    a = nmath::multiply(a, b);

    return a;
}

NMATH_DEFINE_MULTIPLY_OPERATOR(
    const NCPP_MA(nmath::TF_directional_box<ncpp::f32, nmath::F_quaternion_f32>)&,
    nmath::PA_quaternion_f32,
    nmath::NCPP_MA(TF_directional_box<ncpp::f32, nmath::F_quaternion_f32>)
);
NCPP_FORCE_INLINE nmath::TF_directional_box<ncpp::f32, nmath::F_quaternion_f32>& NMATH_CALL_CNV operator *= (
    nmath::TF_directional_box<ncpp::f32, nmath::F_quaternion_f32>& a,
    nmath::PA_quaternion_f32 b
) noexcept
{
    a = nmath::multiply(a, b);

    return a;
}