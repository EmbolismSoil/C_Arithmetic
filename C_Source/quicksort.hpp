#ifndef QUICKSORInputIterator_HPP
#define QUICKSORInputIterator_HPP
#include <stdlib.h>
#include <time.h>
#include <iterator>

namespace Algorithms {
template<class InputIterator>
     InputIterator Partions( InputIterator begin,  InputIterator end)
    {
         InputIterator j = begin;
         InputIterator i = j;
         InputIterator pivot = end;

        for (--i, --pivot; j != pivot; ++j){
            if (*j < *pivot){
                ++i;
                std::swap(*i, *j);
            }
        }
        ++i;
        std::swap(*i, *pivot);
        return i;
    }

static inline int Random(int x)
{
    srand((int)timer_t(0));
    int rand = (int)(random() % x);
    return rand;
}

template <class InputIterator>
     InputIterator RandomizedPartions(InputIterator begin, InputIterator end)
     {
         int distance = std::distance(begin, end - 1);
         if (distance > 0){
             distance = Random(distance);
             std::cout << "ramdom povit = " << distance << std::endl;
              std::swap(*(begin + distance), *(end - 1));
         }
         return Partions(begin, end);
     }

template <class InputIterator>
       void QuickSort( InputIterator begin,  InputIterator end)
    {
         if (begin < end){
           InputIterator pos = Partions(begin, end);
            QuickSort(begin, pos);
            QuickSort(pos+1, end);
         }
    }

template <class InputIterator>
    void PermuteQuickSort(InputIterator begin, InputIterator end)
    {
        if (begin < end){
            InputIterator pos = RandomizedPartions(begin, end);
            PermuteQuickSort(begin, pos);
            PermuteQuickSort(pos + 1, end);
        }
    }
}
#endif // QUICKSORInputIterator_HPP

