//
// Created by we7289 on 3/13/2024.
//

#include "Heap.h"

void swap(int *array, int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

template<class T>
Heap<T>::Heap() {
    max_size = 100;
    size = 0;
    elements = new T[max_size];
}

template<class T>
Heap<T>::Heap(int max_size) {
    this->max_size = max_size;
    size = 0;
    elements = new T[max_size];
}

template<class T>
void Heap<T>::ReheapUp(T value) {
    if (size >= max_size) {
        throw FullHeap();
    }
    elements[size] = value;
    int currInd = size;

    while (currInd != 0) {
        int parentInd = (currInd - 1)/2;

        if (elements[parentInd] < elements[currInd]) {
            swap (elements, currInd, parentInd);
            currInd = parentInd;
        } else {
            break;
        }
    }
    ++size;

}

template<class T>
T Heap<T>::ReheapDown() {
    T priority_value = elements[0];

    elements[0] = elements[size -1];
    --size;

    int currInd = 0;
    int bottomInd = size-1;

    int leftInd = currInd * 2 + 1;
    int rightInd = currInd * 2 + 2;

    int maxChildInd;

    while (currInd != bottomInd) {
        if (leftInd == bottomInd) {
            maxChildInd = leftInd;
        } else if (elements[leftInd] > elements[rightInd]) {
            maxChildInd = leftInd;                  //find the larger child

        } else {
            maxChildInd = rightInd;
        }
        //compare larger child to currInd
        if (elements[currInd] < elements[maxChildInd]) {
            swap(elements, currInd, maxChildInd);
        } else {
            break;
        }
        leftInd = currInd * 2 + 1;
        rightInd = currInd * 2 + 2;
    }

    return priority_value;
}
