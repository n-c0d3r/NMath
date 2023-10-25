
# nmath.samples.rvector target source files
file(GLOB source_files
    "source/*.cpp"
    "source/*.hpp"
)
source_group("source" FILES ${source_files})



# Create nmath.samples.rvector target
add_executable(nmath.samples.rvector
    ${source_files}
)



# nmath.samples.rvector target settings
set_target_properties(nmath.samples.rvector
    PROPERTIES 
        FOLDER "nmath/samples"
        PROJECT_LABEL "rvector"
)
target_link_libraries(nmath.samples.rvector
    PUBLIC 
        nmath
)
target_include_directories(nmath.samples.rvector
    PUBLIC 
        nmath
        ${CMAKE_CURRENT_SOURCE_DIR}/source
)



# nmath.samples.rvector target dependencies
add_dependencies(nmath.samples.rvector 
    nmath
)