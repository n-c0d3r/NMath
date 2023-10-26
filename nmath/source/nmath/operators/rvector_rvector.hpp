#pragma once

/** @file nmath/operators/rvector_rvector.hpp
*
*   Implement operators between rvector and rvector.
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

#include <nmath/types/rvector.hpp>

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



////////////////////////////////////////////////////////////////////////////////////
//  nmath::F_rvector2_f32
////////////////////////////////////////////////////////////////////////////////////
inline nmath::F_rvector2_f32 operator + (nmath::CR_rvector2_f32 a, nmath::CR_rvector2_f32 b) noexcept {
    
    return {
        
        a.x + b.x,
        a.y + b.y
        
    };
}
inline nmath::F_rvector2_f32 operator - (nmath::CR_rvector2_f32 a, nmath::CR_rvector2_f32 b) noexcept {
    
    return {
        
        a.x - b.x,
        a.y - b.y
        
    };
}
inline nmath::F_rvector2_f32 operator * (nmath::CR_rvector2_f32 a, nmath::CR_rvector2_f32 b) noexcept {
    
    return {
        
        a.x * b.x,
        a.y * b.y
        
    };
}
inline nmath::F_rvector2_f32 operator / (nmath::CR_rvector2_f32 a, nmath::CR_rvector2_f32 b) noexcept {
    
    return {
        
        a.x / b.x,
        a.y / b.y
        
    };
}



////////////////////////////////////////////////////////////////////////////////////
//  nmath::F_rvector3_f32
////////////////////////////////////////////////////////////////////////////////////
inline nmath::F_rvector3_f32 operator + (nmath::CR_rvector3_f32 a, nmath::CR_rvector3_f32 b) noexcept {
    
#ifdef NCPP_ENABLE_SSE
    return _mm_add_ps(a.xyz_, b.xyz_);
#else
    return {
        
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
        
    };
#endif
}
inline nmath::F_rvector3_f32 operator - (nmath::CR_rvector3_f32 a, nmath::CR_rvector3_f32 b) noexcept {
    
#ifdef NCPP_ENABLE_SSE
    return _mm_sub_ps(a.xyz_, b.xyz_);
#else
    return {
        
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
        
    };
#endif
}
inline nmath::F_rvector3_f32 operator * (nmath::CR_rvector3_f32 a, nmath::CR_rvector3_f32 b) noexcept {
    
#ifdef NCPP_ENABLE_SSE
    return _mm_mul_ps(a.xyz_, b.xyz_);
#else
    return {
        
        a.x * b.x,
        a.y * b.y,
        a.z * b.z
        
    };
#endif
}
inline nmath::F_rvector3_f32 operator / (nmath::CR_rvector3_f32 a, nmath::CR_rvector3_f32 b) noexcept {
    
#ifdef NCPP_ENABLE_SSE
    return _mm_div_ps(a.xyz_, b.xyz_);
#else
    return {
        
        a.x / b.x,
        a.y / b.y,
        a.z / b.z
        
    };
#endif
}



////////////////////////////////////////////////////////////////////////////////////
//  nmath::F_rvector4_f32
////////////////////////////////////////////////////////////////////////////////////
inline nmath::F_rvector4_f32 operator + (nmath::CR_rvector4_f32 a, nmath::CR_rvector4_f32 b) noexcept {
    
#ifdef NCPP_ENABLE_SSE
    return _mm_add_ps(a.xyzw_, b.xyzw_);
#else
    return {
        
        a.x + b.x,
        a.y + b.y,
        a.z + b.z,
        a.w + b.w
        
    };
#endif
}
inline nmath::F_rvector4_f32 operator - (nmath::CR_rvector4_f32 a, nmath::CR_rvector4_f32 b) noexcept {
    
#ifdef NCPP_ENABLE_SSE
    return _mm_sub_ps(a.xyzw_, b.xyzw_);
#else
    return {
        
        a.x - b.x,
        a.y - b.y,
        a.z - b.z,
        a.w - b.w
        
    };
#endif
}
inline nmath::F_rvector4_f32 operator * (nmath::CR_rvector4_f32 a, nmath::CR_rvector4_f32 b) noexcept {
    
#ifdef NCPP_ENABLE_SSE
    return _mm_mul_ps(a.xyzw_, b.xyzw_);
#else
    return {
        
        a.x * b.x,
        a.y * b.y,
        a.z * b.z,
        a.w * b.w
        
    };
#endif
}
inline nmath::F_rvector4_f32 operator / (nmath::CR_rvector4_f32 a, nmath::CR_rvector4_f32 b) noexcept {
    
#ifdef NCPP_ENABLE_SSE
    return _mm_div_ps(a.xyzw_, b.xyzw_);
#else
    return {
        
        a.x / b.x,
        a.y / b.y,
        a.z / b.z,
        a.w / b.w
        
    };
#endif
}
