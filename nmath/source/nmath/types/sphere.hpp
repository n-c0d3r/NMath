#pragma once

/** @file nmath/types/sphere.hpp
*
*   Implement sphere.
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
#include <nmath/operators/vector_vector.hpp>
#include <nmath/operators/vector_scalar.hpp>
#include <nmath/functions/element_min_max.hpp>
#include <nmath/functions/length.hpp>
#include <nmath/utilities/passed_argument_helper.hpp>
#include <nmath/utilities/default_tolerance_helper.hpp>

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
    class TF_sphere {

    public:
        using F_element = F_element__;

        using F_center = TF_vector3<F_element__>;
        using PA_center = TPA_vector3<F_element__>;
        using F_radius = F_element__;

        using F_center_and_radius = TF_vector4<F_element__>;
        using PA_center_and_radius = TPA_vector4<F_element__>;

        using F_position = TF_vector3<F_element__>;
        using PA_position = TPA_vector3<F_element__>;



    public:
        F_center_and_radius center_and_radius;

    public:
        NCPP_FORCE_INLINE b8 is_valid() const noexcept { return (center_and_radius.w > T_default_tolerance<F_element>); }
        NCPP_FORCE_INLINE F_center center() const noexcept { return center_and_radius.xyz(); }
        NCPP_FORCE_INLINE F_radius radius() const noexcept { return center_and_radius.w; }



    public:
        NCPP_FORCE_INLINE TF_sphere() noexcept = default;
        NCPP_FORCE_INLINE TF_sphere(PA_center_and_radius center_and_radius) noexcept :
            center_and_radius(center_and_radius)
        {}
        NCPP_FORCE_INLINE TF_sphere(PA_center center) noexcept :
            center_and_radius({ center, 0.0f })
        {}
        NCPP_FORCE_INLINE TF_sphere(F_radius radius) noexcept :
            center_and_radius({
                F_center::zero(),
                radius
            })
        {}
        NCPP_FORCE_INLINE TF_sphere(const TF_sphere& x) noexcept :
            center_and_radius(x.center_and_radius)
        {}
        NCPP_FORCE_INLINE TF_sphere& operator = (const TF_sphere& x) noexcept {

            center_and_radius = x.center_and_radius;

            return *this;
        }



    public:
        NCPP_FORCE_INLINE operator b8 () const noexcept {

            return is_valid();
        }
        F_element NMATH_CALL_CNV signed_distance(PA_position v) const noexcept {

            return (
                length(v - center())
                - radius()
            );
        }
        b8 NMATH_CALL_CNV is_contains(PA_position v) const noexcept {

            F_element radius_sq = radius();
            radius_sq *= radius_sq;

            return (
                length_sq(v - center())
                <= radius_sq
            );
        }
        TF_sphere NMATH_CALL_CNV expand(PA_position v) noexcept {

            F_element r = radius();
            F_position c = center();

            return {
                c,
                eastl::max(
                    length(v - c),
                    r
                )
            };
        }
        b8 NMATH_CALL_CNV is_contains(const TF_sphere& x) const noexcept {

            F_element radius_sq = radius();
            radius_sq *= radius_sq;

            F_element x_radius = x.radius();

            return (
                (
                    length_sq(x.center() - center())
                    + x_radius * x_radius
                )
                <= radius_sq
            );
        }
        TF_sphere NMATH_CALL_CNV expand(const TF_sphere& x) noexcept {

            F_element r = radius();
            F_position c = center();

            return {
                c,
                eastl::max(
                    (
                        length(x.center() - c)
                        + x.radius()
                    ),
                    r
                )
            };
        }
    };



    using F_sphere = TF_sphere<>;

    using F_sphere_f32 = TF_sphere<f32>;
}
