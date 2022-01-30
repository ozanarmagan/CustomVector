#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include "iteratorBase.h"

template<typename T>
class Iterator : public IteratorBase<T>
{
    public:
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::input_iterator_tag;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using constReference = const T&;
        using IteratorBase<T>::operator-;
        using IteratorBase<T>::operator+;
        Iterator() : IteratorBase<T>() {    };
        Iterator(T* rhs) : IteratorBase<T>(rhs) {   };
        Iterator(const T& rhs) : IteratorBase<T>(rhs) {   };
        inline reference operator*()  { return *this->head; };
        inline reference operator->()  { return this->head; };
        inline reference operator[](const difference_type rhs)  { return this->head[rhs]; };
        inline Iterator& operator+=(const difference_type rhs) { this->head += rhs; return *this; };
        inline Iterator& operator-=(const difference_type rhs) { this->head -= rhs; return *this; };
        inline Iterator& operator++() { this->head++; return *this; };
        inline Iterator& operator--() { this->head--; return *this; };
        inline Iterator operator++(int) { Iterator<T> temp = *this;++this->head; return temp; };
        inline Iterator operator--(int) { Iterator<T> temp = *this;--this->head; return temp; };
        inline Iterator operator-(const difference_type rhs)  { Iterator<T> temp = *this; temp.head -= rhs; return temp; };
        inline Iterator operator+(const difference_type rhs)  { Iterator<T> temp = *this; temp.head += rhs; return temp; };
        inline friend Iterator operator+(const difference_type lhs,Iterator<T> rhs) { return Iterator(lhs + rhs.head); };
        inline friend Iterator operator-(const difference_type lhs,Iterator<T> rhs) { return Iterator(lhs - rhs.head); };
    private:

};


#endif 