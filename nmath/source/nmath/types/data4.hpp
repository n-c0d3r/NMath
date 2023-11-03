

#pragma once

/** @file nmath/types/data4.hpp
*
*   Implement data4.
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

#include <nmath/types/data2.hpp>
#include <nmath/types/data3.hpp>
#include <nmath/types/data_helper.hpp>
#include <nmath/types/data_forward.hpp>
#include <nmath/types/data_default_flag.hpp>

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



    template<typename F_entry__ = NMATH_DEFAULT_FP_TYPE, typename F_flag__ = F_data_default_flag>
    struct TF_data4;

    template<typename F_entry__ = NMATH_DEFAULT_FP_TYPE, typename F_flag__ = F_data_default_flag>
    using TPA_data4 = typename TF_data4<F_entry__, F_flag__>::F_passed_argument;

    NCPP_RTTI_CREATE_FLAG(F_data4_f32_flag);
    NCPP_RTTI_CREATE_FLAG(F_data4_i32_flag);
    NCPP_RTTI_CREATE_FLAG(F_data4_u32_flag);

    NCPP_RTTI_CREATE_FLAG(F_data4_f64_flag);
    NCPP_RTTI_CREATE_FLAG(F_data4_i64_flag);
    NCPP_RTTI_CREATE_FLAG(F_data4_u64_flag);



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    using F_data4_f32 = TF_data4<f32>;
    using F_data4_i32 = TF_data4<i32>;
    using F_data4_u32 = TF_data4<u32>;



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

#ifdef NCPP_ENABLE_SSE2
#define NMATH_DATA4_SIMD_M128I() \
    __m128i xyzw_;
#define NMATH_DATA4_SIMD_CONSTRUCTOR_M128I()\
    NCPP_FORCE_INLINE TF_data4(__m128i xyzw) : \
        xyzw_(xyzw)\
    {}
#else
#define NMATH_DATA4_SIMD_M128I() ;
#define NMATH_DATA4_SIMD_CONSTRUCTOR_M128I() ;
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
    struct NCPP_ALIGN(16) TF_data4<f32, F_flag__> {
        
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
        
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data4, nmath::F_data4_f32_flag);
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data4, F_flag__);
        
        
        
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

            F_entry m[4];
            
            NMATH_DATA4_SIMD_M128();
            
        };
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Basic constructors
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data4() noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_(simd_f32x4_0000)
#else
            x(0.0f),
            y(0.0f),
            z(0.0f),
            w(0.0f)
#endif
        {
            
            
            
        }
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
        NCPP_FORCE_INLINE TF_data4& NCPP_VECTOR_CALL operator = (F_passed_argument o) noexcept
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
        friend NCPP_FORCE_INLINE ncpp::b8 NCPP_VECTOR_CALL operator == (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            __m128 compare4 = _mm_cmpeq_ps(a.xyzw_, b.xyzw_);
            int mask = _mm_movemask_ps(compare4);

            return (mask == 0b1111);
#else
            return (a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w);
#endif
        }
        friend NCPP_FORCE_INLINE ncpp::b8 NCPP_VECTOR_CALL operator != (F_passed_argument a, F_passed_argument b) noexcept
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
        //  Functions
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE F_data2 xy() const {

            return {
                x,
                y
            };
        }
        NCPP_FORCE_INLINE F_data2 xz() const {

            return {
                x,
                z
            };
        }
        NCPP_FORCE_INLINE F_data2 xw() const {

            return {
                x,
                w
            };
        }
        NCPP_FORCE_INLINE F_data2 yx() const {

            return {
                y,
                x
            };
        }
        NCPP_FORCE_INLINE F_data2 yz() const {

            return {
                y,
                z
            };
        }
        NCPP_FORCE_INLINE F_data2 yw() const {

            return {
                y,
                w
            };
        }
        NCPP_FORCE_INLINE F_data2 zx() const {

            return {
                z,
                x
            };
        }
        NCPP_FORCE_INLINE F_data2 zy() const {

            return {
                z,
                y
            };
        }
        NCPP_FORCE_INLINE F_data2 zw() const {

            return {
                z,
                w
            };
        }
        NCPP_FORCE_INLINE F_data2 wx() const {

            return {
                w,
                x
            };
        }
        NCPP_FORCE_INLINE F_data2 wy() const {

            return {
                w,
                y
            };
        }
        NCPP_FORCE_INLINE F_data2 wz() const {

            return {
                w,
                z
            };
        }

        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xyz() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xyw() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xzy() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xzw() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xwy() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xwz() const {

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

        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL yxz() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL yxw() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL yzx() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL yzw() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL ywx() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL ywz() const {

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

        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zxy() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zxw() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zyx() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zyw() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zwx() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zwy() const {

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

        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wxy() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wxz() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wyx() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wyz() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wzx() const {

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
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wzy() const {

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

        NCPP_FORCE_INLINE TF_data4<F_entry> NCPP_VECTOR_CALL data4() const {

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
        template<typename F_another_data4__>
        NCPP_FORCE_INLINE TF_data_cast<F_another_data4__> T_data4() const {

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
        NCPP_FORCE_INLINE F_this xyzw() const {

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
        NCPP_FORCE_INLINE F_this xywz() const {

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
        NCPP_FORCE_INLINE F_this xzyw() const {

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
        NCPP_FORCE_INLINE F_this xzwy() const {

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
        NCPP_FORCE_INLINE F_this xwyz() const {

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
        NCPP_FORCE_INLINE F_this xwzy() const {

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

        NCPP_FORCE_INLINE F_this yxzw() const {

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
        NCPP_FORCE_INLINE F_this yxwz() const {

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
        NCPP_FORCE_INLINE F_this yzxw() const {

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
        NCPP_FORCE_INLINE F_this yzwx() const {

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
        NCPP_FORCE_INLINE F_this ywxz() const {

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
        NCPP_FORCE_INLINE F_this ywzx() const {

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

        NCPP_FORCE_INLINE F_this zxyw() const {

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
        NCPP_FORCE_INLINE F_this zxwy() const {

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
        NCPP_FORCE_INLINE F_this zyxw() const {

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
        NCPP_FORCE_INLINE F_this zywx() const {

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
        NCPP_FORCE_INLINE F_this zwxy() const {

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
        NCPP_FORCE_INLINE F_this zwyx() const {

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

        NCPP_FORCE_INLINE F_this wxyz() const {

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
        NCPP_FORCE_INLINE F_this wxzy() const {

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
        NCPP_FORCE_INLINE F_this wyxz() const {

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
        NCPP_FORCE_INLINE F_this wyzx() const {

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
        NCPP_FORCE_INLINE F_this wzxy() const {

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
        NCPP_FORCE_INLINE F_this wzyx() const {

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



    template<typename F_flag__>
    struct NCPP_ALIGN(16) TF_data4<i32, F_flag__> {
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = i32;

        using F_flag = F_flag__;

        using F_this = TF_data4<F_entry, F_flag__>;

        using F_data2 = TF_data2<F_entry, F_flag__>;
        using PA_data2 = TPA_data2<F_entry, F_flag__>;

        using F_data3 = TF_data3<F_entry, F_flag__>;
        using PA_data3 = TPA_data3<F_entry, F_flag__>;

        static constexpr u32 entry_count_s = 4;

#ifdef NCPP_ENABLE_SSE2
        using F_passed_argument = const F_this;
#else
        using F_passed_argument = const F_this&;
#endif
        
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data4, nmath::F_data4_i32_flag);
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data4, F_flag__);
        
        
        
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

            F_entry m[4];

            NMATH_DATA4_SIMD_M128I();
            
        };
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Constructors
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data4() noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(simd_i32x4_0000)
#else
            x(0),
            y(0),
            z(0),
            w(0)
#endif
        {
            
            
            
        }
        NCPP_FORCE_INLINE TF_data4(F_entry x, F_entry y, F_entry z, F_entry w) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(_mm_set_epi32(w, z, y, x))
#else
            x(x),
            y(y),
            z(z),
            w(w)
#endif
        {
            
            
            
        }
        NCPP_FORCE_INLINE TF_data4(F_entry x, F_entry y, PA_data2 zw) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(_mm_set_epi32(zw.w, zw.z, y, x))
#else
            x(x),
            y(y),
            z(zw.x),
            w(zw.y)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4(F_entry x, PA_data2 yz, F_entry w) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(_mm_set_epi32(w, yz.y, yz.x, x))
#else
            x(x),
            y(yz.x),
            z(yz.y),
            w(w)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4(PA_data2 xy, F_entry z, F_entry w) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(_mm_set_epi32(w, z, xy.y, xy.x))
#else
            x(xy.x),
            y(xy.y),
            z(z),
            w(w)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4(PA_data2 xy, PA_data2 zw) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(_mm_set_epi32(zw.y, zw.x, xy.y, xy.x))
#else
            x(xy.x),
            y(xy.y),
            z(zw.x),
            w(zw.y)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4(PA_data3 xyz, F_entry w) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(xyz.xyz_)
#else
            x(xyz.x),
            y(xyz.y),
            z(xyz.z),
            w(w)
#endif
        {

#ifdef NCPP_ENABLE_SSE2
            this->w = w;
#endif

        }
        NCPP_FORCE_INLINE TF_data4(F_entry x, PA_data3 yzw) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(_mm_shuffle_epi32(yzw.xyz_, _MM_SHUFFLE(2, 1, 0, 3)))
#else
            x(x),
            y(yzw.x),
            z(yzw.y),
            w(yzw.z)
#endif
        {

#ifdef NCPP_ENABLE_SSE2
            this->x = x;
#endif

        }
        NCPP_FORCE_INLINE TF_data4(PA_data3 xyz) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(_mm_and_epi32(xyz.xyz_, simd_i32x4_FFF0))
#else
            x(xyz.x),
            y(xyz.y),
            z(xyz.z),
            w(0)
#endif
        {

        }
        NCPP_FORCE_INLINE TF_data4(const TF_data4& o) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(o.xyzw_)
#else
            x(o.x),
            y(o.y),
            z(o.z),
            w(o.w)
#endif
        {



        }

        NMATH_DATA4_SIMD_CONSTRUCTOR_M128I();
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data4& NCPP_VECTOR_CALL operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_SSE2
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
        friend NCPP_FORCE_INLINE ncpp::b8 NCPP_VECTOR_CALL operator == (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE2
            __m128i compare4 = _mm_cmpeq_epi32(a.xyzw_, b.xyzw_);
            int mask = _mm_movemask_epi8(compare4);

            return (mask == 0xFFFF);
#else
            return (a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w);
#endif
        }
        friend NCPP_FORCE_INLINE ncpp::b8 NCPP_VECTOR_CALL operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE2
            __m128i compare4 = _mm_cmpeq_epi32(a.xyzw_, b.xyzw_);
            int mask = _mm_movemask_epi8(compare4);

            return (mask != 0xFFFF);
#else
            return (a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w);
#endif
        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Functions
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE F_data2 xy() const {

            return {
                x,
                y
            };
        }
        NCPP_FORCE_INLINE F_data2 xz() const {

            return {
                x,
                z
            };
        }
        NCPP_FORCE_INLINE F_data2 xw() const {

            return {
                x,
                w
            };
        }
        NCPP_FORCE_INLINE F_data2 yx() const {

            return {
                y,
                x
            };
        }
        NCPP_FORCE_INLINE F_data2 yz() const {

            return {
                y,
                z
            };
        }
        NCPP_FORCE_INLINE F_data2 yw() const {

            return {
                y,
                w
            };
        }
        NCPP_FORCE_INLINE F_data2 zx() const {

            return {
                z,
                x
            };
        }
        NCPP_FORCE_INLINE F_data2 zy() const {

            return {
                z,
                y
            };
        }
        NCPP_FORCE_INLINE F_data2 zw() const {

            return {
                z,
                w
            };
        }
        NCPP_FORCE_INLINE F_data2 wx() const {

            return {
                w,
                x
            };
        }
        NCPP_FORCE_INLINE F_data2 wy() const {

            return {
                w,
                y
            };
        }
        NCPP_FORCE_INLINE F_data2 wz() const {

            return {
                w,
                z
            };
        }

        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xyz() const {

#ifdef NCPP_ENABLE_SSE2
            return xyzw_;
#else
            return {
                x,
                y,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xyw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 3, 1, 0));
#else
            return {
                x,
                y,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xzy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 1, 2, 0));
#else
            return {
                x,
                z,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xzw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 3, 2, 0));
#else
            return {
                x,
                z,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xwy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 1, 3, 0));
#else
            return {
                x,
                w,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xwz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 2, 3, 0));
#else
            return {
                x,
                w,
                z
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL yxz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 2, 0, 1));
#else
            return {
                y,
                x,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL yxw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 3, 0, 1));
#else
            return {
                y,
                x,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL yzx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 0, 2, 1));
#else
            return {
                y,
                z,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL yzw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 3, 2, 1));
#else
            return {
                y,
                z,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL ywx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 0, 3, 1));
#else
            return {
                y,
                w,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL ywz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 2, 3, 1));
#else
            return {
                y,
                w,
                z
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zxy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 1, 0, 2));
#else
            return {
                z,
                x,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zxw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 3, 0, 2));
#else
            return {
                z,
                x,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zyx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 0, 1, 2));
#else
            return {
                z,
                y,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zyw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 3, 1, 2));
#else
            return {
                z,
                y,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zwx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 0, 3, 2));
#else
            return {
                z,
                w,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zwy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 1, 3, 2));
#else
            return {
                z,
                w,
                y
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wxy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 1, 0, 3));
#else
            return {
                w,
                x,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wxz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 2, 0, 3));
#else
            return {
                w,
                x,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wyx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 0, 1, 3));
#else
            return {
                w,
                y,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wyz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 2, 1, 3));
#else
            return {
                w,
                y,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wzx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 0, 2, 3));
#else
            return {
                w,
                z,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wzy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 1, 2, 3));
#else
            return {
                w,
                z,
                y
            };
#endif
        }

        NCPP_FORCE_INLINE TF_data4<F_entry> NCPP_VECTOR_CALL data4() const {

#ifdef NCPP_ENABLE_SSE2
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
        template<typename F_another_data4__>
        NCPP_FORCE_INLINE TF_data_cast<F_another_data4__> T_data4() const {

#ifdef NCPP_ENABLE_SSE2
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
        NCPP_FORCE_INLINE F_this xyzw() const {

#ifdef NCPP_ENABLE_SSE2
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
        NCPP_FORCE_INLINE F_this xywz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(2, 3, 1, 0));
#else
            return {
                x,
                y,
                w,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xzyw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 1, 2, 0));
#else
            return {
                x,
                z,
                y,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xzwy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(1, 3, 2, 0));
#else
            return {
                x,
                z,
                w,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xwyz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(2, 1, 3, 0));
#else
            return {
                x,
                w,
                y,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xwzy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(1, 2, 3, 0));
#else
            return {
                x,
                w,
                z,
                y
            };
#endif
        }

        NCPP_FORCE_INLINE F_this yxzw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 2, 0, 1));
#else
            return {
                y,
                x,
                z,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yxwz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(2, 3, 0, 1));
#else
            return {
                y,
                x,
                w,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yzxw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 0, 2, 1));
#else
            return {
                y,
                z,
                x,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yzwx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(0, 3, 2, 1));
#else
            return {
                y,
                z,
                w,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_this ywxz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(2, 0, 3, 1));
#else
            return {
                y,
                w,
                x,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this ywzx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(0, 2, 3, 1));
#else
            return {
                y,
                w,
                z,
                x
            };
#endif
        }

        NCPP_FORCE_INLINE F_this zxyw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 1, 0, 2));
#else
            return {
                z,
                x,
                y,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zxwy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(1, 3, 0, 2));
#else
            return {
                z,
                x,
                w,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zyxw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 0, 1, 2));
#else
            return {
                z,
                y,
                x,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zywx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(0, 3, 1, 2));
#else
            return {
                z,
                y,
                w,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zwxy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(1, 0, 3, 2));
#else
            return {
                z,
                w,
                x,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zwyx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(0, 1, 3, 2));
#else
            return {
                z,
                w,
                y,
                x
            };
#endif
        }

        NCPP_FORCE_INLINE F_this wxyz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(2, 1, 0, 3));
#else
            return {
                w,
                x,
                y,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wxzy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(1, 2, 0, 3));
#else
            return {
                w,
                x,
                z,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wyxz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(2, 0, 1, 3));
#else
            return {
                w,
                y,
                x,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wyzx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(0, 2, 1, 3));
#else
            return {
                w,
                y,
                z,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wzxy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(1, 0, 2, 3));
#else
            return {
                w,
                z,
                x,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wzyx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(0, 1, 2, 3));
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



    template<typename F_flag__>
    struct NCPP_ALIGN(16) TF_data4<u32, F_flag__> {
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = u32;

        using F_flag = F_flag__;

        using F_this = TF_data4<F_entry, F_flag__>;

        using F_data2 = TF_data2<F_entry, F_flag__>;
        using PA_data2 = TPA_data2<F_entry, F_flag__>;

        using F_data3 = TF_data3<F_entry, F_flag__>;
        using PA_data3 = TPA_data3<F_entry, F_flag__>;

        static constexpr u32 entry_count_s = 4;

#ifdef NCPP_ENABLE_SSE2
        using F_passed_argument = const F_this;
#else
        using F_passed_argument = const F_this&;
#endif
        
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data4, nmath::F_data4_u32_flag);
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data4, F_flag__);
        
        
        
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

            F_entry m[4];

            NMATH_DATA4_SIMD_M128I();
            
        };
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Constructors
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data4() noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(simd_i32x4_0000)
#else
            x(0),
            y(0),
            z(0),
            w(0)
#endif
        {
            
            
            
        }
        NCPP_FORCE_INLINE TF_data4(F_entry x, F_entry y, F_entry z, F_entry w) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(_mm_set_epi32(w, z, y, x))
#else
            x(x),
            y(y),
            z(z),
            w(w)
#endif
        {
            
            
            
        }
        NCPP_FORCE_INLINE TF_data4(F_entry x, F_entry y, PA_data2 zw) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(_mm_set_epi32(zw.w, zw.z, y, x))
#else
            x(x),
            y(y),
            z(zw.x),
            w(zw.y)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4(F_entry x, PA_data2 yz, F_entry w) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(_mm_set_epi32(w, yz.y, yz.x, x))
#else
            x(x),
            y(yz.x),
            z(yz.y),
            w(w)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4(PA_data2 xy, F_entry z, F_entry w) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(_mm_set_epi32(w, z, xy.y, xy.x))
#else
            x(xy.x),
            y(xy.y),
            z(z),
            w(w)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4(PA_data2 xy, PA_data2 zw) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(_mm_set_epi32(zw.y, zw.x, xy.y, xy.x))
#else
            x(xy.x),
            y(xy.y),
            z(zw.x),
            w(zw.y)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4(PA_data3 xyz, F_entry w) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(xyz.xyz_)
#else
            x(xyz.x),
            y(xyz.y),
            z(xyz.z),
            w(w)
#endif
        {

#ifdef NCPP_ENABLE_SSE2
            this->w = w;
#endif

        }
        NCPP_FORCE_INLINE TF_data4(F_entry x, PA_data3 yzw) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(_mm_shuffle_epi32(yzw.xyz_, _MM_SHUFFLE(2, 1, 0, 3)))
#else
            x(x),
            y(yzw.x),
            z(yzw.y),
            w(yzw.z)
#endif
        {

#ifdef NCPP_ENABLE_SSE2
            this->x = x;
#endif

        }
        NCPP_FORCE_INLINE TF_data4(PA_data3 xyz) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(_mm_and_epi32(xyz.xyz_, simd_i32x4_FFF0))
#else
            x(xyz.x),
            y(xyz.y),
            z(xyz.z),
            w(0)
#endif
        {

        }
        NCPP_FORCE_INLINE TF_data4(const TF_data4& o) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyzw_(o.xyzw_)
#else
            x(o.x),
            y(o.y),
            z(o.z),
            w(o.w)
#endif
        {



        }

        NMATH_DATA4_SIMD_CONSTRUCTOR_M128I();
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data4& NCPP_VECTOR_CALL operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_SSE2
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
        friend NCPP_FORCE_INLINE ncpp::b8 NCPP_VECTOR_CALL operator == (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE2
            __m128i compare4 = _mm_cmpeq_epi32(a.xyzw_, b.xyzw_);
            int mask = _mm_movemask_epi8(compare4);

            return (mask == 0xFFFFFFFF);
#else
            return (a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w);
#endif
        }
        friend NCPP_FORCE_INLINE ncpp::b8 NCPP_VECTOR_CALL operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE2
            __m128i compare4 = _mm_cmpeq_epi32(a.xyzw_, b.xyzw_);
            int mask = _mm_movemask_epi8(compare4);

            return (mask != 0xFFFFFFFF);
#else
            return (a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w);
#endif
        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Functions
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE F_data2 xy() const {

            return {
                x,
                y
            };
        }
        NCPP_FORCE_INLINE F_data2 xz() const {

            return {
                x,
                z
            };
        }
        NCPP_FORCE_INLINE F_data2 xw() const {

            return {
                x,
                w
            };
        }
        NCPP_FORCE_INLINE F_data2 yx() const {

            return {
                y,
                x
            };
        }
        NCPP_FORCE_INLINE F_data2 yz() const {

            return {
                y,
                z
            };
        }
        NCPP_FORCE_INLINE F_data2 yw() const {

            return {
                y,
                w
            };
        }
        NCPP_FORCE_INLINE F_data2 zx() const {

            return {
                z,
                x
            };
        }
        NCPP_FORCE_INLINE F_data2 zy() const {

            return {
                z,
                y
            };
        }
        NCPP_FORCE_INLINE F_data2 zw() const {

            return {
                z,
                w
            };
        }
        NCPP_FORCE_INLINE F_data2 wx() const {

            return {
                w,
                x
            };
        }
        NCPP_FORCE_INLINE F_data2 wy() const {

            return {
                w,
                y
            };
        }
        NCPP_FORCE_INLINE F_data2 wz() const {

            return {
                w,
                z
            };
        }

        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xyz() const {

#ifdef NCPP_ENABLE_SSE2
            return xyzw_;
#else
            return {
                x,
                y,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xyw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 3, 1, 0));
#else
            return {
                x,
                y,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xzy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 1, 2, 0));
#else
            return {
                x,
                z,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xzw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 3, 2, 0));
#else
            return {
                x,
                z,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xwy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 1, 3, 0));
#else
            return {
                x,
                w,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL xwz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 2, 3, 0));
#else
            return {
                x,
                w,
                z
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL yxz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 2, 0, 1));
#else
            return {
                y,
                x,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL yxw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 3, 0, 1));
#else
            return {
                y,
                x,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL yzx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 0, 2, 1));
#else
            return {
                y,
                z,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL yzw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 3, 2, 1));
#else
            return {
                y,
                z,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL ywx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 0, 3, 1));
#else
            return {
                y,
                w,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL ywz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 2, 3, 1));
#else
            return {
                y,
                w,
                z
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zxy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 1, 0, 2));
#else
            return {
                z,
                x,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zxw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 3, 0, 2));
#else
            return {
                z,
                x,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zyx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 0, 1, 2));
#else
            return {
                z,
                y,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zyw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 3, 1, 2));
#else
            return {
                z,
                y,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zwx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 0, 3, 2));
#else
            return {
                z,
                w,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL zwy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 1, 3, 2));
#else
            return {
                z,
                w,
                y
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wxy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 1, 0, 3));
#else
            return {
                w,
                x,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wxz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 2, 0, 3));
#else
            return {
                w,
                x,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wyx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 0, 1, 3));
#else
            return {
                w,
                y,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wyz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 2, 1, 3));
#else
            return {
                w,
                y,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wzx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 0, 2, 3));
#else
            return {
                w,
                z,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3 NCPP_VECTOR_CALL wzy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 1, 2, 3));
#else
            return {
                w,
                z,
                y
            };
#endif
        }

        NCPP_FORCE_INLINE TF_data4<F_entry> NCPP_VECTOR_CALL data4() const {

#ifdef NCPP_ENABLE_SSE2
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
        template<typename F_another_data4__>
        NCPP_FORCE_INLINE TF_data_cast<F_another_data4__> T_data4() const {

#ifdef NCPP_ENABLE_SSE2
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
        NCPP_FORCE_INLINE F_this xyzw() const {

#ifdef NCPP_ENABLE_SSE2
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
        NCPP_FORCE_INLINE F_this xywz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(2, 3, 1, 0));
#else
            return {
                x,
                y,
                w,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xzyw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 1, 2, 0));
#else
            return {
                x,
                z,
                y,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xzwy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(1, 3, 2, 0));
#else
            return {
                x,
                z,
                w,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xwyz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(2, 1, 3, 0));
#else
            return {
                x,
                w,
                y,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xwzy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(1, 2, 3, 0));
#else
            return {
                x,
                w,
                z,
                y
            };
#endif
        }

        NCPP_FORCE_INLINE F_this yxzw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 2, 0, 1));
#else
            return {
                y,
                x,
                z,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yxwz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(2, 3, 0, 1));
#else
            return {
                y,
                x,
                w,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yzxw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 0, 2, 1));
#else
            return {
                y,
                z,
                x,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yzwx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(0, 3, 2, 1));
#else
            return {
                y,
                z,
                w,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_this ywxz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(2, 0, 3, 1));
#else
            return {
                y,
                w,
                x,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this ywzx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(0, 2, 3, 1));
#else
            return {
                y,
                w,
                z,
                x
            };
#endif
        }

        NCPP_FORCE_INLINE F_this zxyw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 1, 0, 2));
#else
            return {
                z,
                x,
                y,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zxwy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(1, 3, 0, 2));
#else
            return {
                z,
                x,
                w,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zyxw() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(3, 0, 1, 2));
#else
            return {
                z,
                y,
                x,
                w
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zywx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(0, 3, 1, 2));
#else
            return {
                z,
                y,
                w,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zwxy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(1, 0, 3, 2));
#else
            return {
                z,
                w,
                x,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zwyx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(0, 1, 3, 2));
#else
            return {
                z,
                w,
                y,
                x
            };
#endif
        }

        NCPP_FORCE_INLINE F_this wxyz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(2, 1, 0, 3));
#else
            return {
                w,
                x,
                y,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wxzy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(1, 2, 0, 3));
#else
            return {
                w,
                x,
                z,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wyxz() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(2, 0, 1, 3));
#else
            return {
                w,
                y,
                x,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wyzx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(0, 2, 1, 3));
#else
            return {
                w,
                y,
                z,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wzxy() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(1, 0, 2, 3));
#else
            return {
                w,
                z,
                x,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wzyx() const {

#ifdef NCPP_ENABLE_SSE2
            return _mm_shuffle_epi32(xyzw_, _MM_SHUFFLE(0, 1, 2, 3));
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
    using PA_data4_i32 = TPA_data4<i32>;
    using PA_data4_u32 = TPA_data4<u32>;

    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    NMATH_DEFINE_DATA4_F32_FORWARD(F_data4_f32);

}
