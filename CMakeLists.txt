cmake_minimum_required(VERSION 3.12)



#####################################################################################
#   Project NMATH
#####################################################################################
project(nmath)



#####################################################################################
#   CMake module
#####################################################################################
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")



#####################################################################################
#   Local variables
#####################################################################################
set(NMATH_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(NMATH_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(NMATH_SCRIPTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/scripts")
set(NMATH_SUBMODULES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/submodules")
set(NMATH_CMAKE_MODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(NMATH_DEPENDENCIES_DIR "${CMAKE_CURRENT_BINARY_DIR}/dependencies")
set(NMATH_GENERATED_FILES_DIR "${CMAKE_CURRENT_BINARY_DIR}/nmath/generated_files/nmath")
set(NMATH_THIRD_PARTY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party")



#####################################################################################
#   Setup NCPP
#####################################################################################
include(NMath/CheckNCPP)
include(NMath/ConfigureNCPP)



#####################################################################################
#   Dependencies
#####################################################################################
include(NMath/CheckDependencies)
include(NMath/ConfigureDependencies)



#####################################################################################
#   Version
#####################################################################################
include(NCPP/Utilities/VersionHelper)
NCPP_VersionHelper_CreateVersionMacros(
    PROJECT_NAME NMATH
    OUTPUT_FILE "${NMATH_GENERATED_FILES_DIR}/version.hpp"
    MAJOR 0
    MINOR 1
    PATCH 2
)



#####################################################################################
#   Global variables
#####################################################################################
include(NCPP/Utilities/ApplyGlobal)
NCPP_ApplyGlobal(
    NMATH_ROOT_DIR
    NMATH_BINARY_DIR
    NMATH_SCRIPTS_DIR
    NMATH_SUBMODULES_DIR
    NMATH_CMAKE_MODULE_DIR 
    NMATH_DEPENDENCIES_DIR 
    NMATH_GENERATED_FILES_DIR
)



#####################################################################################
#   Documentations
#####################################################################################
option(NMATH_ENABLE_DOCUMENTATIONS "If enabled, creating a target being capable of generating documentations" OFF)
if(NMATH_ENABLE_DOCUMENTATIONS)
    option(NMATH_INTERNAL_DOCS "Generate docs for anything" OFF)

    include(NCPP/Utilities/DocsHelper)

    NCPP_DocsHelper_CreateTarget(
        NAME NMATH
        BRIEF "Ncoder's Learning Aimed C++ Surface Library."

        TARGET_NAME nmath.documentations
        TARGET_FOLDER nmath
        TARGET_LABEL documentations

        INPUT_DIRS 
            "${CMAKE_CURRENT_SOURCE_DIR}/nmath/source"
            "${CMAKE_CURRENT_SOURCE_DIR}/documentations"
            "${CMAKE_CURRENT_SOURCE_DIR}/README.md"
        STYLE_DIRS
            "${CMAKE_CURRENT_SOURCE_DIR}/documentations/styles"
        OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/documentations"
        CWD "${CMAKE_CURRENT_SOURCE_DIR}"
        INTERNAL_DOCS ${NMATH_INTERNAL_DOCS}

        PREDEFINED 
            ${NCPP_DOCUMENTATIONS_PREDEFINED}

        MAIN_PAGE "${CMAKE_CURRENT_SOURCE_DIR}/README.md"
    )
endif()



#####################################################################################
#   Add main directory
#####################################################################################
add_subdirectory(nmath)



include(CPack)