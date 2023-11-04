

#pragma once

/** @file nmath/types/data4x4.hpp
*
*   Implement data4x4.
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
#include <nmath/types/data3x4.hpp>
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
    struct TF_data4x4;

    template<typename F_entry__ = NMATH_DEFAULT_FP_TYPE, typename F_flag__ = F_data_default_flag>
    using TPA_data4x4 = typename TF_data4x4<F_entry__, F_flag__>::F_passed_argument;

    NCPP_RTTI_CREATE_FLAG(F_data4x4_f32_flag);
    NCPP_RTTI_CREATE_FLAG(F_data4x4_i32_flag);
    NCPP_RTTI_CREATE_FLAG(F_data4x4_u32_flag);

    NCPP_RTTI_CREATE_FLAG(F_data4x4_f64_flag);
    NCPP_RTTI_CREATE_FLAG(F_data4x4_i64_flag);
    NCPP_RTTI_CREATE_FLAG(F_data4x4_u64_flag);



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    using F_data4x4_f32 = TF_data4x4<f32>;



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
#define NMATH_DATA4X4_SIMD_M256X2() \
    struct {\
        __m256 ab_;\
        __m256 cd_;\
    };
#define NMATH_DATA4X4_SIMD_CONSTRUCTOR_M256X2() \
    NCPP_FORCE_INLINE TF_data4x4(__m256 ab, __m256 cd) : \
        ab_(ab),\
        cd_(cd)\
    {}
#else
#define NMATH_DATA4X4_SIMD_M256X2() ;
#define NMATH_DATA4X4_SIMD_CONSTRUCTOR_M256X2() ;
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
    struct NCPP_ALIGN(64) TF_data4x4<f32, F_flag__> {
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = f32;

        using F_pack = TF_data4<F_entry, F_flag__>;
        using PA_pack = TPA_data4<F_entry, F_flag__>;

        using F_data2x4 = TF_data2x4<F_entry, F_flag__>;
        using PA_data2x4 = TPA_data2x4<F_entry, F_flag__>;

        using F_data3x4 = TF_data3x4<F_entry, F_flag__>;
        using PA_data3x4 = TPA_data3x4<F_entry, F_flag__>;

        using F_flag = F_flag__;

        using F_this = TF_data4x4<F_entry, F_flag__>;

        static constexpr u32 entry_count_s = 16;
        static constexpr u32 pack_count_s = 4;

        // at least the lowest SIMD level is enabled, use pass-by-value
#if defined(NCPP_ENABLE_SSE)
        using F_passed_argument = const F_this;
#else
        using F_passed_argument = const F_this&;
#endif
        
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data4x4, nmath::F_data4x4_f32_flag);
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data4x4, F_flag__);
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Arguments
        ////////////////////////////////////////////////////////////////////////////////////
        union {
            
            struct {
                
                F_pack a;
                F_pack b;
                F_pack c;
                F_pack d;
                
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

                F_entry dx;
                F_entry dy;
                F_entry dz;
                F_entry dw;

            };

            F_pack m[4];
            
            NMATH_DATA4X4_SIMD_M256X2();
            
        };
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Basic constructors
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data4x4() noexcept :
#ifdef NCPP_ENABLE_AVX
            ab_(simd_f32x8_00000000),
            cd_(simd_f32x8_00000000)
#else
            a(),
            b(),
            c(),
            d()
#endif
        {
            
            
            
        }
        NCPP_FORCE_INLINE TF_data4x4(F_pack a, F_pack b, F_pack c, F_pack d) noexcept :
#ifdef NCPP_ENABLE_AVX
            ab_(_mm256_set_m128(b.xyzw_, a.xyzw_)),
            cd_(_mm256_set_m128(d.xyzw_, c.xyzw_))
#else
            a(a),
            b(b),
            c(c),
            d(d)
#endif
        {
            
            
            
        }
        NCPP_FORCE_INLINE TF_data4x4(const TF_data4x4& o) noexcept :
#ifdef NCPP_ENABLE_AVX
            ab_(o.ab_),
            cd_(o.cd_)
#else
            a(o.a),
            b(o.b),
            c(o.c),
            d(o.d)
#endif
        {
            
            
            
        }

        NMATH_DATA4X4_SIMD_CONSTRUCTOR_M256X2();
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data4x4& NCPP_VECTOR_CALL operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_AVX
            ab_ = o.ab_;
            cd_ = o.cd_;
#else
            a = o.a;
            b = o.b;
            c = o.c;
            d = o.d;
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

            __m256 cd_compare8 = _mm256_cmp_ps(a.cd_, b.cd_, _CMP_EQ_OQ);
            int cd_mask = _mm256_movemask_ps(cd_compare8);

            return ((ab_mask & cd_mask) == 0b11111111);
#else
            return (a.a == b.a) && (a.b == b.b) && (a.c == b.c) && (a.d == b.d);
#endif
        }
        friend NCPP_FORCE_INLINE ncpp::b8 NCPP_VECTOR_CALL operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_AVX
            __m256 ab_compare8 = _mm256_cmp_ps(a.ab_, b.ab_, _CMP_EQ_OQ);
            int ab_mask = _mm256_movemask_ps(ab_compare8);

            __m256 cd_compare8 = _mm256_cmp_ps(a.cd_, b.cd_, _CMP_EQ_OQ);
            int cd_mask = _mm256_movemask_ps(cd_compare8);

            return ((ab_mask & cd_mask) != 0b11111111);
#else
            return (a.a != b.a) || (a.b != b.b) || (a.c != b.c) || (a.d != b.d);
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
        NCPP_FORCE_INLINE F_data2x4 ac() const {

#ifdef NCPP_ENABLE_AVX
            return _mm256_permute2f128_ps(ab_, cd_, 0x20);
#else
            return {
                a,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x4 ad() const {

#ifdef NCPP_ENABLE_AVX
            return _mm256_permute2f128_ps(ab_, cd_, 0x30);
#else
            return {
                a,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x4 ba() const {

#ifdef NCPP_ENABLE_AVX
            return _mm256_permute2f128_ps(ab_, ab_, 0x01);
#else
            return {
                b,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x4 bc() const {

#ifdef NCPP_ENABLE_AVX
            return _mm256_permute2f128_ps(ab_, cd_, 0x21);
#else
            return {
                b,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x4 bd() const {

#ifdef NCPP_ENABLE_AVX
            return _mm256_permute2f128_ps(ab_, cd_, 0x31);
#else
            return {
                b,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x4 ca() const {

#ifdef NCPP_ENABLE_AVX
            return _mm256_permute2f128_ps(ab_, cd_, 0x02);
#else
            return {
                c,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x4 cb() const {

#ifdef NCPP_ENABLE_AVX
            return _mm256_permute2f128_ps(ab_, cd_, 0x12);
#else
            return {
                c,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x4 cd() const {

#ifdef NCPP_ENABLE_AVX
            return cd_;
#else
            return {
                c,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x4 da() const {

#ifdef NCPP_ENABLE_AVX
            return _mm256_permute2f128_ps(ab_, cd_, 0x03);
#else
            return {
                d,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x4 db() const {

#ifdef NCPP_ENABLE_AVX
            return _mm256_permute2f128_ps(ab_, cd_, 0x13);
#else
            return {
                d,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x4 dc() const {

#ifdef NCPP_ENABLE_AVX
            return _mm256_permute2f128_ps(cd_, cd_, 0x01);
#else
            return {
                d,
                c
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3x4 abc() const {

#ifdef NCPP_ENABLE_AVX
            return {
                ab_,
                cd_
            };
#else
            return {
                a,
                b,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x4 abd() const {

#ifdef NCPP_ENABLE_AVX
            return {
                ab_,
                _mm256_permute2f128_ps(cd_, cd_, 0x01)
            };
#else
            return {
                a,
                b,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x4 acb() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x20),
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
        NCPP_FORCE_INLINE F_data3x4 acd() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x20),
                _mm256_permute2f128_ps(cd_, cd_, 0x01)
            };
#else
            return {
                a,
                c,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x4 adb() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x30),
                _mm256_permute2f128_ps(ab_, ab_, 0x01)
            };
#else
            return {
                a,
                d,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x4 adc() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x30),
                cd_
            };
#else
            return {
                a,
                d,
                c
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3x4 bac() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, ab_, 0x01),
                cd_
            };
#else
            return {
                b,
                a,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x4 bad() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, ab_, 0x01),
                _mm256_permute2f128_ps(cd_, cd_, 0x01)
            };
#else
            return {
                b,
                a,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x4 bca() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x21),
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
        NCPP_FORCE_INLINE F_data3x4 bcd() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x21),
                _mm256_permute2f128_ps(cd_, cd_, 0x01)
            };
#else
            return {
                b,
                c,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x4 bda() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x31),
                ab_
            };
#else
            return {
                b,
                d,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x4 bdc() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x31),
                cd_
            };
#else
            return {
                b,
                d,
                c
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3x4 cab() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x02),
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
        NCPP_FORCE_INLINE F_data3x4 cad() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x20),
                _mm256_permute2f128_ps(cd_, cd_, 0x01)
            };
#else
            return {
                c,
                a,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x4 cba() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x12),
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
        NCPP_FORCE_INLINE F_data3x4 cbd() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x12),
                _mm256_permute2f128_ps(cd_, cd_, 0x01)
            };
#else
            return {
                c,
                b,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x4 cda() const {

#ifdef NCPP_ENABLE_AVX
            return {
                cd_,
                ab_
            };
#else
            return {
                c,
                d,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x4 cdb() const {

#ifdef NCPP_ENABLE_AVX
            return {
                cd_,
                _mm256_permute2f128_ps(ab_, ab_, 0x01)
            };
#else
            return {
                c,
                d,
                b
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3x4 dab() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x03),
                _mm256_permute2f128_ps(ab_, ab_, 0x01)
            };
#else
            return {
                d,
                a,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x4 dac() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x03),
                cd_
            };
#else
            return {
                d,
                a,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x4 dba() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x13),
                ab_
            };
#else
            return {
                d,
                b,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x4 dbc() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x13),
                cd_
            };
#else
            return {
                d,
                b,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x4 dca() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(cd_, cd_, 0x01),
                ab_
            };
#else
            return {
                d,
                c,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x4 dcb() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(cd_, cd_, 0x01),
                _mm256_permute2f128_ps(ab_, ab_, 0x01)
            };
#else
            return {
                d,
                c,
                b
            };
#endif
        }

        NCPP_FORCE_INLINE F_this abcd() const {

#ifdef NCPP_ENABLE_AVX
            return {
                ab_,
                cd_
            };
#else
            return {
                a,
                b,
                c,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_this abdc() const {

#ifdef NCPP_ENABLE_AVX
            return {
                ab_,
                _mm256_permute2f128_ps(cd_, cd_, 0x01)
            };
#else
            return {
                a,
                b,
                d,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_this acbd() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x20),
                _mm256_permute2f128_ps(ab_, cd_, 0x31)
            };
#else
            return {
                a,
                c,
                b,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_this acdb() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x20),
                _mm256_permute2f128_ps(ab_, cd_, 0x13)
            };
#else
            return {
                a,
                c,
                d,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_this adbc() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x30),
                _mm256_permute2f128_ps(ab_, cd_, 0x21)
            };
#else
            return {
                a,
                d,
                b,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_this adcb() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x30),
                _mm256_permute2f128_ps(ab_, cd_, 0x12)
            };
#else
            return {
                a,
                d,
                c,
                b
            };
#endif
        }

        NCPP_FORCE_INLINE F_this bacd() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, ab_, 0x01),
                cd_
            };
#else
            return {
                b,
                a,
                c,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_this badc() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, ab_, 0x01),
                _mm256_permute2f128_ps(cd_, cd_, 0x01)
            };
#else
            return {
                b,
                a,
                d,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_this bcad() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x21),
                _mm256_permute2f128_ps(ab_, cd_, 0x30)
            };
#else
            return {
                b,
                c,
                a,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_this bcda() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x21),
                _mm256_permute2f128_ps(ab_, cd_, 0x03)
            };
#else
            return {
                b,
                c,
                d,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_this bdac() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x31),
                _mm256_permute2f128_ps(ab_, cd_, 0x20)
            };
#else
            return {
                b,
                d,
                a,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_this bdca() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x31),
                _mm256_permute2f128_ps(ab_, cd_, 0x02)
            };
#else
            return {
                b,
                d,
                c,
                a
            };
#endif
        }

        NCPP_FORCE_INLINE F_this cabd() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x02),
                _mm256_permute2f128_ps(ab_, cd_, 0x31)
            };
#else
            return {
                c,
                a,
                b,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_this cadb() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x20),
                _mm256_permute2f128_ps(ab_, cd_, 0x13)
            };
#else
            return {
                c,
                a,
                d,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_this cbad() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x12),
                _mm256_permute2f128_ps(ab_, cd_, 0x30)
            };
#else
            return {
                c,
                b,
                a,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_this cbda() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x12),
                _mm256_permute2f128_ps(ab_, cd_, 0x03)
            };
#else
            return {
                c,
                b,
                d,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_this cdab() const {

#ifdef NCPP_ENABLE_AVX
            return {
                cd_,
                ab_
            };
#else
            return {
                c,
                d,
                a,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_this cdba() const {

#ifdef NCPP_ENABLE_AVX
            return {
                cd_,
                _mm256_permute2f128_ps(ab_, ab_, 0x01)
            };
#else
            return {
                c,
                d,
                b,
                a
            };
#endif
        }

        NCPP_FORCE_INLINE F_this dabc() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x03),
                _mm256_permute2f128_ps(ab_, cd_, 0x21)
            };
#else
            return {
                d,
                a,
                b,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_this dacb() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x03),
                _mm256_permute2f128_ps(ab_, cd_, 0x12)
            };
#else
            return {
                d,
                a,
                c,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_this dbac() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x13),
                _mm256_permute2f128_ps(ab_, cd_, 0x20)
            };
#else
            return {
                d,
                b,
                a,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_this dbca() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(ab_, cd_, 0x13),
                _mm256_permute2f128_ps(ab_, cd_, 0x02)
            };
#else
            return {
                d,
                b,
                c,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_this dcab() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(cd_, cd_, 0x01),
                ab_
            };
#else
            return {
                d,
                c,
                a,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_this dcba() const {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute2f128_ps(cd_, cd_, 0x01),
                _mm256_permute2f128_ps(ab_, ab_, 0x01)
            };
#else
            return {
                d,
                c,
                b,
                a
            };
#endif
        }

        NCPP_FORCE_INLINE TF_data4x4<F_entry> NCPP_VECTOR_CALL data4x4() const {

#ifdef NCPP_ENABLE_AVX
            return {
                ab_,
                cd_
            };
#else
            return {
                a,
                b,
                c,
                d
            };
#endif
        }
        template<typename F_another_data4x4__>
        NCPP_FORCE_INLINE TF_data_cast<F_another_data4x4__> T_data4x4() const {

#ifdef NCPP_ENABLE_AVX
            return {
                ab_,
                cd_
            };
#else
            return {
                a,
                b,
                c,
                d
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



    using PA_data4x4_f32 = TPA_data4x4<f32>;

}
