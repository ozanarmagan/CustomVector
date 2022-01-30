#ifndef __ITERATORBASE_H__
#define __ITERATORBASE_H__

template<typename T>
class IteratorBase 
{
    public:
        using iterator_category = std::input_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using constReference = const T&;
        IteratorBase() : head(nullptr) {  };
        IteratorBase(pointer rhs) : head(rhs) {   };
        IteratorBase(const reference rhs) : head(&rhs) { };
        inline bool operator==(const IteratorBase& rhs) const { return head == rhs.head; };
        inline bool operator!=(const IteratorBase& rhs) const { return head != rhs.head; };
        inline bool operator<(const IteratorBase& rhs) const { return head < rhs.head; };
        inline bool operator>(const IteratorBase& rhs) const { return head > rhs.head; };
        inline bool operator<=(const IteratorBase& rhs) const { return head <= rhs.head; };
        inline bool operator>=(const IteratorBase& rhs) const { return head >= rhs.head; };
        inline IteratorBase<T>& operator=(const IteratorBase& rhs) { head = rhs.head; return *this; };
        inline const difference_type operator-(const IteratorBase<T>& other) { return this->head - other.head; }; 
        inline const difference_type operator+(const IteratorBase<T>& other) { return this->head + other.head;}
    private:
        T* head;
};


#endif 