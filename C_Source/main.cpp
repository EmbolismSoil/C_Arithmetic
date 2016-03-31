#include <vector>
#include <stdlib.h>
#include <iostream>
#include "quicksort.hpp"
#include "maxheap.hpp"
#include "heapsort.hpp"

int main(void)
{
    std::vector<int> vec;
    for (int cnt = 0; cnt < 10; ++cnt)
        vec.push_back(random() % 1000);
    Algorithms::PermuteQuickSort(vec.begin(), vec.end());
    for (std::vector<int>::iterator pos = vec.begin();
                                            pos != vec.end(); ++pos){
        std::cout << *pos << " ";
    }
    std::cout << std::endl;
}
