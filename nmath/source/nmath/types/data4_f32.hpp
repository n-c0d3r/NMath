

#pragma once

/** @file nmath/types/data4_f32.hpp
*
*   Implement data4_f32.
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

#include <nmath/types/data4_template.hpp>

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



    using F_data4_f32 = TF_data4<f32>;



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
#define NMATH_DATA4_SIMD_M128() \
    __m128 xyzw_;
#define NMATH_DATA4_SIMD_CONSTRUCTOR_M128()\
    NCPP_FORCE_INLINE TF_data4(__m128 xyzw) : \
        xyzw_(xyzw)\
    {}
#else
#define NMATH_DATA4_SIMD_M128() ;
#define NMATH_DATA4_SIMD_CONSTRUCTOR_M128() ;
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
    struct NCPP_ALIGN(sizeof(f32) * 4) TF_data4<f32, F_flag__> {
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = f32;

        using F_flag = F_flag__;

        using F_this = TF_data4<F_entry, F_flag__>;

        using F_data2 = TF_data2<F_entry, F_flag__>;
        using PA_data2 = TPA_data2<F_entry, F_flag__>;

        using F_data3 = TF_data3<F_entry, F_flag__>;
        using PA_data3 = TPA_data3<F_entry, F_flag__>;

        static constexpr u32 entry_count_s = 4;

#ifdef NCPP_ENABLE_SSE
        using F_passed_argument = const F_this;
#else
        using F_passed_argument = const F_this&;
#endif
        
        NCPP_RTTI_IMPLEMENT_FLAG(nmath::F_data4_f32_flag);
        NCPP_RTTI_IMPLEMENT_FLAG(F_flag__);
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Arguments
        ////////////////////////////////////////////////////////////////////////////////////
        union {
            
            struct {
                
                F_entry x;
                F_entry y;
                F_entry z;
                F_entry w;
                
            };
            struct {

                F_entry width;
                F_entry height;
                F_entry depth;
                F_entry distance;

            };

            F_entry m[4];
            
            NMATH_DATA4_SIMD_M128();
            
        };
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Basic constructors
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data4() noexcept = default;
        NCPP_FORCE_INLINE TF_data4(F_entry x, F_entry y, F_entry z, F_entry w) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_(_mm_set_ps(w, z, y, x))
#else
            x(x),
            y(y),
            z(z),
            w(w)
#endif
        {
            
            
            
        }
        NCPP_FORCE_INLINE TF_data4(F_entry x, F_entry y, PA_data2 zw) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_(_mm_set_ps(zw.w, zw.z, y, x))
#else
            x(x),
            y(y),
            z(zw.x),
            w(zw.y)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4(F_entry x, PA_data2 yz, F_entry w) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_(_mm_set_ps(w, yz.y, yz.x, x))
#else
            x(x),
            y(yz.x),
            z(yz.y),
            w(w)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4(PA_data2 xy, PA_data2 zw) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_(_mm_set_ps(zw.y, zw.x, xy.y, xy.x))
#else
            x(xy.x),
            y(xy.y),
            z(zw.x),
            w(zw.y)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4(PA_data2 xy, F_entry z, F_entry w) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_(_mm_set_ps(w, z, xy.y, xy.x))
#else
            x(xy.x),
            y(xy.y),
            z(z),
            w(w)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4(PA_data3 xyz, F_entry w) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_(xyz.xyz_)
#else
            x(xyz.x),
            y(xyz.y),
            z(xyz.z),
            w(w)
#endif
        {

#ifdef NCPP_ENABLE_SSE
            this->w = w;
#endif

        }
        NCPP_FORCE_INLINE TF_data4(F_entry x, PA_data3 yzw) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_(_mm_permute_ps(yzw.xyz_, _MM_SHUFFLE(2, 1, 0, 3)))
#else
            x(x),
            y(yzw.x),
            z(yzw.y),
            w(yzw.z)
#endif
        {

#ifdef NCPP_ENABLE_SSE
            this->x = x;
#endif

        }
        NCPP_FORCE_INLINE TF_data4(PA_data3 xyz) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_(_mm_and_ps(xyz.xyz_, simd_f32x4_FFF0))
#else
            x(xyz.x),
            y(xyz.y),
            z(xyz.z),
            w(0.0f)
#endif
        {

        }
        NCPP_FORCE_INLINE TF_data4(const TF_data4& o) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_(o.xyzw_)
#else
            x(o.x),
            y(o.y),
            z(o.z),
            w(o.w)
#endif
        {
            
            
            
        }

        NMATH_DATA4_SIMD_CONSTRUCTOR_M128();
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data4& NMATH_CALL_CNV operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            xyzw_ = o.xyzw_;
#else
            x = o.x;
            y = o.y;
            z = o.z;
            w = o.w;
#endif

            return *this;
        }
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
            __m128 compare4 = _mm_cmpeq_ps(a.xyzw_, b.xyzw_);
            int mask = _mm_movemask_ps(compare4);

            return (mask == 0b1111);
#else
            return (a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w);
#endif
        }
        friend NCPP_FORCE_INLINE ncpp::b8 NMATH_CALL_CNV operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            __m128 compare4 = _mm_cmpeq_ps(a.xyzw_, b.xyzw_);
            int mask = _mm_movemask_ps(compare4);

            return (mask != 0b1111);
#else
            return (a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w);
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
                0.0f,
                0.0f
            }
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
                1.0f,
                1.0f
            }
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
                0.0f,
                0.0f
            }
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
                0.0f,
                0.0f
            }
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
                1.0f,
                0.0f
            }
#endif
        }
        static NCPP_FORCE_INLINE F_this future() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_0001
            };
#else
            return {
                0.0f,
                0.0f,
                0.0f,
                1.0f
            }
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
                0.0f,
                0.0f
            }
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
                0.0f,
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
                -1.0f,
                0.0f
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this past() noexcept {

#ifdef NCPP_ENABLE_SSE
            return {
                simd_f32x4_0001_negative
            };
#else
            return {
                0.0f,
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
        NCPP_FORCE_INLINE F_data2 xz() const noexcept {

            return {
                x,
                z
            };
        }
        NCPP_FORCE_INLINE F_data2 xw() const noexcept {

            return {
                x,
                w
            };
        }
        NCPP_FORCE_INLINE F_data2 yx() const noexcept {

            return {
                y,
                x
            };
        }
        NCPP_FORCE_INLINE F_data2 yz() const noexcept {

            return {
                y,
                z
            };
        }
        NCPP_FORCE_INLINE F_data2 yw() const noexcept {

            return {
                y,
                w
            };
        }
        NCPP_FORCE_INLINE F_data2 zx() const noexcept {

            return {
                z,
                x
            };
        }
        NCPP_FORCE_INLINE F_data2 zy() const noexcept {

            return {
                z,
                y
            };
        }
        NCPP_FORCE_INLINE F_data2 zw() const noexcept {

            return {
                z,
                w
            };
        }
        NCPP_FORCE_INLINE F_data2 wx() const noexcept {

            return {
                w,
                x
            };
        }
        NCPP_FORCE_INLINE F_data2 wy() const noexcept {

            return {
                w,
                y
            };
        }
        NCPP_FORCE_INLINE F_data2 wz() const noexcept {

            return {
                w,
                z
            };
        }

        NCPP_FORCE_INLINE F_data3 xyz() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return xyzw_;
#else
            return {
                x,
                y,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 xyw() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 3, 1, 0));
#else
            return {
                x,
                y,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 xzy() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 1, 2, 0));
#else
            return {
                x,
                z,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 xzw() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 3, 2, 0));
#else
            return {
                x,
                z,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 xwy() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 1, 3, 0));
#else
            return {
                x,
                w,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 xwz() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 2, 3, 0));
#else
            return {
                x,
                w,
                z
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3 yxz() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 2, 0, 1));
#else
            return {
                y,
                x,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 yxw() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 3, 0, 1));
#else
            return {
                y,
                x,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 yzx() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 0, 2, 1));
#else
            return {
                y,
                z,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 yzw() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 3, 2, 1));
#else
            return {
                y,
                z,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 ywx() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 0, 3, 1));
#else
            return {
                y,
                w,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 ywz() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 2, 3, 1));
#else
            return {
                y,
                w,
                z
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3 zxy() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 1, 0, 2));
#else
            return {
                z,
                x,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 zxw() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 3, 0, 2));
#else
            return {
                z,
                x,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 zyx() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 0, 1, 2));
#else
            return {
                z,
                y,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 zyw() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 3, 1, 2));
#else
            return {
                z,
                y,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 zwx() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 0, 3, 2));
#else
            return {
                z,
                w,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 zwy() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 1, 3, 2));
#else
            return {
                z,
                w,
                y
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3 wxy() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 1, 0, 3));
#else
            return {
                w,
                x,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 wxz() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 2, 0, 3));
#else
            return {
                w,
                x,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 wyx() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 0, 1, 3));
#else
            return {
                w,
                y,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 wyz() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 2, 1, 3));
#else
            return {
                w,
                y,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 wzx() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 0, 2, 3));
#else
            return {
                w,
                z,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 wzy() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 1, 2, 3));
#else
            return {
                w,
                z,
                y
            };
#endif
        }

        NCPP_FORCE_INLINE TF_data4<F_entry> data() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return xyzw_;
#else
            return {
                x,
                y,
                z,
                w
            };
#endif
        }
        template<typename F_another_data__>
        NCPP_FORCE_INLINE TF_data_cast<F_another_data__> T_data() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return xyzw_;
#else
            return {
                x,
                y,
                z,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xyzw() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return xyzw_;
#else
            return {
                x,
                y,
                z,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xywz() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(2, 3, 1, 0));
#else
            return {
                x,
                y,
                w,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xzyw() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 1, 2, 0));
#else
            return {
                x,
                z,
                y,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xzwy() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(1, 3, 2, 0));
#else
            return {
                x,
                z,
                w,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xwyz() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(2, 1, 3, 0));
#else
            return {
                x,
                w,
                y,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xwzy() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(1, 2, 3, 0));
#else
            return {
                x,
                w,
                z,
                y
            };
#endif
        }

        NCPP_FORCE_INLINE F_this yxzw() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 2, 0, 1));
#else
            return {
                y,
                x,
                z,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yxwz() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(2, 3, 0, 1));
#else
            return {
                y,
                x,
                w,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yzxw() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 0, 2, 1));
#else
            return {
                y,
                z,
                x,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yzwx() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(0, 3, 2, 1));
#else
            return {
                y,
                z,
                w,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_this ywxz() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(2, 0, 3, 1));
#else
            return {
                y,
                w,
                x,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this ywzx() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(0, 2, 3, 1));
#else
            return {
                y,
                w,
                z,
                x
            };
#endif
        }

        NCPP_FORCE_INLINE F_this zxyw() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 1, 0, 2));
#else
            return {
                z,
                x,
                y,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zxwy() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(1, 3, 0, 2));
#else
            return {
                z,
                x,
                w,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zyxw() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(3, 0, 1, 2));
#else
            return {
                z,
                y,
                x,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zywx() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(0, 3, 1, 2));
#else
            return {
                z,
                y,
                w,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zwxy() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(1, 0, 3, 2));
#else
            return {
                z,
                w,
                x,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zwyx() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(0, 1, 3, 2));
#else
            return {
                z,
                w,
                y,
                x
            };
#endif
        }

        NCPP_FORCE_INLINE F_this wxyz() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(2, 1, 0, 3));
#else
            return {
                w,
                x,
                y,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wxzy() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(1, 2, 0, 3));
#else
            return {
                w,
                x,
                z,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wyxz() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(2, 0, 1, 3));
#else
            return {
                w,
                y,
                x,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wyzx() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(0, 2, 1, 3));
#else
            return {
                w,
                y,
                z,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wzxy() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(1, 0, 2, 3));
#else
            return {
                w,
                z,
                x,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wzyx() const noexcept {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyzw_, _MM_SHUFFLE(0, 1, 2, 3));
#else
            return {
                w,
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



    using PA_data4_f32 = TPA_data4<f32>;

    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    NMATH_DEFINE_DATA4_F32_FORWARD(F_data4_f32);

}
