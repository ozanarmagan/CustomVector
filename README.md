# C++ Custom Vector Template Class

This is an implementation of a template class for storing data in any type.It includes user-friendly interface with lots of helper abstract functions and also custom iterators.


## Member Functions

|Function Name|Parameters            |Return Type|Description                                                                                |
|-------------|----------------------|-----------|-------------------------------------------------------------------------------------------|
|add          |T element             |void       |Adds given element to end of current array                                                 |
|clear        |                      |void       |Clears the array                                                                           |
|count        |T element             |int        |Returns total count of the element                                                         |
|first        |                      |T          |Returns first element in the array                                                         |
|firstIndexOf |T element             |int        |Returns first index of the element in the array                                            |
|getCapacity  |                      |int        |Returns capacity of the array                                                              |
|getSize      |                      |int        |Returns size of the array                                                                  |
|insert       |T element, int index  |void       |Inserts given element to a specific index                                                  |
|includes     |T element             |bool       |Returns if the element exists in the array                                                 |
|isEmpty      |                      |bool       |Returns if the array is empty                                                              |
|last         |                      |T          |Returns last element in the array                                                          |
|lastIndexOf  |T element             |int        |Returns last index of the element in the array                                             |
|pop          |                      |T element  |Returns first element in the array and removes it from the array                           |
|push         |T element             |void       |Inserts the element in first index of the array                                            |
|select       |bool (T)              |Array<T>   |Returns a sub-array with elements in the array which returns true for given lambda function|
|sort         |                      |void       |Sorts the array                                                                            |
|sort         |bool(T,T)             |void       |Sorts the array according to the given lambda function                                     |
|subArray     |int start,int end     |Array<T>   |Returns a sub-array between given indexes                                                  |
|swap         |int index1, int index2|void       |Swaps elements in the given indexes                                                        |
|remove       |T element             |void       |Removes all occurances of the element from the array                                       |
|removeIf     |bool(T)               |void       |Removes all elements from the array which return false from given lambda function          |
|removeIndex  |int index             |void       |Removes the element in the given index                                                     |
|removeRange  |int start, int end    |void       |Removes all elements in the given range of indexes                                         |
|reverse      |                      |void       |Reverses order of the array                                                                |


## Overloaded Operators

|Operator    |Parameters            |Return Type|Description                                                                                |
|------------|----------------------|-----------|-------------------------------------------------------------------------------------------|
|<<          |std::ostream stream, Array<T> element|std::ostream|Inserts elements of the array to stream via stream insertion operator                      |
|+           |Array<T> array,Array<T> other|Array<T>   |Concats elements of two arrays                                                             |
|-           |Array<T> array,Array<T> other|Array<T>   |Removes elements of second array from first array                                          |
|^           |Array<T> array,Array<T> other|Array<T>   |Returns an array which includes intersection of two arrays                                 |
|==          |Array<T> array,Array<T> other|bool       |Returns if two arrays are equal                                                            |
|!=          |Array<T> array,Array<T> other|bool       |Returns if two arrays are not equal                                                        |
|[]          |int index             |T          |Returns element in given index                                                             |
|[]          |{int index1,int index2}|Array<T>   |Returns an sub-array which includes elements between two indexes                           |


## Important Note
To use some of listed functions and overloaded operators given T type must support these operations
