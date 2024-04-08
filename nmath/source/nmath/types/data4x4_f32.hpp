

#pragma once

/** @file nmath/types/data4x4_f32.hpp
*
*   Implement data4x4_f32.
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

#include <nmath/types/data4x4_template.hpp>

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
    struct NCPP_ALIGN(sizeof(f32) * 4 * 4) TF_data4x4<f32, F_flag__> {
        
        ////////////////////////////////////////////////////////////////////////////////////
        //  Typedefs
        ////////////////////////////////////////////////////////////////////////////////////
        using F_entry = f32;

        using F_pack = TF_data4<F_entry, F_flag__>;
        using PA_pack = TPA_data4<F_entry, F_flag__>;

        using F_data2x2 = TF_data2x2<F_entry, F_flag__>;
        using PA_data2x2 = TPA_data2x2<F_entry, F_flag__>;

        using F_data3x3 = TF_data3x3<F_entry, F_flag__>;
        using PA_data3x3 = TPA_data3x3<F_entry, F_flag__>;

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
        
        NCPP_RTTI_IMPLEMENT_FLAG(nmath::F_data4x4_f32_flag);
        NCPP_RTTI_IMPLEMENT_FLAG(F_flag__);
        
        
        
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

                F_pack right;
                F_pack up;
                F_pack forward;
                F_pack translation;

            };
            struct {

                F_pack bitangent;
                F_pack normal;
                F_pack tangent;

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
        NCPP_FORCE_INLINE TF_data4x4() noexcept = default;
        NCPP_FORCE_INLINE TF_data4x4(PA_pack a, PA_pack b, PA_pack c, PA_pack d) noexcept :
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
        NCPP_FORCE_INLINE TF_data4x4& NMATH_CALL_CNV operator = (F_passed_argument o) noexcept
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
        friend NCPP_FORCE_INLINE ncpp::b8 NMATH_CALL_CNV operator == (F_passed_argument a, F_passed_argument b) noexcept
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
        friend NCPP_FORCE_INLINE ncpp::b8 NMATH_CALL_CNV operator != (F_passed_argument a, F_passed_argument b) noexcept
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
        //  Special values
        ////////////////////////////////////////////////////////////////////////////////////
        static NCPP_FORCE_INLINE F_this zero() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_00000000,
                simd_f32x8_00000000
            };
#else
            return {
                F_pack::zero(),
                F_pack::zero(),
                F_pack::zero(),
                F_pack::zero()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this one() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111,
                simd_f32x8_11111111
            };
#else
            return {
                F_pack::one(),
                F_pack::one(),
                F_pack::one(),
                F_pack::one()
            };
#endif
        }       
        static NCPP_FORCE_INLINE F_this infinity() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_infinity,
                simd_f32x8_11111111_infinity
            };
#else
            return {
                F_pack::infinity(),
                F_pack::infinity(),
                F_pack::infinity(),
                F_pack::infinity()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this negative_infinity() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_negative_infinity,
                simd_f32x8_11111111_negative_infinity
            };
#else
            return {
                F_pack::negative_infinity(),
                F_pack::negative_infinity(),
                F_pack::negative_infinity(),
                F_pack::negative_infinity()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_pi,
                simd_f32x8_11111111_pi
            };
#else
            return {
                F_pack::pi(),
                F_pack::pi(),
                F_pack::pi(),
                F_pack::pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this negative_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_negative_pi,
                simd_f32x8_11111111_negative_pi
            };
#else
            return {
                F_pack::negative_pi(),
                F_pack::negative_pi(),
                F_pack::negative_pi(),
                F_pack::negative_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this half_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_half_pi,
                simd_f32x8_11111111_half_pi
            };
#else
            return {
                F_pack::half_pi(),
                F_pack::half_pi(),
                F_pack::half_pi(),
                F_pack::half_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this negative_half_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_negative_half_pi,
                simd_f32x8_11111111_negative_half_pi
            };
#else
            return {
                F_pack::negative_half_pi(),
                F_pack::negative_half_pi(),
                F_pack::negative_half_pi(),
                F_pack::negative_half_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this two_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_two_pi,
                simd_f32x8_11111111_two_pi
            };
#else
            return {
                F_pack::two_pi(),
                F_pack::two_pi(),
                F_pack::two_pi(),
                F_pack::two_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this negative_two_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_negative_two_pi,
                simd_f32x8_11111111_negative_two_pi
            };
#else
            return {
                F_pack::negative_two_pi(),
                F_pack::negative_two_pi(),
                F_pack::negative_two_pi(),
                F_pack::negative_two_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_inv_pi,
                simd_f32x8_11111111_inv_pi
            };
#else
            return {
                F_pack::inv_pi(),
                F_pack::inv_pi(),
                F_pack::inv_pi(),
                F_pack::inv_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_negative_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_inv_negative_pi,
                simd_f32x8_11111111_inv_negative_pi
            };
#else
            return {
                F_pack::inv_negative_pi(),
                F_pack::inv_negative_pi(),
                F_pack::inv_negative_pi(),
                F_pack::inv_negative_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_half_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_inv_half_pi,
                simd_f32x8_11111111_inv_half_pi
            };
#else
            return {
                F_pack::inv_half_pi(),
                F_pack::inv_half_pi(),
                F_pack::inv_half_pi(),
                F_pack::inv_half_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_negative_half_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_inv_negative_half_pi,
                simd_f32x8_11111111_inv_negative_half_pi
            };
#else
            return {
                F_pack::inv_negative_half_pi(),
                F_pack::inv_negative_half_pi(),
                F_pack::inv_negative_half_pi(),
                F_pack::inv_negative_half_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_two_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_inv_two_pi,
                simd_f32x8_11111111_inv_two_pi
            };
#else
            return {
                F_pack::inv_two_pi(),
                F_pack::inv_two_pi(),
                F_pack::inv_two_pi(),
                F_pack::inv_two_pi()
            };
#endif
        }
        static NCPP_FORCE_INLINE F_this inv_negative_two_pi() noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                simd_f32x8_11111111_inv_negative_two_pi,
                simd_f32x8_11111111_inv_negative_two_pi
            };
#else
            return {
                F_pack::inv_negative_two_pi(),
                F_pack::inv_negative_two_pi(),
                F_pack::inv_negative_two_pi(),
                F_pack::inv_negative_two_pi()
            };
#endif
        }



        ////////////////////////////////////////////////////////////////////////////////////
        //  Functions
        ////////////////////////////////////////////////////////////////////////////////////
        NCPP_FORCE_INLINE TF_data4x4<F_entry> data() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                ab_,
                cd_
            };
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
        NCPP_FORCE_INLINE TF_data_cast<F_another_data__> T_data() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                ab_,
                cd_
            };
#else
            return {
                a.template T_data<TF_pack_cast<F_another_data__>>(),
                b.template T_data<TF_pack_cast<F_another_data__>>(),
                c.template T_data<TF_pack_cast<F_another_data__>>(),
                d.template T_data<TF_pack_cast<F_another_data__>>()
            };
#endif
        }
        NCPP_FORCE_INLINE F_data2x2 tl2x2() const noexcept {

#ifdef NCPP_ENABLE_AVX
            __m128 a_128 = _mm256_extractf128_ps(ab_, 0x00);
            __m128 b_128 = _mm256_extractf128_ps(ab_, 0x01);
            
            return _mm_shuffle_ps(a_128, b_128, _MM_SHUFFLE(1, 0, 1, 0));
#else
            return {
                a.xy(),
                b.xy()
            };
#endif
        }
        NCPP_FORCE_INLINE F_data3x3 tl3x3() const noexcept {

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
                d,
            };
#endif
        }
        
        NCPP_FORCE_INLINE F_this abdc() const noexcept {

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
        NCPP_FORCE_INLINE F_this acbd() const noexcept {

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
        NCPP_FORCE_INLINE F_this acdb() const noexcept {

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
        NCPP_FORCE_INLINE F_this adbc() const noexcept {

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
        NCPP_FORCE_INLINE F_this adcb() const noexcept {

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

        NCPP_FORCE_INLINE F_this bacd() const noexcept {

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
        NCPP_FORCE_INLINE F_this badc() const noexcept {

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
        NCPP_FORCE_INLINE F_this bcad() const noexcept {

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
        NCPP_FORCE_INLINE F_this bcda() const noexcept {

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
        NCPP_FORCE_INLINE F_this bdac() const noexcept {

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
        NCPP_FORCE_INLINE F_this bdca() const noexcept {

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

        NCPP_FORCE_INLINE F_this cabd() const noexcept {

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
        NCPP_FORCE_INLINE F_this cadb() const noexcept {

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
        NCPP_FORCE_INLINE F_this cbad() const noexcept {

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
        NCPP_FORCE_INLINE F_this cbda() const noexcept {

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
        NCPP_FORCE_INLINE F_this cdab() const noexcept {

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
        NCPP_FORCE_INLINE F_this cdba() const noexcept {

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

        NCPP_FORCE_INLINE F_this dabc() const noexcept {

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
        NCPP_FORCE_INLINE F_this dacb() const noexcept {

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
        NCPP_FORCE_INLINE F_this dbac() const noexcept {

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
        NCPP_FORCE_INLINE F_this dbca() const noexcept {

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
        NCPP_FORCE_INLINE F_this dcab() const noexcept {

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
        NCPP_FORCE_INLINE F_this dcba() const noexcept {

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
        
        NCPP_FORCE_INLINE F_this xyzw() const noexcept {

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
        NCPP_FORCE_INLINE F_this xzyw() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(3, 1, 2, 0)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(3, 1, 2, 0))
            };
#else
            return {
                a.xzyw(),
                c.xzyw(),
                b.xzyw(),
                d.xzyw()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xzwy() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(1, 3, 2, 0)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(1, 3, 2, 0))
            };
#else
            return {
                a.xzwy(),
                c.xzwy(),
                b.xzwy(),
                d.xzwy()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xwyz() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(2, 1, 3, 0)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(2, 1, 3, 0))
            };
#else
            return {
                a.xwyz(),
                c.xwyz(),
                b.xwyz(),
                d.xwyz()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this xwzy() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(1, 2, 3, 0)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(1, 2, 3, 0))
            };
#else
            return {
                a.xwzy(),
                c.xwzy(),
                b.xwzy(),
                d.xwzy()
            };
#endif
        }

        NCPP_FORCE_INLINE F_this yxzw() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(3, 2, 0, 1)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(3, 2, 0, 1))
            };
#else
            return {
                a.yxzw(),
                c.yxzw(),
                b.yxzw(),
                d.yxzw()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yxwz() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(2, 3, 0, 1)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(2, 3, 0, 1))
            };
#else
            return {
                a.yxwz(),
                c.yxwz(),
                b.yxwz(),
                d.yxwz()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yzxw() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(3, 0, 2, 1)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(3, 0, 2, 1))
            };
#else
            return {
                a.yzxw(),
                c.yzxw(),
                b.yzxw(),
                d.yzxw()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this yzwx() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(0, 3, 2, 1)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(0, 3, 2, 1))
            };
#else
            return {
                a.yzwx(),
                c.yzwx(),
                b.yzwx(),
                d.yzwx()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this ywxz() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(2, 0, 3, 1)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(2, 0, 3, 1))
            };
#else
            return {
                a.ywxz(),
                c.ywxz(),
                b.ywxz(),
                d.ywxz()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this ywzx() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(0, 2, 3, 1)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(0, 2, 3, 1))
            };
#else
            return {
                a.ywzx(),
                c.ywzx(),
                b.ywzx(),
                d.ywzx()
            };
#endif
        }

        NCPP_FORCE_INLINE F_this zxyw() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(3, 1, 0, 2)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(3, 1, 0, 2))
            };
#else
            return {
                a.zxyw(),
                c.zxyw(),
                b.zxyw(),
                d.zxyw()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zxwy() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(1, 3, 0, 2)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(1, 3, 0, 2))
            };
#else
            return {
                a.zxwy(),
                c.zxwy(),
                b.zxwy(),
                d.zxwy()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zyxw() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(3, 0, 1, 2)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(3, 0, 1, 2))
            };
#else
            return {
                a.zyxw(),
                c.zyxw(),
                b.zyxw(),
                d.zyxw()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zywx() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(0, 3, 1, 2)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(0, 3, 1, 2))
            };
#else
            return {
                a.zywx(),
                c.zywx(),
                b.zywx(),
                d.zywx()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zwxy() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(1, 0, 3, 2)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(1, 0, 3, 2))
            };
#else
            return {
                a.zwxy(),
                c.zwxy(),
                b.zwxy(),
                d.zwxy()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this zwyx() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(0, 1, 3, 2)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(0, 1, 3, 2))
            };
#else
            return {
                a.zwyx(),
                c.zwyx(),
                b.zwyx(),
                d.zwyx()
            };
#endif
        }

        NCPP_FORCE_INLINE F_this wxyz() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(2, 1, 0, 3)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(2, 1, 0, 3))
            };
#else
            return {
                a.wxyz(),
                c.wxyz(),
                b.wxyz(),
                d.wxyz()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wxzy() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(1, 2, 0, 3)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(1, 2, 0, 3))
            };
#else
            return {
                a.wxzy(),
                c.wxzy(),
                b.wxzy(),
                d.wxzy()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wyxz() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(2, 0, 1, 3)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(2, 0, 1, 3))
            };
#else
            return {
                a.wyxz(),
                c.wyxz(),
                b.wyxz(),
                d.wyxz()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wyzx() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(0, 2, 1, 3)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(0, 2, 1, 3))
            };
#else
            return {
                a.wyzx(),
                c.wyzx(),
                b.wyzx(),
                d.wyzx()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wzxy() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(1, 0, 2, 3)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(1, 0, 2, 3))
            };
#else
            return {
                a.wzxy(),
                c.wzxy(),
                b.wzxy(),
                d.wzxy()
            };
#endif
        }
        NCPP_FORCE_INLINE F_this wzyx() const noexcept {

#ifdef NCPP_ENABLE_AVX
            return {
                _mm256_permute_ps(ab_, _MM_SHUFFLE(0, 1, 2, 3)),
                _mm256_permute_ps(cd_, _MM_SHUFFLE(0, 1, 2, 3))
            };
#else
            return {
                a.wzyx(),
                c.wzyx(),
                b.wzyx(),
                d.wzyx()
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
