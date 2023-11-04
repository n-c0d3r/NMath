#pragma once

/** @file nmath/types/data_forward.hpp
*
*   Implement data data_forward.
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

#include <nmath/types/data_helper.hpp>
#include <nmath/operators/literal.hpp>

#pragma endregion



namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data2
    ////////////////////////////////////////////////////////////////////////////////////
#define NMATH_DEFINE_DATA2_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data2_f32 data_forward(NMATH_DATA2_F32_PA(ClassName) o) noexcept { \
        \
        return (::nmath::PA_data2_f32)o; \
    }

#define NMATH_DEFINE_DATA2_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> ForwardName(::nmath::PA_data2_f32 o) noexcept { \
        \
        return (::nmath::TPA_data_cast<ClassName>)o; \
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data3
    ////////////////////////////////////////////////////////////////////////////////////
#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA3_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data3_f32 NCPP_VECTOR_CALL data_forward(NMATH_DATA3_F32_PA(ClassName) o) noexcept { \
        \
        return o.data3(); \
    }
#else
#define NMATH_DEFINE_DATA3_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data3_f32 data_forward(NMATH_DATA3_F32_PA(ClassName) o) noexcept { \
        \
        return (::nmath::PA_data3_f32)o; \
    }
#endif

#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA3_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> NCPP_VECTOR_CALL ForwardName(::nmath::PA_data3_f32 o) noexcept { \
        \
        return o.T_data3<::nmath::TPA_data_cast<ClassName>>(); \
    }
#else
#define NMATH_DEFINE_DATA3_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> ForwardName(::nmath::PA_data3_f32 o) noexcept { \
        \
        return (::nmath::TPA_data_cast<ClassName>)o; \
    }
#endif



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data4
    ////////////////////////////////////////////////////////////////////////////////////
#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA4_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data4_f32 NCPP_VECTOR_CALL data_forward(NMATH_DATA4_F32_PA(ClassName) o) noexcept { \
        \
        return o.data4(); \
    }
#else
#define NMATH_DEFINE_DATA4_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data4_f32 data_forward(NMATH_DATA4_F32_PA(ClassName) o) noexcept { \
        \
        return (::nmath::PA_data4_f32)o; \
    }
#endif

#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA4_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> NCPP_VECTOR_CALL ForwardName(::nmath::PA_data4_f32 o) noexcept { \
        \
        return o.T_data4<::nmath::TPA_data_cast<ClassName>>(); \
    }
#else
#define NMATH_DEFINE_DATA4_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> ForwardName(::nmath::PA_data4_f32 o) noexcept { \
        \
        return (::nmath::TPA_data_cast<ClassName>)o; \
    }
#endif



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data2x4
    ////////////////////////////////////////////////////////////////////////////////////
    // at least the lowest SIMD level is enabled, use pass-by-value
#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA2X4_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data2x4_f32 NCPP_VECTOR_CALL data_forward(NMATH_DATA2X4_F32_PA(ClassName) o) noexcept { \
        \
        return o.data2x4(); \
    }
#else
#define NMATH_DEFINE_DATA2X4_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data2x4_f32 data_forward(NMATH_DATA2X4_F32_PA(ClassName) o) noexcept { \
        \
        return (::nmath::PA_data2x4_f32)o; \
    }
#endif

    // at least the lowest SIMD level is enabled, use pass-by-value
#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA2X4_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> NCPP_VECTOR_CALL ForwardName(::nmath::PA_data2x4_f32 o) noexcept { \
        \
        return o.T_data2x4<::nmath::TPA_data_cast<ClassName>>(); \
    }
#else
#define NMATH_DEFINE_DATA2X4_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> ForwardName(::nmath::PA_data2x4_f32 o) noexcept { \
        \
        return (::nmath::TPA_data_cast<ClassName>)o; \
    }
#endif



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data3x4
    ////////////////////////////////////////////////////////////////////////////////////
    // at least the lowest SIMD level is enabled, use pass-by-value
#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA3X4_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data3x4_f32 NCPP_VECTOR_CALL data_forward(NMATH_DATA3X4_F32_PA(ClassName) o) noexcept { \
        \
        return o.data3x4(); \
    }
#else
#define NMATH_DEFINE_DATA3X4_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data3x4_f32 data_forward(NMATH_DATA3X4_F32_PA(ClassName) o) noexcept { \
        \
        return (::nmath::PA_data3x4_f32)o; \
    }
#endif

    // at least the lowest SIMD level is enabled, use pass-by-value
#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA3X4_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> NCPP_VECTOR_CALL ForwardName(::nmath::PA_data3x4_f32 o) noexcept { \
        \
        return o.T_data3x4<::nmath::TPA_data_cast<ClassName>>(); \
    }
#else
#define NMATH_DEFINE_DATA3X4_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> ForwardName(::nmath::PA_data3x4_f32 o) noexcept { \
        \
        return (::nmath::TPA_data_cast<ClassName>)o; \
    }
#endif



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data4x4
    ////////////////////////////////////////////////////////////////////////////////////
    // at least the lowest SIMD level is enabled, use pass-by-value
#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA4X4_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data4x4_f32 NCPP_VECTOR_CALL data_forward(NMATH_DATA4X4_F32_PA(ClassName) o) noexcept { \
        \
        return o.data4x4(); \
    }
#else
#define NMATH_DEFINE_DATA4X4_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data4x4_f32 data_forward(NMATH_DATA4X4_F32_PA(ClassName) o) noexcept { \
        \
        return (::nmath::PA_data4x4_f32)o; \
    }
#endif

    // at least the lowest SIMD level is enabled, use pass-by-value
#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA4X4_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> NCPP_VECTOR_CALL ForwardName(::nmath::PA_data4x4_f32 o) noexcept { \
        \
        return o.T_data4x4<::nmath::TPA_data_cast<ClassName>>(); \
    }
#else
#define NMATH_DEFINE_DATA4X4_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> ForwardName(::nmath::PA_data4x4_f32 o) noexcept { \
        \
        return (::nmath::TPA_data_cast<ClassName>)o; \
    }
#endif

}
