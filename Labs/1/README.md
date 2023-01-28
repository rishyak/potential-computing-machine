# Toolchains
## Notes
- cmake version 3.25.2
- Makefile targets:
  - **all:** Creates everything for a complete build
  - **clean**: Deletes generated files (object files, executables, etc.)
  - **depend**: Generate dependencies of source files
  - **edit_cache**: Runs CMakeSetup
  - **rebuild_cache**: Regenerates build system
  - **hello_world**: Creates hello_world executable
  - **hello.o:** Creates object file
  - **hello.i:** Creates visual studio intermediate file
  - **hello.s:** Creates assembly file

## Answers
1. **The paths used by `target_sources` and `target_include_directories` are relative, not absolute. What file or folder are they relative to?**
   - Location of CMK

2. **What some differences between `cmake` and `ninja`?**
   - CMake is a build system generator
   - Ninja is a build system
   - CMake generates Ninja
   - Ninja generates final executables

3. **Why is it important to run `cmake` in its own directory?**
   - To avoid polluting source code directory with cmake crap
