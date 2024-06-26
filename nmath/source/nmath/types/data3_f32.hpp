
#pragma once

/** @file nmath/types/data3_f32.hpp
*
*   Implement data3_f32.
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

#include <nmath/types/data3_template.hpp>

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
    


    using F_data3_f32 = TF_data3<f32>;



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
#define NMATH_DATA3_SIMD_M128() \
    __m128 xyz_;
#define NMATH_DATA3_SIMD_CONSTRUCTOR_M128()\
    NCPP_FORCE_INLINE TF_data3(__m128 xyz) : \
        xyz_(xyz)\
    {}
#else
#define NMATH_DATA3_SIMD_M128() ;
#define NMATH_DATA3_SIMD_CONSTRUCTOR_M128() ;
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
    struct NCPP_ALIGN(sizeof(f32) * 4) TF_data3<f32, F_flag__> {

        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = f32;

        using F_flag = F_flag__;

        using F_this = TF_data3<F_entry, F_flag__>;

        using F_data2 = TF_data2<F_entry, F_flag__>;
        using PA_data2 = TPA_data2<F_entry, F_flag__>;

        static constexpr u32 entry_count_s = 3;

#ifdef NCPP_ENABLE_SSE
        using F_passed_argument = const F_this;
#else
        using F_passed_argument = const F_this&;
#endif

		template<typename F_entry__>
		using TF_bind_entry = TF_data3<F_entry__, F_flag__>;
        
        NCPP_RTTI_IMPLEMENT_FLAG(nmath::F_data3_f32_flag);
        NCPP_RTTI_IMPLEMENT_FLAG(F_flag__);
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Arguments
        ////////////////////////////////////////////////////////////////////////////////////
        union {
            
            struct {
                
                F_entry x;
                F_entry y;
                F_entry z;
                
            };
            struct {

                F_entry width;
                F_entry height;
                F_entry depth;

            };

            F_entry m[4];
            
            NMATH_DATA3_SIMD_M128();
            
        };

        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Constructors
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data3() noexcept = default;
        NCPP_FORCE_INLINE TF_data3(F_entry x, F_entry y, F_entry z) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(_mm_set_ps(0.0f, z, y, x))
#else
            x(x),
            y(y),
            z(z)
#endif
        {}
        NCPP_FORCE_INLINE TF_data3(PA_data2 xy, F_entry z) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(_mm_set_ps(0.0f, z, xy.y, xy.x))
#else
            x(xy.x),
            y(xy.y),
            z(z)
#endif
        {}
        NCPP_FORCE_INLINE TF_data3(F_entry x, PA_data2 yz) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(_mm_set_ps(0.0f, yz.y, yz.x, x))
#else
            x(x),
            y(yz.x),
            z(yz.y)
#endif
        {}
        NCPP_FORCE_INLINE TF_data3(PA_data2 xy) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(_mm_set_ps(0.0f, 0.0f, xy.y, xy.x))
#else
            x(xy.x),
            y(xy.y),
            z(0.0f)
#endif
        {}
        NCPP_FORCE_INLINE TF_data3(const TF_data3& o) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(o.xyz_)
#else
            x(o.x),
            y(o.y),
            z(o.z)
#endif
        {}
#ifdef NCPP_ENABLE_SSE4
		TF_data3(TF_data3<i32, F_flag> o) noexcept;
#else
		TF_data3(const TF_data3<i32, F_flag>& o) noexcept;
#endif
#ifdef NCPP_ENABLE_SSE2
		TF_data3(TF_data3<u32, F_flag> o) noexcept;
#else
		TF_data3(const TF_data3<u32, F_flag>& o) noexcept;
#endif

        NMATH_DATA3_SIMD_CONSTRUCTOR_M128();
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data3& NMATH_CALL_CNV operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            xyz_ = o.xyz_;
#else
            x = o.x;
            y = o.y;
            z = o.z;
#endif

            return *this;
        }
#ifdef NCPP_ENABLE_SSE4
		TF_data3& NMATH_CALL_CNV operator = (TF_data3<i32, F_flag> o) noexcept;
#else
		TF_data3& NMATH_CALL_CNV operator = (const TF_data3<i32, F_flag>& o) noexcept;
#endif
#ifdef NCPP_ENABLE_SSE2
		TF_data3& NMATH_CALL_CNV operator = (TF_data3<u32, F_flag> o) noexcept;
#else
		TF_data3& NMATH_CALL_CNV operator = (const TF_data3<u32, F_flag>& o) noexcept;
#endif
        NCPP_FORCE_INLINE const F_entry operator [] (i32 index) const noexcept
        {

            return m[index];
        }
        NCPP_FORCE_INLINE F_entry& operator [] (i32 index) noexcept
        {

            return m[index];
        }
        friend NCPP_FORCE_INLINE ncpp::b8 NMATH_CALL_CNV operator == (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            __m128 compare3 = _mm_cmpeq_ps(a.xyz_, b.xyz_);
            int mask = _mm_movemask_ps(compare3);

            return ((mask & 0b0111) == 0b0111);
#else
            return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
#endif
        }
        friend NCPP_FORCE_INLINE ncpp::b8 NMATH_CALL_CNV operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            __m128 compare3 = _mm_cmpeq_ps(a.xyz_, b.xyz_);
            int mask = _mm_movemask_ps(compare3);

            return ((mask & 0b0111) != 0b0111);
#else
            return (a.x != b.x) || (a.y != b.y) || (a.z != b.z);
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
                0.0f,
                0.0f,
                0.0f
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
                1.0f,
                1.0f,
                1.0f
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
                NMATH_F32_HALF,
                NMATH_F32_HALF,
                NMATH_F32_HALF
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
                NMATH_F32_NEGATIVE_HALF,
                NMATH_F32_NEGATIVE_HALF,
                NMATH_F32_NEGATIVE_HALF
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
                NMATH_F32_HALF,
                NMATH_F32_HALF,
                NMATH_F32_HALF
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
                NMATH_F32_INV_NEGATIVE_HALF,
                NMATH_F32_INV_NEGATIVE_HALF,
                NMATH_F32_INV_NEGATIVE_HALF
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
                NMATH_F32_INFINITY,
                NMATH_F32_INFINITY,
                NMATH_F32_INFINITY
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
                NMATH_F32_NEGATIVE_INFINITY,
                NMATH_F32_NEGATIVE_INFINITY,
                NMATH_F32_NEGATIVE_INFINITY
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
                NMATH_F32_PI,
                NMATH_F32_PI,
                NMATH_F32_PI
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
                NMATH_F32_NEGATIVE_PI,
                NMATH_F32_NEGATIVE_PI,
                NMATH_F32_NEGATIVE_PI
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
                NMATH_F32_HALF_PI,
                NMATH_F32_HALF_PI,
                NMATH_F32_HALF_PI
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
                NMATH_F32_NEGATIVE_HALF_PI,
                NMATH_F32_NEGATIVE_HALF_PI,
                NMATH_F32_NEGATIVE_HALF_PI
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
                NMATH_F32_TWO_PI,
                NMATH_F32_TWO_PI,
                NMATH_F32_TWO_PI
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
                NMATH_F32_NEGATIVE_TWO_PI,
                NMATH_F32_NEGATIVE_TWO_PI,
                NMATH_F32_NEGATIVE_TWO_PI
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
                NMATH_F32_INV_PI,
                NMATH_F32_INV_PI,
                NMATH_F32_INV_PI
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
                NMATH_F32_INV_NEGATIVE_PI,
                NMATH_F32_INV_NEGATIVE_PI,
                NMATH_F32_INV_NEGATIVE_PI
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
                NMATH_F32_INV_HALF_PI,
                NMATH_F32_INV_HALF_PI,
                NMATH_F32_INV_HALF_PI
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
                NMATH_F32_INV_NEGATIVE_HALF_PI,
                NMATH_F32_INV_NEGATIVE_HALF_PI,
                NMATH_F32_INV_NEGATIVE_HALF_PI
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
                NMATH_F32_INV_TWO_PI,
                NMATH_F32_INV_TWO_PI,
                NMATH_F32_INV_TWO_PI
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
                NMATH_F32_INV_NEGATIVE_TWO_PI,
                NMATH_F32_INV_NEGATIVE_TWO_PI,
                NMATH_F32_INV_NEGATIVE_TWO_PI
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this right() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1000
            };
#else
            return {
                1.0f,
                0.0f,
                0.0f
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this up() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_0100
            };
#else
            return {
                0.0f,
                1.0f,
                0.0f
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this forward() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_0010
            };
#else
            return {
                0.0f,
                0.0f,
                1.0f
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this left() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_1000_negative
            };
#else
            return {
                -1.0f,
                0.0f,
                0.0f
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this down() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_0100_negative
            };
#else
            return {
                0.0f,
                -1.0f,
                0.0f
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this backward() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_0010_negative
            };
#else
            return {
                0.0f,
                0.0f,
                -1.0f
            };
#endif
        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Functions
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE F_data2 xy() const noexcept {

            return {            
                x,
                y
            };
        }
        NCPP_FORCE_INLINE F_data2 yx() const noexcept {

            return {
                y,
                x
            };
        }
        NCPP_FORCE_INLINE F_data2 xz() const noexcept {

            return {
                x,
                z
            };
        }
        NCPP_FORCE_INLINE F_data2 zx() const noexcept {

            return {
                z,
                x
            };
        }
        NCPP_FORCE_INLINE F_data2 yz() const noexcept {

            return {
                y,
                z
            };
        }
        NCPP_FORCE_INLINE F_data2 zy() const noexcept {

            return {
                z,
                y
            };
        }

        NCPP_FORCE_INLINE TF_data3<F_entry> data() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return xyz_;
#else
            return {
                x,
                y,
                z
            };
#endif
        }
        template<typename F_another_data__>
        NCPP_FORCE_INLINE TF_data_cast<F_another_data__> T_data() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return xyz_;
#else
            return {
                x,
                y,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xyz() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return xyz_;
#else
            return {
                x,
                y,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xzy() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyz_, _MM_SHUFFLE(3, 1, 2, 0));
#else
            return {
                x,
                z,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yxz() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyz_, _MM_SHUFFLE(3, 2, 0, 1));
#else
            return {
                y,
                x,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yzx() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyz_, _MM_SHUFFLE(3, 0, 2, 1));
#else
            return {
                y,
                z,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zxy() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyz_, _MM_SHUFFLE(3, 1, 0, 2));
#else
            return {
                z,
                x,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zyx() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyz_, _MM_SHUFFLE(3, 0, 1, 2));
#else
            return {
                z,
                y,
                x
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



    using PA_data3_f32 = TPA_data3<f32>;

    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    NMATH_DEFINE_DATA3_F32_FORWARD(F_data3_f32)

}
