#pragma once

/** @file nmath/types/data_constants.hpp
*
*   Implement data constants.
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
#include <nmath/types/data3.hpp>
#include <nmath/types/data4.hpp>
#include <nmath/operators/literal.hpp>

#pragma endregion



namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data2
    ////////////////////////////////////////////////////////////////////////////////////
    extern const F_data2_f32 reciprocal_two_pi_x2;
    extern const F_data2_f32 two_pi_x2;



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data3
    ////////////////////////////////////////////////////////////////////////////////////
    extern const F_data3_f32 reciprocal_two_pi_x3;
    extern const F_data3_f32 two_pi_x3;



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data4
    ////////////////////////////////////////////////////////////////////////////////////
    extern const F_data4_f32 reciprocal_two_pi_x4;
    extern const F_data4_f32 two_pi_x4;
    extern const F_data4_f32 pi_x4;
    extern const F_data4_f32 half_pi_x4;
    extern const F_data4_f32 negative_zero_x4;
    extern const F_data4_f32 abs_mask_x4;
    extern const F_data4_f32 no_fraction_x4;
    extern const F_data4_f32 sin_coefficient_s1_x4;
    extern const F_data4_f32 sin_coefficient_s0_x4;
    extern const F_data4_f32 cos_coefficient_s1_x4;
    extern const F_data4_f32 cos_coefficient_s0_x4;



    extern const F_data4_f32 data4_f32_0000;

    extern const F_data4_f32 data4_f32_FFFF;

    extern const F_data4_f32 data4_f32_000F;
    extern const F_data4_f32 data4_f32_00F0;
    extern const F_data4_f32 data4_f32_0F00;
    extern const F_data4_f32 data4_f32_F000;

    extern const F_data4_f32 data4_f32_FFF0;
    extern const F_data4_f32 data4_f32_FF0F;
    extern const F_data4_f32 data4_f32_F0FF;
    extern const F_data4_f32 data4_f32_0FFF;

    extern const F_data4_f32 data4_f32_FF00;
    extern const F_data4_f32 data4_f32_F00F;
    extern const F_data4_f32 data4_f32_00FF;
    extern const F_data4_f32 data4_f32_0FF0;
    extern const F_data4_f32 data4_f32_0F0F;
    extern const F_data4_f32 data4_f32_F0F0;

    extern const F_data4_f32 data4_f32_1111;

    extern const F_data4_f32 data4_f32_0001;
    extern const F_data4_f32 data4_f32_0010;
    extern const F_data4_f32 data4_f32_0100;
    extern const F_data4_f32 data4_f32_1000;

    extern const F_data4_f32 data4_f32_1110;
    extern const F_data4_f32 data4_f32_1101;
    extern const F_data4_f32 data4_f32_1011;
    extern const F_data4_f32 data4_f32_0111;

    extern const F_data4_f32 data4_f32_1100;
    extern const F_data4_f32 data4_f32_1001;
    extern const F_data4_f32 data4_f32_0011;
    extern const F_data4_f32 data4_f32_0110;
    extern const F_data4_f32 data4_f32_0101;
    extern const F_data4_f32 data4_f32_1010;

    extern const F_data4_f32 data4_f32_1111_negative;

    extern const F_data4_f32 data4_f32_0001_negative;
    extern const F_data4_f32 data4_f32_0010_negative;
    extern const F_data4_f32 data4_f32_0100_negative;
    extern const F_data4_f32 data4_f32_1000_negative;

    extern const F_data4_f32 data4_f32_1110_negative;
    extern const F_data4_f32 data4_f32_1101_negative;
    extern const F_data4_f32 data4_f32_1011_negative;
    extern const F_data4_f32 data4_f32_0111_negative;

    extern const F_data4_f32 data4_f32_1100_negative;
    extern const F_data4_f32 data4_f32_1001_negative;
    extern const F_data4_f32 data4_f32_0011_negative;
    extern const F_data4_f32 data4_f32_0110_negative;
    extern const F_data4_f32 data4_f32_0101_negative;
    extern const F_data4_f32 data4_f32_1010_negative;

    // extern const F_data4_i32 data4_i32_0000;

    // extern const F_data4_i32 data4_i32_FFFF;

    // extern const F_data4_i32 data4_i32_000F;
    // extern const F_data4_i32 data4_i32_00F0;
    // extern const F_data4_i32 data4_i32_0F00;
    // extern const F_data4_i32 data4_i32_F000;

    // extern const F_data4_i32 data4_i32_FFF0;
    // extern const F_data4_i32 data4_i32_FF0F;
    // extern const F_data4_i32 data4_i32_F0FF;
    // extern const F_data4_i32 data4_i32_0FFF;

    // extern const F_data4_i32 data4_i32_FF00;
    // extern const F_data4_i32 data4_i32_F00F;
    // extern const F_data4_i32 data4_i32_00FF;
    // extern const F_data4_i32 data4_i32_0FF0;
    // extern const F_data4_i32 data4_i32_0F0F;
    // extern const F_data4_i32 data4_i32_F0F0;

    // extern const F_data4_i32 data4_i32_1111;

    // extern const F_data4_i32 data4_i32_0001;
    // extern const F_data4_i32 data4_i32_0010;
    // extern const F_data4_i32 data4_i32_0100;
    // extern const F_data4_i32 data4_i32_1000;

    // extern const F_data4_i32 data4_i32_1110;
    // extern const F_data4_i32 data4_i32_1101;
    // extern const F_data4_i32 data4_i32_1011;
    // extern const F_data4_i32 data4_i32_0111;

    // extern const F_data4_i32 data4_i32_1100;
    // extern const F_data4_i32 data4_i32_1001;
    // extern const F_data4_i32 data4_i32_0011;
    // extern const F_data4_i32 data4_i32_0110;
    // extern const F_data4_i32 data4_i32_0101;
    // extern const F_data4_i32 data4_i32_1010;

    // extern const F_data4_i32 data4_i32_1111_negative;

    // extern const F_data4_i32 data4_i32_0001_negative;
    // extern const F_data4_i32 data4_i32_0010_negative;
    // extern const F_data4_i32 data4_i32_0100_negative;
    // extern const F_data4_i32 data4_i32_1000_negative;

    // extern const F_data4_i32 data4_i32_1110_negative;
    // extern const F_data4_i32 data4_i32_1101_negative;
    // extern const F_data4_i32 data4_i32_1011_negative;
    // extern const F_data4_i32 data4_i32_0111_negative;

    // extern const F_data4_i32 data4_i32_1100_negative;
    // extern const F_data4_i32 data4_i32_1001_negative;
    // extern const F_data4_i32 data4_i32_0011_negative;
    // extern const F_data4_i32 data4_i32_0110_negative;
    // extern const F_data4_i32 data4_i32_0101_negative;
    // extern const F_data4_i32 data4_i32_1010_negative;

    // extern const F_data4_u32 data4_u32_0000;

    // extern const F_data4_u32 data4_u32_FFFF;

    // extern const F_data4_u32 data4_u32_000F;
    // extern const F_data4_u32 data4_u32_00F0;
    // extern const F_data4_u32 data4_u32_0F00;
    // extern const F_data4_u32 data4_u32_F000;

    // extern const F_data4_u32 data4_u32_FFF0;
    // extern const F_data4_u32 data4_u32_FF0F;
    // extern const F_data4_u32 data4_u32_F0FF;
    // extern const F_data4_u32 data4_u32_0FFF;

    // extern const F_data4_u32 data4_u32_FF00;
    // extern const F_data4_u32 data4_u32_F00F;
    // extern const F_data4_u32 data4_u32_00FF;
    // extern const F_data4_u32 data4_u32_0FF0;
    // extern const F_data4_u32 data4_u32_0F0F;
    // extern const F_data4_u32 data4_u32_F0F0;

    // extern const F_data4_u32 data4_u32_1111;

    // extern const F_data4_u32 data4_u32_0001;
    // extern const F_data4_u32 data4_u32_0010;
    // extern const F_data4_u32 data4_u32_0100;
    // extern const F_data4_u32 data4_u32_1000;

    // extern const F_data4_u32 data4_u32_1110;
    // extern const F_data4_u32 data4_u32_1101;
    // extern const F_data4_u32 data4_u32_1011;
    // extern const F_data4_u32 data4_u32_0111;

    // extern const F_data4_u32 data4_u32_1100;
    // extern const F_data4_u32 data4_u32_1001;
    // extern const F_data4_u32 data4_u32_0011;
    // extern const F_data4_u32 data4_u32_0110;
    // extern const F_data4_u32 data4_u32_0101;
    // extern const F_data4_u32 data4_u32_1010;

}
