
# nmath.samples.hello_nmath target source files
file(GLOB source_files
    "source/*.cpp"
    "source/*.hpp"
)
source_group("source" FILES ${source_files})



# Create nmath.samples.hello_nmath target
add_executable(nmath.samples.hello_nmath
    ${source_files}
)



# nmath.samples.hello_nmath target settings
set_target_properties(nmath.samples.hello_nmath
    PROPERTIES 
        FOLDER "NCoder/nmath/samples"
        PROJECT_LABEL "hello_nmath"
)
target_link_libraries(nmath.samples.hello_nmath
    PUBLIC 
        nmath
)
target_include_directories(nmath.samples.hello_nmath
    PUBLIC 
        nmath
        ${CMAKE_CURRENT_SOURCE_DIR}/source
)



# nmath.samples.hello_nmath target dependencies
add_dependencies(nmath.samples.hello_nmath 
    nmath
)