# Testing library
FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.6)
FetchContent_MakeAvailable(catch)

# Tests need to be added as executables first
add_executable(hipcpu test_hipcpu.cpp)
target_compile_features(hipcpu PRIVATE cxx_std_20)
# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(hipcpu PRIVATE hip_cpu_rt::hip_cpu_rt Catch2::Catch2)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME test_hipcpu COMMAND hipcpu) # Command can be a target
