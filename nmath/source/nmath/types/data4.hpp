

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

    using F_data4 = TF_data4<>;
    using F_data4_i = TF_data4<NMATH_DEFAULT_INT_TYPE>;



    template<typename F_flag__>
    struct NCPP_ALIGN(16) TF_data4<f32, F_flag__> {
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = f32;
        using F_flag = F_flag__;
        
        
        
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
            
#ifdef NCPP_ENABLE_SSE
            __m128 xyzw_;
#endif
            
        };
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Basic constructors
        ////////////////////////////////////////////////////////////////////////////////////
        inline TF_data4() noexcept :
#ifdef NCPP_ENABLE_SSE
            xyzw_(_mm_setzero_ps())
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
#ifdef NCPP_ENABLE_SSE
        inline TF_data4(__m128 m128) noexcept :
            xyzw_(m128)
        {
            
            
            
        }
#endif
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
        inline TF_data4& operator = (const TF_data4& o) noexcept
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
        
    };

    using F_data4_f32 = TF_data4<f32>;

}



#ifdef NCPP_ENABLE_SSE
template<typename F_flag__>
inline ncpp::b8 operator == (const nmath::TF_data4<ncpp::f32, F_flag__>& a, const nmath::TF_data4<ncpp::f32, F_flag__>& b) noexcept
{
    
    __m128 compare4 = _mm_cmpeq_ps(a.xyzw_, b.xyzw_);
    int mask = _mm_movemask_ps(compare4);
    
    return (mask == 0b1111);
}
template<typename F_flag__>
inline ncpp::b8 operator != (const nmath::TF_data4<ncpp::f32, F_flag__>& a, const nmath::TF_data4<ncpp::f32, F_flag__>& b) noexcept
{
    
    __m128 compare4 = _mm_cmpeq_ps(a.xyzw_, b.xyzw_);
    int mask = _mm_movemask_ps(compare4);
    
    return (mask != 0b1111);
}
#endif

