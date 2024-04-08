#pragma once

/** @file nmath/types/range.hpp
*
*   Implement range.
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

#include <nmath/types/vector.hpp>
#include <nmath/operators/vector_vector.hpp>
#include <nmath/operators/vector_scalar.hpp>
#include <nmath/functions/element_min_max.hpp>
#include <nmath/functions/element_abs.hpp>
#include <nmath/functions/element_if_equal.hpp>
#include <nmath/functions/element_if_not_equal.hpp>

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

    namespace internal {

        template<typename F_value__>
        concept T_is_has_passed_arg_type = requires {

            typename F_value__::F_passed_argument;

        };

        template<typename F_value__, b8 is_has_passed_arg_type__>
        struct TF_range_value_passed_arg_type_helper;

        template<typename F_value__>
        struct TF_range_value_passed_arg_type_helper<F_value__, true> {

            using F = typename F_value__::F_passed_argument;

        };

        template<typename F_value__>
        struct TF_range_value_passed_arg_type_helper<F_value__, false> {

            using F = F_value__;

        };

    }



    template<typename F_value__ = NMATH_DEFAULT_FP_TYPE>
    class TF_range {

    public:
        using F_value = F_value__;
        using PA_value = internal::TF_range_value_passed_arg_type_helper<
            F_value,
            internal::T_is_has_passed_arg_type<F_value>
        >::F;



    private:
        F_value min_;
        F_value max_;

    public:
        NCPP_FORCE_INLINE b8 is_valid() const noexcept { return (min_ <= max_); }
        NCPP_FORCE_INLINE F_value min() const noexcept { return min_; }
        NCPP_FORCE_INLINE F_value max() const noexcept { return max_; }
        NCPP_FORCE_INLINE F_value center() const noexcept { return (min_ + max_) * 0.5; }
        NCPP_FORCE_INLINE F_value half_size() const noexcept { return (max_ - min_) * 0.5; }



    public:
        NCPP_FORCE_INLINE TF_range() noexcept = default;
        NCPP_FORCE_INLINE TF_range(PA_value min, PA_value max) noexcept :
            min_(min),
            max_(max)
        {}
        NCPP_FORCE_INLINE TF_range(const TF_range& x) noexcept :
            min_(x.min_),
            max_(x.max_)
        {}
        NCPP_FORCE_INLINE TF_range& operator = (const TF_range& x) noexcept {

            min_ = x.min_;
            max_ = x.max_;

            return *this;
        }



    public:
        NCPP_FORCE_INLINE f32 NMATH_CALL_CNV distance(PA_value v) const noexcept {

            F_value min_delta = min_ - v;
            F_value max_delta = v - max_;

            F_value min_delta_abs = element_abs(min_delta);
            F_value max_delta_abs = element_abs(max_delta);

            F_value choosed_delta_abs = element_min(min_delta_abs, max_delta_abs);

            F_value result = element_if_equal(choosed_delta_abs, min_delta_abs, min_delta);

            return element_if_equal(result, max_delta_abs, max_delta);
        }
        NCPP_FORCE_INLINE b8 NMATH_CALL_CNV is_contains(PA_value v) const noexcept {

            return (
                (v >= min_)
                && (v <= max_)
            );
        }
        NCPP_FORCE_INLINE TF_range NMATH_CALL_CNV expand(PA_value v) noexcept {

            return {
                element_min(v, min_),
                element_max(v, max_)
            };
        }

    };



    using F_range = TF_range<>;

    using F_vector2_range = TF_range<F_vector2>;
    using F_vector3_range = TF_range<F_vector3>;
    using F_vector4_range = TF_range<F_vector4>;

    using F_vector2_range_f32 = TF_range<F_vector2_f32>;
    using F_vector3_range_f32 = TF_range<F_vector3_f32>;
    using F_vector4_range_f32 = TF_range<F_vector4_f32>;

}
