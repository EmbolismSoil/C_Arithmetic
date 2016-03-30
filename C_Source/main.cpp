#include <vector>
#include <stdlib.h>
#include <iostream>
//#include "quicksort.hpp"
#include "maxheap.hpp"

int main(void)
{
    MaxHeap<int> heap;
    heap.Insert(12);
    heap.Insert(13);
    heap.Insert(19);
    heap.Insert(8);

    int x;
    while(heap.Top(x)){
        std::cout << x << " ";
        heap.Pop();
    }
}
