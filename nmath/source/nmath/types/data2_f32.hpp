#pragma once

/** @file nmath/types/data2_f32.hpp
*
*   Implement data2_f32.
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



    using F_data2_f32 = TF_data2<f32>;



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
        
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data2, nmath::F_data2_f32_flag);
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data2, F_flag__);
        
        

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
        NCPP_FORCE_INLINE const F_entry operator [] (i32 index) const noexcept
        {

            return m[index];
        }
        NCPP_FORCE_INLINE F_entry& operator [] (i32 index) noexcept
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



    using PA_data2_f32 = TPA_data2<f32>;

    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    NMATH_DEFINE_DATA2_F32_FORWARD(F_data2_f32);

}