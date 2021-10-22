#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
    SimpleVector() {
        data = nullptr;
        end_ = nullptr;
        size_ = 0;
        cap = 0;
    }

    explicit SimpleVector(size_t size) {
        data = new T[size];
        end_ = data + size;
        size_ = size;
        cap = size;
    }
    ~SimpleVector() {
        delete[] data;
    }

    T& operator[](size_t index) { return data[index]; }

    T* begin() { return data; }
    T* end() { return end_; }
    const T* begin() const { return data; }
    const T* end() const { return end_; }

    size_t Size() const {
        return size_;
    }

    size_t Capacity() const {
        return cap;
    }

    void PushBack(const T& value) {
        if(cap == 0) {
            data = new T[1];
            end_ = data + 1;
            size_ = 1;
            *data = value;
            cap = 1;
        } else {
            if(size_ == cap) {
                T* new_data = new T[cap * 2];
                for(size_t i = 0; i < cap; ++i) {
                    new_data[i] = data[i];
                }
                delete[] data;
                data = new_data;
                end_ = new_data + size_;
                cap *= 2;
            }
            data[size_] = value;
            ++size_;
            ++end_;
        }
    }

private:
    T* data;
    T* end_;
    size_t size_;
    size_t cap;
};
