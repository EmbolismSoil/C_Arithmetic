#include <vector>
#include <stdlib.h>
#include <iostream>
//#include "quicksort.hpp"
#include "maxheap.hpp"
#include "heapsort.hpp"

int main(void)
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(12);
    vec.push_back(19);
    vec.push_back(8);
    vec.push_back(11);
    HeapBuild(vec);

    for (std::vector<int>::iterator pos = vec.begin();
                                            pos != vec.end(); ++pos){
        std::cout << *pos << " ";
    }
    std::cout << std::endl;
}
