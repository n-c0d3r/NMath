#pragma once

/** @file nmath/operators/helper.hpp
*
*   Implement helper.
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


    
#define NMATH_DEFINE_SIMPLE_ADD_OPERATOR(Type) \
    inline Type operator + (typename Type::F_passed_argument a, typename Type::F_passed_argument b) noexcept \
    {\
        \
        return nmath::add(a, b);\
    }
#define NMATH_DEFINE_SIMPLE_SELF_ADD_OPERATOR(Type) \
    inline Type& operator += (Type& a, typename Type::F_passed_argument b) noexcept \
    {\
        \
        a = nmath::add(a, b);\
        \
        return a;\
    }   

#define NMATH_DEFINE_SIMPLE_SUBTRACT_OPERATOR(Type) \
    inline Type operator - (typename Type::F_passed_argument a, typename Type::F_passed_argument b) noexcept \
    {\
        \
        return nmath::subtract(a, b);\
    }
#define NMATH_DEFINE_SIMPLE_SELF_SUBTRACT_OPERATOR(Type) \
    inline Type& operator -= (Type& a, typename Type::F_passed_argument b) noexcept \
    {\
        \
        a = nmath::subtract(a, b);\
        \
        return a;\
    }

#define NMATH_DEFINE_SIMPLE_MULTIPLY_OPERATOR(Type) \
    inline Type operator * (typename Type::F_passed_argument a, typename Type::F_passed_argument b) noexcept \
    {\
        \
        return nmath::multiply(a, b);\
    }
#define NMATH_DEFINE_SIMPLE_SELF_MULTIPLY_OPERATOR(Type) \
    inline Type& operator *= (Type& a, typename Type::F_passed_argument b) noexcept \
    {\
        \
        a = nmath::multiply(a, b);\
        \
        return a;\
    }   

#define NMATH_DEFINE_SIMPLE_DIVIDE_OPERATOR(Type) \
    inline Type operator / (typename Type::F_passed_argument a, typename Type::F_passed_argument b) noexcept \
    {\
        \
        return nmath::divide(a, b);\
    }
#define NMATH_DEFINE_SIMPLE_SELF_DIVIDE_OPERATOR(Type) \
    inline Type& operator /= (Type& a, typename Type::F_passed_argument b) noexcept \
    {\
        \
        a = nmath::divide(a, b);\
        \
        return a;\
    }

#define NMATH_DEFINE_SIMPLE_PLUS_OPERATOR(Type) \
    inline typename Type::F_passed_argument operator + (typename Type::F_passed_argument a) noexcept \
    {\
        \
        return a;\
    }
#define NMATH_DEFINE_SIMPLE_MINUS_OPERATOR(Type) \
    inline typename Type::F_passed_argument operator - (typename Type::F_passed_argument a) noexcept \
    {\
        \
        return nmath::minus(a);\
    }

#define NMATH_DEFINE_SIMPLE_OPERATORS(Type) \
    NMATH_DEFINE_SIMPLE_PLUS_OPERATOR(Type);\
    NMATH_DEFINE_SIMPLE_MINUS_OPERATOR(Type);\
    NMATH_DEFINE_SIMPLE_ADD_OPERATOR(Type);\
    NMATH_DEFINE_SIMPLE_SELF_ADD_OPERATOR(Type);\
    NMATH_DEFINE_SIMPLE_SUBTRACT_OPERATOR(Type);\
    NMATH_DEFINE_SIMPLE_SELF_SUBTRACT_OPERATOR(Type);\
    NMATH_DEFINE_SIMPLE_MULTIPLY_OPERATOR(Type);\
    NMATH_DEFINE_SIMPLE_SELF_MULTIPLY_OPERATOR(Type);\
    NMATH_DEFINE_SIMPLE_DIVIDE_OPERATOR(Type);\
    NMATH_DEFINE_SIMPLE_SELF_DIVIDE_OPERATOR(Type);