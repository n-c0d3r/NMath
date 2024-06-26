
message(STATUS "<NMath::SIMDMacos> Start creating SIMD macros")



#####################################################################################
#   Setup file
#####################################################################################
set(SIMD_MACROS_FILE_PATH "${NMATH_GENERATED_FILES_DIR}/simd_macros.hpp")
file(WRITE "${SIMD_MACROS_FILE_PATH}" "")



#####################################################################################
#   Namespace beginning
#####################################################################################
file(APPEND "${SIMD_MACROS_FILE_PATH}" "
namespace nmath {
")



#####################################################################################
#   SIMD platform specific types
#####################################################################################
file(APPEND "${SIMD_MACROS_FILE_PATH}" "
#ifdef NCPP_ENABLE_SSE
using F_simd_f32x4 = __m128;
    #ifndef NMATH_ENABLE_SIMD_F32X4
    #define NMATH_ENABLE_SIMD_F32X4
    #endif
#endif

#ifdef NCPP_ENABLE_SSE2
using F_simd_i32x4 = __m128i;
    #ifndef NMATH_ENABLE_SIMD_I32X4
    #define NMATH_ENABLE_SIMD_I32X4
    #endif
#endif
")

file(APPEND "${SIMD_MACROS_FILE_PATH}" "
#ifdef NCPP_ENABLE_AVX
using F_simd_f32x8 = __m256;
    #ifndef NMATH_ENABLE_SIMD_F32X8
    #define NMATH_ENABLE_SIMD_F32X8
    #endif
#endif

#ifdef NCPP_ENABLE_AVX2
using F_simd_i32x8 = __m256i;
    #ifndef NMATH_ENABLE_SIMD_I32X8
    #define NMATH_ENABLE_SIMD_I32X8
    #endif
#endif
")



#####################################################################################
#   Functions
#####################################################################################
function(NMath_Permutations_4 Name)
    # Create a list to store the permutations
    set(local_permutations "")

    # Generate all 4-element permutations of 1 and 0
    foreach(i RANGE 0 1)
        foreach(j RANGE 0 1)
            foreach(k RANGE 0 1)
                foreach(l RANGE 0 1)
                    list(APPEND local_permutations "${i}${j}${k}${l}")
                endforeach()
            endforeach()
        endforeach()
    endforeach()

    # Create a list to store the permutations
    set(${Name} ${local_permutations} PARENT_SCOPE)
endfunction()

function(NMath_Permutations_8 Name)
    # Create a list to store the permutations
    set(local_permutations "")

    # Generate all 8-element permutations of 1 and 0
    foreach(i RANGE 0 1)
        foreach(j RANGE 0 1)
            foreach(k RANGE 0 1)
                foreach(l RANGE 0 1)
                    foreach(i2 RANGE 0 1)
                        foreach(j2 RANGE 0 1)
                            foreach(k2 RANGE 0 1)
                                foreach(l2 RANGE 0 1)
                                    list(APPEND local_permutations "${i}${j}${k}${l}${i2}${j2}${k2}${l2}")
                                endforeach()
                            endforeach()
                        endforeach()
                    endforeach()
                endforeach()
            endforeach()
        endforeach()
    endforeach()

    # Create a list to store the permutations
    set(${Name} ${local_permutations} PARENT_SCOPE)
endfunction()

function(NMath_DeclareSIMDConstants_f32x4)
    cmake_parse_arguments(
        PARGS
        ""
        "PREFIX;"
        ""
        ${ARGN}
    )

    if(NOT PARGS_PREFIX)
        message(FATAL "prefix must not be empty")
    endif()

    NMath_Permutations_4(permutations)

    file(APPEND "${SIMD_MACROS_FILE_PATH}" "
    #ifdef NMATH_ENABLE_SIMD_F32X4
    ")

    # Utility functions
    file(APPEND "${SIMD_MACROS_FILE_PATH}" "
        NCPP_FORCE_INLINE F_simd_f32x4 make_simd_f32x4(f32 x, f32 y, f32 z, f32 w, f32 none = 0.0f) noexcept {

        #ifdef NCPP_ENABLE_SSE
            return _mm_set_ps(w,z,y,x);
        #endif
        }
    ")

    # For constant defining
    file(APPEND "${SIMD_MACROS_FILE_PATH}" "#define NMATH_DEFINE_SIMD_F32X4_CONSTANTS() \\")
    foreach(permutation IN LISTS permutations)
        set(range_one_value ${permutation})
        string(REPLACE "1" "NMATH_F32_ONE," range_one_value ${range_one_value})
        string(REPLACE "0" "NMATH_F32_ZERO," range_one_value ${range_one_value})
        file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation} = make_simd_f32x4(${range_one_value}0.0f);\\")

        if(NOT ${permutation} STREQUAL 0000)  
            set(range_infinity_value ${permutation})
            string(REPLACE "1" "NMATH_F32_INFINITY," range_infinity_value ${range_infinity_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_infinity_value ${range_infinity_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_infinity = make_simd_f32x4(${range_infinity_value}0.0f);\\")

            set(range_negative_infinity_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_INFINITY," range_negative_infinity_value ${range_negative_infinity_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_negative_infinity_value ${range_negative_infinity_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_negative_infinity = make_simd_f32x4(${range_negative_infinity_value}0.0f);\\")

            set(range_pi_value ${permutation})
            string(REPLACE "1" "NMATH_F32_PI," range_pi_value ${range_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_pi_value ${range_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_pi = make_simd_f32x4(${range_pi_value}0.0f);\\")

            set(range_negative_pi_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_PI," range_negative_pi_value ${range_negative_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_negative_pi_value ${range_negative_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_negative_pi = make_simd_f32x4(${range_negative_pi_value}0.0f);\\")

            set(range_half_pi_value ${permutation})
            string(REPLACE "1" "NMATH_F32_HALF_PI," range_half_pi_value ${range_half_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_half_pi_value ${range_half_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_half_pi = make_simd_f32x4(${range_half_pi_value}0.0f);\\")

            set(range_negative_half_pi_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_HALF_PI," range_negative_half_pi_value ${range_negative_half_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_negative_half_pi_value ${range_negative_half_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_negative_half_pi = make_simd_f32x4(${range_negative_half_pi_value}0.0f);\\")
            
            set(range_two_pi_value ${permutation})
            string(REPLACE "1" "NMATH_F32_TWO_PI," range_two_pi_value ${range_two_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_two_pi_value ${range_two_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_two_pi = make_simd_f32x4(${range_two_pi_value}0.0f);\\")

            set(range_negative_two_pi_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_TWO_PI," range_negative_two_pi_value ${range_negative_two_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_negative_two_pi_value ${range_negative_two_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_negative_two_pi = make_simd_f32x4(${range_negative_two_pi_value}0.0f);\\")

            set(range_inv_pi_value ${permutation})
            string(REPLACE "1" "NMATH_F32_INV_PI," range_inv_pi_value ${range_inv_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_inv_pi_value ${range_inv_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_inv_pi = make_simd_f32x4(${range_inv_pi_value}0.0f);\\")

            set(range_inv_negative_pi_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_INV_PI," range_inv_negative_pi_value ${range_inv_negative_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_inv_negative_pi_value ${range_inv_negative_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_inv_negative_pi = make_simd_f32x4(${range_inv_negative_pi_value}0.0f);\\")

            set(range_inv_half_pi_value ${permutation})
            string(REPLACE "1" "NMATH_F32_INV_HALF_PI," range_inv_half_pi_value ${range_inv_half_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_inv_half_pi_value ${range_inv_half_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_inv_half_pi = make_simd_f32x4(${range_inv_half_pi_value}0.0f);\\")

            set(range_inv_negative_half_pi_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_INV_HALF_PI," range_inv_negative_half_pi_value ${range_inv_negative_half_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_inv_negative_half_pi_value ${range_inv_negative_half_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_inv_negative_half_pi = make_simd_f32x4(${range_inv_negative_half_pi_value}0.0f);\\")
            
            set(range_inv_two_pi_value ${permutation})
            string(REPLACE "1" "NMATH_F32_INV_TWO_PI," range_inv_two_pi_value ${range_inv_two_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_inv_two_pi_value ${range_inv_two_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_inv_two_pi = make_simd_f32x4(${range_inv_two_pi_value}0.0f);\\")

            set(range_inv_negative_two_pi_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_INV_TWO_PI," range_inv_negative_two_pi_value ${range_inv_negative_two_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_inv_negative_two_pi_value ${range_inv_negative_two_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_inv_negative_two_pi = make_simd_f32x4(${range_inv_negative_two_pi_value}0.0f);\\")

            set(range_negative_one_value ${permutation})
            string(REPLACE "1" "NMATH_F32_ONE_NEGATIVE," range_negative_one_value ${range_negative_one_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_negative_one_value ${range_negative_one_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_negative = make_simd_f32x4(${range_negative_one_value}0.0f);\\")
            
            string(REPLACE "1" "F" range_full_permutation ${permutation})
            set(range_full_value ${permutation})
            string(REPLACE "1" "NMATH_F32_FULL," range_full_value ${range_full_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_full_value ${range_full_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${range_full_permutation} = make_simd_f32x4(${range_full_value}0.0f);\\")

            set(range_half_value ${permutation})
            string(REPLACE "1" "NMATH_F32_HALF," range_half_value ${range_half_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_half_value ${range_half_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_half = make_simd_f32x4(${range_half_value}0.0f);\\")

            set(range_negative_half_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_HALF," range_negative_half_value ${range_negative_half_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_negative_half_value ${range_negative_half_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_negative_half = make_simd_f32x4(${range_negative_half_value}0.0f);\\")

            set(range_inv_half_value ${permutation})
            string(REPLACE "1" "NMATH_F32_INV_HALF," range_inv_half_value ${range_inv_half_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_inv_half_value ${range_inv_half_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_inv_half = make_simd_f32x4(${range_inv_half_value}0.0f);\\")

            set(range_inv_negative_half_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_INV_HALF," range_inv_negative_half_value ${range_inv_negative_half_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_inv_negative_half_value ${range_inv_negative_half_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x4 ${PARGS_PREFIX}${permutation}_inv_negative_half = make_simd_f32x4(${range_inv_negative_half_value}0.0f);\\")
        endif()
    endforeach()

    file(APPEND "${SIMD_MACROS_FILE_PATH}" "\n")
    file(APPEND "${SIMD_MACROS_FILE_PATH}" "\n")

    # For declaration
    foreach(permutation IN LISTS permutations)
        file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation};\n")

        if(NOT ${permutation} STREQUAL 0000)   
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_infinity;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_negative_infinity;\n")

            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_pi;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_negative_pi;\n")

            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_half_pi;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_negative_half_pi;\n")

            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_two_pi;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_negative_two_pi;\n")

            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_inv_pi;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_inv_negative_pi;\n")
            
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_inv_half_pi;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_inv_negative_half_pi;\n")
            
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_inv_two_pi;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_inv_negative_two_pi;\n")

            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_negative;\n")

            string(REPLACE "1" "F" range_full_permutation ${permutation})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${range_full_permutation};\n")

            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_half;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_negative_half;\n")

            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_inv_half;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x4 ${PARGS_PREFIX}${permutation}_inv_negative_half;\n")
        endif()
    endforeach()

    file(APPEND "${SIMD_MACROS_FILE_PATH}" "
    #else
    #define NMATH_DEFINE_SIMD_F32X4_CONSTANTS()
    #endif
    ")

endfunction()

function(NMath_DeclareSIMDConstants_i32x4)
    cmake_parse_arguments(
        PARGS
        ""
        "PREFIX;"
        ""
        ${ARGN}
    )

    if(NOT PARGS_PREFIX)
        message(FATAL "prefix must not be empty")
    endif()

    NMath_Permutations_4(permutations)

    file(APPEND "${SIMD_MACROS_FILE_PATH}" "
    #ifdef NMATH_ENABLE_SIMD_I32X4
    ")

    # Utility functions
    file(APPEND "${SIMD_MACROS_FILE_PATH}" "
        NCPP_FORCE_INLINE F_simd_i32x4 make_simd_i32x4(i32 x, i32 y, i32 z, i32 w, i32 none = 0) noexcept {

        #ifdef NCPP_ENABLE_SSE2
            return _mm_set_epi32(w,z,y,x);
        #endif
        }
    ")

    # For constant defining
    file(APPEND "${SIMD_MACROS_FILE_PATH}" "#define NMATH_DEFINE_SIMD_I32X4_CONSTANTS() \\")
    foreach(permutation IN LISTS permutations)
        set(range_one_value ${permutation})
        string(REPLACE "1" "NMATH_I32_ONE," range_one_value ${range_one_value})
        string(REPLACE "0" "NMATH_I32_ZERO," range_one_value ${range_one_value})
        file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_i32x4 ${PARGS_PREFIX}${permutation} = make_simd_i32x4(${range_one_value}0);\\")
        
        if(NOT ${permutation} STREQUAL 0000)
            set(range_negative_one_value ${permutation})
            string(REPLACE "1" "NMATH_I32_ONE_NEGATIVE," range_negative_one_value ${range_negative_one_value})
            string(REPLACE "0" "NMATH_I32_ZERO," range_negative_one_value ${range_negative_one_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_i32x4 ${PARGS_PREFIX}${permutation}_negative = make_simd_i32x4(${range_negative_one_value}0);\\")
            
            string(REPLACE "1" "F" range_full_permutation ${permutation})
            set(range_full_value ${permutation})
            string(REPLACE "1" "NMATH_I32_FULL," range_full_value ${range_full_value})
            string(REPLACE "0" "NMATH_I32_ZERO," range_full_value ${range_full_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_i32x4 ${PARGS_PREFIX}${range_full_permutation} = make_simd_i32x4(${range_full_value}0);\\")
        endif()
    endforeach()

    file(APPEND "${SIMD_MACROS_FILE_PATH}" "\n")
    file(APPEND "${SIMD_MACROS_FILE_PATH}" "\n")

    # For declaration
    foreach(permutation IN LISTS permutations)
        file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_i32x4 ${PARGS_PREFIX}${permutation};\n")

        if(NOT ${permutation} STREQUAL 0000)   
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_i32x4 ${PARGS_PREFIX}${permutation}_negative;\n")

            string(REPLACE "1" "F" range_full_permutation ${permutation})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_i32x4 ${PARGS_PREFIX}${range_full_permutation};\n")            
        endif()
    endforeach()

    file(APPEND "${SIMD_MACROS_FILE_PATH}" "
    #else
    #define NMATH_DEFINE_SIMD_I32X4_CONSTANTS()
    #endif
    ")

endfunction()

function(NMath_DeclareSIMDConstants_f32x8)
    cmake_parse_arguments(
        PARGS
        ""
        "PREFIX;"
        ""
        ${ARGN}
    )

    if(NOT PARGS_PREFIX)
        message(FATAL "prefix must not be empty")
    endif()

    NMath_Permutations_8(permutations)

    file(APPEND "${SIMD_MACROS_FILE_PATH}" "
    #ifdef NMATH_ENABLE_SIMD_F32X8
    ")

    # Utility functions
    file(APPEND "${SIMD_MACROS_FILE_PATH}" "
        NCPP_FORCE_INLINE F_simd_f32x8 make_simd_f32x8(f32 x, f32 y, f32 z, f32 w, f32 x2, f32 y2, f32 z2, f32 w2, f32 none = 0.0f) noexcept {

        #ifdef NCPP_ENABLE_AVX
            return _mm256_set_ps(w2,z2,y2,x2, w,z,y,x);
        #endif
        }
    ")

    # For constant defining
    file(APPEND "${SIMD_MACROS_FILE_PATH}" "#define NMATH_DEFINE_SIMD_F32X8_CONSTANTS() \\")
    foreach(permutation IN LISTS permutations)
        set(range_one_value ${permutation})
        string(REPLACE "1" "NMATH_F32_ONE," range_one_value ${range_one_value})
        string(REPLACE "0" "NMATH_F32_ZERO," range_one_value ${range_one_value})
        file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation} = make_simd_f32x8(${range_one_value}0.0f);\\")

        if(NOT ${permutation} STREQUAL 00000000)  
            set(range_infinity_value ${permutation})
            string(REPLACE "1" "NMATH_F32_INFINITY," range_infinity_value ${range_infinity_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_infinity_value ${range_infinity_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_infinity = make_simd_f32x8(${range_infinity_value}0.0f);\\")

            set(range_negative_infinity_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_INFINITY," range_negative_infinity_value ${range_negative_infinity_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_negative_infinity_value ${range_negative_infinity_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_negative_infinity = make_simd_f32x8(${range_negative_infinity_value}0.0f);\\")

            set(range_pi_value ${permutation})
            string(REPLACE "1" "NMATH_F32_PI," range_pi_value ${range_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_pi_value ${range_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_pi = make_simd_f32x8(${range_pi_value}0.0f);\\")
            
            set(range_negative_pi_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_PI," range_negative_pi_value ${range_negative_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_negative_pi_value ${range_negative_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_negative_pi = make_simd_f32x8(${range_negative_pi_value}0.0f);\\")
            
            set(range_half_pi_value ${permutation})
            string(REPLACE "1" "NMATH_F32_HALF_PI," range_half_pi_value ${range_half_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_half_pi_value ${range_half_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_half_pi = make_simd_f32x8(${range_half_pi_value}0.0f);\\")
            
            set(range_negative_half_pi_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_HALF_PI," range_negative_half_pi_value ${range_negative_half_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_negative_half_pi_value ${range_negative_half_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_negative_half_pi = make_simd_f32x8(${range_negative_half_pi_value}0.0f);\\")
            
            set(range_two_pi_value ${permutation})
            string(REPLACE "1" "NMATH_F32_TWO_PI," range_two_pi_value ${range_two_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_two_pi_value ${range_two_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_two_pi = make_simd_f32x8(${range_two_pi_value}0.0f);\\")
            
            set(range_negative_two_pi_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_TWO_PI," range_negative_two_pi_value ${range_negative_two_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_negative_two_pi_value ${range_negative_two_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_negative_two_pi = make_simd_f32x8(${range_negative_two_pi_value}0.0f);\\")

            set(range_inv_pi_value ${permutation})
            string(REPLACE "1" "NMATH_F32_INV_PI," range_inv_pi_value ${range_inv_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_inv_pi_value ${range_inv_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_inv_pi = make_simd_f32x8(${range_inv_pi_value}0.0f);\\")

            set(range_inv_negative_pi_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_INV_PI," range_inv_negative_pi_value ${range_inv_negative_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_inv_negative_pi_value ${range_inv_negative_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_inv_negative_pi = make_simd_f32x8(${range_inv_negative_pi_value}0.0f);\\")

            set(range_inv_half_pi_value ${permutation})
            string(REPLACE "1" "NMATH_F32_INV_HALF_PI," range_inv_half_pi_value ${range_inv_half_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_inv_half_pi_value ${range_inv_half_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_inv_half_pi = make_simd_f32x8(${range_inv_half_pi_value}0.0f);\\")

            set(range_inv_negative_half_pi_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_INV_HALF_PI," range_inv_negative_half_pi_value ${range_inv_negative_half_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_inv_negative_half_pi_value ${range_inv_negative_half_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_inv_negative_half_pi = make_simd_f32x8(${range_inv_negative_half_pi_value}0.0f);\\")
            
            set(range_inv_two_pi_value ${permutation})
            string(REPLACE "1" "NMATH_F32_INV_TWO_PI," range_inv_two_pi_value ${range_inv_two_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_inv_two_pi_value ${range_inv_two_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_inv_two_pi = make_simd_f32x8(${range_inv_two_pi_value}0.0f);\\")

            set(range_inv_negative_two_pi_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_INV_TWO_PI," range_inv_negative_two_pi_value ${range_inv_negative_two_pi_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_inv_negative_two_pi_value ${range_inv_negative_two_pi_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_inv_negative_two_pi = make_simd_f32x8(${range_inv_negative_two_pi_value}0.0f);\\")
            
            set(range_negative_one_value ${permutation})
            string(REPLACE "1" "NMATH_F32_ONE_NEGATIVE," range_negative_one_value ${range_negative_one_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_negative_one_value ${range_negative_one_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_negative = make_simd_f32x8(${range_negative_one_value}0.0f);\\")
            
            string(REPLACE "1" "F" range_full_permutation ${permutation})
            set(range_full_value ${permutation})
            string(REPLACE "1" "NMATH_F32_FULL," range_full_value ${range_full_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_full_value ${range_full_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${range_full_permutation} = make_simd_f32x8(${range_full_value}0.0f);\\")

            set(range_half_value ${permutation})
            string(REPLACE "1" "NMATH_F32_HALF," range_half_value ${range_half_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_half_value ${range_half_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_half = make_simd_f32x8(${range_half_value}0.0f);\\")

            set(range_negative_half_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_HALF," range_negative_half_value ${range_negative_half_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_negative_half_value ${range_negative_half_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_negative_half = make_simd_f32x8(${range_negative_half_value}0.0f);\\")

            set(range_inv_half_value ${permutation})
            string(REPLACE "1" "NMATH_F32_INV_HALF," range_inv_half_value ${range_inv_half_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_inv_half_value ${range_inv_half_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_inv_half = make_simd_f32x8(${range_inv_half_value}0.0f);\\")

            set(range_inv_negative_half_value ${permutation})
            string(REPLACE "1" "-NMATH_F32_INV_HALF," range_inv_negative_half_value ${range_inv_negative_half_value})
            string(REPLACE "0" "NMATH_F32_ZERO," range_inv_negative_half_value ${range_inv_negative_half_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_f32x8 ${PARGS_PREFIX}${permutation}_inv_negative_half = make_simd_f32x8(${range_inv_negative_half_value}0.0f);\\")
        endif()
    endforeach()

    file(APPEND "${SIMD_MACROS_FILE_PATH}" "\n")
    file(APPEND "${SIMD_MACROS_FILE_PATH}" "\n")

    # For declaration
    foreach(permutation IN LISTS permutations)
        file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation};\n")

        if(NOT ${permutation} STREQUAL 00000000)   
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_infinity;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_negative_infinity;\n")

            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_pi;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_negative_pi;\n")

            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_half_pi;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_negative_half_pi;\n")

            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_two_pi;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_negative_two_pi;\n")

            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_inv_pi;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_inv_negative_pi;\n")
            
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_inv_half_pi;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_inv_negative_half_pi;\n")
            
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_inv_two_pi;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_inv_negative_two_pi;\n")
            
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_negative;\n")

            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_half;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_negative_half;\n")

            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_inv_half;\n")
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${permutation}_inv_negative_half;\n")

            string(REPLACE "1" "F" range_full_permutation ${permutation})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_f32x8 ${PARGS_PREFIX}${range_full_permutation};\n")            
        endif()
    endforeach()

    file(APPEND "${SIMD_MACROS_FILE_PATH}" "
    #else
    #define NMATH_DEFINE_SIMD_F32X8_CONSTANTS()
    #endif
    ")

endfunction()

function(NMath_DeclareSIMDConstants_i32x8)
    cmake_parse_arguments(
        PARGS
        ""
        "PREFIX;"
        ""
        ${ARGN}
    )

    if(NOT PARGS_PREFIX)
        message(FATAL "prefix must not be empty")
    endif()

    NMath_Permutations_8(permutations)

    file(APPEND "${SIMD_MACROS_FILE_PATH}" "
    #ifdef NMATH_ENABLE_SIMD_I32X8
    ")

    # Utility functions
    file(APPEND "${SIMD_MACROS_FILE_PATH}" "
        NCPP_FORCE_INLINE F_simd_i32x8 make_simd_i32x8(i32 x, i32 y, i32 z, i32 w, i32 x2, i32 y2, i32 z2, i32 w2, i32 none = 0) noexcept {

        #ifdef NCPP_ENABLE_AVX2
            return _mm256_set_epi32(w2,z2,y2,x2, w,z,y,x);
        #endif
        }
    ")

    # For constant defining
    file(APPEND "${SIMD_MACROS_FILE_PATH}" "#define NMATH_DEFINE_SIMD_I32X8_CONSTANTS() \\")
    foreach(permutation IN LISTS permutations)
        set(range_one_value ${permutation})
        string(REPLACE "1" "NMATH_I32_ONE," range_one_value ${range_one_value})
        string(REPLACE "0" "NMATH_I32_ZERO," range_one_value ${range_one_value})
        file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_i32x8 ${PARGS_PREFIX}${permutation} = make_simd_i32x8(${range_one_value}0);\\")
        
        if(NOT ${permutation} STREQUAL 00000000)  
            set(range_negative_one_value ${permutation})
            string(REPLACE "1" "NMATH_I32_ONE_NEGATIVE," range_negative_one_value ${range_negative_one_value})
            string(REPLACE "0" "NMATH_I32_ZERO," range_negative_one_value ${range_negative_one_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_i32x8 ${PARGS_PREFIX}${permutation}_negative = make_simd_i32x8(${range_negative_one_value}0);\\")
            
            string(REPLACE "1" "F" range_full_permutation ${permutation})
            set(range_full_value ${permutation})
            string(REPLACE "1" "NMATH_I32_FULL," range_full_value ${range_full_value})
            string(REPLACE "0" "NMATH_I32_ZERO," range_full_value ${range_full_value})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "\nconst F_simd_i32x8 ${PARGS_PREFIX}${range_full_permutation} = make_simd_i32x8(${range_full_value}0);\\")
        endif()
    endforeach()

    file(APPEND "${SIMD_MACROS_FILE_PATH}" "\n")
    file(APPEND "${SIMD_MACROS_FILE_PATH}" "\n")

    # For declaration
    foreach(permutation IN LISTS permutations)
        file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_i32x8 ${PARGS_PREFIX}${permutation};\n")

        if(NOT ${permutation} STREQUAL 00000000)   
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_i32x8 ${PARGS_PREFIX}${permutation}_negative;\n")

            string(REPLACE "1" "F" range_full_permutation ${permutation})
            file(APPEND "${SIMD_MACROS_FILE_PATH}" "extern const F_simd_i32x8 ${PARGS_PREFIX}${range_full_permutation};\n")            
        endif()
    endforeach()

    file(APPEND "${SIMD_MACROS_FILE_PATH}" "
    #else
    #define NMATH_DEFINE_SIMD_I32X8_CONSTANTS()
    #endif
    ")

endfunction()



#####################################################################################
#   Declare types
#####################################################################################
NMath_DeclareSIMDConstants_f32x4(
    PREFIX simd_f32x4_
)
NMath_DeclareSIMDConstants_i32x4(
    PREFIX simd_i32x4_
)

NMath_DeclareSIMDConstants_f32x8(
    PREFIX simd_f32x8_
)
NMath_DeclareSIMDConstants_i32x8(
    PREFIX simd_i32x8_
)



#####################################################################################
#   End of namespace
#####################################################################################
file(APPEND "${SIMD_MACROS_FILE_PATH}" "
}
")



message(STATUS "<NMath::SIMDMacos> Create SIMD macros done")