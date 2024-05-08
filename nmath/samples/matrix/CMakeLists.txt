
# nmath.samples.matrix target source files
file(GLOB source_files
    "source/*.cpp"
    "source/*.hpp"
)
source_group("source" FILES ${source_files})



# Create nmath.samples.matrix target
add_executable(nmath.samples.matrix
    ${source_files}
)



# nmath.samples.matrix target settings
set_target_properties(nmath.samples.matrix
    PROPERTIES 
        FOLDER "NCoder/nmath/samples"
        PROJECT_LABEL "matrix"
)
target_link_libraries(nmath.samples.matrix
    PUBLIC 
        nmath
)
target_include_directories(nmath.samples.matrix
    PUBLIC 
        nmath
        ${CMAKE_CURRENT_SOURCE_DIR}/source
)



# nmath.samples.matrix target dependencies
add_dependencies(nmath.samples.matrix 
    nmath
)