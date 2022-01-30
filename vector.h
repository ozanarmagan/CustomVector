#ifndef __ARRAY_H__
#define __ARRAY_H__



#include <iostream>
#include <array>
#include <vector>
#include <functional>

#include "iterator.h"
#include "constIterator.h"

template <typename T>
class CustomVector
{
    public:
        using iterator = Iterator<T>;
        using constIterator = ConstIterator<T>;
        using value_type = T;
        using pointer = T*;
        using reference = value_type&;
        using constReference = const value_type&;
        CustomVector();
        CustomVector(int capacity);
        CustomVector(CustomVector<T> &other);
        ~CustomVector();
        CustomVector(CustomVector&& other) { head = other.head; size = other.size; capacity = other.capacity; other.head = nullptr; };
        int inline getSize() const { return size; };
        int inline getCapacity() const { return capacity; };
        void clear();
        void add(const value_type element);
        void insert(const value_type element,int index);
        void swap(int index1,int index2);
        void sort();
        void sort(std::function<bool(T,T)> lambda);
        void remove(const value_type element);
        void removeRange(int start,int end);
        void removeIf(std::function<bool(T)> lambda);
        void removeIndex(int index);
        void reverse();
        bool includes(const value_type element);
        inline void push(const value_type element) { insert(element,0); };
        inline value_type pop() { value_type element = head[0]; remove(head[0]); };
        int count(const value_type element);
        int firstIndexOf(const value_type element);
        int lastIndexOf(const value_type element);
        CustomVector<T>& subArray(const int start, const int end);
        CustomVector<T> select(std::function<bool(T)> lambda);
        template<T> friend std::ostream& operator<<(std::ostream& stream,CustomVector<T>& element);
        template<T> friend const CustomVector<T> operator+(CustomVector<T>&, CustomVector<T>& other);
        template<T> friend const CustomVector<T> operator-(CustomVector<T>&, CustomVector<T>& other);
        template<T> friend const CustomVector<T> operator^(CustomVector<T>&, CustomVector<T>& other);
        void operator=(const CustomVector<T>& other);
        void operator=(CustomVector&& other) { head = other.head; size = other.size; capacity = other.capacity; other.head = nullptr; }
        template<T> friend bool const operator==(CustomVector<T>&, CustomVector<T>& other) ;
        template<T> friend inline const bool operator!=(CustomVector<T>&, CustomVector<T>& other) ;
        reference operator[](int i);
        CustomVector<T> operator[](std::array<int,2> points);
        inline reference last() { return head[size - 1]; };
        inline reference first() {return *head; };
        bool isEmpty() const { return size == 0; };
        iterator begin() { return  iterator(this->head); }
        iterator end() { return iterator(this->head + size); }
        constIterator cbegin() { return constIterator(this->head); }
        constIterator cend() { return constIterator(this->head + size); }
    private:
        pointer head;
        int size,capacity;
        void increaseCapacity();
        bool isFull() const { return size == capacity; };
};

template <typename T>
CustomVector<T>::CustomVector(int capacity) : capacity(capacity),size(0)
{
    head = new T[capacity];
}


template <typename T>
CustomVector<T>::CustomVector() : capacity(10000),size(0)
{
    head = new T[capacity];
}

template <typename T>
CustomVector<T>::CustomVector(CustomVector<T>& other) : capacity(other.getCapacity()),size(other.getSize())
{
    head = new T[other.getCapacity()];
    for(int i = 0;i < other.getSize();i++)
        head[i] = other[i];
}




template <typename T>
void CustomVector<T>::remove(T element)
{
    for(int i = 0; i < size;i++)
        if(head[i] == element)
        {
            for(;i < size - 1;i++)
                head[i]  = head[i+1];
            size--;
            return;
        }
}

template <typename T>
void CustomVector<T>::increaseCapacity()
{
    capacity += 100;
    T* newHead = new T[capacity];
    for(int i = 0;i < capacity - 100;i++)
        newHead[i] = head[i];
    delete [] head;
    head = newHead;
}

template <typename T>
void CustomVector<T>::add(T element)
{    
    if(isFull())
        increaseCapacity();
    head[size++] = element;
}


template <typename T>
void CustomVector<T>::insert(T element,int index)
{
    if(isFull())
        increaseCapacity();
    if(index >= size || index < 0)
        return;
    for(int i = size;i > index;i--)
        head[i] = head[i-1];
    head[index] = element;
    size++;
}


template <typename T>
void CustomVector<T>::swap(int index1,int index2)
{
    if(index1 >= size || index2 >= size || index1 < 0 || index2 < 0)
        return;
    T temp; 
    temp = head[index1];
    head[index1] = head[index2];
    head[index2] = temp;
}


template <typename T>
void CustomVector<T>::clear()
{
    delete [] head;
    head = new T[capacity];
}

template <typename T>
void CustomVector<T>::sort()
{
    bool completed = false;
    while(!completed)
    {
        completed = true;
        for(int i = 0;i < size - 1;i++)
        {
            if(head[i] > head[i+1])
            {
                swap(i,i+1);
                completed = false;
            }
        }
    }
}

template <typename T>
void CustomVector<T>::reverse()
{
    int start = 0, end = size - 1;
    while(start < end)
        swap(start++,end--);
}


template <typename T>
void CustomVector<T>::removeRange(int start,int end)
{
    if(start > end || end >= size || end < 0 || start >= size || start < 0 )
        return;
    for(int i = 0; i < size - end;i++)
        head[start + i] = head[end + i];
    size -= end - start;
}

template <typename T>
CustomVector<T>& CustomVector<T>::subArray(const int start,const int end)
{
    CustomVector<T> result(end - start);
    for(int i = start;i < end;i++)
        result.add(head[i]);
    return result;
}


template <typename T>
const CustomVector<T> operator+(CustomVector<T>& array, CustomVector<T>& other)
{
    CustomVector<T> result(other);
    for(int i = 0;i < array.getSize();i++)
        result.add(array[i]);
    return result;
}

template <typename T>
bool CustomVector<T>::includes(const T element)
{
    for(int i = 0;i < size;i++)
        if(head[i] == element)
            return true;
    return false;
}

template <typename T>
int CustomVector<T>::count(const T element)
{
    int count = 0;
    for(int i = 0;i < size;i++)
        if(head[i] == element)
            count++;
    return count;
}


template <typename T>
int CustomVector<T>::firstIndexOf(const T element)
{
    for(int i = 0;i < size;i++)
        if(head[i] == element)
            return i;
    return -1;
}

template <typename T>
int CustomVector<T>::lastIndexOf(const T element)
{
    int lastIndex = -1;
    for(int i = 0;i < size;i++)
        if(head[i] == element)
            lastIndex = i;
    return lastIndex;
}

template <typename T>
const CustomVector<T> operator-(CustomVector<T>& array, CustomVector<T>& other) 
{
    CustomVector<T> result(other);
    for(int i = 0;i < array.getSize();i++)
        result.remove(array[i]);
    return result;
}

template <typename T>
const CustomVector<T> operator^(CustomVector<T>& array, CustomVector<T>& other) 
{
    CustomVector<T> result(other);
    for(int i = 0;i < result.getSize();i++)
        if(!array.includes(result[i]))
            result.remove(array[i]);
    return result;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream,CustomVector<T>& element)
{
    for(int i = 0; i < element.getSize();i++)
    {
        stream << element[i] << " ";
    }
    stream << std::endl;

    return stream;
}

template <typename T>
CustomVector<T> CustomVector<T>::operator[](std::array<int,2> points)
{
    CustomVector<T> result(points[1] - points[0]);
    for(int i = points[0];i < points[1];i++)
        result.add(head[i]);
    return result;
}

template <typename T>
T& CustomVector<T>::operator[](int i)
{
    return head[i];
}

template <typename T>
void CustomVector<T>::removeIf(std::function<bool(T)> lambda)
{
    for(int i = 0;i < size;i++)
        if(lambda(head[i]))
        {
            remove(head[i]);
            i = -1;
        }
}


template <typename T>
void CustomVector<T>::removeIndex(int index)
{
    if(index < 0 || index >= size)
        return;
    for(size--;index < size;index++)
        head[index] = head[index + 1];
    
}

template <typename T>
CustomVector<T> CustomVector<T>::select(std::function<bool(T)> lambda)
{
    CustomVector<T> result;
    for(int i = 0;i < size;i++)
        if(lambda(head[i]))
            result.add(head[i]);
    return result;
}

template <typename T>
void CustomVector<T>::sort(std::function<bool(T,T)> lambda)
{
    bool completed = false;
    while(!completed)
    {
        completed = true;
        for(int i = 0;i < size - 1;i++)
        {
            if(!lambda(head[i],head[i+1]))
            {
                swap(i,i+1);
                completed = false;
            }
        }
    }
}

template <typename T>
const bool operator==(CustomVector<T>& array, CustomVector<T>& other)
{
    if(array.getSize() != other.getSize())
        return false;
    for(int i = 0;i < array.getSize();i++)
        if(array[i] != other[i])
            return false;
    return true;
}


template <typename T>
const bool operator!=(CustomVector<T>& array, CustomVector<T>& other)
{
    return !(operator==(array,other));
}

template <typename T>
CustomVector<T>::~CustomVector<T>()
{
    delete [] head;
}

template <typename T>
void CustomVector<T>::operator=(const CustomVector<T>& other) 
{
    delete [] head;
    size = other.getSize();
    head = new T[other.getCapacity()];
    for(int i = 0;i < size;i++)
        head[i] = other.head[i];
}


#endif // __ARRAY_H__