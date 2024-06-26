

#pragma once

/** @file nmath/types/data2x2_f32.hpp
*
*   Implement data2x2_f32.
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

#include <nmath/types/data2x2_template.hpp>

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
    


    using F_data2x2_f32 = TF_data2x2<f32>;



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#ifdef NCPP_ENABLE_SSE
#define NMATH_DATA2X2_SIMD_M128() \
    __m128 ab_;
#define NMATH_DATA2X2_SIMD_CONSTRUCTOR_M128() \
    NCPP_FORCE_INLINE TF_data2x2(__m128 ab) : \
        ab_(ab)\
    {}
#else
#define NMATH_DATA2X2_SIMD_M128() ;
#define NMATH_DATA2X2_SIMD_CONSTRUCTOR_M128() ;
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
    struct NCPP_ALIGN(sizeof(f32) * 2 * 2) TF_data2x2<f32, F_flag__> {
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = f32;

        using F_pack = TF_data2<F_entry, F_flag__>;
        using PA_pack = TPA_data2<F_entry, F_flag__>;

        using F_flag = F_flag__;

        using F_this = TF_data2x2<F_entry, F_flag__>;

        static constexpr u32 entry_count_s = 4;
        static constexpr u32 pack_count_s = 2;

        // at least the lowest SIMD level is enabled, use pass-by-value
#if defined(NCPP_ENABLE_SSE)
        using F_passed_argument = const F_this;
#else
        using F_passed_argument = const F_this&;
#endif
        
        NCPP_RTTI_IMPLEMENT_FLAG(nmath::F_data2x2_f32_flag);
        NCPP_RTTI_IMPLEMENT_FLAG(F_flag__);
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Arguments
        ////////////////////////////////////////////////////////////////////////////////////
        union {
            
            struct {
                
                F_pack a;
                F_pack b;
                
            };
            struct {

                F_pack right;
                F_pack up;

            };

            struct {

                F_entry ax;
                F_entry ay;

                F_entry bx;
                F_entry by;

            };

            F_pack m[2];
            
            NMATH_DATA2X2_SIMD_M128();
            
        };
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Basic constructors
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data2x2() noexcept = default;
        NCPP_FORCE_INLINE TF_data2x2(PA_pack a, PA_pack b) noexcept :
#ifdef NCPP_ENABLE_SSE
            ab_(_mm_set_ps(b.y, b.x, a.y, a.x))
#else
            a(a),
            b(b)
#endif
        {
            
            
            
        }
        NCPP_FORCE_INLINE TF_data2x2(const TF_data2x2& o) noexcept :
#ifdef NCPP_ENABLE_SSE
            ab_(o.ab_)
#else
            a(o.a),
            b(o.b)
#endif
        {
            
            
            
        }

        NMATH_DATA2X2_SIMD_CONSTRUCTOR_M128();
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data2x2& NMATH_CALL_CNV operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            ab_ = o.ab_;
#else
            a = o.a;
            b = o.b;
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

#ifdef NCPP_ENABLE_SSE
            __m128 ab_compare4 = _mm_cmpeq_ps(a.ab_, b.ab_);
            int ab_mask = _mm_movemask_ps(ab_compare4);

            return (ab_mask == 0b1111);
#else
            return (a.a == b.a) && (a.b == b.b);
#endif
        }
        friend NCPP_FORCE_INLINE ncpp::b8 NMATH_CALL_CNV operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            __m128 ab_compare4 = _mm_cmpeq_ps(a.ab_, b.ab_);
            int ab_mask = _mm_movemask_ps(ab_compare4);

            return (ab_mask != 0b1111);
#else
            return (a.a != b.a) || (a.b != b.b);
#endif
        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Special values
        ////////////////////////////////////////////////////////////////////////////////////
        static NCPP_FORCE_INLINE F_this zero() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_0000
            };
#else
            return {
                F_pack::zero(),
                F_pack::zero()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this one() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1111
            };
#else
            return {
                F_pack::one(),
                F_pack::one()
            };
#endif
        }
		static NCPP_FORCE_INLINE F_this half() noexcept {

#ifdef NCPP_ENABLE_SSE
			return {
				simd_f32x4_1111_half
			};
#else
			return {
                F_pack::half(),
                F_pack::half()
            };
#endif
		}
		static NCPP_FORCE_INLINE F_this negative_half() noexcept {

#ifdef NCPP_ENABLE_SSE
			return {
				simd_f32x4_1111_negative_half
			};
#else
			return {
                F_pack::negative_half(),
                F_pack::negative_half()
            };
#endif
		}
		static NCPP_FORCE_INLINE F_this inv_half() noexcept {

#ifdef NCPP_ENABLE_SSE
			return {
				simd_f32x4_1111_inv_half
			};
#else
			return {
                F_pack::inv_half(),
                F_pack::inv_half()
            };
#endif
		}
		static NCPP_FORCE_INLINE F_this inv_negative_half() noexcept {

#ifdef NCPP_ENABLE_SSE
			return {
				simd_f32x4_1111_inv_negative_half
			};
#else
			return {
                F_pack::inv_negative_half(),
                F_pack::inv_negative_half()
            };
#endif
		}
        static NCPP_FORCE_INLINE F_this infinity() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1111_infinity
            };
#else
            return {
                F_pack::infinity(),
                F_pack::infinity()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this negative_infinity() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1111_negative_infinity
            };
#else
            return {
                F_pack::negative_infinity(),
                F_pack::negative_infinity()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this pi() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1111_pi
            };
#else
            return {
                F_pack::pi(),
                F_pack::pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this negative_pi() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1111_negative_pi
            };
#else
            return {
                F_pack::negative_pi(),
                F_pack::negative_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this half_pi() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1111_half_pi
            };
#else
            return {
                F_pack::half_pi(),
                F_pack::half_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this negative_half_pi() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1111_negative_half_pi
            };
#else
            return {
                F_pack::negative_half_pi(),
                F_pack::negative_half_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this two_pi() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1111_two_pi
            };
#else
            return {
                F_pack::two_pi(),
                F_pack::two_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this negative_two_pi() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1111_negative_two_pi
            };
#else
            return {
                F_pack::negative_two_pi(),
                F_pack::negative_two_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_pi() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1111_inv_pi
            };
#else
            return {
                F_pack::inv_pi(),
                F_pack::inv_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_negative_pi() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1111_inv_negative_pi
            };
#else
            return {
                F_pack::inv_negative_pi(),
                F_pack::inv_negative_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_half_pi() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1111_inv_half_pi
            };
#else
            return {
                F_pack::inv_half_pi(),
                F_pack::inv_half_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_negative_half_pi() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1111_inv_negative_half_pi
            };
#else
            return {
                F_pack::inv_negative_half_pi(),
                F_pack::inv_negative_half_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_two_pi() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1111_inv_two_pi
            };
#else
            return {
                F_pack::inv_two_pi(),
                F_pack::inv_two_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_negative_two_pi() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1111_inv_negative_two_pi
            };
#else
            return {
                F_pack::inv_negative_two_pi(),
                F_pack::inv_negative_two_pi()
            };
#endif
        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Functions
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data2x2<F_entry> data() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return ab_;
#else
            return {
                a.data(),
                b.data()
            };
#endif
        }
        template<typename F_another_data__>
        NCPP_FORCE_INLINE TF_data_cast<F_another_data__> T_data() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return ab_;
#else
            return {
                a.template T_data<TF_pack_cast<F_another_data__>>(),
                b.template T_data<TF_pack_cast<F_another_data__>>()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this ab() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return ab_;
#else
            return {
                a,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_this ba() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(ab_, _MM_SHUFFLE(1, 0, 3, 2));
#else
            return {
                b,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xy() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return ab_;
#else
            return {
                a,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yx() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(ab_, _MM_SHUFFLE(2, 3, 0, 1));
#else
            return {
                a.yx(),
                b.yx()
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



    using PA_data2x2_f32 = TPA_data2x2<f32>;

}
