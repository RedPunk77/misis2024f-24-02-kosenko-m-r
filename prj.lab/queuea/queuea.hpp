#pragma once
#ifndef QUEUEA_HPP
#define QUEUEA_HPP
#include <cstddef>
#include <cstdint>


class QueueA {
public:
  using T = std::uint8_t;
  QueueA() = default;

  QueueA(const QueueA& src);

  QueueA(QueueA&& src);

  ~QueueA();

  QueueA& operator=(const QueueA& src);

  QueueA& operator=(QueueA&& src);

  bool IsEmpty() const;

  void Pop();

  void Push(const T val);

  T& Top();

  const T& Top() const;

  void Clear();

private:
  std::ptrdiff_t size_ = 0;   
  T* data_ = nullptr;         
  std::ptrdiff_t head_ = -1;  
  std::ptrdiff_t tail_ = -1;  
private:
  std::ptrdiff_t Count() const;
  void Swap(QueueA&& src);
};

#endif
