#pragma once

/** @file nmath/functions/dot.hpp
*
*   Implement dot.
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

#pragma endregion



namespace nmath {

	////////////////////////////////////////////////////////////////////////////////////
	//  f32
	////////////////////////////////////////////////////////////////////////////////////
	inline f32 dot(PA_vector2_f32 a, PA_vector2_f32 b) noexcept {

		return a.x * a.x + a.y * a.y;
	}
	inline f32 dot(PA_vector3_f32 a, PA_vector3_f32 b) noexcept {

#ifdef NCPP_ENABLE_SSE4
		return _mm_cvtss_f32(_mm_dp_ps(a.xyz_, b.xyz_, 0x71));
#elif defined(NCPP_ENABLE_SSE)
		__m128 mul_res, shuf_reg, sums_reg;
		mul_res = _mm_mul_ps(a.xyz_, b.xyz_);
		mul_res = _mm_mul_ps(mul_res, m128_f32x4_1110);

		shuf_reg = _mm_movehdup_ps(mul_res);
		sums_reg = _mm_add_ps(mul_res, shuf_reg);
		shuf_reg = _mm_movehl_ps(shuf_reg, sums_reg);
		sums_reg = _mm_add_ss(sums_reg, shuf_reg);

		return  _mm_cvtss_f32(sums_reg);
#else
		return a.x * a.x + a.y * a.y + a.z * a.z;
#endif
	}
	inline f32 dot(PA_vector4_f32 a, PA_vector4_f32 b) noexcept {

#ifdef NCPP_ENABLE_SSE4
		return _mm_cvtss_f32(_mm_dp_ps(a.xyzw_, b.xyzw_, 0xFF));
#elif defined(NCPP_ENABLE_SSE)
		__m128 mul_res, shuf_reg, sums_reg;
		mul_res = _mm_mul_ps(a.xyzw_, b.xyzw_);

		shuf_reg = _mm_movehdup_ps(mul_res);
		sums_reg = _mm_add_ps(mul_res, shuf_reg);
		shuf_reg = _mm_movehl_ps(shuf_reg, sums_reg);
		sums_reg = _mm_add_ss(sums_reg, shuf_reg);

		return  _mm_cvtss_f32(sums_reg);
#else
		return a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
#endif
	}

}