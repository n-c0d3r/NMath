#pragma once

/** @file nmath/functions/cross.hpp
*
*   Implement cross.
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
#include <nmath/simd_helper.hpp>

#pragma endregion



namespace nmath {	
	
	////////////////////////////////////////////////////////////////////////////////////
	//  f32
	////////////////////////////////////////////////////////////////////////////////////
	inline float cross(PA_vector2_f32 a, PA_vector2_f32 b) noexcept {

		return a.x * b.y - a.y * b.x;
	}
	inline F_vector3_f32 cross(PA_vector3_f32 a, PA_vector3_f32 b) noexcept {

#ifdef NCPP_ENABLE_SSE
		// y1,z1,x1,w1
		__m128 vTemp1 = _mm_permute_ps(a.xyz_, _MM_SHUFFLE(3, 0, 2, 1));
		// z2,x2,y2,w2
		__m128 vTemp2 = _mm_permute_ps(b.xyz_, _MM_SHUFFLE(3, 1, 0, 2));
		// Perform the left operation
		__m128 vResult = _mm_mul_ps(vTemp1, vTemp2);
		// z1,x1,y1,w1
		vTemp1 = _mm_permute_ps(vTemp1, _MM_SHUFFLE(3, 0, 2, 1));
		// y2,z2,x2,w2
		vTemp2 = _mm_permute_ps(vTemp2, _MM_SHUFFLE(3, 1, 0, 2));
		// Perform the right operation
		vResult = _mm_fnmadd_ps(vTemp1, vTemp2, vResult);

		return vResult;// _mm_and_ps(vResult, simd_f32x4_FFF0);
#else
		return {
	
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
	
		};
#endif
	}
	inline F_vector4_f32 cross(PA_vector4_f32 a, PA_vector4_f32 b, PA_vector4_f32 c) noexcept {

#ifdef NCPP_ENABLE_SSE
		// V2zwyz * V3wzwy
		__m128 vResult = _mm_permute_ps(b.xyzw_, _MM_SHUFFLE(2, 1, 3, 2));
		__m128 vTemp3 = _mm_permute_ps(c.xyzw_, _MM_SHUFFLE(1, 3, 2, 3));
		vResult = _mm_mul_ps(vResult, vTemp3);
		// - V2wzwy * V3zwyz
		__m128 vTemp2 = _mm_permute_ps(b.xyzw_, _MM_SHUFFLE(1, 3, 2, 3));
		vTemp3 = _mm_permute_ps(vTemp3, _MM_SHUFFLE(1, 3, 0, 1));
		vResult = _mm_fnmadd_ps(vTemp2, vTemp3, vResult);
		// term1 * V1yxxx
		__m128 vTemp1 = _mm_permute_ps(a.xyzw_, _MM_SHUFFLE(0, 0, 0, 1));
		vResult = _mm_mul_ps(vResult, vTemp1);

		// V2ywxz * V3wxwx
		vTemp2 = _mm_permute_ps(b.xyzw_, _MM_SHUFFLE(2, 0, 3, 1));
		vTemp3 = _mm_permute_ps(c.xyzw_, _MM_SHUFFLE(0, 3, 0, 3));
		vTemp3 = _mm_mul_ps(vTemp3, vTemp2);
		// - V2wxwx * V3ywxz
		vTemp2 = _mm_permute_ps(vTemp2, _MM_SHUFFLE(2, 1, 2, 1));
		vTemp1 = _mm_permute_ps(c.xyzw_, _MM_SHUFFLE(2, 0, 3, 1));
		vTemp3 = _mm_fnmadd_ps(vTemp2, vTemp1, vTemp3);
		// vResult - temp * V1zzyy
		vTemp1 = _mm_permute_ps(a.xyzw_, _MM_SHUFFLE(1, 1, 2, 2));
		vResult = _mm_fnmadd_ps(vTemp1, vTemp3, vResult);

		// V2yzxy * V3zxyx
		vTemp2 = _mm_permute_ps(b.xyzw_, _MM_SHUFFLE(1, 0, 2, 1));
		vTemp3 = _mm_permute_ps(c.xyzw_, _MM_SHUFFLE(0, 1, 0, 2));
		vTemp3 = _mm_mul_ps(vTemp3, vTemp2);
		// - V2zxyx * V3yzxy
		vTemp2 = _mm_permute_ps(vTemp2, _MM_SHUFFLE(2, 0, 2, 1));
		vTemp1 = _mm_permute_ps(c.xyzw_, _MM_SHUFFLE(1, 0, 2, 1));
		vTemp3 = _mm_fnmadd_ps(vTemp1, vTemp2, vTemp3);
		// vResult + term * V1wwwz
		vTemp1 = _mm_permute_ps(a.xyzw_, _MM_SHUFFLE(2, 3, 3, 3));
		vResult = _mm_fmadd_ps(vTemp3, vTemp1, vResult);
		return vResult;
#else
		return {

			(b.z * c.w - b.w * c.z)* a.y - (b.y * c.w - b.w * c.y) * a.z + (b.y * c.z - b.z * c.y) * a.w,
			(b.w * c.z - b.z * c.w)* a.x - (b.w * c.x - b.x * c.w) * a.z + (b.z * c.x - b.x * c.z) * a.w,
			(b.y * c.w - b.w * c.y)* a.x - (b.x * c.w - b.w * c.x) * a.y + (b.x * c.y - b.y * c.x) * a.w,
			(b.z * c.y - b.y * c.z)* a.x - (b.z * c.x - b.x * c.z) * a.y + (b.y * c.x - b.x * c.y) * a.z

		};
#endif
	}

}