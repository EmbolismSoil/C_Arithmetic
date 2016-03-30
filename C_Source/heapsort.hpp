#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP
#include <algorithm>

template <class InputIterator>
   static _MaxHeap(InputIterator begin, InputIterator end, InputIterator pos)
    {
        InputIterator leftChild = pos * 2;
        InputIterator rightChild =  pos * 2 + 1;

        if (leftChild < end  && *leftChild > *pos){
             std::swap(*leftChild, *pos);
        }

        if (rightChild < end && *rightChild > *pos){
            std::swap(*rightChild, *pos);
            HeapSort(begin, end, rightChild);
        }else{
            HeapSort(begin, end, leftChild);
        }
    }

template <class InputContainer>
   void HeapBuild(InputContainer container)
   {
       typename InputContainer::size_type pos = container.size() / 2;

   }
#endif // HEAPSORT_HPP

