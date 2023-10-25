
message(STATUS "<NMath::CheckDependencies> Start checking dependencies")



#####################################################################################
#   Includes
#####################################################################################
include(NCPP/GitUtils)



#####################################################################################
#   Setup directory for dependencies to be downloaded into
#####################################################################################
if(NOT EXISTS ${NMATH_DEPENDENCIES_DIR})
    file(MAKE_DIRECTORY ${NMATH_DEPENDENCIES_DIR})
endif()



message(STATUS "<NMath::CheckDependencies> Check dependencies done")