

#pragma once

/** @file nmath/types/data3x4.hpp
*
*   Implement data3x4.
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
#include <nmath/types/data2x4.hpp>
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
    struct TF_data3x4;

    template<typename F_entry__ = NMATH_DEFAULT_FP_TYPE, typename F_flag__ = F_data_default_flag>
    using TPA_data3x4 = typename TF_data3x4<F_entry__, F_flag__>::F_passed_argument;

    NCPP_RTTI_CREATE_FLAG(F_data3x4_f32_flag);
    NCPP_RTTI_CREATE_FLAG(F_data3x4_i32_flag);
    NCPP_RTTI_CREATE_FLAG(F_data3x4_u32_flag);

    NCPP_RTTI_CREATE_FLAG(F_data3x4_f64_flag);
    NCPP_RTTI_CREATE_FLAG(F_data3x4_i64_flag);
    NCPP_RTTI_CREATE_FLAG(F_data3x4_u64_flag);



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    using F_data3x4_f32 = TF_data3x4<f32>;



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
#define NMATH_DATA3X4_SIMD_M256X2() \
    struct {\
        __m256 ab_;\
        __m256 c_;\
    };
#define NMATH_DATA3X4_SIMD_CONSTRUCTOR_M256X2() \
    NCPP_FORCE_INLINE TF_data3x4(__m256 ab, __m256 c) : \
        ab_(ab),\
        c_(c)\
    {}
#else
#define NMATH_DATA3X4_SIMD_M256X2() ;
#define NMATH_DATA3X4_SIMD_CONSTRUCTOR_M256X2() ;
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
    struct NCPP_ALIGN(64) TF_data3x4<f32, F_flag__> {
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = f32;

        using F_pack = TF_data4<F_entry, F_flag__>;
        using PA_pack = TPA_data4<F_entry, F_flag__>;

        using F_data2x4 = TF_data2x4<F_entry, F_flag__>;
        using PA_data2x4 = TPA_data2x4<F_entry, F_flag__>;

        using F_flag = F_flag__;

        using F_this = TF_data3x4<F_entry, F_flag__>;

        static constexpr u32 entry_count_s = 12;
        static constexpr u32 pack_count_s = 3;

        // at least the lowest SIMD level is enabled, use pass-by-value
#if defined(NCPP_ENABLE_SSE)
        using F_passed_argument = const F_this;
#else
        using F_passed_argument = const F_this&;
#endif
        
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data3x4, nmath::F_data3x4_f32_flag);
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data3x4, F_flag__);
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Arguments
        ////////////////////////////////////////////////////////////////////////////////////
        union {
            
            struct {
                
                F_pack a;
                F_pack b;
                F_pack c;
                
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

                F_entry cx;
                F_entry cy;
                F_entry cz;
                F_entry cw;

            };

            F_pack m[3];
            
            NMATH_DATA3X4_SIMD_M256X2();
            
        };
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Basic constructors
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data3x4() noexcept :
#ifdef NCPP_ENABLE_AVX
            ab_(simd_f32x8_00000000),
            c_(simd_f32x8_00000000)
#else
            a(),
            b(),
            c()
#endif
        {
            
            
            
        }
        NCPP_FORCE_INLINE TF_data3x4(F_pack a, F_pack b, F_pack c, F_pack d) noexcept :
#ifdef NCPP_ENABLE_AVX
            ab_(_mm256_set_m128(b.xyzw_, a.xyzw_)),
            c_(_mm256_set_m128(simd_f32x4_0000, c.xyzw_))
#else
            a(a),
            b(b),
            c(c)
#endif
        {
            
            
            
        }
        NCPP_FORCE_INLINE TF_data3x4(PA_data2x4 ab, F_pack c) noexcept :
#ifdef NCPP_ENABLE_AVX
            ab_(ab.ab_),
            c_(_mm256_set_m128(simd_f32x4_0000, c.xyzw_))
#else
            a(ab.a),
            b(ab.b),
            c(c)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data3x4(F_pack a, PA_data2x4 bc) noexcept :
#ifdef NCPP_ENABLE_AVX
            ab_(_mm256_set_m128(a.xyzw_, bc.a.xyzw_)),
            c_(_mm256_set_m128(simd_f32x4_0000, bc.b.xyzw_))
#else
            a(ab.a),
            b(ab.b),
            c(c)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data3x4(const TF_data3x4& o) noexcept :
#ifdef NCPP_ENABLE_AVX
            ab_(o.ab_),
            c_(o.c_)
#else
            a(o.a),
            b(o.b),
            c(o.c)
#endif
        {
            
            
            
        }

        NMATH_DATA3X4_SIMD_CONSTRUCTOR_M256X2();
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data3x4& NCPP_VECTOR_CALL operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_AVX
            ab_ = o.ab_;
            c_ = o.c_;
#else
            a = o.a;
            b = o.b;
            c = o.c;
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

            __m256 c_compare8 = _mm256_cmp_ps(a.c_, b.c_, _CMP_EQ_OQ);
            int c_mask = _mm256_movemask_ps(c_compare8);

            return ((ab_mask & (c_mask | 0b11110000)) == 0b11111111);
#else
            return (a.a == b.a) && (a.b == b.b) && (a.c == b.c);
#endif
        }
        friend NCPP_FORCE_INLINE ncpp::b8 NCPP_VECTOR_CALL operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_AVX
            __m256 ab_compare8 = _mm256_cmp_ps(a.ab_, b.ab_, _CMP_EQ_OQ);
            int ab_mask = _mm256_movemask_ps(ab_compare8);

            __m256 c_compare8 = _mm256_cmp_ps(a.c_, b.c_, _CMP_EQ_OQ);
            int c_mask = _mm256_movemask_ps(c_compare8);

            return ((ab_mask & (c_mask | 0b11110000)) != 0b11111111);
#else
            return (a.a != b.a) || (a.b != b.b) || (a.c != b.c);
#endif
        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Functions
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE F_data2x4 ab() const {

#ifdef NCPP_ENABLE_AVX
            return ab_;
#else
            return {
                a,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x4 ba() const {

#ifdef NCPP_ENABLE_AVX
            return _mm256_permute2f128_ps(ab_, ab_, 0x1);
#else
            return {
                b,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x4 ac() const {

#ifdef NCPP_ENABLE_AVX
            return _mm256_permute2f128_ps(ab_, c_, 0x20);
#else
            return {
                a,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x4 ca() const {

#ifdef NCPP_ENABLE_AVX
            return _mm256_permute2f128_ps(ab_, c_, 0x02);
#else
            return {
                a,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x4 bc() const {

#ifdef NCPP_ENABLE_AVX
            return _mm256_permute2f128_ps(ab_, c_, 0x21);
#else
            return {
                a,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x4 cb() const {

#ifdef NCPP_ENABLE_AVX
            return _mm256_permute2f128_ps(ab_, c_, 0x21);
#else
            return {
                a,
                c
            };
#endif
        }

        NCPP_FORCE_INLINE TF_data3x4<F_entry> NCPP_VECTOR_CALL data3x4() const {

#ifdef NCPP_ENABLE_AVX
            return {
                ab_,
                c_
            };
#else
            return {
                a,
                b,
                c
            };
#endif
        }
        template<typename F_another_data3x4__>
        NCPP_FORCE_INLINE TF_data_cast<F_another_data3x4__> T_data3x4() const {

#ifdef NCPP_ENABLE_AVX
            return {
                ab_,
                c_
            };
#else
            return {
                a,
                b,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_this abc() const {

#ifdef NCPP_ENABLE_AVX
            return {
                ab_,
                c_
            };
#else
            return {
                a,
                b,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_this acb() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, c_, 0x20),
                _mm256_permute2f128_ps(ab_, ab_, 0x01)
            };
#else
            return {
                a,
                c,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_this bac() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, ab_, 0x01),
                c_
            };
#else
            return {
                b,
                a,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_this bca() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, c_, 0x21),
                ab_
            };
#else
            return {
                b,
                c,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_this cab() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, c_, 0x02),
                _mm256_permute2f128_ps(ab_, ab_, 0x01)
            };
#else
            return {
                c,
                a,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_this cba() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, c_, 0x12),
                ab_
            };
#else
            return {
                c,
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



    using PA_data3x4_f32 = TPA_data3x4<f32>;

}
