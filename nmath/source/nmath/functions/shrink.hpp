#pragma once

/** @file nmath/functions/shrink.hpp
*
*   Implement intersect shrink.
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

#include <nmath/types/ray.hpp>
#include <nmath/types/cone.hpp>
#include <nmath/types/plane.hpp>
#include <nmath/functions/intersect.hpp>

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



namespace nmath
{
    template<typename F_element__ = NMATH_DEFAULT_FP_TYPE>
    inline TF_cone<F_element__> T_shrink(const TF_cone<F_element__>& cone, const TF_plane<F_element__>& plane)
    {
        NCPP_ASSERT(cone);
        NCPP_ASSERT(plane);

        using F_vector3 = TF_vector3<F_element__>;
        using F_ray = TF_ray<F_element__>;

        F_vector3 cone_pivot = cone.pivot;
        F_vector3 cone_direction = cone.direction();

        F_vector3 plane_center = plane.center;
        F_vector3 plane_direction = plane.direction;

        F_ray ray = { cone_pivot, cone_direction };

        F_vector3 intersect_point;
        F_element__ t;
        if(
            !T_intersect<F_element__, E_intersect_face::BACK>(
                ray,
                plane,
                intersect_point,
                t
            )
        )
        {
            if(t < 0.0)
            {
                intersect_point = cone_pivot;
            }
            else
            {
                return TF_cone<F_element__>(
                    F_vector3::zero(),
                    F_vector3::zero(),
                    (F_element__)1.0
                );
            }
        }

        F_vector3 cone_pivot_to_intersect_point = intersect_point - cone_pivot;

        f32 offset = eastl::max<F_element__>(
            dot(cone_direction, cone_pivot_to_intersect_point),
            (F_element__)0.0
        );

        return {
            cone_pivot + cone_direction * offset,
            eastl::max<F_element__>(
                cone.min_angle_dot(),
                length(
                    cross(
                        cone_direction,
                        plane_direction
                    )
                )
            )
        };
    }
}
