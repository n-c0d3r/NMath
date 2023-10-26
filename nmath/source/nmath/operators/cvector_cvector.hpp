#pragma once

/** @file nmath/operators/cvector_cvector.hpp
*
*   Implement operators between cvector and cvector.
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

#include <nmath/types/cvector.hpp>

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
//  nmath::F_cvector2_f32
////////////////////////////////////////////////////////////////////////////////////
inline nmath::F_cvector2_f32 operator + (nmath::CR_cvector2_f32 a, nmath::CR_cvector2_f32 b) noexcept {
    
    return {
        
        a.x + b.x,
        a.y + b.y
        
    };
}
inline nmath::F_cvector2_f32 operator - (nmath::CR_cvector2_f32 a, nmath::CR_cvector2_f32 b) noexcept {
    
    return {
        
        a.x - b.x,
        a.y - b.y
        
    };
}
inline nmath::F_cvector2_f32 operator * (nmath::CR_cvector2_f32 a, nmath::CR_cvector2_f32 b) noexcept {
    
    return {
        
        a.x * b.x,
        a.y * b.y
        
    };
}
inline nmath::F_cvector2_f32 operator / (nmath::CR_cvector2_f32 a, nmath::CR_cvector2_f32 b) noexcept {
    
    return {
        
        a.x / b.x,
        a.y / b.y
        
    };
}



////////////////////////////////////////////////////////////////////////////////////
//  nmath::F_cvector3_f32
////////////////////////////////////////////////////////////////////////////////////
inline nmath::F_cvector3_f32 operator + (nmath::CR_cvector3_f32 a, nmath::CR_cvector3_f32 b) noexcept {
    
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
inline nmath::F_cvector3_f32 operator - (nmath::CR_cvector3_f32 a, nmath::CR_cvector3_f32 b) noexcept {
    
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
inline nmath::F_cvector3_f32 operator * (nmath::CR_cvector3_f32 a, nmath::CR_cvector3_f32 b) noexcept {
    
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
inline nmath::F_cvector3_f32 operator / (nmath::CR_cvector3_f32 a, nmath::CR_cvector3_f32 b) noexcept {
    
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
//  nmath::F_cvector4_f32
////////////////////////////////////////////////////////////////////////////////////
inline nmath::F_cvector4_f32 operator + (nmath::CR_cvector4_f32 a, nmath::CR_cvector4_f32 b) noexcept {
    
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
inline nmath::F_cvector4_f32 operator - (nmath::CR_cvector4_f32 a, nmath::CR_cvector4_f32 b) noexcept {
    
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
inline nmath::F_cvector4_f32 operator * (nmath::CR_cvector4_f32 a, nmath::CR_cvector4_f32 b) noexcept {
    
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
inline nmath::F_cvector4_f32 operator / (nmath::CR_cvector4_f32 a, nmath::CR_cvector4_f32 b) noexcept {
    
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
