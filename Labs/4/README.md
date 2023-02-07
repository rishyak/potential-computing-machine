# Advanced Verification

## Answers
1. What is a registry?
   - Stores information on packages such as location, version, and other metadata

2. What is a package?
   - Additional code you wish to use in a project.
   - Typically includes behaviours that you wish to have (such as verilator or numpy)

3. What’s the difference between an interface library and a “normal” library
   or executable? Can you think of any uses for this besides System Verilog 
   files? (Think about source code used for generic programming)
   - Interface libraries have source code that may not be available on compilation 
   - Hence cannot be compiled immediately
   - I'm not sure what "generic programming" examples exist
   - But, I know that header-only libraries (like boost or catch2) are often used as as interface libraries
   - > Templates! You can't compile a template before some code provides an instantiation, a monomorphization of it (or, well, you can't completely compile it). Template libraries are always distributed as pure source code ("header-only"), so they're always interface libraries.

4. What is a top module?
   - Modules that we expose for simulation
