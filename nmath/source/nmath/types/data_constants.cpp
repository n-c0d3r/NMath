#include <nmath/types/data_constants.hpp>
#include <nmath/types/data.hpp>
#include <nmath/utilities/basic_arithmetic.hpp>



namespace nmath {

    ////////////////////////////////////////////////////////////////////////////////////
    //  Data2
    ////////////////////////////////////////////////////////////////////////////////////
    const F_data2_f32 reciprocal_two_pi_x2 = F_data2_f32(1.0f / 2pi, 1.0f / 2pi);
    const F_data2_f32 two_pi_x2 = F_data2_f32(2pi, 2pi);



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data3
    ////////////////////////////////////////////////////////////////////////////////////
    const F_data3_f32 reciprocal_two_pi_x3 = F_data3_f32(1.0f / 2pi, 1.0f / 2pi, 1.0f / 2pi);
    const F_data3_f32 two_pi_x3 = F_data3_f32(2pi, 2pi, 2pi);



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data4
    ////////////////////////////////////////////////////////////////////////////////////
    const F_data4_f32 reciprocal_two_pi_x4 = F_data4_f32(1.0f / 2pi, 1.0f / 2pi, 1.0f / 2pi, 1.0f / 2pi);
    const F_data4_f32 two_pi_x4 = F_data4_f32(2pi, 2pi, 2pi, 2pi);
    const F_data4_f32 pi_x4 = F_data4_f32(1pi, 1pi, 1pi, 1pi);
    const F_data4_f32 half_pi_x4 = F_data4_f32(0.5pi, 0.5pi, 0.5pi, 0.5pi);
    const F_data4_f32 negative_zero_x4 = F_data4_f32(
        reinterpret_cast_u32_to_f32(0x80000000),
        reinterpret_cast_u32_to_f32(0x80000000),
        reinterpret_cast_u32_to_f32(0x80000000),
        reinterpret_cast_u32_to_f32(0x80000000)
    );
    const F_data4_f32 abs_mask_x4 = F_data4_f32(
        reinterpret_cast_u32_to_f32(0x7FFFFFFF),
        reinterpret_cast_u32_to_f32(0x7FFFFFFF),
        reinterpret_cast_u32_to_f32(0x7FFFFFFF),
        reinterpret_cast_u32_to_f32(0x7FFFFFFF)
    );
    const F_data4_f32 no_fraction_x4 = F_data4_f32{ 8388608.0f, 8388608.0f, 8388608.0f, 8388608.0f };
    const F_data4_f32 sin_coefficient_s1_x4 = F_data4_f32(-2.3889859e-08f, -0.16665852f /*Est1*/, +0.0083139502f /*Est2*/, -0.00018524670f /*Est3*/);
    const F_data4_f32 sin_coefficient_s0_x4 = F_data4_f32(-0.16666667f, +0.0083333310f, -0.00019840874f, +2.7525562e-06f);
    const F_data4_f32 cos_coefficient_s1_x4 = F_data4_f32(-2.6051615e-07f, -0.49992746f /*Est1*/, +0.041493919f /*Est2*/, -0.0012712436f /*Est3*/);
    const F_data4_f32 cos_coefficient_s0_x4 = F_data4_f32(-0.5f, +0.041666638f, -0.0013888378f, +2.4760495e-05f);

}