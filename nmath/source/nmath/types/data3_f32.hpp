
#pragma once

/** @file nmath/types/data3_f32.hpp
*
*   Implement data3_f32.
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

#include <nmath/types/data3_template.hpp>

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
    


    using F_data3_f32 = TF_data3<f32>;



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#ifdef NCPP_ENABLE_SSE
#define NMATH_DATA3_SIMD_M128() \
    __m128 xyz_;
#define NMATH_DATA3_SIMD_CONSTRUCTOR_M128()\
    NCPP_FORCE_INLINE TF_data3(__m128 xyz) : \
        xyz_(xyz)\
    {}
#else
#define NMATH_DATA3_SIMD_M128() ;
#define NMATH_DATA3_SIMD_CONSTRUCTOR_M128() ;
#endif

#ifdef NCPP_ENABLE_SSE2
#define NMATH_DATA3_SIMD_M128I() \
    __m128i xyz_;
#define NMATH_DATA3_SIMD_CONSTRUCTOR_M128I()\
    NCPP_FORCE_INLINE TF_data3(__m128i xyz) : \
        xyz_(xyz)\
    {}
#else
#define NMATH_DATA3_SIMD_M128I() ;
#define NMATH_DATA3_SIMD_CONSTRUCTOR_M128I() ;
#endif



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
    struct NCPP_ALIGN(16) TF_data3<f32, F_flag__> {

        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = f32;

        using F_flag = F_flag__;

        using F_this = TF_data3<F_entry, F_flag__>;

        using F_data2 = TF_data2<F_entry, F_flag__>;
        using PA_data2 = TPA_data2<F_entry, F_flag__>;

        static constexpr u32 entry_count_s = 3;

#ifdef NCPP_ENABLE_SSE
        using F_passed_argument = const F_this;
#else
        using F_passed_argument = const F_this&;
#endif
        
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data3, nmath::F_data3_f32_flag);
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data3, F_flag__);
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Arguments
        ////////////////////////////////////////////////////////////////////////////////////
        union {
            
            struct {
                
                F_entry x;
                F_entry y;
                F_entry z;
                
            };

            F_entry m[3];
            
            NMATH_DATA3_SIMD_M128();
            
        };

        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Constructors
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data3() noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(simd_f32x4_0000)
#else
            x(0.0f),
            y(0.0f),
            z(0.0f)
#endif
        {
            
            
            
        }
        NCPP_FORCE_INLINE TF_data3(F_entry x, F_entry y, F_entry z) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(_mm_set_ps(0.0f, z, y, x))
#else
            x(x),
            y(y),
            z(z)
#endif
        {
            
            
            
        }
        NCPP_FORCE_INLINE TF_data3(PA_data2 xy, F_entry z) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(_mm_set_ps(0.0f, z, xy.y, xy.x))
#else
            x(xy.x),
            y(xy.y),
            z(z)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data3(F_entry x, PA_data2 yz) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(_mm_set_ps(0.0f, yz.y, yz.x, x))
#else
            x(x),
            y(yz.x),
            z(yz.y)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data3(PA_data2 xy) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(_mm_set_ps(0.0f, 0.0f, xy.y, xy.x))
#else
            x(xy.x),
            y(xy.y),
            z(0.0f)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data3(const TF_data3& o) noexcept :
#ifdef NCPP_ENABLE_SSE
            xyz_(o.xyz_)
#else
            x(o.x),
            y(o.y),
            z(o.z)
#endif
        {



        }

        NMATH_DATA3_SIMD_CONSTRUCTOR_M128();
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data3& NCPP_VECTOR_CALL operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            xyz_ = o.xyz_;
#else
            x = o.x;
            y = o.y;
            z = o.z;
#endif

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
        friend NCPP_FORCE_INLINE ncpp::b8 NCPP_VECTOR_CALL operator == (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            __m128 compare3 = _mm_cmpeq_ps(a.xyz_, b.xyz_);
            int mask = _mm_movemask_ps(compare3);

            return ((mask & 0b0111) == 0b0111);
#else
            return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
#endif
        }
        friend NCPP_FORCE_INLINE ncpp::b8 NCPP_VECTOR_CALL operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_SSE
            __m128 compare3 = _mm_cmpeq_ps(a.xyz_, b.xyz_);
            int mask = _mm_movemask_ps(compare3);

            return ((mask & 0b0111) != 0b0111);
#else
            return (a.x != b.x) || (a.y != b.y) || (a.z != b.z);
#endif
        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Functions
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE F_data2 xy() const {

            return {            
                x,
                y
            };
        }
        NCPP_FORCE_INLINE F_data2 yx() const {

            return {
                y,
                x
            };
        }
        NCPP_FORCE_INLINE F_data2 xz() const {

            return {
                x,
                z
            };
        }
        NCPP_FORCE_INLINE F_data2 zx() const {

            return {
                z,
                x
            };
        }
        NCPP_FORCE_INLINE F_data2 yz() const {

            return {
                y,
                z
            };
        }
        NCPP_FORCE_INLINE F_data2 zy() const {

            return {
                z,
                y
            };
        }

        NCPP_FORCE_INLINE TF_data3<F_entry> data() const {

#ifdef NCPP_ENABLE_SSE
            return xyz_;
#else
            return {
                x,
                y,
                z
            };
#endif
        }
        template<typename F_another_data__>
        NCPP_FORCE_INLINE TF_data_cast<F_another_data__> T_data() const {

#ifdef NCPP_ENABLE_SSE
            return xyz_;
#else
            return {
                x,
                y,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xyz() const {

#ifdef NCPP_ENABLE_SSE
            return xyz_;
#else
            return {
                x,
                y,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xzy() const {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyz_, _MM_SHUFFLE(3, 1, 2, 0));
#else
            return {
                x,
                z,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yxz() const {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyz_, _MM_SHUFFLE(3, 2, 0, 1));
#else
            return {
                y,
                x,
                z
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yzx() const {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyz_, _MM_SHUFFLE(3, 0, 2, 1));
#else
            return {
                y,
                z,
                x
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zxy() const {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyz_, _MM_SHUFFLE(3, 1, 0, 2));
#else
            return {
                z,
                x,
                y
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zyx() const {

#ifdef NCPP_ENABLE_SSE
            return _mm_permute_ps(xyz_, _MM_SHUFFLE(3, 0, 1, 2));
#else
            return {
                z,
                y,
                x
            };
#endif
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



    using PA_data3_f32 = TPA_data3<f32>;

    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    NMATH_DEFINE_DATA3_F32_FORWARD(F_data3_f32)

}
