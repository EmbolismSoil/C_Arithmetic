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
    _Buf.push_back(-1);
}

template <class T>
void MaxHeap<T>::Insert(const T &e)
{
    _Buf.push_back(e);
    typename std::vector<T>::size_type pos = _Buf.size() - 1;
    typename std::vector<T>::size_type parent;
    while(pos > 1){
            parent = pos / 2;
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
    if (_Buf.size() == 1)
        return false;

    x = _Buf[1];
    return true;
}


template <class T>
void MaxHeap<T>::Pop()
{
    _Buf[1] = _Buf[_Buf.size() - 1];
    _Buf.erase(_Buf.end() - 1);

    typename std::vector<T>::size_type pos = 1;
    typename std::vector<T>::size_type end = _Buf.size() - 1;
    typename std::vector<T>::size_type leftChild = 0;
    typename std::vector<T>::size_type rightChild = 0;

    for(;;){
        leftChild = pos * 2;
        rightChild = pos * 2 + 1;

        if (leftChild <= end && rightChild <= end){
            if (_Buf[leftChild] > _Buf[rightChild]){
                if (_Buf[leftChild] > _Buf[pos]){
                    std::swap(_Buf[leftChild], _Buf[pos]);
                    pos = leftChild;
                    continue;
                 }
            }else{
                if (_Buf[rightChild] > _Buf[pos]){
                    std::swap(_Buf[rightChild], _Buf[pos]);
                    pos = rightChild;
                    continue;
                }
            }
        }else if (leftChild <= end){
            if (_Buf[leftChild] > _Buf[pos]){
                std::swap(_Buf[leftChild], _Buf[pos]);
                pos = leftChild;
                continue;
            }
        }else if (rightChild <= end){
            if (_Buf[rightChild] > _Buf[pos]){
                std::swap(_Buf[rightChild], _Buf[rightChild]);
                pos = rightChild;
                continue;
            }
        }else break;
    }
}

#endif // MAXHEAP_H
