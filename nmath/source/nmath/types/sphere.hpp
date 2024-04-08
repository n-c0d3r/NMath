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



    private:
        F_center_and_radius center_and_radius_;

    public:
        NCPP_FORCE_INLINE b8 is_valid() const noexcept { return (center_and_radius_.w > 0.0f); }
        NCPP_FORCE_INLINE F_center_and_radius center_and_radius() const noexcept { return center_and_radius_; }
        NCPP_FORCE_INLINE F_center center() const noexcept { return center_and_radius_.xyz(); }
        NCPP_FORCE_INLINE F_radius radius() const noexcept { return center_and_radius_.w; }



    public:
        NCPP_FORCE_INLINE TF_sphere() noexcept = default;
        NCPP_FORCE_INLINE TF_sphere(PA_center_and_radius center_and_radius) noexcept :
            center_and_radius_(center_and_radius)
        {}
        NCPP_FORCE_INLINE TF_sphere(F_radius radius) noexcept :
            center_and_radius_({
                F_center::zero(),
                radius
            })
        {}
        NCPP_FORCE_INLINE TF_sphere(const TF_sphere& x) noexcept :
            center_and_radius_(x.center_and_radius_)
        {}
        NCPP_FORCE_INLINE TF_sphere& operator = (const TF_sphere& x) noexcept {

            center_and_radius_ = x.center_and_radius_;

            return *this;
        }



    public:
        inline f32 NMATH_CALL_CNV distance_sq(PA_position v) const noexcept {

            f32 radius_sq = radius();
            radius_sq *= radius_sq;

            return (
                length_sq(v - center())
                - radius_sq
            );
        }
        inline f32 NMATH_CALL_CNV distance(PA_position v) const noexcept {

            return sqrt(
                distance_sq(v)
            );
        }
        inline b8 NMATH_CALL_CNV is_contains(PA_position v) const noexcept {

            f32 radius_sq = radius();
            radius_sq *= radius_sq;

            return (
                length_sq(v - center())
                <= radius_sq
            );
        }
        NCPP_FORCE_INLINE TF_sphere NMATH_CALL_CNV expand(PA_position v) noexcept {

            f32 radius_sq = radius();
            radius_sq *= radius_sq;

            F_position c = center();

            return {
                c,
                sqrt(
                    max(
                        length_sq(v - c),
                        radius_sq
                    )
                )
            };
        }

    };



    using F_sphere = TF_sphere<>;

    using F_sphere_f32 = TF_sphere<f32>;

}