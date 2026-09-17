add_library(gclist gclist.cc gclist.h)
target_link_libraries(gclist stage catalog persons)

target_include_directories(gclist PUBLIC ${CMAKE_CURRENT_LIST_DIR})


add_executable(gclist-main1 gclist-main1.cc)
add_executable(gclist-main2 gclist-main2.cc)


target_link_libraries(gclist-main1 PUBLIC gclist stage catalog persons)
target_link_libraries(gclist-main2 PUBLIC gclist stage catalog persons)