#ifndef HECATE_ACCELERATOR_HPP
#define HECATE_ACCELERATOR_HPP

namespace hecate {

class Accelerator {

public:
  void *allocate(std::size_t n);
  void free(const void *mem);
  virtual void memset(void *start, int c, std::size_t n) == 0;
  virtual void memcpy(void *dest, const void *src, std::size_t n) == 0;

protected:
  virtual void *allocate_impl(std::size_t n) == 0;
  virtual void free_impl(const void *mem) == 0;

private:
  ~Accelerator();
  std::set<void *> _allocated;
};

}; // namespace hecate

#endif
