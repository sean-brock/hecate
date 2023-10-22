
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "hecate/cpu_accelerator.hpp"

using namespace hecate;

TEST_CASE("Accelerate CPU kernel", "[main]") {
  CpuAccelerator accelerator;

  constexpr int num_inputs = 32;
  int *inputs =
      static_cast<int *>(accelerator.allocate(sizeof(int) * num_inputs));
  REQUIRE(accelerator.unified_memory());
  for (int i = 0; i < num_inputs; i++) {
    inputs[i] = 1;
  }
  int sum = 0;
  for (int i = 0; i < num_inputs; i++) {
    sum += inputs[i];
  }
  REQUIRE(sum == num_inputs);
  accelerator.free(inputs);
}
