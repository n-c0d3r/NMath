
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
#include <nmath/types/data2.hpp>

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
#define NMATH_DATA3_SIMD_M128() \
    __m128 xyz_;
#define NMATH_DATA3_SIMD_CONSTRUCTOR_M128()\
    inline TF_data3(__m128 xyz) : \
        xyz_(xyz)\
    {}
#else
#define NMATH_DATA3_SIMD_M128() ;
#define NMATH_DATA3_SIMD_CONSTRUCTOR_M128() ;
#endif

#ifdef NCPP_ENABLE_SSE2
#define NMATH_DATA3_SIMD_M128I() \
    __m128 xyz_i_;
#define NMATH_DATA3_SIMD_CONSTRUCTOR_M128I()\
    inline TF_data3(__m128i xyz) : \
        xyz_i_(xyz)\
    {}
#else
#define NMATH_DATA3_SIMD_M128I() ;
#define NMATH_DATA3_SIMD_CONSTRUCTOR_M128I() ;
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

        using F_data2 = TF_data2<F_entry, F_flag__>;
        using PA_data2 = TPA_data2<F_entry, F_flag__>;

        static constexpr u32 component_count_s = 3;

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
            
            NMATH_DATA3_SIMD_M128();
            
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
        inline TF_data3(PA_data2 xy, F_entry z) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(_mm_set_ps(0.0f, z, xy.y, xy.x))
#else
            x(xy.x),
            y(xy.y),
            z(z)
#endif
        {



        }
        inline TF_data3(F_entry x, PA_data2 yz) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(_mm_set_ps(0.0f, yz.y, yz.x, x))
#else
            x(x),
            y(yz.x),
            z(yz.y)
#endif
        {



        }
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

        NMATH_DATA3_SIMD_CONSTRUCTOR_M128();
        
        
        
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

        using F_data2 = TF_data2<F_entry, F_flag__>;
        using PA_data2 = TPA_data2<F_entry, F_flag__>;

        static constexpr u32 component_count_s = 3;

#ifdef NCPP_ENABLE_SSE2
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

            NMATH_DATA3_SIMD_M128I();

        };



        ////////////////////////////////////////////////////////////////////////////////////
        //  Constructors
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data3() noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyz_i_(simd_i32x4_0000)
#else
            x(0),
            y(0),
            z(0)
#endif
        {



        }
        inline TF_data3(F_entry x, F_entry y, F_entry z) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyz_i_(_mm_set_epi32(0, z, y, x))
#else
            x(x),
            y(y),
            z(z)
#endif
        {



        }
        inline TF_data3(PA_data2 xy, F_entry z) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyz_i_(_mm_set_epi32(0, z, xy.y, xy.x))
#else
            x(xy.x),
            y(xy.y),
            z(z)
#endif
        {



        }
        inline TF_data3(F_entry x, PA_data2 yz) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyz_i_(_mm_set_epi32(0, yz.y, yz.x, x))
#else
            x(x),
            y(yz.x),
            z(yz.y)
#endif
        {



        }
        inline TF_data3(const TF_data3& o) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyz_i_(o.xyz_i_)
#else
            x(o.x),
            y(o.y),
            z(o.z)
#endif
        {



        }

        NMATH_DATA3_SIMD_CONSTRUCTOR_M128I();



        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data3& operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_SSE2
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

        using F_data2 = TF_data2<F_entry, F_flag__>;
        using PA_data2 = TPA_data2<F_entry, F_flag__>;

        static constexpr u32 component_count_s = 3;

#ifdef NCPP_ENABLE_SSE2
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

            NMATH_DATA3_SIMD_M128I();
            
        };
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Constructors
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data3() noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyz_i_(simd_i32x4_0000)
#else
            x(0),
            y(0),
            z(0)
#endif
        {
            
            
            
        }
        inline TF_data3(F_entry x, F_entry y, F_entry z) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyz_i_(_mm_set_epi32(0, z, y, x))
#else
            x(x),
            y(y),
            z(z)
#endif
        {
            
            
            
        }
        inline TF_data3(PA_data2 xy, F_entry z) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyz_i_(_mm_set_epi32(0, z, xy.y, xy.x))
#else
            x(xy.x),
            y(xy.y),
            z(z)
#endif
        {



        }
        inline TF_data3(F_entry x, PA_data2 yz) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyz_i_(_mm_set_epi32(0, yz.y, yz.x, x))
#else
            x(x),
            y(yz.x),
            z(yz.y)
#endif
        {



        }
        inline TF_data3(const TF_data3& o) noexcept :
#ifdef NCPP_ENABLE_SSE2
            xyz_i_(o.xyz_i_)
#else
            x(o.x),
            y(o.y),
            z(o.z)
#endif
        {



        }

        NMATH_DATA3_SIMD_CONSTRUCTOR_M128I();
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data3& operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_SSE2
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