
message(STATUS "<NMath::CheckNCPP> Start checking NCPP")



#####################################################################################
#   Main checkings
#####################################################################################
# check for ncpp
if(NOT TARGET ncpp)
    if(NOT EXISTS "${NMATH_SUBMODULES_DIR}/NCPP")
        if(WIN32)
            execute_process(COMMAND "${NMATH_SCRIPTS_DIR}/check_submodules.bat")
        elseif(UNIX)
            execute_process(COMMAND "${NMATH_SCRIPTS_DIR}/check_submodules.sh")
        endif()
    endif()    
endif()



message(STATUS "<NMath::CheckNCPP> Check NCPP done")