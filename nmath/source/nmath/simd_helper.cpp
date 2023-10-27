#include <nmath/simd_helper.hpp>



namespace nmath {

#ifdef NCPP_ENABLE_SSE
    const __m128 m128_zero = _mm_setzero_ps();
    const __m128 m128_f32x4_one = _mm_set1_ps(1.0f);
    const __m128 m128_f32x4_minus_one = _mm_set1_ps(-1.0f);

    const __m128 m128_f32x4_1110 = _mm_set_ps(0.0f, 1.0f, 1.0f, 1.0f);
    const __m128 m128_f32x4_1101 = _mm_set_ps(1.0f, 0.0f, 1.0f, 1.0f);
    const __m128 m128_f32x4_1011 = _mm_set_ps(1.0f, 1.0f, 0.0f, 1.0f);
    const __m128 m128_f32x4_0111 = _mm_set_ps(1.0f, 1.0f, 1.0f, 0.0f);

    const __m128 m128_f32x4_1100 = _mm_set_ps(0.0f, 0.0f, 1.0f, 1.0f);
    const __m128 m128_f32x4_1001 = _mm_set_ps(1.0f, 0.0f, 0.0f, 1.0f);
    const __m128 m128_f32x4_0011 = _mm_set_ps(1.0f, 1.0f, 0.0f, 0.0f);
    const __m128 m128_f32x4_0110 = _mm_set_ps(0.0f, 1.0f, 1.0f, 0.0f);
    const __m128 m128_f32x4_1010 = _mm_set_ps(0.0f, 1.0f, 0.0f, 1.0f);
    const __m128 m128_f32x4_0101 = _mm_set_ps(1.0f, 0.0f, 1.0f, 0.0f);

    const __m128 m128_f32x4_0001 = _mm_set_ps(1.0f, 0.0f, 0.0f, 0.0f);
    const __m128 m128_f32x4_0010 = _mm_set_ps(0.0f, 1.0f, 0.0f, 0.0f);
    const __m128 m128_f32x4_0100 = _mm_set_ps(0.0f, 0.0f, 1.0f, 0.0f);
    const __m128 m128_f32x4_1000 = _mm_set_ps(0.0f, 0.0f, 0.0f, 1.0f);
#endif

}