
#pragma once

/** @file nmath/types/data3.hpp
*
*   Implement data3.
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
    struct TF_data3;

    template<typename F_entry__ = NMATH_DEFAULT_FP_TYPE, typename F_flag__ = void>
    using TPA_data3 = typename TF_data3<F_entry__, F_flag__>::F_passed_argument;



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    using F_data3_f32 = TF_data3<f32>;
    using F_data3_i32 = TF_data3<i32>;
    using F_data3_u32 = TF_data3<u32>;



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
#define DATA3_SIMD() \
    __m128 xyz_;\
    __m128i xyz_i_;
#define DATA3_SIMD_CONSTRUCTORS()\
    inline TF_data3(__m128 xyz) : \
        xyz_(xyz)\
    {}\
    inline TF_data3(__m128i xyz_i) : \
        xyz_i_(xyz_i)\
    {}
#else
#define DATA3_SIMD() ;
#define DATA3_SIMD_CONSTRUCTORS() ;
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
    struct NCPP_ALIGN(16) TF_data3<f32, F_flag__> {

        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = f32;
        using F_flag = F_flag__;
        using F_this = TF_data3<F_entry, F_flag__>;

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
                
            };
            
            DATA3_SIMD();
            
        };

        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Constructors
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data3() noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(simd_f32x4_0000)
#else
            x(0.0f),
            y(0.0f),
            z(0.0f)
#endif
        {
            
            
            
        }
        inline TF_data3(F_entry x, F_entry y, F_entry z) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(_mm_set_ps(0.0f, z, y, x))
#else
            x(x),
            y(y),
            z(z)
#endif
        {
            
            
            
        }

        DATA3_SIMD_CONSTRUCTORS();

        inline TF_data3(const TF_data3& o) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(o.xyz_)
#else
            x(o.x),
            y(o.y),
            z(o.z)
#endif
        {



        }
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data3& operator = (F_passed_argument o) noexcept
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
        friend inline ncpp::b8 operator == (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            __m128 compare3 = _mm_cmpeq_ps(a.xyz_, b.xyz_);
            int mask = _mm_movemask_ps(compare3);

            return ((mask & 0b0111) == 0b0111);
#else
            return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
#endif
        }
        friend inline ncpp::b8 operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            __m128 compare3 = _mm_cmpeq_ps(a.xyz_, b.xyz_);
            int mask = _mm_movemask_ps(compare3);

            return ((mask & 0b0111) != 0b0111);
#else
            return (a.x != b.x) || (a.y != b.y) || (a.z != b.z);
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
    struct NCPP_ALIGN(16) TF_data3<i32, F_flag__> {

        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = i32;
        using F_flag = F_flag__;
        using F_this = TF_data3<F_entry, F_flag__>;

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

            };

            DATA3_SIMD();

        };



        ////////////////////////////////////////////////////////////////////////////////////
        //  Constructors
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data3() noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_i_(simd_i32x4_0000)
#else
            x(0),
            y(0),
            z(0)
#endif
        {



        }
        inline TF_data3(F_entry x, F_entry y, F_entry z) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_i_(_mm_set_epi32(0, z, y, x))
#else
            x(x),
            y(y),
            z(z)
#endif
        {



        }

        DATA3_SIMD_CONSTRUCTORS();

        inline TF_data3(const TF_data3& o) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_i_(o.xyz_i_)
#else
            x(o.x),
            y(o.y),
            z(o.z)
#endif
        {



        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data3& operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            xyz_i_ = o.xyz_i_;
#else
            x = o.x;
            y = o.y;
            z = o.z;
#endif

            return *this;
        }
        friend inline ncpp::b8 operator == (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE2
            __m128i compare3 = _mm_cmpeq_epi32(a.xyz_i_, b.xyz_i_);
            int mask = _mm_movemask_epi8(compare3);

            return ((mask & 0x0FFF) == 0x0FFF);
#else
            return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
#endif
        }
        friend inline ncpp::b8 operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE2
            __m128i compare3 = _mm_cmpeq_epi32(a.xyz_i_, b.xyz_i_);
            int mask = _mm_movemask_epi8(compare3);

            return ((mask & 0x0FFF) != 0x0FFF);
#else
            return (a.x != b.x) || (a.y != b.y) || (a.z != b.z);
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
    struct NCPP_ALIGN(16) TF_data3<u32, F_flag__> {
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = u32;
        using F_flag = F_flag__;
        using F_this = TF_data3<F_entry, F_flag__>;

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
                
            };

            DATA3_SIMD();
            
        };
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Constructors
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data3() noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_i_(simd_i32x4_0000)
#else
            x(0),
            y(0),
            z(0)
#endif
        {
            
            
            
        }
        inline TF_data3(F_entry x, F_entry y, F_entry z) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_i_(_mm_set_epi32(0, z, y, x))
#else
            x(x),
            y(y),
            z(z)
#endif
        {
            
            
            
        }

        DATA3_SIMD_CONSTRUCTORS();

        inline TF_data3(const TF_data3& o) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_i_(o.xyz_i_)
#else
            x(o.x),
            y(o.y),
            z(o.z)
#endif
        {



        }
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data3& operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            xyz_i_ = o.xyz_i_;
#else
            x = o.x;
            y = o.y;
            z = o.z;
#endif

            return *this;
        }
        friend inline ncpp::b8 operator == (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE2
            __m128i compare3 = _mm_cmpeq_epi32(a.xyz_i_, b.xyz_i_);
            int mask = _mm_movemask_epi8(compare3);

            return ((mask & 0x00FFFFFF) == 0x00FFFFFF);
#else
            return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
#endif
        }
        friend inline ncpp::b8 operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE2
            __m128i compare3 = _mm_cmpeq_epi32(a.xyz_i_, b.xyz_i_);
            int mask = _mm_movemask_epi8(compare3);

            return ((mask & 0x00FFFFFF) != 0x00FFFFFF);
#else
            return (a.x != b.x) || (a.y != b.y) || (a.z != b.z);
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
    using PA_data3_i32 = TPA_data3<i32>;
    using PA_data3_u32 = TPA_data3<u32>;

}