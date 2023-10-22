#include "hecate/accelerator.hpp"

#include <loguru.hpp>
#include <string>
using namespace hecate;

void *Accelerator::allocate(std::size_t n) {
  void *mem = allocate_impl(n);
  auto result = _allocated.insert(mem);
  CHECK_F(result.second, "Allocator returned duplicate address.");
  return mem;
}

void Accelerator::free(void *mem) noexcept {
  auto found = _allocated.find(mem);
  CHECK_F(found != _allocated.cend(), "Attempted to free unallocated address.");
  free_impl(mem);
  _allocated.erase(found);
}

Accelerator::~Accelerator() {
  LOG_IF_F(WARNING, _allocated.size() > 0,
           "Accelerator memory not-empty. Possible memory leak.");
}
