//
// Created by Сергей Ваниславский on 12.02.2021.
//

#include <stdexcept>
#include <limits>
#include <utility>
#include "vector.h"

namespace fefu
{

    template<typename T>
    vector_iterator<T>::vector_iterator(pointer _point) noexcept
    :
    point(_point) {}

    template<typename T>
    T& vector_iterator<T>::operator*() {
        return *point;
    }

    template<typename T>
    T* vector_iterator<T>::operator->() {
        return point;
    }

    template<typename T>
    vector_iterator<T>& vector_iterator<T>::operator++() {
        point++;
        return *this;
    }

    template<typename T>
    vector_iterator<T>& vector_iterator<T>::operator++(int) {
        return ++(*this);
    }

    template<typename T>
    bool vector_iterator<T>::operator==(const vector_iterator<T>& r_point) {
        return point == r_point.point;
    }

    template<typename T>
    bool vector_iterator<T>::operator!=(const vector_iterator<T>& r_point) {
        return !(*this == r_point);
    }

    template<typename T>
    vector_const_iterator<T>::vector_const_iterator(pointer _point) noexcept
            :
            point(_point) {}

    template<typename T>
    const T& vector_const_iterator<T>::operator*() const {
        return *point;
    }

    template<typename T>
    const T* vector_const_iterator<T>::operator->() const {
        return point;
    }

    template<typename T>
    vector_const_iterator<T>& vector_const_iterator<T>::operator++() {
        point++;
        return *this;
    }

    template<typename T>
    vector_const_iterator<T>& vector_const_iterator<T>::operator++(int) {
        return ++(*this);
    }

    template<typename T>
    bool vector_const_iterator<T>::operator==(const vector_const_iterator<T>& r_point) {
        return point == r_point.point;
    }

    template<typename T>
    bool vector_const_iterator<T>::operator!=(const vector_const_iterator<T>& r_point) {
        return !(*this == r_point);
    }


    template<typename T>
    vector<T>::vector() {
        SIZE = 0;
    }

    template<typename T>
    vector<T>::vector(size_type count) {
        SIZE = 0;

        resize(count);
    }

    template<typename T>
    vector<T>::vector(const vector<T> &other) {
        SIZE = other.SIZE;
        while (SIZE >= CAPACITY) {
            auto_reserve_helper();
        }
        for(int i = 0; i < SIZE; i++) {
            buffer[i] = other.buffer[i];
        }
    }

    template<typename T>
    vector<T>::vector(vector<T> &&other)
    :
    SIZE(other.SIZE),
    CAPACITY(other.CAPACITY),
    buffer(std::move(other.buffer)) {}

    template<typename T>
    vector<T>::~vector() {
        delete [] buffer;
    }
    template<typename T>
    vector<T>::vector(std::initializer_list<T> init) {
        for (auto &element : init) {
            push_back(element);
        }
    }

    template<typename T>
    vector<T>& vector<T>::operator=(const vector<T> &other) {
        SIZE = other.SIZE;
        while (SIZE >= CAPACITY) {
            auto_reserve_helper();
        }
        for(int i = 0; i < SIZE; i++) {
            buffer[i] = other.buffer[i];
        }
    }

    template<typename T>
    vector<T> & vector<T>::operator=(vector<T> &&other) {
        buffer = std::move(other.buffer);
        SIZE = other.SIZE;
        CAPACITY = other.CAPACITY;
    }

    template<typename T>
    vector<T>& vector<T>::operator=(std::initializer_list<T> ilist) {
        SIZE = ilist.size();
        while (SIZE >= CAPACITY) {
            auto_reserve_helper();
        }

        for(int i = 0; i < SIZE; i++) {
            buffer[i] = ilist[i];
        }
    }

    template<typename T>
    T& vector<T>::at(size_type pos) {
        if(pos < SIZE)
            return buffer[pos];
        else
            throw std::out_of_range("pos >= " + SIZE);
    }

    template<typename T>
    T& vector<T>::operator[](size_type pos) {
        return buffer[pos];
    }

    template<typename T>
    T& vector<T>::front() {
        return buffer[0];
    }

    template<typename T>
    T& vector<T>::back() {
        return buffer[SIZE-1];
    }

    template<typename T>
    T* vector<T>::data() noexcept {
        return buffer;
    }

    template<typename T>
    vector_iterator<T> vector<T>::begin() {
        return iterator (buffer);
    }

    template<typename T>
    vector_iterator<T> vector<T>::end() {
        return iterator(buffer + SIZE);
    }



    template<typename T>
    bool vector<T>::empty() const {
        return SIZE == 0;
    }

    template<typename T>
    size_t vector<T>::size() const {
        return SIZE;
    }

    template<typename T>
    size_t vector<T>::max_size() const {
        return std::numeric_limits<difference_type>::max();
    }

    template<typename T>
    void vector<T>::reserve(size_type new_cap) {
        if(CAPACITY < new_cap) {
            auto temp_buffer = new value_type[CAPACITY];
            std::swap(buffer, temp_buffer);

            buffer = new T[new_cap];
            for(int i = 0; i < SIZE; i++)
                buffer[i] = temp_buffer[i];
        }
    }

    template<typename T>
    void vector<T>::resize(size_type count) {
        reserve(count);
        SIZE = count;
    }

    template<typename T>
    size_t vector<T>::capacity() const {
        return CAPACITY;
    }



    template<typename T>
    void vector<T>::push_back(const T &value) {
        if (SIZE >= CAPACITY) {
            auto_reserve_helper();
        }
        buffer[SIZE++] = value;
    }

    template<typename T>
    void vector<T>::push_back(T &&value) {
        push_back(std::move(value));
    }

    template<typename T>
    void vector<T>::pop_back() {
        buffer[SIZE--] = 0;
    }

    template<typename T>
    void vector<T>::clear() {
        SIZE = 0;
    }

    template<typename T>
    void vector<T>::swap(vector<T> &other) {
        std::swap(buffer, other.buffer);
        std::swap(SIZE, other.SIZE);
        std::swap(CAPACITY, other.CAPACITY);
    }

    template<typename T>
    vector_iterator<T> vector<T>::insert(iterator pos, const value_type &value) {
        *pos = value;
    }

    template<typename T>
    template< class... Args >
    vector_iterator<T> vector<T>::emplace(const_iterator pos, Args &&...args) {
        return insert(pos ,value_type(std::forward<Args>(args)...));
    }

    template<typename T>
    template< class... Args >
    void vector<T>::emplace_back(Args &&...args) {
        return push_back(value_type(std::forward<Args>(args)...));
    }

    template<typename T>
    bool vector<T>::operator==(const vector<T> other) const {
        if(SIZE != other.SIZE)
            return false;

        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < other.SIZE; j++) {
                if(buffer[i] != other.buffer[i])
                    return false;
            }
        }

        return true;
    }

    template<typename T>
    bool vector<T>::operator!=(const vector<T> other) const {
        return !(this == other);
    }

    template<typename T>
    void vector<T>::auto_reserve_helper() {
        auto temp_buffer = new value_type[CAPACITY];
        std::swap(buffer, temp_buffer);

        if (CAPACITY == 0) {
            CAPACITY = 1;
        } else {
            CAPACITY *= 2;
        }
        buffer = new T[CAPACITY];
//        for(int i = 0; )
        for(int i = 0; i < SIZE; i++)
            buffer[i] = temp_buffer[i];
    }
}