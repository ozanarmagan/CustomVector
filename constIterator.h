#ifndef __CONSTITERATOR_H__
#define __CONSTITERATOR_H__

#include "iteratorBase.h"

template<typename T>
class ConstIterator : public IteratorBase<T>
{
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::input_iterator_tag;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using constReference = const T&;
        using IteratorBase<T>::operator-;
        using IteratorBase<T>::operator+;
        ConstIterator() : Iterator<T>() {    };
        ConstIterator(pointer rhs) : Iterator<T>(rhs) {   };
        ConstIterator(constReference rhs) : Iterator<T>(rhs) {   };
        inline constReference operator*()  { return *this->head; };
        inline constReference operator->()  { return this->head; };
        inline constReference operator[](difference_type rhs)  { return this->head[rhs]; };
        inline ConstIterator& operator+=(difference_type rhs) { this->head += rhs; return *this; };
        inline ConstIterator& operator-=(difference_type rhs) { this->head -= rhs; return *this; };
        inline ConstIterator& operator++() { this->head++; return *this; };
        inline ConstIterator& operator--() { this->head--; return *this; };
        inline ConstIterator operator++(int) { ConstIterator<T> temp = *this;++this->head; return temp; };
        inline ConstIterator operator--(int) { ConstIterator<T> temp = *this;--this->head; return temp; };
        inline const difference_type operator-(const ConstIterator<T>& other) { return this->head - other.head; }; 
        inline const difference_type operator+(const ConstIterator<T>& other) { return this->head + other.head;}
        inline ConstIterator operator-(difference_type rhs)  { ConstIterator<T> temp = *this; temp.head -= rhs; return temp; };
        inline ConstIterator operator+(difference_type rhs)  { ConstIterator<T> temp = *this; temp.head += rhs; return temp; };
        inline friend ConstIterator operator+(difference_type lhs,Iterator<T>& rhs) { return ConstIterator(lhs + rhs.head); };
        inline friend ConstIterator operator-(difference_type lhs,Iterator<T>& rhs) { return ConstIterator(lhs - rhs.head); };
};


#endif