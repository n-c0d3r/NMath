#pragma once

/** @file nmath/functions/length.hpp
*
*   Implement length.
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
#include <nmath/types/quaternion.hpp>
#include <nmath/functions/dot.hpp>

#pragma endregion



namespace nmath {

	////////////////////////////////////////////////////////////////////////////////////
	//  f32
	////////////////////////////////////////////////////////////////////////////////////
	NCPP_FORCE_INLINE f32 length_sq(PA_vector2_f32 a) noexcept {

		return dot(a, a);
	}
	NCPP_FORCE_INLINE f32 length(PA_vector2_f32 a) noexcept {

		return std::sqrtf(length_sq(a));
	}
	NCPP_FORCE_INLINE f32 NCPP_VECTOR_CALL length_sq(PA_vector3_f32 a) noexcept {

		return dot(a, a);
	}
	NCPP_FORCE_INLINE f32 NCPP_VECTOR_CALL length(PA_vector3_f32 a) noexcept {

		return std::sqrtf(length_sq(a));
	}
	NCPP_FORCE_INLINE f32 NCPP_VECTOR_CALL length_sq(PA_vector4_f32 a) noexcept {

		return dot(a, a);
	}
	NCPP_FORCE_INLINE f32 NCPP_VECTOR_CALL length(PA_vector4_f32 a) noexcept {

		return std::sqrtf(length_sq(a));
	}
	NCPP_FORCE_INLINE f32 NCPP_VECTOR_CALL length_sq(PA_quaternion_f32 a) noexcept {

		return dot(a, a);
	}
	NCPP_FORCE_INLINE f32 NCPP_VECTOR_CALL length(PA_quaternion_f32 a) noexcept {

		return std::sqrtf(length_sq(a));
	}

}