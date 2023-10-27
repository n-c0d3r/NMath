#include <nmath/simd_helper.hpp>



namespace nmath {

#ifdef NCPP_ENABLE_SSE
    const __m128 m128_zero = _mm_setzero_ps();
    const __m128 m128_f32x4_one = _mm_set1_ps(1.0f);
    const __m128 m128_f32x4_minus_one = _mm_set1_ps(-1.0f);
#endif

}