#ifndef HECATE_ACCELERATOR_HPP
#define HECATE_ACCELERATOR_HPP

#include <cstddef>
#include <set>
namespace hecate {

class Accelerator {
 public:
  Accelerator(bool unifed_memory_enabled = false)
      : _unified_memory(unifed_memory_enabled) {}
  void *allocate(std::size_t n);
  void free(void *mem) noexcept;
  virtual void memset(void *start, int c, std::size_t n) = 0;
  virtual void memcpy_htod(void *dev_dest, const void *host_src,
                           std::size_t n) = 0;
  virtual void memcpy_dtod(void *dev_dest, const void *dev_src,
                           std::size_t n) = 0;
  virtual void memcpy_dtoh(void *host_dest, const void *dev_src,
                           std::size_t n) = 0;
  virtual ~Accelerator();
  inline bool unified_memory() const { return _unified_memory; }

 protected:
  virtual void *allocate_impl(std::size_t n) = 0;
  virtual void free_impl(void *mem) = 0;
  std::set<void *> _allocated;

 private:
  const bool _unified_memory;
};

};  // namespace hecate

#endif
