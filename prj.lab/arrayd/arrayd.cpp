#include <arrayd/arrayd.hpp>

#include <stdexcept>
#include <cstring>

ArrayD::ArrayD(const ArrayD& rhs)
    : size_(rhs.size_), capacity_(rhs.size_) {
    data_ = new double[rhs.size_];
    for (int i = 0; i < rhs.size_; ++i) {
        *(data_ + i) = *(rhs.data_ + i);
    }
}

ArrayD::ArrayD(const ptrdiff_t size)
    : size_(size), capacity_(size) {
    if (size <= 0) {
        throw std::invalid_argument("Zero size isn`t allowed in ArrayD ctor");
    }
    data_ = new double[size] {0};
}


ArrayD& ArrayD::operator=(ArrayD const& rhs) {
    if (this != &rhs) {
        delete[] data_;
        size_ = rhs.size_;
        capacity_ = rhs.size_ /** 2*/;
        data_ = new double[capacity_] {};
        for (int i = 0; i < rhs.size_; i++) {
            data_[i] = rhs.data_[i];
        }
    }
    return *this;
}

ArrayD::~ArrayD() {
    delete[] data_;
    data_ = nullptr;
    capacity_ = 0;
}


void ArrayD::Resize(const std::ptrdiff_t size) {
    if (size < 0) {
        throw std::invalid_argument("Resizing by negative value");
    }
    if (size > capacity_) {
      
        auto new_data = new double[size] {};
        for (int i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_; 
        data_ = new_data;
        capacity_ = size; 
    }
    else {
     
        for (std::ptrdiff_t i = size; i < size_; ++i) {
            data_[i] = 0;
        }
    }
    size_ = size;
}




double& ArrayD::operator[](const std::ptrdiff_t idx) {
    if (idx >= size_ || idx < 0) {
        throw std::invalid_argument("ArrayD::operator[] - invalid argument");
    }
    return data_[idx];
}

const double& ArrayD::operator[](const std::ptrdiff_t idx) const {
    if (idx >= size_ || idx < 0) {
        throw std::invalid_argument("ArrayD::operator[] - invalid argument");
    }
    return data_[idx];
}

ArrayD& ArrayD::operator=(ArrayD&& rhs) noexcept {
    if (this != &rhs) {
        std::swap(size_, rhs.size_);
        std::swap(capacity_, rhs.capacity_);
        std::swap(data_, rhs.data_);
        rhs.data_ = nullptr;
    }
    return *this;
}


void ArrayD::Insert(const std::ptrdiff_t idx, const double val) {
    if (idx > size_ || idx < 0) {
        throw std::invalid_argument("ArrayD::Insert - invalid argument");
    }

  
    if (size_ == capacity_) {
       
        std::ptrdiff_t new_capacity;
        if (capacity_ == 0) {
            new_capacity = 1;
        }
        else {
            new_capacity = capacity_ * 2;
        }
        double* new_data = new double[new_capacity] {};

        
        for (std::ptrdiff_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }


        delete[] data_;       
        data_ = new_data;     
        capacity_ = new_capacity; 
    }

    for (std::ptrdiff_t i = size_; i > idx; --i) {
        data_[i] = data_[i - 1];
    }

    
    data_[idx] = val;
    ++size_;
}


void ArrayD::Remove(const std::ptrdiff_t idx) {
    if (size_ == 0) {
        throw std::underflow_error("ArrayD::Remove - cannot remove from an empty array");
    }
    if (idx >= size_ || idx < 0) {
        throw std::invalid_argument("ArrayD::Remove - invalid argument");
    }
    if (idx != size_ - 1) {
        for (std::ptrdiff_t i = idx; i < size_ - 1; i++) {
            data_[i] = data_[i + 1];

        }
    }


}
