#pragma once

/** @file nmath/functions/data_functions.hpp
*
*   Implement data functions.
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

#include <nmath/types/data2.hpp>
#include <nmath/types/data_helper.hpp>
#include <nmath/utilities/basic_arithmetic.hpp>

#pragma endregion



////////////////////////////////////////////////////////////////////////////////////
//  D2 selectors
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    static constexpr u32 D2_SELECT_X0 = 0;
    static constexpr u32 D2_SELECT_Y0 = 1;

    static constexpr u32 D2_SELECT_X1 = 2;
    static constexpr u32 D2_SELECT_Y1 = 3;

}



////////////////////////////////////////////////////////////////////////////////////
//  F32 declares
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    ////////////////////////////////////////////////////////////////////////////////////
    //  Basic arithmetic functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data2_f32 data2_minus(PA_data2_f32 a) noexcept;

    F_data2_f32 data2_add(PA_data2_f32 a, PA_data2_f32 b) noexcept;
    F_data2_f32 data2_subtract(PA_data2_f32 a, PA_data2_f32 b) noexcept;

    F_data2_f32 data2_multiply(PA_data2_f32 a, PA_data2_f32 b) noexcept;
    F_data2_f32 data2_divide(PA_data2_f32 a, PA_data2_f32 b) noexcept;

    F_data2_f32 data2_round(PA_data2_f32 a) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  Entry manipulate functions
    ////////////////////////////////////////////////////////////////////////////////////
    template<
        u32 x_selector__,
        u32 y_selector__
    >
    F_data2_f32 T_data2_static_permute(
        PA_data2_f32 a,
        PA_data2_f32 b
    ) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  FMA functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data2_f32 data2_multiply_add(
        PA_data2_f32 a,
        PA_data2_f32 b,
        PA_data2_f32 c
    ) noexcept;

    F_data2_f32 data2_multiply_addsub(
        PA_data2_f32 a,
        PA_data2_f32 b,
        PA_data2_f32 c
    ) noexcept;

    F_data2_f32 data2_multiply_sub(
        PA_data2_f32 a,
        PA_data2_f32 b,
        PA_data2_f32 c
    ) noexcept;

    F_data2_f32 data2_multiply_subadd(
        PA_data2_f32 a,
        PA_data2_f32 b,
        PA_data2_f32 c
    ) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  Dot, cross product, length, etc.
    ////////////////////////////////////////////////////////////////////////////////////
    f32 data2_dot(PA_data2_f32 a, PA_data2_f32 b) noexcept;

    f32 data2_cross(PA_data2_f32 a, PA_data2_f32 b) noexcept;



    ////////////////////////////////////////////////////////////////////////////////////
    //  Trigonometry functions
    ////////////////////////////////////////////////////////////////////////////////////
    F_data2_f32 data2_mod_angles(PA_data2_f32 a) noexcept;

    F_data2_f32 data2_sin_angles(PA_data2_f32 a) noexcept;

    F_data2_f32 data2_cos_angles(PA_data2_f32 a) noexcept;

    void data2_sin_cos_angles(PA_data2_f32 a, F_data2_f32& out_sin, F_data2_f32& out_cos) noexcept;

}



////////////////////////////////////////////////////////////////////////////////////
//  F32 defines
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    ////////////////////////////////////////////////////////////////////////////////////
    //  Basic arithmetic functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data2_f32 data2_minus(PA_data2_f32 a) noexcept
    {
        return {

            -a.x,
            -a.y

        };
    }
    NCPP_FORCE_INLINE F_data2_f32 data2_add(PA_data2_f32 a, PA_data2_f32 b) noexcept
    {
        return {

            a.x + b.x,
            a.y + b.y
        };
    }
    NCPP_FORCE_INLINE F_data2_f32 data2_subtract(PA_data2_f32 a, PA_data2_f32 b) noexcept
    {
        return {

            a.x - b.x,
            a.y - b.y

        };
    }

    NCPP_FORCE_INLINE F_data2_f32 data2_multiply(PA_data2_f32 a, PA_data2_f32 b) noexcept
    {
        return {

            a.x * b.x,
            a.y * b.y

        };
    }
    NCPP_FORCE_INLINE F_data2_f32 data2_divide(PA_data2_f32 a, PA_data2_f32 b) noexcept
    {
        return {

            a.x / b.x,
            a.y / b.y

        };
    }
    NCPP_FORCE_INLINE F_data2_f32 data2_round(PA_data2_f32 a) noexcept {

        return {

            round_to_nearest(a.x),
            round_to_nearest(a.y)

        };
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Entry manipulate functions
    ////////////////////////////////////////////////////////////////////////////////////
    template<
        u32 x_selector__,
        u32 y_selector__
    >
    NCPP_FORCE_INLINE F_data2_f32 T_data2_static_permute(
        PA_data2_f32 a,
        PA_data2_f32 b
    ) noexcept {
        
        return {
          
            a[(u32)x_selector__ & 2],
            a[(u32)y_selector__ & 2]
            
        };
        
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  FMA functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data2_f32 data2_multiply_add(
        PA_data2_f32 a,
        PA_data2_f32 b,
        PA_data2_f32 c
    ) noexcept {
                
        return {
          
            a.x * b.x + c.x,
            a.y * b.y + c.y
            
        };
        
    }
    NCPP_FORCE_INLINE F_data2_f32 data2_multiply_addsub(
        PA_data2_f32 a,
        PA_data2_f32 b,
        PA_data2_f32 c
   ) noexcept {
        
        return {
          
            a.x * b.x + c.x,
            a.y * b.y - c.y
            
        };
        
    }
    NCPP_FORCE_INLINE F_data2_f32 data2_multiply_sub(
        PA_data2_f32 a,
        PA_data2_f32 b,
        PA_data2_f32 c
    ) noexcept {
    
        return {
          
            a.x * b.x - c.x,
            a.y * b.y - c.y
            
        };
        
    }
    NCPP_FORCE_INLINE F_data2_f32 data2_multiply_subadd(
        PA_data2_f32 a,
        PA_data2_f32 b,
        PA_data2_f32 c
   ) noexcept {
    
        return {
          
            a.x * b.x - c.x,
            a.y * b.y + c.y
            
        };
        
    }
    NCPP_FORCE_INLINE F_data2_f32 data2_negative_multiply_add(
        PA_data2_f32 a,
        PA_data2_f32 b,
        PA_data2_f32 c
    ) noexcept {

        return {

            a.x * -b.x + c.x,
            a.y * -b.y + c.y

        };

    }
    NCPP_FORCE_INLINE F_data2_f32 data2_negative_multiply_sub(
        PA_data2_f32 a,
        PA_data2_f32 b,
        PA_data2_f32 c
    ) noexcept {

        return {

            a.x * -b.x - c.x,
            a.y * -b.y - c.y

        };

    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Dot, cross product, length, etc.
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE f32 data2_dot(PA_data2_f32 a, PA_data2_f32 b) noexcept {

        return a.x * a.x + a.y * a.y;
    }
    NCPP_FORCE_INLINE f32 data2_cross(PA_data2_f32 a, PA_data2_f32 b) noexcept {

        return a.x * b.y - a.y * b.x;
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Trigonometry functions
    ////////////////////////////////////////////////////////////////////////////////////
    NCPP_FORCE_INLINE F_data2_f32 data2_mod_angles(PA_data2_f32 a) noexcept {

        static const F_data2_f32 reciprocal_two_pi = F_data2_f32(1.0f / 2pi, 1.0f / 2pi);
        static const F_data2_f32 two_pi = F_data2_f32(2pi, 2pi);

        F_data2_f32 V;
        F_data2_f32 Result;

        // Modulo the range of the given angles such that -XM_PI <= Angles < XM_PI
        V = data2_multiply(a, reciprocal_two_pi);
        V = data2_round(V);
        Result = data2_negative_multiply_sub(two_pi, V, a);
        return Result;
    }

    NCPP_FORCE_INLINE F_data2_f32 data2_sin_angles(PA_data2_f32 a) noexcept {

        return {
        
            sinf(a.x),
            sinf(a.y)

        };
    }

    NCPP_FORCE_INLINE F_data2_f32 data2_cos_angles(PA_data2_f32 a) noexcept {

        return {

            cosf(a.x),
            cosf(a.y)
        
        };
    }

    NCPP_FORCE_INLINE void data2_sin_cos_angles(PA_data2_f32 a, F_data2_f32& out_sin, F_data2_f32& out_cos) noexcept {

        out_sin = data2_sin_angles(a);
        out_cos = data2_cos_angles(a);
    }

}
