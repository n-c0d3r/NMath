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



    NCPP_FORCE_INLINE f32 data_forward(f32 o) noexcept {

        return o;
    }



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

#define NMATH_DEFINE_DATA2_I32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data2_i32 data_forward(NMATH_DATA2_I32_PA(ClassName) o) noexcept { \
        \
        return (::nmath::PA_data2_i32)o; \
    }

#define NMATH_DEFINE_DATA2_I32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> ForwardName(::nmath::PA_data2_i32 o) noexcept { \
        \
        return (::nmath::TPA_data_cast<ClassName>)o; \
    }

#define NMATH_DEFINE_DATA2_U32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data2_u32 data_forward(NMATH_DATA2_U32_PA(ClassName) o) noexcept { \
        \
        return (::nmath::PA_data2_u32)o; \
    }

#define NMATH_DEFINE_DATA2_U32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> ForwardName(::nmath::PA_data2_u32 o) noexcept { \
        \
        return (::nmath::TPA_data_cast<ClassName>)o; \
    }



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data3
    ////////////////////////////////////////////////////////////////////////////////////
#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA3_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data3_f32 NMATH_CALL_CNV data_forward(NMATH_DATA3_F32_PA(ClassName) o) noexcept { \
        \
        return o.data(); \
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
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> NMATH_CALL_CNV ForwardName(::nmath::PA_data3_f32 o) noexcept { \
        \
        return o.T_data<::nmath::TPA_data_cast<ClassName>>(); \
    }
#else
#define NMATH_DEFINE_DATA3_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> ForwardName(::nmath::PA_data3_f32 o) noexcept { \
        \
        return (::nmath::TPA_data_cast<ClassName>)o; \
    }
#endif

#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA3_U32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data3_u32 NMATH_CALL_CNV data_forward(NMATH_DATA3_U32_PA(ClassName) o) noexcept { \
        \
        return o.data(); \
    }
#else
	#define NMATH_DEFINE_DATA3_U32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data3_u32 data_forward(NMATH_DATA3_U32_PA(ClassName) o) noexcept { \
        \
        return (::nmath::PA_data3_u32)o; \
    }
#endif

#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA3_U32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> NMATH_CALL_CNV ForwardName(::nmath::PA_data3_u32 o) noexcept { \
        \
        return o.T_data<::nmath::TPA_data_cast<ClassName>>(); \
    }
#else
	#define NMATH_DEFINE_DATA3_U32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> ForwardName(::nmath::PA_data3_u32 o) noexcept { \
        \
        return (::nmath::TPA_data_cast<ClassName>)o; \
    }
#endif

#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA3_I32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data3_i32 NMATH_CALL_CNV data_forward(NMATH_DATA3_I32_PA(ClassName) o) noexcept { \
        \
        return o.data(); \
    }
#else
	#define NMATH_DEFINE_DATA3_I32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data3_i32 data_forward(NMATH_DATA3_I32_PA(ClassName) o) noexcept { \
        \
        return (::nmath::PA_data3_i32)o; \
    }
#endif

#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA3_I32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> NMATH_CALL_CNV ForwardName(::nmath::PA_data3_i32 o) noexcept { \
        \
        return o.T_data<::nmath::TPA_data_cast<ClassName>>(); \
    }
#else
	#define NMATH_DEFINE_DATA3_I32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> ForwardName(::nmath::PA_data3_i32 o) noexcept { \
        \
        return (::nmath::TPA_data_cast<ClassName>)o; \
    }
#endif



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data4
    ////////////////////////////////////////////////////////////////////////////////////
#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA4_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data4_f32 NMATH_CALL_CNV data_forward(NMATH_DATA4_F32_PA(ClassName) o) noexcept { \
        \
        return o.data(); \
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
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> NMATH_CALL_CNV ForwardName(::nmath::PA_data4_f32 o) noexcept { \
        \
        return o.T_data<::nmath::TPA_data_cast<ClassName>>(); \
    }
#else
#define NMATH_DEFINE_DATA4_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> ForwardName(::nmath::PA_data4_f32 o) noexcept { \
        \
        return (::nmath::TPA_data_cast<ClassName>)o; \
    }
#endif



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data2x2
    ////////////////////////////////////////////////////////////////////////////////////
    // at least the lowest SIMD level is enabled, use pass-by-value
#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA2X2_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data2x2_f32 NMATH_CALL_CNV data_forward(NMATH_DATA2X2_F32_PA(ClassName) o) noexcept { \
        \
        return o.data(); \
    }
#else
#define NMATH_DEFINE_DATA2X2_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data2x2_f32 data_forward(NMATH_DATA2X2_F32_PA(ClassName) o) noexcept { \
        \
        return (::nmath::PA_data2x2_f32)o; \
    }
#endif

    // at least the lowest SIMD level is enabled, use pass-by-value
#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA2X2_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> NMATH_CALL_CNV ForwardName(::nmath::PA_data2x2_f32 o) noexcept { \
        \
        return o.T_data<::nmath::TPA_data_cast<ClassName>>(); \
    }
#else
#define NMATH_DEFINE_DATA2X2_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> ForwardName(::nmath::PA_data2x2_f32 o) noexcept { \
        \
        return (::nmath::TPA_data_cast<ClassName>)o; \
    }
#endif



    ////////////////////////////////////////////////////////////////////////////////////
    //  Data3x3
    ////////////////////////////////////////////////////////////////////////////////////
    // at least the lowest SIMD level is enabled, use pass-by-value
#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA3X3_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data3x3_f32 NMATH_CALL_CNV data_forward(NMATH_DATA3X3_F32_PA(ClassName) o) noexcept { \
        \
        return o.data(); \
    }
#else
#define NMATH_DEFINE_DATA3X3_F32_FORWARD(ClassName) \
    NCPP_FORCE_INLINE ::nmath::PA_data3x3_f32 data_forward(NMATH_DATA3X3_F32_PA(ClassName) o) noexcept { \
        \
        return (::nmath::PA_data3x3_f32)o; \
    }
#endif

    // at least the lowest SIMD level is enabled, use pass-by-value
#ifdef NCPP_ENABLE_SSE
#define NMATH_DEFINE_DATA3X3_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> NMATH_CALL_CNV ForwardName(::nmath::PA_data3x3_f32 o) noexcept { \
        \
        return o.T_data<::nmath::TPA_data_cast<ClassName>>(); \
    }
#else
#define NMATH_DEFINE_DATA3X3_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> ForwardName(::nmath::PA_data3x3_f32 o) noexcept { \
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
    NCPP_FORCE_INLINE ::nmath::PA_data4x4_f32 NMATH_CALL_CNV data_forward(NMATH_DATA4X4_F32_PA(ClassName) o) noexcept { \
        \
        return o.data(); \
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
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> NMATH_CALL_CNV ForwardName(::nmath::PA_data4x4_f32 o) noexcept { \
        \
        return o.T_data<::nmath::TPA_data_cast<ClassName>>(); \
    }
#else
#define NMATH_DEFINE_DATA4X4_F32_REVERSE_FORWARD(ForwardName, ClassName) \
    NCPP_FORCE_INLINE ::nmath::TPA_data_cast<ClassName> ForwardName(::nmath::PA_data4x4_f32 o) noexcept { \
        \
        return (::nmath::TPA_data_cast<ClassName>)o; \
    }
#endif

}
