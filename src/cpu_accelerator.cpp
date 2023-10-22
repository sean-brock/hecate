#include "hecate/cpu_accelerator.hpp"
using namespace hecate;

CpuAccelerator::~CpuAccelerator() noexcept {
  for (void *mem : _allocated) {
    free(mem);
  }
}
