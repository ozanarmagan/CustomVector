#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <array>
#include <vector>
#include <functional>

template <typename T>
class Array
{
    public:
        Array();
        Array(int capacity);
        Array(std::vector<T> arry);
        Array(Array<T> &other);
        int inline getSize() const { return size; };
        int inline getCapacity() const { return capacity; };
        void clear();
        void add(const T element);
        void insert(const T element,int index);
        void swap(int index1,int index2);
        void sort();
        void sort(std::function<bool(T,T)> lambda);
        void remove(const T element);
        void removeRange(int start,int end);
        void removeIf(std::function<bool(T)> lambda);
        void removeIndex(int index);
        void reverse();
        bool includes(const T element);
        inline void push(const T element) { insert(element,0); };
        inline T pop() { T element = head[0]; remove(head[0]); };
        int count(const T element);
        int firstIndexOf(const T element);
        int lastIndexOf(const T element);
        Array<T>& subArray(const int start, const int end);
        Array<T> select(std::function<bool(T)> lambda);
        template<T> friend std::ostream& operator<<(std::ostream& stream,Array<T>& element);
        template<T> friend const Array<T> operator+(Array<T>&, Array<T>& other) ;
        template<T> friend const Array<T> operator-(Array<T>&, Array<T>& other) ;
        template<T> friend const Array<T> operator^(Array<T>&, Array<T>& other) ;
        void operator=(const Array<T>& other) ;
        template<T> friend bool const operator==(Array<T>&, Array<T>& other) ;
        template<T> friend inline const bool operator!=(Array<T>&, Array<T>& other) ;
        T& operator[](int i);
        Array<T> operator[](std::array<int,2> points);
        inline T& last() { return head[size - 1]; };
        inline T& first() {return *head; };
        bool isEmpty() const { return size == 0; };
        ~Array();
    private:
        T* head;
        int size,capacity;
        void increaseCapacity();
        bool isFull() const { return size == capacity; };
};


#endif