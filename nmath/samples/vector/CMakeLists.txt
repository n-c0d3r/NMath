
# nmath.samples.vector target source files
file(GLOB source_files
    "source/*.cpp"
    "source/*.hpp"
)
source_group("source" FILES ${source_files})



# Create nmath.samples.vector target
add_executable(nmath.samples.vector
    ${source_files}
)



# nmath.samples.vector target settings
set_target_properties(nmath.samples.vector
    PROPERTIES 
        FOLDER "NCoder/nmath/samples"
        PROJECT_LABEL "vector"
)
target_link_libraries(nmath.samples.vector
    PUBLIC 
        nmath
)
target_include_directories(nmath.samples.vector
    PUBLIC 
        nmath
        ${CMAKE_CURRENT_SOURCE_DIR}/source
)



# nmath.samples.vector target dependencies
add_dependencies(nmath.samples.vector 
    nmath
)