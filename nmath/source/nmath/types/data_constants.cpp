#include <nmath/types/data_constants.hpp>
#include <nmath/types/data.hpp>
#include <nmath/utilities/basic_arithmetic.hpp>



namespace nmath {

    ////////////////////////////////////////////////////////////////////////////////////
    //  Data2
    ////////////////////////////////////////////////////////////////////////////////////
    const F_data2_f32 reciprocal_two_pi_x2 = F_data2_f32(1.0f / 2_pi, 1.0f / 2_pi);
    const F_data2_f32 two_pi_x2 = F_data2_f32(2_pi, 2_pi);



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data3
    ////////////////////////////////////////////////////////////////////////////////////
    const F_data3_f32 reciprocal_two_pi_x3 = F_data3_f32(1.0f / 2_pi, 1.0f / 2_pi, 1.0f / 2_pi);
    const F_data3_f32 two_pi_x3 = F_data3_f32(2_pi, 2_pi, 2_pi);



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data4
    ////////////////////////////////////////////////////////////////////////////////////
    const F_data4_f32 reciprocal_two_pi_x4 = F_data4_f32(1.0f / 2_pi, 1.0f / 2_pi, 1.0f / 2_pi, 1.0f / 2_pi);
    const F_data4_f32 two_pi_x4 = F_data4_f32(2_pi, 2_pi, 2_pi, 2_pi);
    const F_data4_f32 pi_x4 = F_data4_f32(1_pi, 1_pi, 1_pi, 1_pi);
    const F_data4_f32 half_pi_x4 = F_data4_f32(0.5_pi, 0.5_pi, 0.5_pi, 0.5_pi);
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



    const F_data4_f32 data4_f32_0000 = F_data4_f32(0.0f, 0.0f, 0.0f, 0.0f);

    const F_data4_f32 data4_f32_FFFF = F_data4_f32(reinterpret_cast_u32_to_f32(NCPP_U32_MAX), reinterpret_cast_u32_to_f32(NCPP_U32_MAX), reinterpret_cast_u32_to_f32(NCPP_U32_MAX), reinterpret_cast_u32_to_f32(NCPP_U32_MAX));

    const F_data4_f32 data4_f32_000F = F_data4_f32(0, 0, 0, reinterpret_cast_u32_to_f32(NCPP_U32_MAX));
    const F_data4_f32 data4_f32_00F0 = F_data4_f32(0, 0, reinterpret_cast_u32_to_f32(NCPP_U32_MAX), 0);
    const F_data4_f32 data4_f32_0F00 = F_data4_f32(0, reinterpret_cast_u32_to_f32(NCPP_U32_MAX), 0, 0);
    const F_data4_f32 data4_f32_F000 = F_data4_f32(reinterpret_cast_u32_to_f32(NCPP_U32_MAX), 0, 0, 0);

    const F_data4_f32 data4_f32_FFF0 = F_data4_f32(reinterpret_cast_u32_to_f32(NCPP_U32_MAX), reinterpret_cast_u32_to_f32(NCPP_U32_MAX), reinterpret_cast_u32_to_f32(NCPP_U32_MAX), 0);
    const F_data4_f32 data4_f32_FF0F = F_data4_f32(reinterpret_cast_u32_to_f32(NCPP_U32_MAX), reinterpret_cast_u32_to_f32(NCPP_U32_MAX), 0, reinterpret_cast_u32_to_f32(NCPP_U32_MAX));
    const F_data4_f32 data4_f32_F0FF = F_data4_f32(reinterpret_cast_u32_to_f32(NCPP_U32_MAX), 0, reinterpret_cast_u32_to_f32(NCPP_U32_MAX), reinterpret_cast_u32_to_f32(NCPP_U32_MAX));
    const F_data4_f32 data4_f32_0FFF = F_data4_f32(0, reinterpret_cast_u32_to_f32(NCPP_U32_MAX), reinterpret_cast_u32_to_f32(NCPP_U32_MAX), reinterpret_cast_u32_to_f32(NCPP_U32_MAX));

    const F_data4_f32 data4_f32_FF00 = F_data4_f32(reinterpret_cast_u32_to_f32(NCPP_U32_MAX), reinterpret_cast_u32_to_f32(NCPP_U32_MAX), 0, 0);
    const F_data4_f32 data4_f32_F00F = F_data4_f32(reinterpret_cast_u32_to_f32(NCPP_U32_MAX), 0, 0, reinterpret_cast_u32_to_f32(NCPP_U32_MAX));
    const F_data4_f32 data4_f32_00FF = F_data4_f32(0, 0, reinterpret_cast_u32_to_f32(NCPP_U32_MAX), reinterpret_cast_u32_to_f32(NCPP_U32_MAX));
    const F_data4_f32 data4_f32_0FF0 = F_data4_f32(0, reinterpret_cast_u32_to_f32(NCPP_U32_MAX), reinterpret_cast_u32_to_f32(NCPP_U32_MAX), 0);
    const F_data4_f32 data4_f32_0F0F = F_data4_f32(0, reinterpret_cast_u32_to_f32(NCPP_U32_MAX), 0, reinterpret_cast_u32_to_f32(NCPP_U32_MAX));
    const F_data4_f32 data4_f32_F0F0 = F_data4_f32(reinterpret_cast_u32_to_f32(NCPP_U32_MAX), 0, reinterpret_cast_u32_to_f32(NCPP_U32_MAX), 0);

    const F_data4_f32 data4_f32_1111 = F_data4_f32(1.0f, 1.0f, 1.0f, 1.0f);

    const F_data4_f32 data4_f32_0001 = F_data4_f32(0.0f, 0.0f, 0.0f, 1.0f);
    const F_data4_f32 data4_f32_0010 = F_data4_f32(0.0f, 0.0f, 1.0f, 0.0f);
    const F_data4_f32 data4_f32_0100 = F_data4_f32(0.0f, 1.0f, 0.0f, 0.0f);
    const F_data4_f32 data4_f32_1000 = F_data4_f32(1.0f, 0.0f, 0.0f, 0.0f);

    const F_data4_f32 data4_f32_1110 = F_data4_f32(1.0f, 1.0f, 1.0f, 0.0f);
    const F_data4_f32 data4_f32_1101 = F_data4_f32(1.0f, 1.0f, 0.0f, 1.0f);
    const F_data4_f32 data4_f32_1011 = F_data4_f32(1.0f, 0.0f, 1.0f, 1.0f);
    const F_data4_f32 data4_f32_0111 = F_data4_f32(0.0f, 1.0f, 1.0f, 1.0f);

    const F_data4_f32 data4_f32_1100 = F_data4_f32(1.0f, 1.0f, 0.0f, 0.0f);
    const F_data4_f32 data4_f32_1001 = F_data4_f32(1.0f, 0.0f, 0.0f, 1.0f);
    const F_data4_f32 data4_f32_0011 = F_data4_f32(0.0f, 0.0f, 1.0f, 1.0f);
    const F_data4_f32 data4_f32_0110 = F_data4_f32(0.0f, 1.0f, 1.0f, 0.0f);
    const F_data4_f32 data4_f32_0101 = F_data4_f32(0.0f, 1.0f, 0.0f, 1.0f);
    const F_data4_f32 data4_f32_1010 = F_data4_f32(1.0f, 0.0f, 1.0f, 0.0f);

    const F_data4_f32 data4_f32_1111_negative = F_data4_f32(-1.0f, -1.0f, -1.0f, -1.0f);

    const F_data4_f32 data4_f32_0001_negative = F_data4_f32(0.0f, 0.0f, 0.0f, -1.0f);
    const F_data4_f32 data4_f32_0010_negative = F_data4_f32(0.0f, 0.0f, -1.0f, 0.0f);
    const F_data4_f32 data4_f32_0100_negative = F_data4_f32(0.0f, -1.0f, 0.0f, 0.0f);
    const F_data4_f32 data4_f32_1000_negative = F_data4_f32(-1.0f, 0.0f, 0.0f, 0.0f);

    const F_data4_f32 data4_f32_1110_negative = F_data4_f32(-1.0f, -1.0f, -1.0f, 0.0f);
    const F_data4_f32 data4_f32_1101_negative = F_data4_f32(-1.0f, -1.0f, 0.0f, -1.0f);
    const F_data4_f32 data4_f32_1011_negative = F_data4_f32(-1.0f, 0.0f, -1.0f, -1.0f);
    const F_data4_f32 data4_f32_0111_negative = F_data4_f32(0.0f, -1.0f, -1.0f, -1.0f);

    const F_data4_f32 data4_f32_1100_negative = F_data4_f32(-1.0f, -1.0f, 0.0f, 0.0f);
    const F_data4_f32 data4_f32_1001_negative = F_data4_f32(-1.0f, 0.0f, 0.0f, -1.0f);
    const F_data4_f32 data4_f32_0011_negative = F_data4_f32(0.0f, 0.0f, -1.0f, -1.0f);
    const F_data4_f32 data4_f32_0110_negative = F_data4_f32(0.0f, -1.0f, -1.0f, 0.0f);
    const F_data4_f32 data4_f32_0101_negative = F_data4_f32(0.0f, -1.0f, 0.0f, -1.0f);
    const F_data4_f32 data4_f32_1010_negative = F_data4_f32(-1.0f, 0.0f, -1.0f, 0.0f);

    const F_data4_i32 data4_i32_0000 = F_data4_i32(0, 0, 0, 0);

    const F_data4_i32 data4_i32_FFFF = F_data4_i32(NCPP_U32_MAX, NCPP_U32_MAX, NCPP_U32_MAX, NCPP_U32_MAX);

    const F_data4_i32 data4_i32_000F = F_data4_i32(0, 0, 0, NCPP_U32_MAX);
    const F_data4_i32 data4_i32_00F0 = F_data4_i32(0, 0, NCPP_U32_MAX, 0);
    const F_data4_i32 data4_i32_0F00 = F_data4_i32(0, NCPP_U32_MAX, 0, 0);
    const F_data4_i32 data4_i32_F000 = F_data4_i32(NCPP_U32_MAX, 0, 0, 0);

    const F_data4_i32 data4_i32_FFF0 = F_data4_i32(NCPP_U32_MAX, NCPP_U32_MAX, NCPP_U32_MAX, 0);
    const F_data4_i32 data4_i32_FF0F = F_data4_i32(NCPP_U32_MAX, NCPP_U32_MAX, 0, NCPP_U32_MAX);
    const F_data4_i32 data4_i32_F0FF = F_data4_i32(NCPP_U32_MAX, 0, NCPP_U32_MAX, NCPP_U32_MAX);
    const F_data4_i32 data4_i32_0FFF = F_data4_i32(0, NCPP_U32_MAX, NCPP_U32_MAX, NCPP_U32_MAX);

    const F_data4_i32 data4_i32_FF00 = F_data4_i32(NCPP_U32_MAX, NCPP_U32_MAX, 0, 0);
    const F_data4_i32 data4_i32_F00F = F_data4_i32(NCPP_U32_MAX, 0, 0, NCPP_U32_MAX);
    const F_data4_i32 data4_i32_00FF = F_data4_i32(0, 0, NCPP_U32_MAX, NCPP_U32_MAX);
    const F_data4_i32 data4_i32_0FF0 = F_data4_i32(0, NCPP_U32_MAX, NCPP_U32_MAX, 0);
    const F_data4_i32 data4_i32_0F0F = F_data4_i32(0, NCPP_U32_MAX, 0, NCPP_U32_MAX);
    const F_data4_i32 data4_i32_F0F0 = F_data4_i32(NCPP_U32_MAX, 0, NCPP_U32_MAX, 0);

    const F_data4_i32 data4_i32_1111 = F_data4_i32(1, 1, 1, 1);

    const F_data4_i32 data4_i32_0001 = F_data4_i32(0, 0, 0, 1);
    const F_data4_i32 data4_i32_0010 = F_data4_i32(0, 0, 1, 0);
    const F_data4_i32 data4_i32_0100 = F_data4_i32(0, 1, 0, 0);
    const F_data4_i32 data4_i32_1000 = F_data4_i32(1, 0, 0, 0);

    const F_data4_i32 data4_i32_1110 = F_data4_i32(1, 1, 1, 0);
    const F_data4_i32 data4_i32_1101 = F_data4_i32(1, 1, 0, 1);
    const F_data4_i32 data4_i32_1011 = F_data4_i32(1, 0, 1, 1);
    const F_data4_i32 data4_i32_0111 = F_data4_i32(0, 1, 1, 1);

    const F_data4_i32 data4_i32_1100 = F_data4_i32(1, 1, 0, 0);
    const F_data4_i32 data4_i32_1001 = F_data4_i32(1, 0, 0, 1);
    const F_data4_i32 data4_i32_0011 = F_data4_i32(0, 0, 1, 1);
    const F_data4_i32 data4_i32_0110 = F_data4_i32(0, 1, 1, 0);
    const F_data4_i32 data4_i32_0101 = F_data4_i32(0, 1, 0, 1);
    const F_data4_i32 data4_i32_1010 = F_data4_i32(1, 0, 1, 0);

    const F_data4_i32 data4_i32_1111_negative = F_data4_i32(-1, -1, -1, -1);

    const F_data4_i32 data4_i32_0001_negative = F_data4_i32(0, 0, 0, -1);
    const F_data4_i32 data4_i32_0010_negative = F_data4_i32(0, 0, -1, 0);
    const F_data4_i32 data4_i32_0100_negative = F_data4_i32(0, -1, 0, 0);
    const F_data4_i32 data4_i32_1000_negative = F_data4_i32(-1, 0, 0, 0);

    const F_data4_i32 data4_i32_1110_negative = F_data4_i32(-1, -1, -1, 0);
    const F_data4_i32 data4_i32_1101_negative = F_data4_i32(-1, -1, 0, -1);
    const F_data4_i32 data4_i32_1011_negative = F_data4_i32(-1, 0, -1, -1);
    const F_data4_i32 data4_i32_0111_negative = F_data4_i32(0, -1, -1, -1);

    const F_data4_i32 data4_i32_1100_negative = F_data4_i32(-1, -1, 0, 0);
    const F_data4_i32 data4_i32_1001_negative = F_data4_i32(-1, 0, 0, -1);
    const F_data4_i32 data4_i32_0011_negative = F_data4_i32(0, 0, -1, -1);
    const F_data4_i32 data4_i32_0110_negative = F_data4_i32(0, -1, -1, 0);
    const F_data4_i32 data4_i32_0101_negative = F_data4_i32(0, -1, 0, -1);
    const F_data4_i32 data4_i32_1010_negative = F_data4_i32(-1, 0, -1, 0);

    const F_data4_u32 data4_u32_0000 = F_data4_u32(0, 0, 0, 0);

    const F_data4_u32 data4_u32_FFFF = F_data4_u32(NCPP_U32_MAX, NCPP_U32_MAX, NCPP_U32_MAX, NCPP_U32_MAX);

    const F_data4_u32 data4_u32_000F = F_data4_u32(0, 0, 0, NCPP_U32_MAX);
    const F_data4_u32 data4_u32_00F0 = F_data4_u32(0, 0, NCPP_U32_MAX, 0);
    const F_data4_u32 data4_u32_0F00 = F_data4_u32(0, NCPP_U32_MAX, 0, 0);
    const F_data4_u32 data4_u32_F000 = F_data4_u32(NCPP_U32_MAX, 0, 0, 0);

    const F_data4_u32 data4_u32_FFF0 = F_data4_u32(NCPP_U32_MAX, NCPP_U32_MAX, NCPP_U32_MAX, 0);
    const F_data4_u32 data4_u32_FF0F = F_data4_u32(NCPP_U32_MAX, NCPP_U32_MAX, 0, NCPP_U32_MAX);
    const F_data4_u32 data4_u32_F0FF = F_data4_u32(NCPP_U32_MAX, 0, NCPP_U32_MAX, NCPP_U32_MAX);
    const F_data4_u32 data4_u32_0FFF = F_data4_u32(0, NCPP_U32_MAX, NCPP_U32_MAX, NCPP_U32_MAX);

    const F_data4_u32 data4_u32_FF00 = F_data4_u32(NCPP_U32_MAX, NCPP_U32_MAX, 0, 0);
    const F_data4_u32 data4_u32_F00F = F_data4_u32(NCPP_U32_MAX, 0, 0, NCPP_U32_MAX);
    const F_data4_u32 data4_u32_00FF = F_data4_u32(0, 0, NCPP_U32_MAX, NCPP_U32_MAX);
    const F_data4_u32 data4_u32_0FF0 = F_data4_u32(0, NCPP_U32_MAX, NCPP_U32_MAX, 0);
    const F_data4_u32 data4_u32_0F0F = F_data4_u32(0, NCPP_U32_MAX, 0, NCPP_U32_MAX);
    const F_data4_u32 data4_u32_F0F0 = F_data4_u32(NCPP_U32_MAX, 0, NCPP_U32_MAX, 0);

    const F_data4_u32 data4_u32_1111 = F_data4_u32(1, 1, 1, 1);

    const F_data4_u32 data4_u32_0001 = F_data4_u32(0, 0, 0, 1);
    const F_data4_u32 data4_u32_0010 = F_data4_u32(0, 0, 1, 0);
    const F_data4_u32 data4_u32_0100 = F_data4_u32(0, 1, 0, 0);
    const F_data4_u32 data4_u32_1000 = F_data4_u32(1, 0, 0, 0);

    const F_data4_u32 data4_u32_1110 = F_data4_u32(1, 1, 1, 0);
    const F_data4_u32 data4_u32_1101 = F_data4_u32(1, 1, 0, 1);
    const F_data4_u32 data4_u32_1011 = F_data4_u32(1, 0, 1, 1);
    const F_data4_u32 data4_u32_0111 = F_data4_u32(0, 1, 1, 1);

    const F_data4_u32 data4_u32_1100 = F_data4_u32(1, 1, 0, 0);
    const F_data4_u32 data4_u32_1001 = F_data4_u32(1, 0, 0, 1);
    const F_data4_u32 data4_u32_0011 = F_data4_u32(0, 0, 1, 1);
    const F_data4_u32 data4_u32_0110 = F_data4_u32(0, 1, 1, 0);
    const F_data4_u32 data4_u32_0101 = F_data4_u32(0, 1, 0, 1);
    const F_data4_u32 data4_u32_1010 = F_data4_u32(1, 0, 1, 0);
}
