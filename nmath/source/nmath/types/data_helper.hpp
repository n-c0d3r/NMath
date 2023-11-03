#pragma once

/** @file nmath/types/data_helper.hpp
*
*   Implement data helper.
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



namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    template<typename F_data_or_PA_data__>
    using TF_data_cast = std::remove_const_t<std::remove_reference_t<F_data_or_PA_data__>>;
    template<typename F_data_or_PA_data__>
    using TPA_data_cast = typename TF_data_cast<F_data_or_PA_data__>::F_passed_argument;
    template<typename F_data_or_PA_data__>
    using TF_entry_cast = typename TF_data_cast<F_data_or_PA_data__>::F_entry;
    template<typename F_data_or_PA_data__>
    static constexpr u32 T_entry_count_cast = TF_data_cast<F_data_or_PA_data__>::entry_count_s;



#define NMATH_DATA2_F32_PA(T) const T&

#ifdef NCPP_ENABLE_SSE
#define NMATH_DATA3_F32_PA(T) const T
#define NMATH_DATA4_F32_PA(T) const T
#else
#define NMATH_DATA3_F32_PA(T) const T&
#define NMATH_DATA4_F32_PA(T) const T&
#endif



#define NMATH_DATA4_ARGS_STEP_A(I, Name) \
    using NCPP_EXPAND(NCPP_GLUE(F_, Name)) = nmath::TF_data_cast<NCPP_EXPAND(NCPP_GLUE(F_ta_, Name))>;\
    using NCPP_EXPAND(NCPP_GLUE(PA_, Name)) = nmath::TPA_data_cast<NCPP_EXPAND(NCPP_GLUE(F_ta_, Name))>;\
    using NCPP_EXPAND(NCPP_GLUE(F_entry_, Name)) = nmath::TF_entry_cast<NCPP_EXPAND(NCPP_GLUE(F_ta_, Name))>;\
    static constexpr ncpp::u32 NCPP_EXPAND(NCPP_GLUE(entry_count_, Name)) = nmath::T_entry_count_cast<NCPP_EXPAND(NCPP_GLUE(F_ta_, Name))>;
#define NMATH_DATA4_ARGS_STEP_F_ENTRY_F32(I, Name) std::is_same_v<NCPP_EXPAND(NCPP_GLUE(F_entry_, Name)), ncpp::f32> &&
#define NMATH_DATA4_ARGS_STEP_F_ENTRY_F64(I, Name) std::is_same_v<NCPP_EXPAND(NCPP_GLUE(F_entry_, Name)), ncpp::f64> &&
#define NMATH_DATA4_ARGS_STEP_F_ENTRY_U32(I, Name) std::is_same_v<NCPP_EXPAND(NCPP_GLUE(F_entry_, Name)), ncpp::u32> &&
#define NMATH_DATA4_ARGS_STEP_F_ENTRY_I32(I, Name) std::is_same_v<NCPP_EXPAND(NCPP_GLUE(F_entry_, Name)), ncpp::i32> &&
#define NMATH_DATA4_ARGS_STEP_F_ENTRY_U64(I, Name) std::is_same_v<NCPP_EXPAND(NCPP_GLUE(F_entry_, Name)), ncpp::u64> &&
#define NMATH_DATA4_ARGS_STEP_F_ENTRY_I64(I, Name) std::is_same_v<NCPP_EXPAND(NCPP_GLUE(F_entry_, Name)), ncpp::i64> &&
#define NMATH_DATA4_ARGS_STEP_ENTRY_COUNT(I, Name) static_assert((NCPP_EXPAND(NCPP_GLUE(entry_count_, Name)) == 4) && "Invalid entry count", #Name);
    
#define NMATH_DATA4_ARGS(...) \
    NCPP_EXPAND(NCPP_FOR_EACH(NMATH_DATA4_ARGS_STEP_A __VA_OPT__(,) __VA_ARGS__)) \
    static_assert(\
        (NCPP_EXPAND(NCPP_FOR_EACH(NMATH_DATA4_ARGS_STEP_F_ENTRY_F32 __VA_OPT__(,) __VA_ARGS__)) true)\
        || (NCPP_EXPAND(NCPP_FOR_EACH(NMATH_DATA4_ARGS_STEP_F_ENTRY_F64 __VA_OPT__(,) __VA_ARGS__)) true)\
        || (NCPP_EXPAND(NCPP_FOR_EACH(NMATH_DATA4_ARGS_STEP_F_ENTRY_U32 __VA_OPT__(,) __VA_ARGS__)) true)\
        || (NCPP_EXPAND(NCPP_FOR_EACH(NMATH_DATA4_ARGS_STEP_F_ENTRY_I32 __VA_OPT__(,) __VA_ARGS__)) true)\
        || (NCPP_EXPAND(NCPP_FOR_EACH(NMATH_DATA4_ARGS_STEP_F_ENTRY_U64 __VA_OPT__(,) __VA_ARGS__)) true)\
        || (NCPP_EXPAND(NCPP_FOR_EACH(NMATH_DATA4_ARGS_STEP_F_ENTRY_I64 __VA_OPT__(,) __VA_ARGS__)) true),\
        "entry type miss match"\
    ); \
    NCPP_EXPAND(NCPP_FOR_EACH(NMATH_DATA4_ARGS_STEP_ENTRY_COUNT __VA_OPT__(,) __VA_ARGS__));

}
