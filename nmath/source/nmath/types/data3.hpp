
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



    template<typename F_flag__>
    struct NCPP_ALIGN(16) TF_data3<f32, F_flag__> {
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = f32;
        using F_flag = F_flag__;

#ifdef NCPP_ENABLE_SSE
        using F_passed_argument = const TF_data3<f32, F_flag__>;
#else
        using F_passed_argument = const TF_data3<f32, F_flag__>&;
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
            
#ifdef NCPP_ENABLE_SSE
            __m128 xyz_;
#endif
            
        };
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Constructors
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data3() noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(m128_zero)
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
#ifdef NCPP_ENABLE_SSE
        inline TF_data3(__m128 m128) noexcept :
            xyz_(m128)
        {
            
            
            
        }
#endif
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

}