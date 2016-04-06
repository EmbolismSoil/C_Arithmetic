#ifndef RANDOMSELECT_HPP
#define RANDOMSELECT_HPP
#include "quicksort.hpp"
#include <vector>

namespace Algorithms {
template <class InputIterator>
    InputIterator RandomSelect(InputIterator begin, InputIterator end,  InputIterator I)
    {
        InputIterator endElemt = end;
        InputIterator beginElemt = begin;
        --endElemt;

        if (beginElemt  == endElemt)
            return beginElemt;

        InputIterator pos = RandomizedPartions(begin, end);
        if (pos > I){
            return RandomSelect(begin, pos, I);
        }else if (pos < I){
            return RandomSelect(++pos, end, I);
        }
            return pos;
    }

}

#endif // RANDOMSELECT_HPP

