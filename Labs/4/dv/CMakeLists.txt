find_package(Catch2 3 REQUIRED CONFIG)
find_package(nyu-util REQUIRED CONFIG)

add_executable(tests)
target_sources(tests PRIVATE exercise1.cpp exercise2.cpp exercise3.cpp exercise4.cpp)

nyu_link_sv(tests PRIVATE lab4)

nyu_target_verilate(tests 
 TOP_MODULES Exercise1 Exercise2 Exercise3 Exercise4
 ARGS COVERAGE
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain nyu::covrecorder)
target_compile_features(tests PRIVATE cxx_std_23)

include(Catch)
catch_discover_tests(tests)
