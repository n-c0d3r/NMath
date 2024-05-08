
# nmath.samples.quaternion target source files
file(GLOB source_files
    "source/*.cpp"
    "source/*.hpp"
)
source_group("source" FILES ${source_files})



# Create nmath.samples.quaternion target
add_executable(nmath.samples.quaternion
    ${source_files}
)



# nmath.samples.quaternion target settings
set_target_properties(nmath.samples.quaternion
    PROPERTIES 
        FOLDER "NCoder/nmath/samples"
        PROJECT_LABEL "quaternion"
)
target_link_libraries(nmath.samples.quaternion
    PUBLIC 
        nmath
)
target_include_directories(nmath.samples.quaternion
    PUBLIC 
        nmath
        ${CMAKE_CURRENT_SOURCE_DIR}/source
)



# nmath.samples.quaternion target dependencies
add_dependencies(nmath.samples.quaternion 
    nmath
)