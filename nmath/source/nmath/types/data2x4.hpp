

#pragma once

/** @file nmath/types/data2x4.hpp
*
*   Implement data2x4.
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

#include <nmath/types/data4.hpp>
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
    struct TF_data2x4;

    template<typename F_entry__ = NMATH_DEFAULT_FP_TYPE, typename F_flag__ = F_data_default_flag>
    using TPA_data2x4 = typename TF_data2x4<F_entry__, F_flag__>::F_passed_argument;

    NCPP_RTTI_CREATE_FLAG(F_data2x4_f32_flag);
    NCPP_RTTI_CREATE_FLAG(F_data2x4_i32_flag);
    NCPP_RTTI_CREATE_FLAG(F_data2x4_u32_flag);

    NCPP_RTTI_CREATE_FLAG(F_data2x4_f64_flag);
    NCPP_RTTI_CREATE_FLAG(F_data2x4_i64_flag);
    NCPP_RTTI_CREATE_FLAG(F_data2x4_u64_flag);



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    using F_data2x4_f32 = TF_data2x4<f32>;



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#ifdef NCPP_ENABLE_AVX
#define NMATH_DATA2X4_SIMD_M256() \
    __m256 ab_;
#define NMATH_DATA2X4_SIMD_CONSTRUCTOR_M256() \
    NCPP_FORCE_INLINE TF_data2x4(__m256 ab) : \
        ab_(ab)\
    {}
#else
#define NMATH_DATA2X4_SIMD_M256() ;
#define NMATH_DATA2X4_SIMD_CONSTRUCTOR_M256() ;
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
    struct NCPP_ALIGN(32) TF_data2x4<f32, F_flag__> {
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = f32;

        using F_pack = TF_data4<F_entry, F_flag__>;
        using PA_pack = TPA_data4<F_entry, F_flag__>;

        using F_flag = F_flag__;

        using F_this = TF_data2x4<F_entry, F_flag__>;

        static constexpr u32 entry_count_s = 8;
        static constexpr u32 pack_count_s = 2;

        // at least the lowest SIMD level is enabled, use pass-by-value
#if defined(NCPP_ENABLE_SSE)
        using F_passed_argument = const F_this;
#else
        using F_passed_argument = const F_this&;
#endif
        
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data2x4, nmath::F_data2x4_f32_flag);
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data2x4, F_flag__);
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Arguments
        ////////////////////////////////////////////////////////////////////////////////////
        union {
            
            struct {
                
                F_pack a;
                F_pack b;
                
            };

            struct {

                F_entry ax;
                F_entry ay;
                F_entry az;
                F_entry aw;

                F_entry bx;
                F_entry by;
                F_entry bz;
                F_entry bw;

            };

            F_pack m[2];
            
            NMATH_DATA2X4_SIMD_M256();
            
        };
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Basic constructors
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data2x4() noexcept :
#ifdef NCPP_ENABLE_AVX
            ab_(simd_f32x8_00000000)
#else
            a(),
            b()
#endif
        {
            
            
            
        }
        NCPP_FORCE_INLINE TF_data2x4(PA_pack a, PA_pack b) noexcept :
#ifdef NCPP_ENABLE_AVX
            ab_(_mm256_set_m128(b.xyzw_, a.xyzw_))
#else
            a(a),
            b(b)
#endif
        {
            
            
            
        }
        NCPP_FORCE_INLINE TF_data2x4(const TF_data2x4& o) noexcept :
#ifdef NCPP_ENABLE_AVX
            ab_(o.ab_)
#else
            a(o.a),
            b(o.b)
#endif
        {
            
            
            
        }

        NMATH_DATA2X4_SIMD_CONSTRUCTOR_M256();
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data2x4& NCPP_VECTOR_CALL operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_AVX
            ab_ = o.ab_;
#else
            a = o.a;
            b = o.b;
#endif

            return *this;
        }
        NCPP_FORCE_INLINE PA_pack operator [] (i32 index) const noexcept
        {

            return m[index];
        }
        NCPP_FORCE_INLINE F_pack& operator [] (i32 index) noexcept
        {

            return m[index];
        }
        friend NCPP_FORCE_INLINE ncpp::b8 NCPP_VECTOR_CALL operator == (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_AVX
            __m256 ab_compare8 = _mm256_cmp_ps(a.ab_, b.ab_, _CMP_EQ_OQ);
            int ab_mask = _mm256_movemask_ps(ab_compare8);

            return (ab_mask == 0b11111111);
#else
            return (a.a == b.a) && (a.b == b.b);
#endif
        }
        friend NCPP_FORCE_INLINE ncpp::b8 NCPP_VECTOR_CALL operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_AVX
            __m256 ab_compare8 = _mm256_cmp_ps(a.ab_, b.ab_, _CMP_EQ_OQ);
            int ab_mask = _mm256_movemask_ps(ab_compare8);

            return (ab_mask != 0b11111111);
#else
            return (a.a != b.a) || (a.b != b.b);
#endif
        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Functions
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data2x4<F_entry> data() const {

#ifdef NCPP_ENABLE_AVX
            return ab_;
#else
            return {
                a.data(),
                b.data()
            };
#endif
        }
        template<typename F_another_data__>
        NCPP_FORCE_INLINE TF_data_cast<F_another_data__> T_data() const {

#ifdef NCPP_ENABLE_AVX
            return ab_;
#else
            return {
                a.T_data<TF_pack_cast<F_another_data__>>(),
                b.T_data<TF_pack_cast<F_another_data__>>()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this ab() const {

#ifdef NCPP_ENABLE_AVX
            return ab_;
#else
            return {
                a,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_this ba() const {

#ifdef NCPP_ENABLE_AVX
            return _mm256_permute2f128_ps(ab_, ab_, 1);
#else
            return {
                b,
                a
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



    using PA_data2x4_f32 = TPA_data2x4<f32>;

}
