
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <hecate/hipcpu.hpp>

TEST_CASE("Accelerate HIP CPU kernel", "[main]") { 
  HipCPUAccelerator accelerator;

  constexpr int num_inputs = 32;
  int *inputs = nullptr;

  REQUIRE_NOTHROW([&](){
    inputs = accelerator.allocate<int>(num_inputs * 2));
  }());
  REQUIRE_NOTHROW(accelerator.memset(mem, sizeof(int) * num_inputs * 2, 0));



}
