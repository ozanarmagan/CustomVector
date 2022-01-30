# C++ Custom Vector Template Class

This is an implementation of a template class for storing data in any type. It includes user-friendly interface with lots of helper abstract functions and also custom iterators.


## Member Functions

|Function Name|Parameters            |Return Type|Description                                                                                |
|-------------|----------------------|-----------|-------------------------------------------------------------------------------------------|
|add          |T element             |void       |Adds given element to end of current vector                                                 |
|clear        |                      |void       |Clears the vector                                                                           |
|count        |T element             |int        |Returns total count of the element                                                         |
|first        |                      |T          |Returns first element in the vector                                                         |
|firstIndexOf |T element             |int        |Returns first index of the element in the vector                                            |
|getCapacity  |                      |int        |Returns capacity of the vector                                                              |
|getSize      |                      |int        |Returns size of the vector                                                                  |
|insert       |T element, int index  |void       |Inserts given element to a specific index                                                  |
|includes     |T element             |bool       |Returns if the element exists in the vector                                                 |
|isEmpty      |                      |bool       |Returns if the vector is empty                                                              |
|last         |                      |T          |Returns last element in the vector                                                          |
|lastIndexOf  |T element             |int        |Returns last index of the element in the vector                                             |
|pop          |                      |T element  |Returns first element in the vector and removes it from the vector                           |
|push         |T element             |void       |Inserts the element in first index of the vector                                            |
|select       |bool (T)              |CustomVector<T>   |Returns a sub-vector with elements in the vector which returns true for given lambda function|
|sort         |                      |void       |Sorts the vector                                                                            |
|sort         |bool(T,T)             |void       |Sorts the vector according to the given lambda function                                     |
|subArray     |int start,int end     |CustomVector<T>   |Returns a sub-vector between given indexes                                                  |
|swap         |int index1, int index2|void       |Swaps elements in the given indexes                                                        |
|remove       |T element             |void       |Removes all occurances of the element from the vector                                       |
|removeIf     |bool(T)               |void       |Removes all elements from the vector which return false from given lambda function          |
|removeIndex  |int index             |void       |Removes the element in the given index                                                     |
|removeRange  |int start, int end    |void       |Removes all elements in the given range of indexes                                         |
|reverse      |                      |void       |Reverses order of the vector                                                                |


## Overloaded Operators

|Operator    |Parameters            |Return Type|Description                                                                                |
|------------|----------------------|-----------|-------------------------------------------------------------------------------------------|
|<<          |std::ostream stream, CustomVector<T> element|std::ostream|Inserts elements of the vector to stream via stream insertion operator                      |
|+           |CustomVector<T> vector,CustomVector<T> other|CustomVector<T>   |Concats elements of two vectors                                                             |
|-           |CustomVector<T> vector,CustomVector<T> other|CustomVector<T>   |Removes elements of second vector from first vector                                          |
|^           |CustomVector<T> vector,CustomVector<T> other|CustomVector<T>   |Returns an vector which includes intersection of two vectors                                 |
|==          |CustomVector<T> vector,CustomVector<T> other|bool       |Returns if two vectors are equal                                                            |
|!=          |CustomVector<T> vector,CustomVector<T> other|bool       |Returns if two vectors are not equal                                                        |
|[]          |int index             |T          |Returns element in given index                                                             |
|[]          |{int index1,int index2}|CustomVector<T>   |Returns an sub-vector which includes elements between two indexes                           |


## Iterators
This template class comes with its own iterators here and they are all compitable with STL functions such as <code>std::find</code>, <code>std::sort</code>
|Function Name |Description            |
|-------------|----------------------|
|begin          |Returns an iterator which points to start of the vector          |
|end        |Returns an iterator which points to start of the vector                      |
|cbegin          |Returns an const iterator which points to start of the vector          |
|cend        |Returns an const iterator which points to start of the vector                      |

## Important Note
To use some of listed functions and overloaded operators given T type must support these operations
