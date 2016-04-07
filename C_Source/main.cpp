#include <vector>
#include <stdlib.h>
#include <iostream>
#include "quicksort.hpp"
#include "maxheap.hpp"
#include "insertsort.hpp"
#include "randomselect.hpp"
#include "avltreenode.h"

int main(void)
{
    std::vector<int> vec;
    for (int cnt = 0; cnt < 10; ++cnt)
        vec.push_back(random() % 1000);

    std::vector<int>::iterator pos = vec.begin() + 7;
    std::vector<int>::iterator ret = Algorithms::RandomSelect(vec.begin(), vec.end(), pos);
    std::cout << "select pos = " << *ret << std::endl;
    Algorithms::InsertSort(vec.begin(), vec.end());
    for (std::vector<int>::iterator pos = vec.begin();
                                            pos != vec.end(); ++pos){
        std::cout << *pos << " ";
    }
    std::cout << std::endl;

    Algorithms::AVLTreeNode<int, int> *A = new Algorithms::AVLTreeNode<int, int>(1, 1);
    for (int cnt = 2; cnt < 100; ++cnt){
        Algorithms::AVLInsert(A, new Algorithms::AVLTreeNode<int, int>(cnt, cnt));
    }

    AVLPrint(A);
    return 0;
}
