#include "stackc/stackc.hpp"

#include <stdexcept>
#include <algorithm>
#include <memory>
#include <stdexcept>

stackc::~stackc() {
	delete[] data_;
	data_ = nullptr;
	size_ = 0;
	inhead_ = 0;
}

void stackc::Pop() noexcept {
	if (inhead_ != 0) {
		inhead_ -= 1;
	}
}

bool stackc::IsEmpty() noexcept {
	return inhead_ == 0;
}
void stackc::Clear() noexcept {
	inhead_ = 0;
}
void stackc::Push(const numbers& x) {
	//метод добавления элемента
}
