#pragma once
#ifndef ARRAYT_HPP
#define ARRAYT_HPP

#include <cstdint>
#include <iosfwd>
#include <cstddef>
#include <stdexcept>
#include <memory>  
#include <algorithm> 



template <class T>
class ArrayT {
public :

    // Конструктор по умолчанию
    ArrayT() = default;

    // Конструктор с начальным размером
    ArrayT(std::size_t size);

    // Копирующий конструктор
    ArrayT(const ArrayT& other);

  //   Перемещающий конструктор
    ArrayT(ArrayT&& other) noexcept;

    // Оператор присваивания (копирование)
    ArrayT& operator=(const ArrayT& other);

    // Оператор присваивания (перемещение)
    ArrayT& operator=(ArrayT&& other) noexcept;

    ~ArrayT();

    // Доступ по индексу
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;


    // Вставка элемента
    void Insert(std::size_t index, const T& value);

    // Удаление элемента
    void Remove(std::size_t index);

    // Изменение размера массива
    void Resize(std::size_t new_size);

    // Получение размера
    std::size_t Size() const;

    // Получение вместимости
    std::size_t Capacity() const;

private:
    std::ptrdiff_t capacity_ = 0;  //!< размер буффера
    std::ptrdiff_t size_ = 0;      //!< число элементов в массиве
    std::unique_ptr<T[]> data_;    


};

// Конструктор с начальным размером
template <class T>
ArrayT<T>::ArrayT(std::size_t size)
    : size_(size), capacity_(size), data_(std::make_unique<T[]>(size)) {}

// Копирующий конструктор
template <class T>
ArrayT<T>::ArrayT(const ArrayT& other)
    : size_(other.size_), capacity_(other.capacity_), data_(std::make_unique<T[]>(other.capacity_)) {
    std::copy(other.data_.get(), other.data_.get() + other.size_, data_.get());
}

// Перемещающий конструктор
template <class T>
ArrayT<T>::ArrayT(ArrayT&& other) noexcept
    : data_(std::move(other.data_)), size_(other.size_), capacity_(other.capacity_) {
    other.size_ = 0;
    other.capacity_ = 0;
}

// Оператор присваивания (копирование)
template <class T>
ArrayT<T>& ArrayT<T>::operator=(const ArrayT& other) {
    if (this != &other) {
        data_ = std::make_unique<T[]>(other.capacity_);
        size_ = other.size_;
        capacity_ = other.capacity_;
        std::copy(other.data_.get(), other.data_.get() + other.size_, data_.get());
    }
    return *this;
}

// Оператор присваивания (перемещение)
template <class T>
ArrayT<T>& ArrayT<T>::operator=(ArrayT&& other) noexcept {
    if (this != &other) {
        data_ = std::move(other.data_);
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

// Деструктор
template <class T>
ArrayT<T>::~ArrayT() {
    // В данном случае ничего делать не нужно, так как std::unique_ptr сам освобождает память.
    data_.reset();
}

// Доступ по индексу
template <class T>
T& ArrayT<T>::operator[](std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template <class T>
const T& ArrayT<T>::operator[](std::size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}


// Вставка элемента
template <class T>
void ArrayT<T>::Insert(std::size_t index, const T& value) {
    if (index > size_) {
        throw std::out_of_range("Index out of range");
    }
    if (size_ == capacity_) {
        std::size_t new_capacity;
        if (size_ == 0) {
            new_capacity = 1;
        }
        else {
            new_capacity = capacity_ * 2;
        }
        Resize(new_capacity);
    }
    std::copy_backward(data_.get() + index, data_.get() + size_, data_.get() + size_ + 1);
    data_[index] = value;
    ++size_;
}

// Удаление элемента
template <class T>
void ArrayT<T>::Remove(std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    std::copy(data_.get() + index + 1, data_.get() + size_, data_.get() + index);
    --size_;
}

// Изменение размера массива
template <class T>
void ArrayT<T>::Resize(std::size_t new_size) {
    if (new_size > capacity_) {
        auto new_data = std::make_unique<T[]>(new_size);
        if (data_) {
            std::copy(data_.get(), data_.get() + size_, new_data.get());
        }
        data_ = std::move(new_data);
        capacity_ = new_size;
    }
    if (new_size > size_) {
        std::fill(data_.get() + size_, data_.get() + new_size, T{});
    }
    size_ = new_size;
}

// Получение размера
template <class T>
std::size_t ArrayT<T>::Size() const {
    return size_;
}

// Получение вместимости
template <class T>
std::size_t ArrayT<T>::Capacity() const {
    return capacity_;
}



#endif 





