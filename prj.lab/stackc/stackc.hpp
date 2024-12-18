ifndef STACKC_HPP
#define STACKC_HPP


#include <cstddef>
#include <stdexcept>
#include <utility>

class StackC {
private:
	std::ptrdiff_t size_ = 0;
	std::ptrdiff_t inhead_ = 0;
	numbers* data_ = nullptr;
public:
	[[nodiscard]] StackC() = default;
	[[nodiscard]] StackC(const StackC& copy);
	StackC(StackC&& copy) noexcept;
	~StackC();
  //
};
#endif
