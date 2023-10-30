#pragma once

/** @file nmath/utilities/q_rsqrt.hpp
*
*   Implement quick invert square root.
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

#pragma endregion



namespace nmath {

	NMATH_USING_NLIB_NAMESPACES();



	NCPP_FORCE_INLINE f32 q_rsqrt(f32 x) noexcept {

		i32 i;
		f32 x2, y;
		const f32 threehalfs = 1.5F;

		x2 = x * 0.5F;
		y  = x;
		i  = * (i32*) &y;
		i  = 0x5f3759df - (i >> 1);
		y  = * (f32*) &i;
		y  = y * (threehalfs - (x2 * y * y));

		return y;
	}

}