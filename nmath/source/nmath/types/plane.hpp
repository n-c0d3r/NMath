#pragma once

/** @file nmath/types/plane.hpp
*
*   Implement plane.
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
#include <nmath/types/matrix.hpp>
#include <nmath/operators/matrix_vector.hpp>
#include <nmath/operators/quaternion_vector.hpp>
#include <nmath/operators/vector_vector.hpp>
#include <nmath/operators/vector_scalar.hpp>
#include <nmath/functions/element_min_max.hpp>
#include <nmath/functions/length.hpp>
#include <nmath/functions/vector_to_vector.hpp>
#include <nmath/functions/direction_position.hpp>
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
    class TF_plane {

    public:
        using F_element = F_element__;

        using F_direction = TF_vector3<F_element__>;
        using PA_direction = TPA_vector3<F_element__>;

        using F_position = TF_vector3<F_element__>;
        using PA_position = TPA_vector3<F_element__>;



    public:
        F_position center;
        F_direction direction;

    public:
        NCPP_FORCE_INLINE b8 is_valid() const noexcept { return (abs(length(direction) - 1.0) <= T_default_tolerance<F_element__>); }
        NCPP_FORCE_INLINE b8 is_null() const noexcept { return (abs(length(direction) - 1.0) > T_default_tolerance<F_element__>); }



    public:
        NCPP_FORCE_INLINE TF_plane() noexcept = default;
        NCPP_FORCE_INLINE TF_plane(PA_position center, PA_direction direction) noexcept :
            center(center),
            direction(direction)
        {}
        NCPP_FORCE_INLINE TF_plane(PA_direction direction) noexcept :
            center(F_position::zero()),
            direction(direction)
        {}
        NCPP_FORCE_INLINE TF_plane(const TF_plane& x) noexcept :
            center(x.center),
            direction(x.direction)
        {}
        NCPP_FORCE_INLINE TF_plane& operator = (const TF_plane& x) noexcept
        {
            this->center = x.center;
            this->direction = x.direction;

            return *this;
        }



    public:
        NCPP_FORCE_INLINE operator b8 () const noexcept
        {
            return is_valid();
        }
        F_element NMATH_CALL_CNV signed_distance(PA_position v) const noexcept
        {
            return (
                dot(direction, v)
                - dot(direction, center)
            );
        }
    };



    using F_plane = TF_plane<>;

    using F_plane_f32 = TF_plane<f32>;
}
