//
// Created by Сергей Ваниславский on 12.02.2021.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#pragma once
#include <cstddef>
#include <initializer_list>
#include <iterator>

namespace fefu
{

    template <typename ValueType>
    class vector_iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = ValueType;
        using difference_type = std::ptrdiff_t;
        using reference = ValueType&;
        using pointer = ValueType*;

        vector_iterator(pointer point) noexcept;

        reference operator*();
        pointer operator->();

        vector_iterator& operator++();
        vector_iterator& operator++(int);

        bool operator==(const vector_iterator<ValueType>& r_point);
        bool operator!=(const vector_iterator<ValueType>& r_point);



    private:
        pointer point;
    };

    template<typename ValueType>
    class vector_const_iterator {
    public:
        using value_type = ValueType;
        using reference = const ValueType&;
        using pointer = const ValueType*;

        vector_const_iterator(pointer point) noexcept;

        reference operator*() const;
        pointer operator->() const;

        vector_const_iterator& operator++();
        vector_const_iterator& operator++(int);

        bool operator==(const vector_const_iterator<ValueType>& r_point);
        bool operator!=(const vector_const_iterator<ValueType>& r_point);

    private:
        const pointer point;
    };

    template<typename T>
    class vector {
    public:
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = vector_iterator<value_type>;
        using const_iterator = vector_const_iterator<value_type>;


        vector();
        ~vector();
        //explicit vector( const Allocator& alloc );
//    vector( size_type count,
//            const T& value,
//            const Allocator& alloc = Allocator());
//    explicit vector( size_type count );
//    template< class InputIt >
//    vector( InputIt first, InputIt last,
//            const Allocator& alloc = Allocator() );


        vector& operator=( const vector& other );
        vector& operator=( vector&& other );
        vector& operator=( std::initializer_list<T> ilist );


        //Element access
        reference at( size_type pos );
        reference operator[]( size_type pos );
        reference front();
        reference back();
        T* data() noexcept;


        //Iterators
        iterator begin();
        const_iterator cbegin() const noexcept;
        iterator end();
        const_iterator cend() const noexcept;
//    reverse_iterator rend ( ) ;
//    const_reverse_iterator crend ( ) const noexcept ;

        //Capacity
        bool empty() const;
        size_type size() const;
        size_type max_size() const;
        void reserve( size_type new_cap );
        size_type capacity() const;
        void shrink_to_fit();

        //Modifiers
        void clear();
        void push_back( const T& value );
        void pop_back();
        void resize ( size_type count ) ;
        void swap( vector& other );
        iterator insert( iterator pos, const value_type & value );

        //Non-member functions

    private:
        void auto_reserve_helper();


    private:
        value_type* buffer;
        size_type SIZE;
        size_type CAPACITY = 0;
    };

}

#endif //VECTOR_VECTOR_H
