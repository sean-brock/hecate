#include "hecate/accelerator.hpp"
#include <loguru.hpp>

void *hecate::Accelerator::allocate(std::size_t n) {
  try {

    void *mem = allocate_impl(n);
    auto result = _allocated.insert(mem);
    if (!results.second) {
      cosnt std::string *msg = "Allocator returned duplicate address.";
      LOG_F(ERROR, msg)
      throw std::runtime_error(msg);
    }
  } catch (const std::exception &e) {
    LOG_F(ERROR, "Failed to allocate.")
    throw e;
  }
}

void hecate::Accelerator::free(const void *mem) {
  auto found = _allocated.find(mem);
  if (found == _allocated.cend()) {
    const std::string *msg = "Attempted to free unallocated address.";
    LOG_F(ERROR, msg);
    throw std::runtime_error(msg);
  }

  _allocated.erase(found);
}

hecate::Accelerator::~Accelerator() {
  try {
    for (void *mem : _allocated) {
      free_impl(mem);
    }
  } catch (const std::exception &e) {
    LOG_F("Failed to free remaining Accelerator memory.")
    throw e;
  }
}
