// SimpleList.cpp
  
#include "SimpleList.h"
#include <iostream>
#include <cstdlib>
#include <type_traits>

// constructor that sets numElements to 0
template<class T>
SimpleList<T>::SimpleList() {
        numElements = 0;
        elements = new T[CAPACITY];
}

template<class T>
void destroy(T element) {
        // do nothing
}

// delete the pointer type
template<class T>
void destroy(T* element) {
        delete element;
}

// destructor must delete array & elements
template <class T>
SimpleList<T>::~SimpleList() {
        for(int i = 0; i < numElements; i++) {
                // will call destroy(T* element)
                destroy(elements[i]);
        }
        // deletes whole array
        delete[] elements;
}

// returns the element at index location. throws a InvalidIndexException
// if there is no element
template <class T>
T SimpleList<T>::at(int index) const throw(InvalidIndexException) {
        if(index < 0 || index >= numElements)
                throw InvalidIndexException();
        return elements[index];
}

// returns true if  the list is empty, false otherwise
template <class T>
bool SimpleList<T>::empty() const {
        if(numElements == 0){
                return true;
        }
        else {
                return false;
        }
}

// return the element at index 0. throws an EmptyListException if 
// list is empty
template <class T>
T SimpleList<T>::first() const throw(EmptyListException) {
        if(numElements == 0)
                throw EmptyListException();
        return elements[0];
}

// return the last element
template <class T>
T SimpleList<T>::last() const throw(EmptyListException) {
        if(numElements == 0)
                throw EmptyListException();
        return elements[numElements-1];
}

// returns num of items currently stored in the SimpleList
template <class T>
int SimpleList<T>::getNumElements() const{
        return numElements;
}

// inserts at item at the first possible slot towards the end of the list
// throws a FullListException if the list is at Capacity
template <class T>
void SimpleList<T>::insert(T item) throw(FullListException) {
        if(numElements == CAPACITY)
                throw FullListException();
/*      int index = 0;
        // loops through array to find first empty spot
        while(elements[index] != 0) {
                index++;
        }
        elements[index] = item; */
        else {
                elements[numElements] = item;
                numElements++;
        }
}
// removes the element at index
template <class T>
void SimpleList<T>::remove(int index) throw(InvalidIndexException, EmptyListException) {
        if(numElements == 0)
                throw EmptyListException();
        if(index < 0 || index >= numElements)
                throw InvalidIndexException();
        for(int i = index; i < numElements; i++) {
                elements[i] = elements[i+1];
        }
        numElements--;
}
      
