#pragma once

/** @file nmath/operators/vector_vector.hpp
*
*   Implement operators between vector and vector.
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

#include <nmath/types/data_forward.hpp>
#include <nmath/types/vector.hpp>
#include <nmath/functions/data_functions.hpp>
#include <nmath/operators/helper.hpp>

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
//  nmath::F_vector2_f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {
    
    NCPP_FORCE_INLINE F_vector2_f32 minus(PA_vector2_f32 a) noexcept
    {
        return vecma_forward(
            data2_minus(data_forward(a))
        );
    }
    NCPP_FORCE_INLINE F_vector2_f32 add(PA_vector2_f32 a, PA_vector2_f32 b) noexcept
    {
        return vecma_forward(
            data2_add(data_forward(a), data_forward(b))
        );
    }
    NCPP_FORCE_INLINE F_vector2_f32 subtract(PA_vector2_f32 a, PA_vector2_f32 b) noexcept
    {
        return vecma_forward(
            data2_subtract(data_forward(a), data_forward(b))
        );
    }

    NCPP_FORCE_INLINE F_vector2_f32 multiply(PA_vector2_f32 a, PA_vector2_f32 b) noexcept
    {
        return vecma_forward(
            data2_multiply(data_forward(a), data_forward(b))
        );
    }
    NCPP_FORCE_INLINE F_vector2_f32 divide(PA_vector2_f32 a, PA_vector2_f32 b) noexcept
    {
        return vecma_forward(
            data2_divide(data_forward(a), data_forward(b))
        );
    }

    NCPP_FORCE_INLINE b8 is_greater(PA_vector2_f32 a, PA_vector2_f32 b) noexcept
    {
        return (
            (a.x > b.x)
            && (a.y > b.y)
        );
    }
    NCPP_FORCE_INLINE b8 is_greater_equal(PA_vector2_f32 a, PA_vector2_f32 b) noexcept
    {
        return (
            (a.x >= b.x)
            && (a.y >= b.y)
        );
    }
    NCPP_FORCE_INLINE b8 is_less(PA_vector2_f32 a, PA_vector2_f32 b) noexcept
    {
        return (
            (a.x < b.x)
            && (a.y < b.y)
        );
    }
    NCPP_FORCE_INLINE b8 is_less_equal(PA_vector2_f32 a, PA_vector2_f32 b) noexcept
    {
        return (
            (a.x <= b.x)
            && (a.y <= b.y)
        );
    }

}

NMATH_DEFINE_PLUS_OPERATOR(nmath::PA_vector2_f32, nmath::F_vector2_f32);
NMATH_DEFINE_MINUS_OPERATOR(nmath::PA_vector2_f32, nmath::F_vector2_f32);

NMATH_DEFINE_ADD_OPERATOR(nmath::PA_vector2_f32, nmath::PA_vector2_f32, nmath::F_vector2_f32);
NMATH_DEFINE_SELF_ADD_OPERATOR(nmath::F_vector2_f32, nmath::PA_vector2_f32);

NMATH_DEFINE_SUBTRACT_OPERATOR(nmath::PA_vector2_f32, nmath::PA_vector2_f32, nmath::F_vector2_f32);
NMATH_DEFINE_SELF_SUBTRACT_OPERATOR(nmath::F_vector2_f32, nmath::PA_vector2_f32);

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_vector2_f32, nmath::PA_vector2_f32, nmath::F_vector2_f32);
NMATH_DEFINE_SELF_MULTIPLY_OPERATOR(nmath::F_vector2_f32, nmath::PA_vector2_f32);

NMATH_DEFINE_DIVIDE_OPERATOR(nmath::PA_vector2_f32, nmath::PA_vector2_f32, nmath::F_vector2_f32);
NMATH_DEFINE_SELF_DIVIDE_OPERATOR(nmath::F_vector2_f32, nmath::PA_vector2_f32);

NMATH_DEFINE_IS_GREATER_OPERATOR(nmath::PA_vector2_f32, nmath::PA_vector2_f32);
NMATH_DEFINE_IS_GREATER_EQUAL_OPERATOR(nmath::PA_vector2_f32, nmath::PA_vector2_f32);
NMATH_DEFINE_IS_LESS_OPERATOR(nmath::PA_vector2_f32, nmath::PA_vector2_f32);
NMATH_DEFINE_IS_LESS_EQUAL_OPERATOR(nmath::PA_vector2_f32, nmath::PA_vector2_f32);



////////////////////////////////////////////////////////////////////////////////////
//  nmath::F_vector2_i32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NCPP_FORCE_INLINE F_vector2_i32 minus(PA_vector2_i32 a) noexcept
    {
        return vecma_forward(
            data2_minus(data_forward(a))
        );
    }
    NCPP_FORCE_INLINE F_vector2_i32 add(PA_vector2_i32 a, PA_vector2_i32 b) noexcept
    {
        return vecma_forward(
            data2_add(data_forward(a), data_forward(b))
        );
    }
    NCPP_FORCE_INLINE F_vector2_i32 subtract(PA_vector2_i32 a, PA_vector2_i32 b) noexcept
    {
        return vecma_forward(
            data2_subtract(data_forward(a), data_forward(b))
        );
    }

    NCPP_FORCE_INLINE F_vector2_i32 multiply(PA_vector2_i32 a, PA_vector2_i32 b) noexcept
    {
        return vecma_forward(
            data2_multiply(data_forward(a), data_forward(b))
        );
    }
    NCPP_FORCE_INLINE F_vector2_i32 divide(PA_vector2_i32 a, PA_vector2_i32 b) noexcept
    {
        return vecma_forward(
            data2_divide(data_forward(a), data_forward(b))
        );
    }

    NCPP_FORCE_INLINE b8 is_greater(PA_vector2_i32 a, PA_vector2_i32 b) noexcept
    {
        return (
            (a.x > b.x)
            && (a.y > b.y)
        );
    }
    NCPP_FORCE_INLINE b8 is_greater_equal(PA_vector2_i32 a, PA_vector2_i32 b) noexcept
    {
        return (
            (a.x >= b.x)
            && (a.y >= b.y)
        );
    }
    NCPP_FORCE_INLINE b8 is_less(PA_vector2_i32 a, PA_vector2_i32 b) noexcept
    {
        return (
            (a.x < b.x)
            && (a.y < b.y)
        );
    }
    NCPP_FORCE_INLINE b8 is_less_equal(PA_vector2_i32 a, PA_vector2_i32 b) noexcept
    {
        return (
            (a.x <= b.x)
            && (a.y <= b.y)
        );
    }

}

NMATH_DEFINE_PLUS_OPERATOR(nmath::PA_vector2_i32, nmath::F_vector2_i32);
NMATH_DEFINE_MINUS_OPERATOR(nmath::PA_vector2_i32, nmath::F_vector2_i32);

NMATH_DEFINE_ADD_OPERATOR(nmath::PA_vector2_i32, nmath::PA_vector2_i32, nmath::F_vector2_i32);
NMATH_DEFINE_SELF_ADD_OPERATOR(nmath::F_vector2_i32, nmath::PA_vector2_i32);

NMATH_DEFINE_SUBTRACT_OPERATOR(nmath::PA_vector2_i32, nmath::PA_vector2_i32, nmath::F_vector2_i32);
NMATH_DEFINE_SELF_SUBTRACT_OPERATOR(nmath::F_vector2_i32, nmath::PA_vector2_i32);

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_vector2_i32, nmath::PA_vector2_i32, nmath::F_vector2_i32);
NMATH_DEFINE_SELF_MULTIPLY_OPERATOR(nmath::F_vector2_i32, nmath::PA_vector2_i32);

NMATH_DEFINE_DIVIDE_OPERATOR(nmath::PA_vector2_i32, nmath::PA_vector2_i32, nmath::F_vector2_i32);
NMATH_DEFINE_SELF_DIVIDE_OPERATOR(nmath::F_vector2_i32, nmath::PA_vector2_i32);

NMATH_DEFINE_IS_GREATER_OPERATOR(nmath::PA_vector2_i32, nmath::PA_vector2_i32);
NMATH_DEFINE_IS_GREATER_EQUAL_OPERATOR(nmath::PA_vector2_i32, nmath::PA_vector2_i32);
NMATH_DEFINE_IS_LESS_OPERATOR(nmath::PA_vector2_i32, nmath::PA_vector2_i32);
NMATH_DEFINE_IS_LESS_EQUAL_OPERATOR(nmath::PA_vector2_i32, nmath::PA_vector2_i32);



////////////////////////////////////////////////////////////////////////////////////
//  nmath::F_vector2_u32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NCPP_FORCE_INLINE F_vector2_u32 minus(PA_vector2_u32 a) noexcept
    {
        return vecma_forward(
            data2_minus(data_forward(a))
        );
    }
    NCPP_FORCE_INLINE F_vector2_u32 add(PA_vector2_u32 a, PA_vector2_u32 b) noexcept
    {
        return vecma_forward(
            data2_add(data_forward(a), data_forward(b))
        );
    }
    NCPP_FORCE_INLINE F_vector2_u32 subtract(PA_vector2_u32 a, PA_vector2_u32 b) noexcept
    {
        return vecma_forward(
            data2_subtract(data_forward(a), data_forward(b))
        );
    }

    NCPP_FORCE_INLINE F_vector2_u32 multiply(PA_vector2_u32 a, PA_vector2_u32 b) noexcept
    {
        return vecma_forward(
            data2_multiply(data_forward(a), data_forward(b))
        );
    }
    NCPP_FORCE_INLINE F_vector2_u32 divide(PA_vector2_u32 a, PA_vector2_u32 b) noexcept
    {
        return vecma_forward(
            data2_divide(data_forward(a), data_forward(b))
        );
    }

    NCPP_FORCE_INLINE b8 is_greater(PA_vector2_u32 a, PA_vector2_u32 b) noexcept
    {
        return (
            (a.x > b.x)
            && (a.y > b.y)
        );
    }
    NCPP_FORCE_INLINE b8 is_greater_equal(PA_vector2_u32 a, PA_vector2_u32 b) noexcept
    {
        return (
            (a.x >= b.x)
            && (a.y >= b.y)
        );
    }
    NCPP_FORCE_INLINE b8 is_less(PA_vector2_u32 a, PA_vector2_u32 b) noexcept
    {
        return (
            (a.x < b.x)
            && (a.y < b.y)
        );
    }
    NCPP_FORCE_INLINE b8 is_less_equal(PA_vector2_u32 a, PA_vector2_u32 b) noexcept
    {
        return (
            (a.x <= b.x)
            && (a.y <= b.y)
        );
    }

}

NMATH_DEFINE_PLUS_OPERATOR(nmath::PA_vector2_u32, nmath::F_vector2_u32);
NMATH_DEFINE_MINUS_OPERATOR(nmath::PA_vector2_u32, nmath::F_vector2_u32);

NMATH_DEFINE_ADD_OPERATOR(nmath::PA_vector2_u32, nmath::PA_vector2_u32, nmath::F_vector2_u32);
NMATH_DEFINE_SELF_ADD_OPERATOR(nmath::F_vector2_u32, nmath::PA_vector2_u32);

NMATH_DEFINE_SUBTRACT_OPERATOR(nmath::PA_vector2_u32, nmath::PA_vector2_u32, nmath::F_vector2_u32);
NMATH_DEFINE_SELF_SUBTRACT_OPERATOR(nmath::F_vector2_u32, nmath::PA_vector2_u32);

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_vector2_u32, nmath::PA_vector2_u32, nmath::F_vector2_u32);
NMATH_DEFINE_SELF_MULTIPLY_OPERATOR(nmath::F_vector2_u32, nmath::PA_vector2_u32);

NMATH_DEFINE_DIVIDE_OPERATOR(nmath::PA_vector2_u32, nmath::PA_vector2_u32, nmath::F_vector2_u32);
NMATH_DEFINE_SELF_DIVIDE_OPERATOR(nmath::F_vector2_u32, nmath::PA_vector2_u32);

NMATH_DEFINE_IS_GREATER_OPERATOR(nmath::PA_vector2_u32, nmath::PA_vector2_u32);
NMATH_DEFINE_IS_GREATER_EQUAL_OPERATOR(nmath::PA_vector2_u32, nmath::PA_vector2_u32);
NMATH_DEFINE_IS_LESS_OPERATOR(nmath::PA_vector2_u32, nmath::PA_vector2_u32);
NMATH_DEFINE_IS_LESS_EQUAL_OPERATOR(nmath::PA_vector2_u32, nmath::PA_vector2_u32);



////////////////////////////////////////////////////////////////////////////////////
//  nmath::F_vector3_f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NCPP_FORCE_INLINE F_vector3_f32 NMATH_CALL_CNV minus(PA_vector3_f32 a) noexcept
    {

        return vecma_forward(
            data3_minus(data_forward(a))
        );
    }
    NCPP_FORCE_INLINE F_vector3_f32 NMATH_CALL_CNV add(PA_vector3_f32 a, PA_vector3_f32 b) noexcept
    {

        return vecma_forward(
            data3_add(data_forward(a), data_forward(b))
        );
    }
    NCPP_FORCE_INLINE F_vector3_f32 NMATH_CALL_CNV subtract(PA_vector3_f32 a, PA_vector3_f32 b) noexcept
    {

        return vecma_forward(
            data3_subtract(data_forward(a), data_forward(b))
        );
    }

    NCPP_FORCE_INLINE F_vector3_f32 NMATH_CALL_CNV multiply(PA_vector3_f32 a, PA_vector3_f32 b) noexcept
    {

        return vecma_forward(
            data3_multiply(data_forward(a), data_forward(b))
        );
    }
    NCPP_FORCE_INLINE F_vector3_f32 NMATH_CALL_CNV divide(PA_vector3_f32 a, PA_vector3_f32 b) noexcept
    {

        return vecma_forward(
            data3_divide(data_forward(a), data_forward(b))
        );
    }

    NCPP_FORCE_INLINE b8 NMATH_CALL_CNV is_greater(PA_vector3_f32 a, PA_vector3_f32 b) noexcept
    {
        return (
            (a.x > b.x)
            && (a.y > b.y)
            && (a.z > b.z)
        );
    }
    NCPP_FORCE_INLINE b8 NMATH_CALL_CNV is_greater_equal(PA_vector3_f32 a, PA_vector3_f32 b) noexcept
    {
        return (
            (a.x >= b.x)
            && (a.y >= b.y)
            && (a.z >= b.z)
        );
    }
    NCPP_FORCE_INLINE b8 NMATH_CALL_CNV is_less(PA_vector3_f32 a, PA_vector3_f32 b) noexcept
    {
        return (
            (a.x < b.x)
            && (a.y < b.y)
            && (a.z < b.z)
        );
    }
    NCPP_FORCE_INLINE b8 NMATH_CALL_CNV is_less_equal(PA_vector3_f32 a, PA_vector3_f32 b) noexcept
    {
        return (
            (a.x <= b.x)
            && (a.y <= b.y)
            && (a.z <= b.z)
        );
    }

}

NMATH_DEFINE_PLUS_OPERATOR(nmath::PA_vector3_f32, nmath::F_vector3_f32);
NMATH_DEFINE_MINUS_OPERATOR(nmath::PA_vector3_f32, nmath::F_vector3_f32);

NMATH_DEFINE_ADD_OPERATOR(nmath::PA_vector3_f32, nmath::PA_vector3_f32, nmath::F_vector3_f32);
NMATH_DEFINE_SELF_ADD_OPERATOR(nmath::F_vector3_f32, nmath::PA_vector3_f32);

NMATH_DEFINE_SUBTRACT_OPERATOR(nmath::PA_vector3_f32, nmath::PA_vector3_f32, nmath::F_vector3_f32);
NMATH_DEFINE_SELF_SUBTRACT_OPERATOR(nmath::F_vector3_f32, nmath::PA_vector3_f32);

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_vector3_f32, nmath::PA_vector3_f32, nmath::F_vector3_f32);
NMATH_DEFINE_SELF_MULTIPLY_OPERATOR(nmath::F_vector3_f32, nmath::PA_vector3_f32);

NMATH_DEFINE_DIVIDE_OPERATOR(nmath::PA_vector3_f32, nmath::PA_vector3_f32, nmath::F_vector3_f32);
NMATH_DEFINE_SELF_DIVIDE_OPERATOR(nmath::F_vector3_f32, nmath::PA_vector3_f32);

NMATH_DEFINE_IS_GREATER_OPERATOR(nmath::PA_vector3_f32, nmath::PA_vector3_f32);
NMATH_DEFINE_IS_GREATER_EQUAL_OPERATOR(nmath::PA_vector3_f32, nmath::PA_vector3_f32);
NMATH_DEFINE_IS_LESS_OPERATOR(nmath::PA_vector3_f32, nmath::PA_vector3_f32);
NMATH_DEFINE_IS_LESS_EQUAL_OPERATOR(nmath::PA_vector3_f32, nmath::PA_vector3_f32);



////////////////////////////////////////////////////////////////////////////////////
//  nmath::F_vector4_f32
////////////////////////////////////////////////////////////////////////////////////
namespace nmath {

    NCPP_FORCE_INLINE F_vector4_f32 NMATH_CALL_CNV minus(PA_vector4_f32 a) noexcept
    {

        return vecma_forward(
            data4_minus(data_forward(a))
        );
    }
    NCPP_FORCE_INLINE F_vector4_f32 NMATH_CALL_CNV add(PA_vector4_f32 a, PA_vector4_f32 b) noexcept
    {

        return vecma_forward(
            data4_add(data_forward(a), data_forward(b))
        );
    }
    NCPP_FORCE_INLINE F_vector4_f32 NMATH_CALL_CNV subtract(PA_vector4_f32 a, PA_vector4_f32 b) noexcept
    {

        return vecma_forward(
            data4_subtract(data_forward(a), data_forward(b))
        );
    }

    NCPP_FORCE_INLINE F_vector4_f32 NMATH_CALL_CNV multiply(PA_vector4_f32 a, PA_vector4_f32 b) noexcept
    {

        return vecma_forward(
            data4_multiply(data_forward(a), data_forward(b))
        );
    }
    NCPP_FORCE_INLINE F_vector4_f32 NMATH_CALL_CNV divide(PA_vector4_f32 a, PA_vector4_f32 b) noexcept
    {

        return vecma_forward(
            data4_divide(data_forward(a), data_forward(b))
        );
    }

    NCPP_FORCE_INLINE b8 NMATH_CALL_CNV is_greater(PA_vector4_f32 a, PA_vector4_f32 b) noexcept
    {
        return (
            (a.x > b.x)
            && (a.y > b.y)
            && (a.z > b.z)
            && (a.w > b.w)
        );
    }
    NCPP_FORCE_INLINE b8 NMATH_CALL_CNV is_greater_equal(PA_vector4_f32 a, PA_vector4_f32 b) noexcept
    {
        return (
            (a.x >= b.x)
            && (a.y >= b.y)
            && (a.z >= b.z)
            && (a.w >= b.w)
        );
    }
    NCPP_FORCE_INLINE b8 NMATH_CALL_CNV is_less(PA_vector4_f32 a, PA_vector4_f32 b) noexcept
    {
        return (
            (a.x < b.x)
            && (a.y < b.y)
            && (a.z < b.z)
            && (a.w < b.w)
        );
    }
    NCPP_FORCE_INLINE b8 NMATH_CALL_CNV is_less_equal(PA_vector4_f32 a, PA_vector4_f32 b) noexcept
    {
        return (
            (a.x <= b.x)
            && (a.y <= b.y)
            && (a.z <= b.z)
            && (a.w <= b.w)
        );
    }

}

NMATH_DEFINE_PLUS_OPERATOR(nmath::PA_vector4_f32, nmath::F_vector4_f32);
NMATH_DEFINE_MINUS_OPERATOR(nmath::PA_vector4_f32, nmath::F_vector4_f32);

NMATH_DEFINE_ADD_OPERATOR(nmath::PA_vector4_f32, nmath::PA_vector4_f32, nmath::F_vector4_f32);
NMATH_DEFINE_SELF_ADD_OPERATOR(nmath::F_vector4_f32, nmath::PA_vector4_f32);

NMATH_DEFINE_SUBTRACT_OPERATOR(nmath::PA_vector4_f32, nmath::PA_vector4_f32, nmath::F_vector4_f32);
NMATH_DEFINE_SELF_SUBTRACT_OPERATOR(nmath::F_vector4_f32, nmath::PA_vector4_f32);

NMATH_DEFINE_MULTIPLY_OPERATOR(nmath::PA_vector4_f32, nmath::PA_vector4_f32, nmath::F_vector4_f32);
NMATH_DEFINE_SELF_MULTIPLY_OPERATOR(nmath::F_vector4_f32, nmath::PA_vector4_f32);

NMATH_DEFINE_DIVIDE_OPERATOR(nmath::PA_vector4_f32, nmath::PA_vector4_f32, nmath::F_vector4_f32);
NMATH_DEFINE_SELF_DIVIDE_OPERATOR(nmath::F_vector4_f32, nmath::PA_vector4_f32);

NMATH_DEFINE_IS_GREATER_OPERATOR(nmath::F_vector4_f32, nmath::F_vector4_f32);
NMATH_DEFINE_IS_GREATER_EQUAL_OPERATOR(nmath::F_vector4_f32, nmath::F_vector4_f32);
NMATH_DEFINE_IS_LESS_OPERATOR(nmath::F_vector4_f32, nmath::F_vector4_f32);
NMATH_DEFINE_IS_LESS_EQUAL_OPERATOR(nmath::F_vector4_f32, nmath::F_vector4_f32);