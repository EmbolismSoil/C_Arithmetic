#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP
#include <algorithm>
#include <vector>
template <class T>
   static void  _MaxHeap(std::vector<T> &vec,
                           typename std::vector<T>::size_type end,
                                    typename std::vector<T>::size_type pos)
    {
        typename std::vector<T>::size_type indicatePos = pos + 1;
        typename std::vector<T>::size_type indicateLeftChild = indicatePos * 2;
        typename std::vector<T>::size_type indicateRightChild = indicatePos * 2 + 1;
        typename std::vector<T>::size_type leftChild = indicateLeftChild - 1;
        typename std::vector<T>::size_type rightChild = indicateRightChild - 1;
        typename std::vector<T>::size_type max = pos;
        //typename std::vector<T>::size_type end = vec.size();

        if (indicateLeftChild <= end && vec[leftChild] > vec[pos])
            max = leftChild;

        if (indicateRightChild <= end && vec[rightChild] > vec[max] )
            max = rightChild;

        if (max != pos){
            std::swap(vec[pos], vec[max]);
            _MaxHeap(vec, end, max);
        }
    }

template <class InputContainer>
   void HeapBuild(InputContainer & container,
                         typename InputContainer::size_type end)
   {
       typename InputContainer::size_type pos = end / 2;
       for (; pos >= 1; --pos){
           _MaxHeap(container,  end , pos - 1);
        }
   }

template <class InputContainer>
     void HeapSort(InputContainer &container)
     {
         typename InputContainer::size_type end = container.size();
         typename InputContainer::size_type pos = end;
          HeapBuild(container , end);
         for (; pos >= 2; --pos){
             std::swap(container[0], container[pos - 1]);
             _MaxHeap(container, --end, 0);
         }
     }
#endif // HEAPSORT_HPP

