#ifndef QUICKSORInputIterator_HPP
#define QUICKSORInputIterator_HPP

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
        QuickSort(begin, end);
    }


#endif // QUICKSORInputIterator_HPP

