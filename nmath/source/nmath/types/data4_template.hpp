

#pragma once

/** @file nmath/types/data4_template.hpp
*
*   Implement data4_template.
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

#include <nmath/types/data2.hpp>
#include <nmath/types/data3.hpp>
#include <nmath/types/data_helper.hpp>
#include <nmath/types/data_forward.hpp>
#include <nmath/types/data_default_flag.hpp>

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



    template<typename F_entry__ = NMATH_DEFAULT_FP_TYPE, typename F_flag__ = F_data_default_flag>
    struct TF_data4;

    template<typename F_entry__ = NMATH_DEFAULT_FP_TYPE, typename F_flag__ = F_data_default_flag>
    using TPA_data4 = typename TF_data4<F_entry__, F_flag__>::F_passed_argument;

    NCPP_RTTI_CREATE_FLAG(F_data4_f32_flag);
    NCPP_RTTI_CREATE_FLAG(F_data4_i32_flag);
    NCPP_RTTI_CREATE_FLAG(F_data4_u32_flag);

    NCPP_RTTI_CREATE_FLAG(F_data4_f64_flag);
    NCPP_RTTI_CREATE_FLAG(F_data4_i64_flag);
    NCPP_RTTI_CREATE_FLAG(F_data4_u64_flag);

}
