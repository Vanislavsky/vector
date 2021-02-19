//
// Created by Сергей Ваниславский on 12.02.2021.
//

#include <stdexcept>
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
        //TODO
        buffer = new T[CAPACITY];
        SIZE = 0;
    }

    template<typename T>
    vector<T>::~vector() {
        delete [] buffer;
    }

    template<typename T>
    vector<T>& vector<T>::operator=(const vector<T> &other) {
        SIZE = other.SIZE;
        if(SIZE < CAPACITY) {
            //TODO
        }
        for(int i = 0; i < SIZE; i++) {
            buffer[i] = other.buffer[i];
        }
    }

    template<typename T>
    vector<T>& vector<T>::operator=(std::initializer_list<T> ilist) {
        SIZE = ilist.size();
        if(SIZE < CAPACITY) {
            //TODO
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
    size_t vector<T>::capacity() const {
        return CAPACITY;
    }



    template<typename T>
    void vector<T>::push_back(const T &value) {
        if(SIZE > CAPACITY) {
            //TODO
        }
        buffer[SIZE++] = value;
    }

    template<typename T>
    void vector<T>::pop_back() {
        buffer[SIZE--] = 0;
    }

    template<typename T>
    void vector<T>::clear() {
        for(int i = 0; i < SIZE; i++)
            buffer[i] = 0;
        SIZE = 0;
    }
}