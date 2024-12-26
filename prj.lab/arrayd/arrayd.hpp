#pragma once
#ifndef ARRAYD_HPP
#define ARRAYD_HPP

#include <cstdint>
#include <iosfwd>
#include <cstddef>
#include <stdexcept>

class ArrayD {
 public : 
   ArrayD() = default;

   ArrayD(const ArrayD&);

   ArrayD(const std::ptrdiff_t size);

   ~ArrayD();

   std::ptrdiff_t Size() const noexcept { return size_; }


   ArrayD& operator=(const ArrayD& dynarr);
   ArrayD& operator=(ArrayD&& rhs) noexcept;


   [[nodiscard]] double& operator[](const std::ptrdiff_t idx);
   [[nodiscard]] const double& operator[](const std::ptrdiff_t idx) const;

   void Resize(const std::ptrdiff_t size);


   void Insert(const std::ptrdiff_t idx, const double val);

  
   void Remove(const std::ptrdiff_t idx);

 private:
  std::ptrdiff_t capacity_ = 0; 
  std::ptrdiff_t size_ = 0;      
  double* data_ = 0;
};





#endif
