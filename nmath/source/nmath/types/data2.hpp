#pragma once

/** @file nmath/types/data2.hpp
*
*   Implement data2.
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



namespace nmath {

    NMATH_USING_NLIB_NAMESPACES();



    template<typename F_entry__ = NMATH_DEFAULT_FP_TYPE, typename F_flag__ = void>
    struct TF_data2;

    template<typename F_entry__ = NMATH_DEFAULT_FP_TYPE, typename F_flag__ = void>
    using TPA_data2 = typename TF_data2<F_entry__, F_flag__>::F_passed_argument;



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    using F_data2_f32 = TF_data2<f32>;
    using F_data2_i32 = TF_data2<i32>;
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
    struct TF_data2<f32, F_flag__> {

        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = f32;
        using F_flag = F_flag__;
        using F_this = TF_data2<F_entry, F_flag__>;

        static constexpr u32 entry_count_s = 2;

        using F_passed_argument = const F_this&;
        
        

        ////////////////////////////////////////////////////////////////////////////////////
        //  Arguments
        ////////////////////////////////////////////////////////////////////////////////////
        union {

            struct {

                F_entry x;
                F_entry y;

            };

            F_entry m[2];

        };



        ////////////////////////////////////////////////////////////////////////////////////
        //  Constructors
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data2() noexcept :
            x(0.0f),
            y(0.0f)
        {
            
            
            
        }
        NCPP_FORCE_INLINE TF_data2(F_entry x, F_entry y) noexcept :
            x(x),
            y(y)
        {
            
            
            
        }
        NCPP_FORCE_INLINE TF_data2(F_entry x) noexcept :
            x(x),
            y(0.0f)
        {



        }
        NCPP_FORCE_INLINE TF_data2(const TF_data2& o) noexcept :
            x(o.x),
            y(o.y)
        {
            
            
            
        }
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data2& operator = (F_passed_argument o) noexcept
        {
            
            x = o.x;
            y = o.y;

            return *this;
        }
        NCPP_FORCE_INLINE F_entry operator [] (i32 index) noexcept
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
        //  Functions
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE F_this xy() const {

            return {
                x,
                y
            };
        }
        NCPP_FORCE_INLINE F_this yx() const {

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



    template<typename F_flag__>
    struct TF_data2<i32, F_flag__> {

        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = i32;
        using F_flag = F_flag__;
        using F_this = TF_data2<F_entry, F_flag__>;

        static constexpr u32 entry_count_s = 2;

        using F_passed_argument = const F_this&;
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Arguments
        ////////////////////////////////////////////////////////////////////////////////////
        union {

            struct {

                F_entry x;
                F_entry y;

            };

            F_entry m[2];

        };



        ////////////////////////////////////////////////////////////////////////////////////
        //  Constructors
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data2() noexcept :
            x(0),
            y(0)
        {



        }
        NCPP_FORCE_INLINE TF_data2(F_entry x, F_entry y) noexcept :
            x(x),
            y(y)
        {



        }
        NCPP_FORCE_INLINE TF_data2(F_entry x) noexcept :
            x(x),
            y(0)
        {



        }
        NCPP_FORCE_INLINE TF_data2(const TF_data2& o) noexcept :
            x(o.x),
            y(o.y)
        {



        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data2& operator = (F_passed_argument o) noexcept
        {

            x = o.x;
            y = o.y;

            return *this;
        }
        NCPP_FORCE_INLINE F_entry operator [] (i32 index) noexcept
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
        //  Functions
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE F_this xy() const {

            return {
                x,
                y
            };
        }
        NCPP_FORCE_INLINE F_this yx() const {

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



    template<typename F_flag__>
    struct TF_data2<u32, F_flag__> {

        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = u32;
        using F_flag = F_flag__;
        using F_this = TF_data2<F_entry, F_flag__>;

        static constexpr u32 entry_count_s = 2;

        using F_passed_argument = const F_this&;
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Arguments
        ////////////////////////////////////////////////////////////////////////////////////
        union {

            struct {

                F_entry x;
                F_entry y;

            };

            F_entry m[2];

        };



        ////////////////////////////////////////////////////////////////////////////////////
        //  Constructors
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data2() noexcept :
            x(0),
            y(0)
        {



        }
        NCPP_FORCE_INLINE TF_data2(F_entry x, F_entry y) noexcept :
            x(x),
            y(y)
        {



        }
        NCPP_FORCE_INLINE TF_data2(F_entry x) noexcept :
            x(x),
            y(0)
        {



        }
        NCPP_FORCE_INLINE TF_data2(const TF_data2& o) noexcept :
            x(o.x),
            y(o.y)
        {



        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data2& operator = (F_passed_argument o) noexcept
        {

            x = o.x;
            y = o.y;

            return *this;
        }
        NCPP_FORCE_INLINE F_entry operator [] (i32 index) noexcept
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
        //  Functions
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE F_this xy() const {

            return {
                x,
                y
            };
        }
        NCPP_FORCE_INLINE F_this yx() const {

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



    using PA_data2_f32 = TPA_data2<f32>;
    using PA_data2_i32 = TPA_data2<i32>;
    using PA_data2_u32 = TPA_data2<u32>;

}
