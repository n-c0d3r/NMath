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
	inline F_vector4_f32 cross(PA_vector4_f32 a, PA_vector4_f32 b) noexcept {

		return {

			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x,
			0.0f

		};
	}

}