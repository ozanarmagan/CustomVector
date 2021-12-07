#include "array.h"

template <typename T>
Array<T>::Array(int capacity) : capacity(capacity),size(0)
{
    head = new T[capacity];
}

template <typename T>
Array<T>::Array(std::vector<T> arry,int capacity) : capacity(capacity),size(0)
{
    head = new T[capacity];
    for(T element : arry)
        add(element);
}

template <typename T>
Array<T>::Array(Array<T>& other) : capacity(other.getCapacity()),size(other.getSize())
{
    head = new T[other.getCapacity()];
    for(int i = 0;i < other.getSize();i++)
        head[i] = other[i];
}




template <typename T>
void Array<T>::remove(T element)
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
void Array<T>::increaseCapacity()
{
    capacity += 100;
    T* newHead = new T[capacity];
    for(int i = 0;i < capacity - 100;i++)
        newHead[i] = head[i];
    delete [] head;
    head = newHead;
}

template <typename T>
void Array<T>::add(T element)
{    
    if(isFull())
        increaseCapacity();
    head[size++] = element;
}


template <typename T>
void Array<T>::insert(T element,int index)
{
    if(isFull())
        increaseCapacity();
    if(index >= size)
        return;
    for(int i = index;i < size;i++)
        head[i+1] = head[i];
    head[index] = element;
    size++;
}


template <typename T>
void Array<T>::swap(int index1,int index2)
{
    if(index1 >= size || index2 >= size)
        return;
    T temp; 
    temp = head[index1];
    head[index1] = head[index2];
    head[index2] = temp;
}


template <typename T>
void Array<T>::clear()
{
    delete [] head;
    head = new T[capacity];
}

template <typename T>
void Array<T>::sort()
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
void Array<T>::removeRange(int start,int end)
{
    if(start > end)
        return;
    for(int i = 0; i < size - end;i++)
        head[start + i] = head[end + i];
    size -= end - start;
}

template <typename T>
Array<T> Array<T>::subArray(const int start,const int end)
{
    Array<T> result(end - start);
    for(int i = start;i < end;i++)
        result.add(head[i]);
    return result;
}


template <typename T>
const Array<T> operator+(Array<T>& array, Array<T>& other)
{
    Array<T> result(other);
    for(int i = 0;i < array.getSize();i++)
        result.add(array[i]);
    return result;
}

template <typename T>
bool Array<T>::includes(const T element)
{
    for(int i = 0;i < size;i++)
        if(head[i] == element)
            return true;
    return false;
}

template <typename T>
int Array<T>::count(const T element)
{
    int count = 0;
    for(int i = 0;i < size;i++)
        if(head[i] == element)
            count++;
    return count;
}

template <typename T>
const Array<T> operator-(Array<T>& array, Array<T>& other) 
{
    Array<T> result(other);
    for(int i = 0;i < array.getSize();i++)
        result.remove(array[i]);
    return result;
}

template <typename T>
const Array<T> operator^(Array<T>& array, Array<T>& other) 
{
    Array<T> result(other);
    for(int i = 0;i < result.getSize();i++)
        if(!array.includes(result[i]))
            result.remove(array[i]);
    return result;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream,Array<T>& element)
{
    for(int i = 0; i < element.getSize();i++)
    {
        stream << element[i] << " ";
    }
    stream << std::endl;

    return stream;
}

template <typename T>
Array<T> Array<T>::operator[](std::array<int,2> points)
{
    Array<T> result(points[1] - points[0]);
    for(int i = points[0];i < points[1];i++)
        result.add(head[i]);
    return result;
}

template <typename T>
void Array<T>::removeIf(std::function<bool(T)> func)
{
    for(int i = 0;i < size;i++)
        if(func(head[i]))
        {
            remove(head[i]);
            i = -1;
        }
}


template <typename T>
Array<T> Array<T>::select(std::function<bool(T)> func)
{
    Array<T> result;
    for(int i = 0;i < size;i++)
        if(func(head[i]))
            result.add(head[i]);
    return result;
}

template <typename T>
const bool operator==(Array<T>& array, Array<T>& other)
{
    if(array.getSize() != other.getSize())
        return false;
    for(int i = 0;i < array.getSize();i++)
        if(array[i] != other[i])
            return false;
    return true;
}


template <typename T>
const bool operator!=(Array<T>& array, Array<T>& other)
{
    return !(operator==(array,other));
}
