# GTest include code for fetch content over the internet 
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.17.0
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)
# End GTest include code

# Testing persons library
add_executable(persons-test persons-test.cc)
# --- AÑADIDO: Dónde encontrar persons.h ---
target_include_directories(persons-test
  PRIVATE
    ../src/persons
)
target_link_libraries(persons-test
  PRIVATE GTest::gtest_main persons)
gtest_discover_tests(persons-test)

# Testing catalog library
add_executable(catalog-test catalog-test.cc)
# --- AÑADIDO: Dónde encontrar catalog.h y persons.h ---
target_include_directories(catalog-test
  PRIVATE
    ../src/catalog
    ../src/persons
)
target_link_libraries(catalog-test
  PRIVATE GTest::gtest_main catalog)
gtest_discover_tests(catalog-test)

# --- AÑADIDO: Bloque entero para el test de Stage ---
# Testing stage library
add_executable(stage-test stage-test.cc)
# --- AÑADIDO: Dónde encontrar stage.h, catalog.h y persons.h ---
target_include_directories(stage-test
  PRIVATE
    ../src/stage
    ../src/catalog
    ../src/persons
)
target_link_libraries(stage-test
  PRIVATE GTest::gtest_main stage)
gtest_discover_tests(stage-test)

# --- AÑADIDO: Bloque entero para el test de GCList ---
# Testing stage library
add_executable(gclist-test gclist-test.cc)
# --- AÑADIDO: Dónde encontrar gclist.h, stage.h, catalog.h y persons.h ---
target_include_directories(gclist-test
  PRIVATE
    ../src/gclist
    ../src/stage
    ../src/catalog
    ../src/persons
)
target_link_libraries(gclist-test
  PRIVATE GTest::gtest_main gclist)
gtest_discover_tests(gclist-test)

# --- AÑADIDO: Bloque entero para el test de Counter ---
# Testing stage library
add_executable(counter-test counter-test.cc)
# --- AÑADIDO: Dónde encontrar counter.h, gclist.h, stage.h, catalog.h y persons.h ---
target_include_directories(counter-test
  PRIVATE
    ../src/counter
    ../src/gclist
    ../src/stage
    ../src/catalog
    ../src/persons
)
target_link_libraries(counter-test
  PRIVATE GTest::gtest_main counter)
gtest_discover_tests(counter-test)