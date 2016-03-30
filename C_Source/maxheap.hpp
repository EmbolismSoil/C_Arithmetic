#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>

template <class T>
class MaxHeap
{
public:
    MaxHeap();
    void Insert(const T &);
    bool Top(T &);
    void Pop();

private:
    std::vector<T> _Buf;
};

template <class T>
MaxHeap<T>::MaxHeap()
{

}

template <class T>
void MaxHeap<T>::Insert(const T &e)
{
    _Buf.push_back(e);
    typename std::vector<T>::size_type pos = _Buf.size() - 1;
    typename std::vector<T>::size_type parent;
    while(pos > 0){
            parent = (pos - 1)/ 2;
            if (_Buf[pos] > _Buf[parent]){
                std::swap(_Buf[pos], _Buf[parent]);
                pos = parent;
             }else{
                break;
            }
    }
}


template <class T>
bool MaxHeap<T>::Top(T &x)
{
    if (_Buf.size() == 0)
        return false;

    x = _Buf[0];
    return true;
}


template <class T>
void MaxHeap<T>::Pop()
{
    _Buf[0] = _Buf[_Buf.size() - 1];
    _Buf.erase(_Buf.end() - 1);

    typename std::vector<T>::size_type pos = 1;
    typename std::vector<T>::size_type end = _Buf.size();
    typename std::vector<T>::size_type leftChild = 0;
    typename std::vector<T>::size_type rightChild = 0;
    typename std::vector<T>::size_type max = pos;
    for(;;){
        leftChild = pos * 2;
        rightChild = pos * 2 + 1;

        if (leftChild > end)
                break;

        --leftChild;
        --rightChild;
        if (leftChild <= end && _Buf[leftChild] >  _Buf[pos - 1]){
            max = leftChild;
        }
        if (rightChild <= end && _Buf[rightChild] > _Buf[leftChild]){
            max = rightChild;
        }

        std::swap(_Buf[max], _Buf[pos - 1]);
        pos = max + 1;
    }
}

#endif // MAXHEAP_H
