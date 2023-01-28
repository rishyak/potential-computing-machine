cmake_minimum_required(VERSION 3.25)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  include(FetchContent)
  FetchContent_Declare(
    vcpkg
    GIT_REPOSITORY https://github.com/microsoft/vcpkg.git
    GIT_TAG master
    GIT_SHALLOW TRUE
  )
  FetchContent_MakeAvailable(vcpkg)
  set(CMAKE_TOOLCHAIN_FILE
    ${vcpkg_SOURCE_DIR}/scripts/buildsystems/vcpkg.cmake
    CACHE FILEPATH "Vcpkg toolchain file"
  )
endif()

project(week-two-lab)

set(NYU_BUILD_TESTS TRUE)

find_package(nyu-cmake CONFIG REQUIRED)
find_package(Catch2 3 CONFIG REQUIRED)

nyu_setup_test(
  TEST_NAME exercise1
  TOP_MODULE Exercise1
  CPP_SOURCES dv/exercise1.cpp
  CPP_LIBS Catch2::Catch2WithMain
  SV_SOURCES rtl/Exercise1.sv
)

nyu_setup_test(
  TEST_NAME exercise2
  TOP_MODULE Exercise2
  CPP_SOURCES dv/exercise2.cpp
  CPP_LIBS Catch2::Catch2WithMain
  SV_SOURCES rtl/Exercise2.sv
)
target_compile_features(exercise2 PRIVATE cxx_std_20)

nyu_setup_test(
  TEST_NAME exercise3
  TOP_MODULE Exercise3
  CPP_SOURCES dv/exercise3.cpp
  CPP_LIBS Catch2::Catch2WithMain
  SV_SOURCES rtl/Exercise3.sv rtl/Mysteries/Mystery1.sv rtl/Mysteries/Mystery2.sv
)

nyu_setup_test(
  TEST_NAME exercise4
  TOP_MODULE Exercise4
  CPP_SOURCES dv/exercise4.cpp
  CPP_LIBS Catch2::Catch2WithMain
  SV_SOURCES rtl/Exercise4.sv
)
