#pragma once

/** @file nmath/types/data2_u32.hpp
*
*   Implement data2_u32.
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

#include <nmath/types/data2_template.hpp>

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



    using F_data2_u32 = TF_data2<u32>;



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    template<typename F_flag__>
    struct NCPP_ALIGN(sizeof(u32) * 2) TF_data2<u32, F_flag__> {

        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = u32;

        using F_flag = F_flag__;

        using F_this = TF_data2<F_entry, F_flag__>;

        static constexpr u32 entry_count_s = 2;

        using F_passed_argument = const F_this&;

		template<typename F_entry__>
		using TF_bind_entry = TF_data2<F_entry__, F_flag__>;

		NCPP_RTTI_IMPLEMENT_FLAG(nmath::F_data2_u32_flag);
		NCPP_RTTI_IMPLEMENT_FLAG(F_flag__);



        ////////////////////////////////////////////////////////////////////////////////////
        //  Arguments
        ////////////////////////////////////////////////////////////////////////////////////
        union {

            struct {

                F_entry x;
                F_entry y;

            };
            struct {

                F_entry width;
                F_entry height;

            };

            F_entry m[2];

        };



        ////////////////////////////////////////////////////////////////////////////////////
        //  Constructors
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data2() noexcept = default;
        NCPP_FORCE_INLINE TF_data2(F_entry x, F_entry y) noexcept :
            x(x),
            y(y)
        {}
        NCPP_FORCE_INLINE TF_data2(const TF_data2& o) noexcept :
            x(o.x),
            y(o.y)
        {}
		TF_data2(const TF_data2<i32, F_flag>& o) noexcept;
		TF_data2(const TF_data2<f32, F_flag>& o) noexcept;



        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data2& operator = (F_passed_argument o) noexcept
        {

            x = o.x;
            y = o.y;

            return *this;
        }
		TF_data2& operator = (const TF_data2<i32, F_flag>& o) noexcept;
		TF_data2& operator = (const TF_data2<f32, F_flag>& o) noexcept;
        NCPP_FORCE_INLINE const F_entry operator [] (u32 index) const noexcept
        {

            return m[index];
        }
        NCPP_FORCE_INLINE F_entry& operator [] (u32 index) noexcept
        {

            return m[index];
        }
        friend NCPP_FORCE_INLINE ncpp::b8 operator == (F_passed_argument a, F_passed_argument b) noexcept
        {

            return a.x == b.x && a.y == b.y;
        }
        friend NCPP_FORCE_INLINE ncpp::b8 operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

            return a.x != b.x || a.y != b.y;
        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Special values
        ////////////////////////////////////////////////////////////////////////////////////
        static NCPP_FORCE_INLINE F_this zero() noexcept {

            return {
                0,
                0
            };
        }
        static NCPP_FORCE_INLINE F_this one() noexcept {

            return {
                1,
                1
            };
        }
        static NCPP_FORCE_INLINE F_this right() noexcept {

            return {
                1,
                0
            };
        }
        static NCPP_FORCE_INLINE F_this up() noexcept {

            return {
                0,
                1
            };
        }
        static NCPP_FORCE_INLINE F_this left() noexcept {

            return {
                -1,
                0
            };
        }
        static NCPP_FORCE_INLINE F_this down() noexcept {

            return {
                0,
                -1
            };
        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Functions
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data2<F_entry> data() const noexcept {

            return {
                x,
                y
            };
        }
        template<typename F_another_data__>
        NCPP_FORCE_INLINE TF_data_cast<F_another_data__> T_data() const noexcept {

            return {
                x,
                y
            };
        }
        NCPP_FORCE_INLINE F_this xy() const noexcept {

            return {
                x,
                y
            };
        }
        NCPP_FORCE_INLINE F_this yx() const noexcept {

            return {
                y,
                x
            };
        }

    };



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    using PA_data2_u32 = TPA_data2<u32>;

    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    NMATH_DEFINE_DATA2_U32_FORWARD(F_data2_u32);

}
