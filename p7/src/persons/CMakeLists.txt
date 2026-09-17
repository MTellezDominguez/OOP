
add_library(persons persons.cc persons.h)


target_include_directories(persons PUBLIC ${CMAKE_CURRENT_LIST_DIR})


add_executable(persons-main persons-main.cc)
add_executable(irole-main irole-main.cc)

target_link_libraries(persons-main PUBLIC persons)
target_link_libraries(irole-main PUBLIC persons)
