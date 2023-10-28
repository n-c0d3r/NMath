#include <nmath/simd_helper.hpp>



namespace nmath {

#ifdef NMATH_ENABLE_SIMD_F32X4
    const F_simd_f32x4 simd_f32x4_0000 = make_simd_f32x4(0.0f, 0.0f, 0.0f, 0.0f);

    const F_simd_f32x4 simd_f32x4_FFFF = make_simd_f32x4(NCPP_U32_MAX, NCPP_U32_MAX, NCPP_U32_MAX, NCPP_U32_MAX);

    const F_simd_f32x4 simd_f32x4_000F = make_simd_f32x4(0, 0, 0, NCPP_U32_MAX);
    const F_simd_f32x4 simd_f32x4_00F0 = make_simd_f32x4(0, 0, NCPP_U32_MAX, 0);
    const F_simd_f32x4 simd_f32x4_0F00 = make_simd_f32x4(0, NCPP_U32_MAX, 0, 0);
    const F_simd_f32x4 simd_f32x4_F000 = make_simd_f32x4(NCPP_U32_MAX, 0, 0, 0);

    const F_simd_f32x4 simd_f32x4_FFF0 = make_simd_f32x4(NCPP_U32_MAX, NCPP_U32_MAX, NCPP_U32_MAX, 0);
    const F_simd_f32x4 simd_f32x4_FF0F = make_simd_f32x4(NCPP_U32_MAX, NCPP_U32_MAX, 0, NCPP_U32_MAX);
    const F_simd_f32x4 simd_f32x4_F0FF = make_simd_f32x4(NCPP_U32_MAX, 0, NCPP_U32_MAX, NCPP_U32_MAX);
    const F_simd_f32x4 simd_f32x4_0FFF = make_simd_f32x4(0, NCPP_U32_MAX, NCPP_U32_MAX, NCPP_U32_MAX);

    const F_simd_f32x4 simd_f32x4_FF00 = make_simd_f32x4(NCPP_U32_MAX, NCPP_U32_MAX, 0, 0);
    const F_simd_f32x4 simd_f32x4_F00F = make_simd_f32x4(NCPP_U32_MAX, 0, 0, NCPP_U32_MAX);
    const F_simd_f32x4 simd_f32x4_00FF = make_simd_f32x4(0, 0, NCPP_U32_MAX, NCPP_U32_MAX);
    const F_simd_f32x4 simd_f32x4_0FF0 = make_simd_f32x4(0, NCPP_U32_MAX, NCPP_U32_MAX, 0);
    const F_simd_f32x4 simd_f32x4_0F0F = make_simd_f32x4(0, NCPP_U32_MAX, 0, NCPP_U32_MAX);
    const F_simd_f32x4 simd_f32x4_F0F0 = make_simd_f32x4(NCPP_U32_MAX, 0, NCPP_U32_MAX, 0);

    const F_simd_f32x4 simd_f32x4_1111 = make_simd_f32x4(1.0f, 1.0f, 1.0f, 1.0f);

    const F_simd_f32x4 simd_f32x4_0001 = make_simd_f32x4(0.0f, 0.0f, 0.0f, 1.0f);
    const F_simd_f32x4 simd_f32x4_0010 = make_simd_f32x4(0.0f, 0.0f, 1.0f, 0.0f);
    const F_simd_f32x4 simd_f32x4_0100 = make_simd_f32x4(0.0f, 1.0f, 0.0f, 0.0f);
    const F_simd_f32x4 simd_f32x4_1000 = make_simd_f32x4(1.0f, 0.0f, 0.0f, 0.0f);

    const F_simd_f32x4 simd_f32x4_1110 = make_simd_f32x4(1.0f, 1.0f, 1.0f, 0.0f);
    const F_simd_f32x4 simd_f32x4_1101 = make_simd_f32x4(1.0f, 1.0f, 0.0f, 1.0f);
    const F_simd_f32x4 simd_f32x4_1011 = make_simd_f32x4(1.0f, 0.0f, 1.0f, 1.0f);
    const F_simd_f32x4 simd_f32x4_0111 = make_simd_f32x4(0.0f, 1.0f, 1.0f, 1.0f);

    const F_simd_f32x4 simd_f32x4_1100 = make_simd_f32x4(1.0f, 1.0f, 0.0f, 0.0f);
    const F_simd_f32x4 simd_f32x4_1001 = make_simd_f32x4(1.0f, 0.0f, 0.0f, 1.0f);
    const F_simd_f32x4 simd_f32x4_0011 = make_simd_f32x4(0.0f, 0.0f, 1.0f, 1.0f);
    const F_simd_f32x4 simd_f32x4_0110 = make_simd_f32x4(0.0f, 1.0f, 1.0f, 0.0f);
    const F_simd_f32x4 simd_f32x4_0101 = make_simd_f32x4(0.0f, 1.0f, 0.0f, 1.0f);
    const F_simd_f32x4 simd_f32x4_1010 = make_simd_f32x4(1.0f, 0.0f, 1.0f, 0.0f);

    const F_simd_f32x4 simd_f32x4_1111_negative = make_simd_f32x4(-1.0f, -1.0f, -1.0f, -1.0f);

    const F_simd_f32x4 simd_f32x4_0001_negative = make_simd_f32x4(0.0f, 0.0f, 0.0f, -1.0f);
    const F_simd_f32x4 simd_f32x4_0010_negative = make_simd_f32x4(0.0f, 0.0f, -1.0f, 0.0f);
    const F_simd_f32x4 simd_f32x4_0100_negative = make_simd_f32x4(0.0f, -1.0f, 0.0f, 0.0f);
    const F_simd_f32x4 simd_f32x4_1000_negative = make_simd_f32x4(-1.0f, 0.0f, 0.0f, 0.0f);

    const F_simd_f32x4 simd_f32x4_1110_negative = make_simd_f32x4(-1.0f, -1.0f, -1.0f, 0.0f);
    const F_simd_f32x4 simd_f32x4_1101_negative = make_simd_f32x4(-1.0f, -1.0f, 0.0f, -1.0f);
    const F_simd_f32x4 simd_f32x4_1011_negative = make_simd_f32x4(-1.0f, 0.0f, -1.0f, -1.0f);
    const F_simd_f32x4 simd_f32x4_0111_negative = make_simd_f32x4(0.0f, -1.0f, -1.0f, -1.0f);

    const F_simd_f32x4 simd_f32x4_1100_negative = make_simd_f32x4(-1.0f, -1.0f, 0.0f, 0.0f);
    const F_simd_f32x4 simd_f32x4_1001_negative = make_simd_f32x4(-1.0f, 0.0f, 0.0f, -1.0f);
    const F_simd_f32x4 simd_f32x4_0011_negative = make_simd_f32x4(0.0f, 0.0f, -1.0f, -1.0f);
    const F_simd_f32x4 simd_f32x4_0110_negative = make_simd_f32x4(0.0f, -1.0f, -1.0f, 0.0f);
    const F_simd_f32x4 simd_f32x4_0101_negative = make_simd_f32x4(0.0f, -1.0f, 0.0f, -1.0f);
    const F_simd_f32x4 simd_f32x4_1010_negative = make_simd_f32x4(-1.0f, 0.0f, -1.0f, 0.0f);
#endif

#ifdef NMATH_ENABLE_SIMD_I32X4
    const F_simd_i32x4 simd_i32x4_0000 = make_simd_i32x4(0, 0, 0, 0);

    const F_simd_i32x4 simd_i32x4_FFFF = make_simd_i32x4(NCPP_U32_MAX, NCPP_U32_MAX, NCPP_U32_MAX, NCPP_U32_MAX);

    const F_simd_i32x4 simd_i32x4_000F = make_simd_i32x4(0, 0, 0, NCPP_U32_MAX);
    const F_simd_i32x4 simd_i32x4_00F0 = make_simd_i32x4(0, 0, NCPP_U32_MAX, 0);
    const F_simd_i32x4 simd_i32x4_0F00 = make_simd_i32x4(0, NCPP_U32_MAX, 0, 0);
    const F_simd_i32x4 simd_i32x4_F000 = make_simd_i32x4(NCPP_U32_MAX, 0, 0, 0);

    const F_simd_i32x4 simd_i32x4_FFF0 = make_simd_i32x4(NCPP_U32_MAX, NCPP_U32_MAX, NCPP_U32_MAX, 0);
    const F_simd_i32x4 simd_i32x4_FF0F = make_simd_i32x4(NCPP_U32_MAX, NCPP_U32_MAX, 0, NCPP_U32_MAX);
    const F_simd_i32x4 simd_i32x4_F0FF = make_simd_i32x4(NCPP_U32_MAX, 0, NCPP_U32_MAX, NCPP_U32_MAX);
    const F_simd_i32x4 simd_i32x4_0FFF = make_simd_i32x4(0, NCPP_U32_MAX, NCPP_U32_MAX, NCPP_U32_MAX);

    const F_simd_i32x4 simd_i32x4_FF00 = make_simd_i32x4(NCPP_U32_MAX, NCPP_U32_MAX, 0, 0);
    const F_simd_i32x4 simd_i32x4_F00F = make_simd_i32x4(NCPP_U32_MAX, 0, 0, NCPP_U32_MAX);
    const F_simd_i32x4 simd_i32x4_00FF = make_simd_i32x4(0, 0, NCPP_U32_MAX, NCPP_U32_MAX);
    const F_simd_i32x4 simd_i32x4_0FF0 = make_simd_i32x4(0, NCPP_U32_MAX, NCPP_U32_MAX, 0);
    const F_simd_i32x4 simd_i32x4_0F0F = make_simd_i32x4(0, NCPP_U32_MAX, 0, NCPP_U32_MAX);
    const F_simd_i32x4 simd_i32x4_F0F0 = make_simd_i32x4(NCPP_U32_MAX, 0, NCPP_U32_MAX, 0);

    const F_simd_i32x4 simd_i32x4_1111 = make_simd_i32x4(1, 1, 1, 1);

    const F_simd_i32x4 simd_i32x4_0001 = make_simd_i32x4(0, 0, 0, 1);
    const F_simd_i32x4 simd_i32x4_0010 = make_simd_i32x4(0, 0, 1, 0);
    const F_simd_i32x4 simd_i32x4_0100 = make_simd_i32x4(0, 1, 0, 0);
    const F_simd_i32x4 simd_i32x4_1000 = make_simd_i32x4(1, 0, 0, 0);

    const F_simd_i32x4 simd_i32x4_1110 = make_simd_i32x4(1, 1, 1, 0);
    const F_simd_i32x4 simd_i32x4_1101 = make_simd_i32x4(1, 1, 0, 1);
    const F_simd_i32x4 simd_i32x4_1011 = make_simd_i32x4(1, 0, 1, 1);
    const F_simd_i32x4 simd_i32x4_0111 = make_simd_i32x4(0, 1, 1, 1);

    const F_simd_i32x4 simd_i32x4_1100 = make_simd_i32x4(1, 1, 0, 0);
    const F_simd_i32x4 simd_i32x4_1001 = make_simd_i32x4(1, 0, 0, 1);
    const F_simd_i32x4 simd_i32x4_0011 = make_simd_i32x4(0, 0, 1, 1);
    const F_simd_i32x4 simd_i32x4_0110 = make_simd_i32x4(0, 1, 1, 0);
    const F_simd_i32x4 simd_i32x4_0101 = make_simd_i32x4(0, 1, 0, 1);
    const F_simd_i32x4 simd_i32x4_1010 = make_simd_i32x4(1, 0, 1, 0);

    const F_simd_i32x4 simd_i32x4_1111_negative = make_simd_i32x4(-1, -1, -1, -1);

    const F_simd_i32x4 simd_i32x4_0001_negative = make_simd_i32x4(0, 0, 0, -1);
    const F_simd_i32x4 simd_i32x4_0010_negative = make_simd_i32x4(0, 0, -1, 0);
    const F_simd_i32x4 simd_i32x4_0100_negative = make_simd_i32x4(0, -1, 0, 0);
    const F_simd_i32x4 simd_i32x4_1000_negative = make_simd_i32x4(-1, 0, 0, 0);

    const F_simd_i32x4 simd_i32x4_1110_negative = make_simd_i32x4(-1, -1, -1, 0);
    const F_simd_i32x4 simd_i32x4_1101_negative = make_simd_i32x4(-1, -1, 0, -1);
    const F_simd_i32x4 simd_i32x4_1011_negative = make_simd_i32x4(-1, 0, -1, -1);
    const F_simd_i32x4 simd_i32x4_0111_negative = make_simd_i32x4(0, -1, -1, -1);

    const F_simd_i32x4 simd_i32x4_1100_negative = make_simd_i32x4(-1, -1, 0, 0);
    const F_simd_i32x4 simd_i32x4_1001_negative = make_simd_i32x4(-1, 0, 0, -1);
    const F_simd_i32x4 simd_i32x4_0011_negative = make_simd_i32x4(0, 0, -1, -1);
    const F_simd_i32x4 simd_i32x4_0110_negative = make_simd_i32x4(0, -1, -1, 0);
    const F_simd_i32x4 simd_i32x4_0101_negative = make_simd_i32x4(0, -1, 0, -1);
    const F_simd_i32x4 simd_i32x4_1010_negative = make_simd_i32x4(-1, 0, -1, 0);
#endif

}