
# nmath.samples.cvector target source files
file(GLOB source_files
    "source/*.cpp"
    "source/*.hpp"
)
source_group("source" FILES ${source_files})



# Create nmath.samples.cvector target
add_executable(nmath.samples.cvector
    ${source_files}
)



# nmath.samples.cvector target settings
set_target_properties(nmath.samples.cvector
    PROPERTIES 
        FOLDER "nmath/samples"
        PROJECT_LABEL "cvector"
)
target_link_libraries(nmath.samples.cvector
    PUBLIC 
        nmath
)
target_include_directories(nmath.samples.cvector
    PUBLIC 
        nmath
        ${CMAKE_CURRENT_SOURCE_DIR}/source
)



# nmath.samples.cvector target dependencies
add_dependencies(nmath.samples.cvector 
    nmath
)