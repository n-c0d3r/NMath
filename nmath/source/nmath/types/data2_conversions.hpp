#pragma once

/** @file nmath/types/data2_conversions.hpp
*
*   Implement data2 conversions.
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

#include <nmath/types/data2_f32.hpp>
#include <nmath/types/data2_i32.hpp>
#include <nmath/types/data2_u32.hpp>

#pragma endregion



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



namespace nmath {

	NMATH_USING_NLIB_NAMESPACES();



NCPP_DISABLE_ALL_WARNINGS_PUSH
	template<typename F_flag__>
	NCPP_FORCE_INLINE TF_data2<f32, F_flag__>::TF_data2(const TF_data2<i32, F_flag__>& o) noexcept :
		x(o.x),
		y(o.y)
	{}
	template<typename F_flag__>
	NCPP_FORCE_INLINE TF_data2<f32, F_flag__>::TF_data2(const TF_data2<u32, F_flag__>& o) noexcept :
		x(o.x),
		y(o.y)
	{}

	template<typename F_flag__>
	NCPP_FORCE_INLINE TF_data2<f32, F_flag__>& TF_data2<f32, F_flag__>::operator = (const TF_data2<i32, F_flag__>& o) noexcept {

		x = o.x;
		y = o.y;

		return *this;
	}
	template<typename F_flag__>
	NCPP_FORCE_INLINE TF_data2<f32, F_flag__>& TF_data2<f32, F_flag__>::operator = (const TF_data2<u32, F_flag__>& o) noexcept {

		x = o.x;
		y = o.y;

		return *this;
	}

	template<typename F_flag__>
	NCPP_FORCE_INLINE TF_data2<i32, F_flag__>::TF_data2(const TF_data2<f32, F_flag__>& o) noexcept :
		x(o.x),
		y(o.y)
	{}
	template<typename F_flag__>
	NCPP_FORCE_INLINE TF_data2<i32, F_flag__>::TF_data2(const TF_data2<u32, F_flag__>& o) noexcept :
		x(o.x),
		y(o.y)
	{}

	template<typename F_flag__>
	NCPP_FORCE_INLINE TF_data2<i32, F_flag__>& TF_data2<i32, F_flag__>::operator = (const TF_data2<f32, F_flag__>& o) noexcept {

		x = o.x;
		y = o.y;

		return *this;
	}
	template<typename F_flag__>
	NCPP_FORCE_INLINE TF_data2<i32, F_flag__>& TF_data2<i32, F_flag__>::operator = (const TF_data2<u32, F_flag__>& o) noexcept {

		x = o.x;
		y = o.y;

		return *this;
	}

	template<typename F_flag__>
	NCPP_FORCE_INLINE TF_data2<u32, F_flag__>::TF_data2(const TF_data2<f32, F_flag__>& o) noexcept :
		x(o.x),
		y(o.y)
	{}
	template<typename F_flag__>
	NCPP_FORCE_INLINE TF_data2<u32, F_flag__>::TF_data2(const TF_data2<i32, F_flag__>& o) noexcept :
		x(o.x),
		y(o.y)
	{}

	template<typename F_flag__>
	NCPP_FORCE_INLINE TF_data2<u32, F_flag__>& TF_data2<u32, F_flag__>::operator = (const TF_data2<f32, F_flag__>& o) noexcept {

		x = o.x;
		y = o.y;

		return *this;
	}
	template<typename F_flag__>
	NCPP_FORCE_INLINE TF_data2<u32, F_flag__>& TF_data2<u32, F_flag__>::operator = (const TF_data2<i32, F_flag__>& o) noexcept {

		x = o.x;
		y = o.y;

		return *this;
	}
NCPP_DISABLE_ALL_WARNINGS_POP

}
