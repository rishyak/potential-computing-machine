cmake_minimum_required(VERSION 3.25)

project(week-one-lab VERSION 1.0.0)

# message("Hello world")

add_executable(hello_world)
target_sources(hello_world PRIVATE hello.cpp)

