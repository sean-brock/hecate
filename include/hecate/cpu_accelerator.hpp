#ifndef HECATE_CPU_ACCELERATOR_H
#define HECATE_CPU_ACCELERATOR_H

#include <cstdlib>
#include <cstring>

#include "accelerator.hpp"

namespace hecate {

class CpuAccelerator : public Accelerator {
 public:
  CpuAccelerator() : Accelerator(true) {}
  inline void memset(void *start, int c, std::size_t n) noexcept override {
    std::memset(start, c, n);
  }
  inline void memcpy_htod(void *dev_dest, const void *host_src,
                          std::size_t n) noexcept override {
    std::memcpy(dev_dest, host_src, n);
  }
  inline void memcpy_dtod(void *dev_dest, const void *dev_src,
                          std::size_t n) noexcept override {
    std::memcpy(dev_dest, dev_src, n);
  }
  inline void memcpy_dtoh(void *host_dest, const void *dev_src,
                          std::size_t n) noexcept override {
    std::memcpy(host_dest, dev_src, n);
  }
  virtual ~CpuAccelerator() noexcept;

 private:
  inline void *allocate_impl(std::size_t n) noexcept override {
    return std::malloc(n);
  }
  inline void free_impl(void *mem) noexcept override { std::free(mem); }
};

};  // namespace hecate
#endif
