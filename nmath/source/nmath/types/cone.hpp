#pragma once

/** @file nmath/types/cone.hpp
*
*   Implement cone.
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
#include <nmath/types/plane.hpp>
#include <nmath/operators/vector_vector.hpp>
#include <nmath/operators/vector_scalar.hpp>
#include <nmath/functions/element_min_max.hpp>
#include <nmath/functions/length.hpp>
#include <nmath/utilities/passed_argument_helper.hpp>
#include <nmath/utilities/default_tolerance_helper.hpp>
#include <nmath/functions/normalize.hpp>

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

    template<typename F_element__ = NMATH_DEFAULT_FP_TYPE>
    class TF_cone {

    public:
        using F_element = F_element__;

        using F_pivot = TF_vector3<F_element__>;
        using PA_pivot = TPA_vector3<F_element__>;
        using F_direction = TF_vector3<F_element__>;
        using PA_direction = TPA_vector3<F_element__>;
        using F_min_angle_dot = F_element__;

        using F_direction_and_min_angle_dot = TF_vector4<F_element__>;
        using PA_direction_and_min_angle_dot = TPA_vector4<F_element__>;

        using F_position = TF_vector3<F_element__>;
        using PA_position = TPA_vector3<F_element__>;



    public:
        F_pivot pivot;
        F_direction_and_min_angle_dot direction_and_min_angle_dot;

    public:
        NCPP_FORCE_INLINE b8 is_valid() const noexcept
        {
            return (abs(length(direction()) - 1.0) <= T_default_tolerance<F_element__>) && (direction_and_min_angle_dot.w >= -1.0f) && (direction_and_min_angle_dot.w <= 1.0f);
        }
        NCPP_FORCE_INLINE b8 is_null() const noexcept
        {
            return (abs(length(direction()) - 1.0) > T_default_tolerance<F_element__>) || (direction_and_min_angle_dot.w < -1.0f) || (direction_and_min_angle_dot.w > 1.0f);
        }
        NCPP_FORCE_INLINE F_direction direction() const noexcept { return direction_and_min_angle_dot.xyz(); }
        NCPP_FORCE_INLINE F_min_angle_dot min_angle_dot() const noexcept { return direction_and_min_angle_dot.w; }



    public:
        NCPP_FORCE_INLINE TF_cone() noexcept = default;
        NCPP_FORCE_INLINE TF_cone(PA_pivot pivot, PA_direction_and_min_angle_dot direction_and_min_angle_dot) noexcept :
            pivot(pivot),
            direction_and_min_angle_dot(direction_and_min_angle_dot)
        {}
        NCPP_FORCE_INLINE TF_cone(PA_pivot pivot, PA_direction direction, f32 min_angle_dot) noexcept :
            pivot(pivot),
            direction_and_min_angle_dot({
                direction,
                min_angle_dot
            })
        {}
        NCPP_FORCE_INLINE TF_cone(const TF_cone& x) noexcept = default;
        NCPP_FORCE_INLINE TF_cone& operator = (const TF_cone& x) noexcept = default;



    public:
        NCPP_FORCE_INLINE operator b8 () const noexcept
        {
            return is_valid();
        }
        NCPP_FORCE_INLINE b8 is_unbound() const noexcept
        {
            return (min_angle_dot() <= (-1.0f + T_default_tolerance<F_element>));
        }
        F_element NMATH_CALL_CNV angle_dot(PA_position v) const noexcept
        {
            return dot(
                normalize(v - pivot),
                direction()
            );
        }
        b8 NMATH_CALL_CNV is_contains(PA_position v) const noexcept
        {
            return (
                angle_dot(v)
                > min_angle_dot()
            );
        }
        TF_cone NMATH_CALL_CNV expand(PA_position v) noexcept
        {
            return {
                pivot,
                direction(),
                eastl::min<F_element>(
                    angle_dot(v),
                    min_angle_dot()
                )
            };
        }
        TF_cone NMATH_CALL_CNV shrink(PA_position v) noexcept
        {
            return {
                pivot,
                direction(),
                eastl::max<F_element>(
                    angle_dot(v),
                    min_angle_dot()
                )
            };
        }
    };



    using F_cone = TF_cone<>;

    using F_cone_f32 = TF_cone<f32>;
}
