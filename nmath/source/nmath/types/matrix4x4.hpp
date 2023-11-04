

#pragma once

/** @file nmath/types/matrix4x4.hpp
*
*   Implement matrix4x4.
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

#include <nmath/types/data4x4.hpp>
#include <nmath/types/data_forward.hpp>
#include <nmath/types/matrix_flag.hpp>

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



    template<typename F_entry__ = NMATH_DEFAULT_FP_TYPE>
    using TF_matrix4x4 = TF_data4x4<F_entry__, F_matrix_flag>;

    template<typename F_entry__ = NMATH_DEFAULT_FP_TYPE>
    using TPA_matrix4x4 = TPA_data4x4<F_entry__, F_matrix_flag>;

    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    using F_matrix4x4 = TF_matrix4x4<>;
    using PA_matrix4x4 = TPA_matrix4x4<>;
    // using F_matrix4x4_i = TF_matrix4x4<NMATH_DEFAULT_INT_TYPE>;
    // using PA_matrix4x4_i = TPA_matrix4x4<NMATH_DEFAULT_INT_TYPE>;
    // using F_matrix4x4_u = TF_matrix4x4<NMATH_DEFAULT_UINT_TYPE>;
    // using PA_matrix4x4_u = TPA_matrix4x4<NMATH_DEFAULT_UINT_TYPE>;

    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    using F_matrix4x4_f32 = TF_matrix4x4<f32>;
    using PA_matrix4x4_f32 = TPA_matrix4x4<f32>;
    // using F_matrix4x4_i32 = TF_matrix4x4<i32>;
    // using PA_matrix4x4_i32 = TPA_matrix4x4<i32>;
    // using F_matrix4x4_u32 = TF_matrix4x4<u32>;
    // using PA_matrix4x4_u32 = TPA_matrix4x4<u32>;

    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    NMATH_DEFINE_DATA4X4_F32_FORWARD(F_matrix4x4_f32);
    NMATH_DEFINE_DATA4X4_F32_REVERSE_FORWARD(vecma_forward, F_matrix4x4_f32);

}
