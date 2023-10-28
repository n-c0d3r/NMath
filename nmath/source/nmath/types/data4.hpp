

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

#include <nmath/simd_helper.hpp>

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



    template<typename F_entry__ = NMATH_DEFAULT_FP_TYPE, typename F_flag__ = void>
    struct TF_data4;

    template<typename F_entry__ = NMATH_DEFAULT_FP_TYPE, typename F_flag__ = void>
    using TPA_data4 = typename TF_data4<F_entry__, F_flag__>::F_passed_argument;



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
#define DATA4_SIMD() \
    __m128 xyzw_;\
    __m128i xyzw_i_;
#define DATA4_SIMD_CONSTRUCTORS()\
    inline TF_data4(__m128 xyzw) : \
        xyzw_(xyzw)\
    {}\
    inline TF_data4(__m128i xyzw_i) : \
        xyzw_i_(xyzw_i)\
    {}
#else
#define DATA4_SIMD() ;
#define DATA4_SIMD_CONSTRUCTORS() ;
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

#ifdef NCPP_ENABLE_SSE
        using F_passed_argument = const F_this;
#else
        using F_passed_argument = const F_this&;
#endif
        
        
        
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
            
            DATA4_SIMD();
            
        };
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Basic constructors
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data4() noexcept :
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
        inline TF_data4(F_entry x, F_entry y, F_entry z, F_entry w) noexcept :
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

        DATA4_SIMD_CONSTRUCTORS();

        inline TF_data4(const TF_data4& o) noexcept :
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
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data4& operator = (F_passed_argument o) noexcept
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
        friend inline ncpp::b8 operator == (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            __m128 compare4 = _mm_cmpeq_ps(a.xyzw_, b.xyzw_);
            int mask = _mm_movemask_ps(compare4);

            return (mask == 0b1111);
#else
            return (a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w);
#endif
        }
        friend inline ncpp::b8 operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            __m128 compare4 = _mm_cmpeq_ps(a.xyzw_, b.xyzw_);
            int mask = _mm_movemask_ps(compare4);

            return (mask != 0b1111);
#else
            return (a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w);
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

#ifdef NCPP_ENABLE_SSE
        using F_passed_argument = const F_this;
#else
        using F_passed_argument = const F_this&;
#endif
        
        
        
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

            DATA4_SIMD();
            
        };
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Constructors
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data4() noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_i_(simd_i32x4_0000)
#else
            x(0),
            y(0),
            z(0),
            w(0)
#endif
        {
            
            
            
        }
        inline TF_data4(F_entry x, F_entry y, F_entry z, F_entry w) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_i_(_mm_set_epi32(w, z, y, x))
#else
            x(x),
            y(y),
            z(z),
            w(w)
#endif
        {
            
            
            
        }

        DATA4_SIMD_CONSTRUCTORS();

        inline TF_data4(const TF_data4& o) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_i_(o.xyzw_i_)
#else
            x(o.x),
            y(o.y),
            z(o.z),
            w(o.w)
#endif
        {



        }
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data4& operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            xyzw_i_ = o.xyzw_i_;
#else
            x = o.x;
            y = o.y;
            z = o.z;
            w = o.w;
#endif

            return *this;
        }
        friend inline ncpp::b8 operator == (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE2
            __m128i compare4 = _mm_cmpeq_epi32(a.xyzw_i_, b.xyzw_i_);
            int mask = _mm_movemask_epi8(compare4);

            return (mask == 0xFFFF);
#else
            return (a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w);
#endif
        }
        friend inline ncpp::b8 operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE2
            __m128i compare4 = _mm_cmpeq_epi32(a.xyzw_i_, b.xyzw_i_);
            int mask = _mm_movemask_epi8(compare4);

            return (mask != 0xFFFF);
#else
            return (a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w);
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

#ifdef NCPP_ENABLE_SSE
        using F_passed_argument = const F_this;
#else
        using F_passed_argument = const F_this&;
#endif
        
        
        
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

            DATA4_SIMD();
            
        };
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Constructors
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data4() noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_i_(simd_i32x4_0000)
#else
            x(0),
            y(0),
            z(0),
            w(0)
#endif
        {
            
            
            
        }
        inline TF_data4(F_entry x, F_entry y, F_entry z, F_entry w) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_i_(_mm_set_epi32(w, z, y, x))
#else
            x(x),
            y(y),
            z(z),
            w(w)
#endif
        {
            
            
            
        }

        DATA4_SIMD_CONSTRUCTORS();

        inline TF_data4(const TF_data4& o) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_i_(o.xyzw_i_)
#else
            x(o.x),
            y(o.y),
            z(o.z),
            w(o.w)
#endif
        {



        }
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data4& operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            xyzw_i_ = o.xyzw_i_;
#else
            x = o.x;
            y = o.y;
            z = o.z;
            w = o.w;
#endif

            return *this;
        }
        friend inline ncpp::b8 operator == (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE2
            __m128i compare4 = _mm_cmpeq_epi32(a.xyzw_i_, b.xyzw_i_);
            int mask = _mm_movemask_epi8(compare4);

            return (mask == 0xFFFFFFFF);
#else
            return (a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w);
#endif
        }
        friend inline ncpp::b8 operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE2
            __m128i compare4 = _mm_cmpeq_epi32(a.xyzw_i_, b.xyzw_i_);
            int mask = _mm_movemask_epi8(compare4);

            return (mask != 0xFFFFFFFF);
#else
            return (a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w);
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

}