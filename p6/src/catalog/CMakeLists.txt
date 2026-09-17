
add_library(catalog catalog.cc catalog.h)


target_link_libraries(catalog persons)


target_include_directories(catalog PUBLIC ${CMAKE_CURRENT_LIST_DIR})


add_executable(catalog-main catalog-main.cc)
add_executable(catalog-main2 catalog-main2.cc)

target_link_libraries(catalog-main PUBLIC catalog persons)
target_link_libraries(catalog-main2 PUBLIC catalog persons)


