

#pragma once

/** @file nmath/types/data4x2.hpp
*
*   Implement data4x2.
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

#include <nmath/types/data2.hpp>
#include <nmath/types/data2x2.hpp>
#include <nmath/types/data3x2.hpp>
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
    struct TF_data4x2;

    template<typename F_entry__ = NMATH_DEFAULT_FP_TYPE, typename F_flag__ = F_data_default_flag>
    using TPA_data4x2 = typename TF_data4x2<F_entry__, F_flag__>::F_passed_argument;

    NCPP_RTTI_CREATE_FLAG(F_data4x2_f32_flag);
    NCPP_RTTI_CREATE_FLAG(F_data4x2_i32_flag);
    NCPP_RTTI_CREATE_FLAG(F_data4x2_u32_flag);

    NCPP_RTTI_CREATE_FLAG(F_data4x2_f64_flag);
    NCPP_RTTI_CREATE_FLAG(F_data4x2_i64_flag);
    NCPP_RTTI_CREATE_FLAG(F_data4x2_u64_flag);



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    using F_data4x2_f32 = TF_data4x2<f32>;



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
#define NMATH_DATA4X2_SIMD_M256() \
    __m256 abcd_;
#define NMATH_DATA4X2_SIMD_CONSTRUCTOR_M256() \
    NCPP_FORCE_INLINE TF_data4x2(__m256 abcd) : \
        abcd_(abcd)\
    {}
#else
#define NMATH_DATA4X2_SIMD_M256() ;
#define NMATH_DATA4X2_SIMD_CONSTRUCTOR_M256() ;
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
    struct NCPP_ALIGN(64) TF_data4x2<f32, F_flag__> {

        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = f32;

        using F_pack = TF_data2<F_entry, F_flag__>;
        using PA_pack = TPA_data2<F_entry, F_flag__>;

        using F_data2x2 = TF_data2x2<F_entry, F_flag__>;
        using PA_data2x2 = TPA_data2x2<F_entry, F_flag__>;

        using F_data3x2 = TF_data3x2<F_entry, F_flag__>;
        using PA_data3x2 = TPA_data3x2<F_entry, F_flag__>;

        using F_flag = F_flag__;

        using F_this = TF_data4x2<F_entry, F_flag__>;

        static constexpr u32 entry_count_s = 8;
        static constexpr u32 pack_count_s = 4;

        // at least the lowest SIMD level is enabled, use pass-by-value
#if defined(NCPP_ENABLE_SSE)
        using F_passed_argument = const F_this;
#else
        using F_passed_argument = const F_this&;
#endif

        NCPP_RTTI_IMPLEMENT_FLAG(TF_data4x2, nmath::F_data4x2_f32_flag);
        NCPP_RTTI_IMPLEMENT_FLAG(TF_data4x2, F_flag__);



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

                F_entry bx;
                F_entry by;

                F_entry cx;
                F_entry cy;

                F_entry dx;
                F_entry dy;

            };

            F_pack m[4];

            NMATH_DATA4X2_SIMD_M256();

        };



        ////////////////////////////////////////////////////////////////////////////////////
        //  Basic constructors
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data4x2() noexcept :
#ifdef NCPP_ENABLE_AVX
            abcd_(simd_f32x8_00000000)
#else
            a(),
            b(),
            c(),
            d()
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4x2(PA_pack a, PA_pack b, PA_pack c, PA_pack d) noexcept :
#ifdef NCPP_ENABLE_AVX
            abcd_(_mm256_set_ps(d.y, d.x, c.y, c.x, b.y, b.x, a.y, a.x))
#else
            a(a),
            b(b),
            c(c),
            d(d)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4x2(PA_pack a, PA_pack b, PA_data2x2 cd) noexcept :
#ifdef NCPP_ENABLE_AVX
            abcd_(_mm256_set_m128(cd.ab_, _mm_set_ps(b.y, b.x, a.y, a.x)))
#else
            a(a),
            b(b),
            c(cd.a),
            d(cd.b)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4x2(PA_pack a, PA_data2x2 bc, PA_pack d) noexcept :
#ifdef NCPP_ENABLE_AVX
            abcd_(_mm256_set_ps(d.y, d.x, bc.b.y, bc.b.x, bc.a.y, bc.a.x, a.y, a.x))
#else
            a(a),
            b(bc.a),
            c(bc.b),
            d(d)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4x2(PA_data2x2 ab, PA_pack c, PA_pack d) noexcept :
#ifdef NCPP_ENABLE_AVX
            abcd_(_mm256_set_m128(_mm_set_ps(d.y, d.x, c.y, c.x), ab.ab_))
#else
            a(ab.a),
            b(ab.b),
            c(c),
            d(d)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4x2(PA_data2x2 ab, PA_data2x2 cd) noexcept :
#ifdef NCPP_ENABLE_AVX
            abcd_(_mm256_set_m128(cd.ab_, ab.ab_))
#else
            a(ab.a),
            b(ab.b),
            c(cd.a),
            d(cd.b)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4x2(PA_data3x2 abc, PA_pack d) noexcept :
#ifdef NCPP_ENABLE_AVX
            abcd_(abc.abc_)
#else
            a(abc.a),
            b(abc.b),
            c(abc.c),
            d(d)
#endif
        {

#ifdef NCPP_ENABLE_AVX
            this->d = d;
#endif

        }
        NCPP_FORCE_INLINE TF_data4x2(F_pack a, PA_data3x2 bcd) noexcept :
#ifdef NCPP_ENABLE_AVX
            abcd_(_mm256_set_ps(bcd.c.y, bcd.c.x, bcd.b.y, bcd.b.x, bcd.a.y, bcd.a.x, a.y, a.x))
#else
            a(a),
            b(bcd.a),
            c(bcd.b),
            d(bcd.c)
#endif
        {



        }
        NCPP_FORCE_INLINE TF_data4x2(const TF_data4x2& o) noexcept :
#ifdef NCPP_ENABLE_AVX
            abcd_(o.abcd_)
#else
            a(o.a),
            b(o.b),
            c(o.c),
            d(o.d)
#endif
        {



        }

        NMATH_DATA4X2_SIMD_CONSTRUCTOR_M256();



        ////////////////////////////////////////////////////////////////////////////////////
        //  Operators
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data4x2& NCPP_VECTOR_CALL operator = (F_passed_argument o) noexcept
        {

#ifdef NCPP_ENABLE_AVX
            abcd_ = o.abcd_;
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
            __m256 abcd_compare8 = _mm256_cmp_ps(a.abcd_, b.abcd_, _CMP_EQ_OQ);
            int abcd_mask = _mm256_movemask_ps(abcd_compare8);

            return ((abcd_mask | 0b10001000) == 0b11111111);
#else
            return (a.a == b.a) && (a.b == b.b) && (a.c == b.c) && (a.d == b.d);
#endif
        }
        friend NCPP_FORCE_INLINE ncpp::b8 NCPP_VECTOR_CALL operator != (F_passed_argument a, F_passed_argument b) noexcept
        {

#ifdef NCPP_ENABLE_AVX
            __m256 abcd_compare8 = _mm256_cmp_ps(a.abcd_, b.abcd_, _CMP_EQ_OQ);
            int abcd_mask = _mm256_movemask_ps(abcd_compare8);

            return ((abcd_mask | 0b10001000) != 0b11111111);
#else
            return (a.a != b.a) || (a.b != b.b) || (a.c != b.c) || (a.d != b.d);
#endif
        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Functions
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE F_data2x2 ab() const {

#ifdef NCPP_ENABLE_AVX
            return {
                a,
                b
            };
#else
            return {
                a,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x2 ac() const {

#ifdef NCPP_ENABLE_AVX
            return {
                a,
                c
            };
#else
            return {
                a,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x2 ad() const {

#ifdef NCPP_ENABLE_AVX
            return {
                a,
                d
            };
#else
            return {
                a,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x2 ba() const {

#ifdef NCPP_ENABLE_AVX
            return {
                b,
                a
            };
#else
            return {
                b,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x2 bc() const {

#ifdef NCPP_ENABLE_AVX
            return {
                b,
                c
            };
#else
            return {
                b,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x2 bd() const {

#ifdef NCPP_ENABLE_AVX
            return {
                b,
                d
            };
#else
            return {
                b,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x2 ca() const {

#ifdef NCPP_ENABLE_AVX
            return {
                c,
                a
            };
#else
            return {
                c,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x2 cb() const {

#ifdef NCPP_ENABLE_AVX
            return {
                c,
                b
            };
#else
            return {
                c,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x2 cd() const {

#ifdef NCPP_ENABLE_AVX
            return {
                c,
                d
            };
#else
            return {
                c,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x2 da() const {

#ifdef NCPP_ENABLE_AVX
            return {
                d,
                a
            };
#else
            return {
                d,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x2 db() const {

#ifdef NCPP_ENABLE_AVX
            return {
                d,
                b
            };
#else
            return {
                d,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x2 dc() const {

#ifdef NCPP_ENABLE_AVX
            return {
                d,
                c
            };
#else
            return {
                d,
                c
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3x2 abc() const {

#ifdef NCPP_ENABLE_AVX
            return {
                a,
                b,
                c
            };
#else
            return {
                a,
                b,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 abd() const {

#ifdef NCPP_ENABLE_AVX
            return {
                a,
                b,
                d
            };
#else
            return {
                a,
                b,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 acb() const {

#ifdef NCPP_ENABLE_AVX
            return {
                a,
                c,
                b
            };
#else
            return {
                a,
                c,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 acd() const {

#ifdef NCPP_ENABLE_AVX
            return {
                a,
                c,
                d
            };
#else
            return {
                a,
                c,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 adb() const {

#ifdef NCPP_ENABLE_AVX
            return {
                a,
                d,
                b
            };
#else
            return {
                a,
                d,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 adc() const {

#ifdef NCPP_ENABLE_AVX
            return {
                a,
                d,
                c
            };
#else
            return {
                a,
                d,
                c
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3x2 bac() const {

#ifdef NCPP_ENABLE_AVX
            return {
                b,
                a,
                c
            };
#else
            return {
                b,
                a,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 bad() const {

#ifdef NCPP_ENABLE_AVX
            return {
                b,
                a,
                d
            };
#else
            return {
                b,
                a,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 bca() const {

#ifdef NCPP_ENABLE_AVX
            return {
                b,
                c,
                a
            };
#else
            return {
                b,
                c,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 bcd() const {

#ifdef NCPP_ENABLE_AVX
            return {
                b,
                c,
                d
            };
#else
            return {
                b,
                c,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 bda() const {

#ifdef NCPP_ENABLE_AVX
            return {
                b,
                d,
                a
            };
#else
            return {
                b,
                d,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 bdc() const {

#ifdef NCPP_ENABLE_AVX
            return {
                b,
                d,
                c
            };
#else
            return {
                b,
                d,
                c
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3x2 cab() const {

#ifdef NCPP_ENABLE_AVX
            return {
                c,
                a,
                b
            };
#else
            return {
                c,
                a,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 cad() const {

#ifdef NCPP_ENABLE_AVX
            return {
                c,
                a,
                d
            };
#else
            return {
                c,
                a,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 cba() const {

#ifdef NCPP_ENABLE_AVX
            return {
                c,
                b,
                a
            };
#else
            return {
                c,
                b,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 cbd() const {

#ifdef NCPP_ENABLE_AVX
            return {
                c,
                b,
                d
            };
#else
            return {
                c,
                b,
                d
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 cda() const {

#ifdef NCPP_ENABLE_AVX
            return {
                c,
                d,
                a
            };
#else
            return {
                c,
                d,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 cdb() const {

#ifdef NCPP_ENABLE_AVX
            return {
                c,
                d,
                b
            };
#else
            return {
                c,
                d,
                b
            };
#endif
        }

        NCPP_FORCE_INLINE F_data3x2 dab() const {

#ifdef NCPP_ENABLE_AVX
            return {
                d,
                a,
                b
            };
#else
            return {
                d,
                a,
                b
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 dac() const {

#ifdef NCPP_ENABLE_AVX
            return {
                d,
                a,
                c
            };
#else
            return {
                d,
                a,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 dba() const {

#ifdef NCPP_ENABLE_AVX
            return {
                d,
                b,
                a
            };
#else
            return {
                d,
                b,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 dbc() const {

#ifdef NCPP_ENABLE_AVX
            return {
                d,
                b,
                c
            };
#else
            return {
                d,
                b,
                c
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 dca() const {

#ifdef NCPP_ENABLE_AVX
            return {
                d,
                c,
                a
            };
#else
            return {
                d,
                c,
                a
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x2 dcb() const {

#ifdef NCPP_ENABLE_AVX
            return {
                d,
                c,
                b
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
                a,
                b,
                c,
                d
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
                a,
                b,
                d,
                c
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
                a,
                c,
                b,
                d
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
                a,
                c,
                d,
                b
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
                a,
                d,
                b,
                c
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
                a,
                d,
                c,
                b
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
                b,
                a,
                c,
                d
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
                b,
                a,
                d,
                c
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
                b,
                c,
                a,
                d
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
                b,
                c,
                d,
                a
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
                b,
                d,
                a,
                c
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
                b,
                d,
                c,
                a
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
                c,
                a,
                b,
                d
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
                c,
                a,
                d,
                b
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
                c,
                b,
                a,
                d
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
                c,
                b,
                d,
                a
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
                c,
                d,
                a,
                b
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
                c,
                d,
                b,
                a
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
                d,
                a,
                b,
                c
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
                d,
                a,
                c,
                b
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
                d,
                b,
                a,
                c
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
                d,
                b,
                c,
                a
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
                d,
                c,
                a,
                b
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
                d,
                c,
                b,
                a
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

        NCPP_FORCE_INLINE TF_data4x2<F_entry> data() const {

#ifdef NCPP_ENABLE_AVX
            return abcd_;
#else
            return {
                a.data(),
                b.data(),
                c.data(),
                d.data()
            };
#endif
        }
        template<typename F_another_data__>
        NCPP_FORCE_INLINE TF_data_cast<F_another_data__> T_data() const {

#ifdef NCPP_ENABLE_AVX
            return abcd_;
#else
            return {
                a.T_data<TF_pack_cast<F_another_data__>>(),
                b.T_data<TF_pack_cast<F_another_data__>>(),
                c.T_data<TF_pack_cast<F_another_data__>>(),
                d.T_data<TF_pack_cast<F_another_data__>>()
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



    using PA_data4x2_f32 = TPA_data4x2<f32>;

}
