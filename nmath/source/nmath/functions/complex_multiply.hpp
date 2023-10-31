#pragma once

/** @file nmath/functions/complex4_multiply.hpp
*
*   Implement complex4 multiply.
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

	template<typename F_a__, typename F_b__, typename F_return__ = std::remove_const_t<std::remove_reference_t<F_a__>>>
	NCPP_FORCE_INLINE F_return__ NCPP_VECTOR_CALL complex_multiply(F_a__ a, F_b__ b) noexcept {

		using F_no_const_ref_a = std::remove_const_t<std::remove_reference_t<F_a__>>;
		using F_no_const_ref_b = std::remove_const_t<std::remove_reference_t<F_b__>>;
		using F_no_const_ref_return = std::remove_const_t<std::remove_reference_t<F_return__>>;

		using F_entry = typename F_no_const_ref_a::F_entry;
		static constexpr u32 entry_count_s = F_no_const_ref_a::entry_count_s;

		static_assert((F_no_const_ref_b::entry_count_s == entry_count_s), "wrong entry count (b type)");
		static_assert((F_no_const_ref_return::entry_count_s == entry_count_s), "wrong entry count (return type)");

		static_assert(std::is_same_v<typename F_no_const_ref_b::F_entry, F_entry>, "wrong entry type (b type)");
		static_assert(std::is_same_v<typename F_no_const_ref_return::F_entry, F_entry>, "wrong entry type (return type)");



		////////////////////////////////////////////////////////////////////////////////////
		//  f32x4
		////////////////////////////////////////////////////////////////////////////////////
		if constexpr (std::is_same_v<F_entry, f32> && (entry_count_s == 4)) {

#ifdef NCPP_ENABLE_FMA3
			static const F_simd_f32x4 ControlWZYX = make_simd_f32x4(1.0f, -1.0f, 1.0f, -1.0f);
			static const F_simd_f32x4 ControlZWXY = make_simd_f32x4(1.0f, 1.0f, -1.0f, -1.0f);
			static const F_simd_f32x4 ControlYXWZ = make_simd_f32x4(-1.0f, 1.0f, 1.0f, -1.0f);
			// Copy to SSE registers and use as few as possible for x86
			__m128 Q2X = b.xyzw_;
			__m128 Q2Y = b.xyzw_;
			__m128 Q2Z = b.xyzw_;
			__m128 vResult = b.xyzw_;
			// Splat with one instruction
			vResult = _mm_permute_ps(vResult, _MM_SHUFFLE(3, 3, 3, 3));
			Q2X = _mm_permute_ps(Q2X, _MM_SHUFFLE(0, 0, 0, 0));
			Q2Y = _mm_permute_ps(Q2Y, _MM_SHUFFLE(1, 1, 1, 1));
			Q2Z = _mm_permute_ps(Q2Z, _MM_SHUFFLE(2, 2, 2, 2));
			// Retire Q1 and perform Q1*Q2W
			vResult = _mm_mul_ps(vResult, a.xyzw_);
			__m128 Q1Shuffle = a.xyzw_;
			// Shuffle the copies of Q1
			Q1Shuffle = _mm_permute_ps(Q1Shuffle, _MM_SHUFFLE(0, 1, 2, 3));
			// Mul by Q1WZYX
			Q2X = _mm_mul_ps(Q2X, Q1Shuffle);
			Q1Shuffle = _mm_permute_ps(Q1Shuffle, _MM_SHUFFLE(2, 3, 0, 1));
			// Flip the signs on y and z
			vResult = _mm_fmadd_ps(Q2X, ControlWZYX, vResult);
			// Mul by Q1ZWXY
			Q2Y = _mm_mul_ps(Q2Y, Q1Shuffle);
			Q1Shuffle = _mm_permute_ps(Q1Shuffle, _MM_SHUFFLE(0, 1, 2, 3));
			// Flip the signs on z and w
			Q2Y = _mm_mul_ps(Q2Y, ControlZWXY);
			// Mul by Q1YXWZ
			Q2Z = _mm_mul_ps(Q2Z, Q1Shuffle);
			// Flip the signs on x and w
			Q2Y = _mm_fmadd_ps(Q2Z, ControlYXWZ, Q2Y);
			vResult = _mm_add_ps(vResult, Q2Y);
			return vResult;
#else
			return {
				(b.w * a.x) + (b.x * a.w) + (b.y * a.z) - (b.z * a.y),
				(b.w * a.y) - (b.x * a.z) + (b.y * a.w) + (b.z * a.x),
				(b.w * a.z) + (b.x * a.y) - (b.y * a.x) + (b.z * a.w),
				(b.w * a.w) - (b.x * a.x) - (b.y * a.y) - (b.z * a.z)
			};
#endif
		}

	}

}