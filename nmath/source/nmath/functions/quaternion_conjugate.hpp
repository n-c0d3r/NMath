#pragma once

/** @file nmath/functions/quaternion_conjugate.hpp
*
*   Implement quaternion conjugate.
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

#include <nmath/types/quaternion.hpp>

#pragma endregion



namespace nmath {

	////////////////////////////////////////////////////////////////////////////////////
	//  f32
	////////////////////////////////////////////////////////////////////////////////////
	NCPP_FORCE_INLINE F_quaternion_f32 NMATH_CALL_CNV conjugate(PA_quaternion_f32 a) noexcept {

#ifdef NCPP_ENABLE_SSE
		static const F_simd_f32x4 factor = make_simd_f32x4(-1.0f, -1.0f, -1.0f, 1.0f);

		return _mm_mul_ps(a.xyzw_, factor);
#else
		return {

			-a.x,
			-a.y,
			-a.z,
			a.w
		
		};
#endif
	}

}