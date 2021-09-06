#pragma once

#include <vector>
#include <stdexcept>

template<typename T>
class Deque {
public:
    Deque(){

    }
    bool Empty() const {
        return front.empty() && back.empty();
    }
    size_t Size() const {
        return front.size() + back.size();
    }
    T& operator[](size_t index) {
        if(index < front.size()) {
            return front[front.size() - index - 1];
        }
        return back[index - front.size()];
    }
    const T& operator[](size_t index) const {
        if(index < front.size()) {
            return front[front.size() - index - 1];
        }
        return back[index - front.size()];
    }
    T& At(size_t index) {
        if(index < front.size()) {
            return front[front.size() - index - 1];
        } else if(index < front.size() + back.size()) {
            return back[index - front.size()];
        } else {
            throw std::out_of_range("error");
        }
    }
    const T& At(size_t index) const {
        if(index < front.size()) {
            return front[front.size() - index - 1];
        } else if(index < front.size() + back.size()) {
            return back[index - front.size()];
        } else {
            throw std::out_of_range("error");
        }
    }
    T& Front() {
        if(front.empty()) {
            return back.front();
        }
        return front.back();
    }
    const T& Front() const {
        if(front.empty()) {
            return back.front();
        }
        return front.back();
    }
    T& Back() {
        if(back.empty()) {
            return front.front();
        }
        return back.back();
    }
    const T& Back() const {
        if(back.empty()) {
            return front.front();
        }
        return back.back();
    }
    void PushFront(T x) {
        front.push_back(x);
    }
    void PushBack(T x) {
        back.push_back(x);
    }
private:
    std::vector<T> front, back;
};
