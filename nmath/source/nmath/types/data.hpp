#pragma once

/** @file nmath/types/data.hpp
*
*   Implement data.
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
#include <nmath/types/data_constants.hpp>
#include <nmath/types/data_forward.hpp>
#include <nmath/types/data_default_flag.hpp>
#include <nmath/types/combine.hpp>

#include <nmath/types/data2.hpp>
#include <nmath/types/data3.hpp>
#include <nmath/types/data4.hpp>

#include <nmath/types/data2x2.hpp>

#include <nmath/types/data3x3.hpp>

#include <nmath/types/data4x4.hpp>

#pragma endregion



namespace nmath {

    namespace data_internal {

        template<typename F_value__>
        concept T_is_has_passed_arg_type = requires {

            typename F_value__::F_passed_argument;

        };

        template<typename F_value__, b8 is_has_passed_arg_type__>
        struct TF_passed_arg_type_helper;

        template<typename F_value__>
        struct TF_passed_arg_type_helper<F_value__, true> {

            using F = typename F_value__::F_passed_argument;

        };

        template<typename F_value__>
        struct TF_passed_arg_type_helper<F_value__, false> {

            using F = F_value__;

        };

    }

    template<typename F_value__>
    using TF_passed_argument = typename data_internal::TF_passed_arg_type_helper<
        F_value__,
        data_internal::T_is_has_passed_arg_type<F_value__>
    >;

    template<typename F_value__>
    using TPA = TF_passed_argument<F_value_>;

}