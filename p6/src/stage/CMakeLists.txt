
add_library(stage stage.cc stage.h)


target_link_libraries(stage catalog persons)


target_include_directories(stage PUBLIC ${CMAKE_CURRENT_LIST_DIR})


add_executable(stage-main stage-main.cc)


target_link_libraries(stage-main PUBLIC stage catalog persons)