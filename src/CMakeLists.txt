add_executable(buffer_pio)
pico_generate_pio_header(buffer_pio ${CMAKE_CURRENT_LIST_DIR}/buffer.pio)
target_sources(buffer_pio PRIVATE buffer.cpp)

target_link_libraries(buffer_pio PRIVATE
        pico_stdlib
        hardware_pio
        )
pico_add_extra_outputs(buffer_pio)