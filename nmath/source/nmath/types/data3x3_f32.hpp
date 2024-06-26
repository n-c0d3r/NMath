

#pragma once

/** @file nmath/types/data3x3_f32.hpp
*
*   Implement data3x3_f32.
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

#include <nmath/types/data3x3_template.hpp>

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



    using F_data3x3_f32 = TF_data3x3<f32>;



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#ifdef NCPP_ENABLE_AVX
#define NMATH_DATA3X3_SIMD_M256X2() \
    struct {\
        __m256 ab_;\
        __m256 c_;\
    };
#define NMATH_DATA3X3_SIMD_CONSTRUCTOR_M256X2() \
    NCPP_FORCE_INLINE TF_data3x3(__m256 ab, __m256 c) : \
        ab_(ab),\
        c_(c)\
    {}
#else
#define NMATH_DATA3X3_SIMD_M256X2() ;
#define NMATH_DATA3X3_SIMD_CONSTRUCTOR_M256X2() ;
#endif



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    template<typename F_flag__>
    struct NCPP_ALIGN(sizeof(f32) * 4 * 4) TF_data3x3<f32, F_flag__> {

        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = f32;

        using F_pack = TF_data3<F_entry, F_flag__>;
        using PA_pack = TPA_data3<F_entry, F_flag__>;

        using F_data2x2 = TF_data2x2<F_entry, F_flag__>;
        using PA_data2x2 = TPA_data2x2<F_entry, F_flag__>;

        using F_flag = F_flag__;

        using F_this = TF_data3x3<F_entry, F_flag__>;

        static constexpr u32 entry_count_s = 9;
        static constexpr u32 pack_count_s = 3;

        // at least the lowest SIMD level is enabled, use pass-by-value
#if defined(NCPP_ENABLE_SSE)
        using F_passed_argument = const F_this;
#else
        using F_passed_argument = const F_this&;
#endif

        NCPP_RTTI_IMPLEMENT_FLAG(nmath::F_data3x3_f32_flag);
        NCPP_RTTI_IMPLEMENT_FLAG(F_flag__);



        ////////////////////////////////////////////////////////////////////////////////////
        //  Arguments
        ////////////////////////////////////////////////////////////////////////////////////
        union {

            struct {

                F_pack a;
                F_pack b;
                F_pack c;

            };
            struct {

                F_pack right;
                F_pack up;
                F_pack forward;

            };
            struct {

                F_pack bitangent;
                F_pack normal;
                F_pack tangent;

            };

            struct {

                F_entry ax;
                F_entry ay;
                F_entry az;
                F_entry aw_;

                F_entry bx;
                F_entry by;
                F_entry bz;
                F_entry bw_;

                F_entry cx;
                F_entry cy;
                F_entry cz;
                F_entry cw_;

                F_entry dx_;
                F_entry dy_;
                F_entry dz_;
                F_entry dw_;

            };

            F_pack m[3];

            NMATH_DATA3X3_SIMD_M256X2();

        };



        ////////////////////////////////////////////////////////////////////////////////////
        //  Basic constructors
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data3x3() noexcept = default;
        NCPP_FORCE_INLINE TF_data3x3(PA_pack a, PA_pack b, PA_pack c) noexcept :
#ifdef NCPP_ENABLE_AVX
            ab_(_mm256_set_m128(b.xyz_, a.xyz_)),
            c_(_mm256_set_m128(simd_f32x4_0000, c.xyz_))
#else
            a(a),
            b(b),
            c(c)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data3x3(const TF_data3x3& o) noexcept :
#ifdef NCPP_ENABLE_AVX
            ab_(o.ab_),
            c_(o.c_)
#else
            a(o.a),
            b(o.b),
            c(o.c)
#endif
        {



        }

        NMATH_DATA3X3_SIMD_CONSTRUCTOR_M256X2();



        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data3x3& NMATH_CALL_CNV operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_AVX
            ab_ = o.ab_;
            c_ = o.c_;
#else
            a = o.a;
            b = o.b;
            c = o.c;
#endif

            return *this;
        }
        NCPP_FORCE_INLINE PA_pack operator [] (i32 index) const noexcept
        {

            return m[index];
        }
        NCPP_FORCE_INLINE F_pack& operator [] (i32 index) noexcept
        {

            return m[index];
        }
        friend NCPP_FORCE_INLINE ncpp::b8 NMATH_CALL_CNV operator == (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_AVX
            __m256 ab_compare8 = _mm256_cmp_ps(a.ab_, b.ab_, _CMP_EQ_OQ);
            int ab_mask = _mm256_movemask_ps(ab_compare8);

            __m256 c_compare8 = _mm256_cmp_ps(a.c_, b.c_, _CMP_EQ_OQ);
            int c_mask = _mm256_movemask_ps(c_compare8);

            return (((ab_mask | 0b10001000) & (c_mask | 0b11111000)) == 0b11111111);
#else
            return (a.a == b.a) && (a.b == b.b) && (a.c == b.c);
#endif
        }
        friend NCPP_FORCE_INLINE ncpp::b8 NMATH_CALL_CNV operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_AVX
            __m256 ab_compare8 = _mm256_cmp_ps(a.ab_, b.ab_, _CMP_EQ_OQ);
            int ab_mask = _mm256_movemask_ps(ab_compare8);

            __m256 c_compare8 = _mm256_cmp_ps(a.c_, b.c_, _CMP_EQ_OQ);
            int c_mask = _mm256_movemask_ps(c_compare8);

            return (((ab_mask | 0b10001000) & (c_mask | 0b11111000)) != 0b11111111);
#else
            return (a.a != b.a) || (a.b != b.b) || (a.c != b.c);
#endif
        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Special values
        ////////////////////////////////////////////////////////////////////////////////////
        static NCPP_FORCE_INLINE F_this zero() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_00000000,
                simd_f32x8_00000000
            };
#else
            return {
                F_pack::zero(),
                F_pack::zero(),
                F_pack::zero()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this one() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111,
                simd_f32x8_11111111
            };
#else
            return {
                F_pack::one(),
                F_pack::one(),
                F_pack::one()
            };
#endif
        }
		static NCPP_FORCE_INLINE F_this half() noexcept {

#ifdef NCPP_ENABLE_AVX
			return {
				simd_f32x8_11111111_half,
				simd_f32x8_11111111_half
			};
#else
			return {
                F_pack::half(),
                F_pack::half(),
                F_pack::half()
            };
#endif
		}
		static NCPP_FORCE_INLINE F_this negative_half() noexcept {

#ifdef NCPP_ENABLE_AVX
			return {
				simd_f32x8_11111111_negative_half,
				simd_f32x8_11111111_negative_half
			};
#else
			return {
                F_pack::negative_half(),
                F_pack::negative_half(),
                F_pack::negative_half()
            };
#endif
		}
		static NCPP_FORCE_INLINE F_this inv_half() noexcept {

#ifdef NCPP_ENABLE_AVX
			return {
				simd_f32x8_11111111_inv_half,
				simd_f32x8_11111111_inv_half
			};
#else
			return {
                F_pack::inv_half(),
                F_pack::inv_half(),
                F_pack::inv_half()
            };
#endif
		}
		static NCPP_FORCE_INLINE F_this inv_negative_half() noexcept {

#ifdef NCPP_ENABLE_AVX
			return {
				simd_f32x8_11111111_inv_negative_half,
				simd_f32x8_11111111_inv_negative_half
			};
#else
			return {
                F_pack::inv_negative_half(),
                F_pack::inv_negative_half(),
                F_pack::inv_negative_half()
            };
#endif
		}
        static NCPP_FORCE_INLINE F_this infinity() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_infinity,
                simd_f32x8_11111111_infinity
            };
#else
            return {
                F_pack::infinity(),
                F_pack::infinity(),
                F_pack::infinity()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this negative_infinity() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_negative_infinity,
                simd_f32x8_11111111_negative_infinity
            };
#else
            return {
                F_pack::negative_infinity(),
                F_pack::negative_infinity(),
                F_pack::negative_infinity()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_pi,
                simd_f32x8_11111111_pi
            };
#else
            return {
                F_pack::pi(),
                F_pack::pi(),
                F_pack::pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this negative_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_negative_pi,
                simd_f32x8_11111111_negative_pi
            };
#else
            return {
                F_pack::negative_pi(),
                F_pack::negative_pi(),
                F_pack::negative_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this half_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_half_pi,
                simd_f32x8_11111111_half_pi
            };
#else
            return {
                F_pack::half_pi(),
                F_pack::half_pi(),
                F_pack::half_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this negative_half_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_negative_half_pi,
                simd_f32x8_11111111_negative_half_pi
            };
#else
            return {
                F_pack::negative_half_pi(),
                F_pack::negative_half_pi(),
                F_pack::negative_half_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this two_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_two_pi,
                simd_f32x8_11111111_two_pi
            };
#else
            return {
                F_pack::two_pi(),
                F_pack::two_pi(),
                F_pack::two_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this negative_two_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_negative_two_pi,
                simd_f32x8_11111111_negative_two_pi
            };
#else
            return {
                F_pack::negative_two_pi(),
                F_pack::negative_two_pi(),
                F_pack::negative_two_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_inv_pi,
                simd_f32x8_11111111_inv_pi
            };
#else
            return {
                F_pack::inv_pi(),
                F_pack::inv_pi(),
                F_pack::inv_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_negative_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_inv_negative_pi,
                simd_f32x8_11111111_inv_negative_pi
            };
#else
            return {
                F_pack::inv_negative_pi(),
                F_pack::inv_negative_pi(),
                F_pack::inv_negative_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_half_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_inv_half_pi,
                simd_f32x8_11111111_inv_half_pi
            };
#else
            return {
                F_pack::inv_half_pi(),
                F_pack::inv_half_pi(),
                F_pack::inv_half_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_negative_half_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_inv_negative_half_pi,
                simd_f32x8_11111111_inv_negative_half_pi
            };
#else
            return {
                F_pack::inv_negative_half_pi(),
                F_pack::inv_negative_half_pi(),
                F_pack::inv_negative_half_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_two_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_inv_two_pi,
                simd_f32x8_11111111_inv_two_pi
            };
#else
            return {
                F_pack::inv_two_pi(),
                F_pack::inv_two_pi(),
                F_pack::inv_two_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_negative_two_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_inv_negative_two_pi,
                simd_f32x8_11111111_inv_negative_two_pi
            };
#else
            return {
                F_pack::inv_negative_two_pi(),
                F_pack::inv_negative_two_pi(),
                F_pack::inv_negative_two_pi()
            };
#endif
        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Functions
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data3x3<F_entry> data() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                ab_,
                c_
            };
#else
            return {
                a.data(),
                b.data(),
                c.data()
            };
#endif
        }
        template<typename F_another_data__>
        NCPP_FORCE_INLINE TF_data_cast<F_another_data__> T_data() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                ab_,
                c_
            };
#else
            return {
                a.template T_data<TF_pack_cast<F_another_data__>>(),
                b.template T_data<TF_pack_cast<F_another_data__>>(),
                c.template T_data<TF_pack_cast<F_another_data__>>()
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x2 tl2x2() const noexcept {

#ifdef NCPP_ENABLE_AVX
            __m128 a_128 = _mm256_extractf128_ps(ab_, 0x00);
            __m128 b_128 = _mm256_extractf128_ps(ab_, 0x01);
            
            return _mm_shuffle_ps(a_128, b_128, _MM_SHUFFLE(1, 0, 1, 0));
#else
            return {
                a.xy(),
                b.xy()
            };
#endif
        }
        
        NCPP_FORCE_INLINE F_this abc() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                ab_,
                c_
            };
#else
            return {
                a,
                b,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_this acb() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, c_, 0x20),
                _mm256_permute2f128_ps(ab_, ab_, 0x01)
            };
#else
            return {
                a,
                c,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_this bac() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, ab_, 0x01),
                c_
            };
#else
            return {
                b,
                a,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_this bca() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, c_, 0x21),
                ab_
            };
#else
            return {
                b,
                c,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_this cab() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, c_, 0x02),
                _mm256_permute2f128_ps(ab_, ab_, 0x01)
            };
#else
            return {
                c,
                a,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_this cba() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, c_, 0x12),
                ab_
            };
#else
            return {
                c,
                b,
                a
            };
#endif
        }
        
        NCPP_FORCE_INLINE F_this xyz() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                ab_,
                c_
            };
#else
            return {
                a,
                b,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xzy() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(3, 1, 2, 0)),
                _mm256_permute_ps(c_, _MM_SHUFFLE(3, 1, 2, 0))
            };
#else
            return {
                a.xzy(),
                b.xzy(),
                c.xzy()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yxz() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(3, 2, 0, 1)),
                _mm256_permute_ps(c_, _MM_SHUFFLE(3, 2, 0, 1))
            };
#else
            return {
                a.yxz(),
                b.yxz(),
                c.yxz()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yzx() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(3, 0, 2, 1)),
                _mm256_permute_ps(c_, _MM_SHUFFLE(3, 0, 2, 1))
            };
#else
            return {
                a.yzx(),
                b.yzx(),
                c.yzx()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zxy() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(3, 1, 0, 2)),
                _mm256_permute_ps(c_, _MM_SHUFFLE(3, 1, 0, 2))
            };
#else
            return {
                a.zxy(),
                b.zxy(),
                c.zxy()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zyx() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(3, 0, 1, 2)),
                _mm256_permute_ps(c_, _MM_SHUFFLE(3, 0, 1, 2))
            };
#else
            return {
                a.zyx(),
                b.zyx(),
                c.zyx()
            };
#endif
        }

    };



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    using PA_data3x3_f32 = TPA_data3x3<f32>;

}
