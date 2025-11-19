project(SandBox)

add_executable(SandBox
    src/SandBox.cpp
)

target_include_directories(SandBox PUBLIC ${HAZEL_CORE_INCLUDE})

target_link_libraries(SandBox PRIVATE HazelCore)
target_compile_definitions(SandBox PRIVATE WINDOWS)


add_custom_command(TARGET SandBox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:HazelCore>
        $<TARGET_FILE_DIR:SandBox>
)
