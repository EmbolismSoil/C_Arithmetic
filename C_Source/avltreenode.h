#ifndef AVLTREENODE_H
#define AVLTREENODE_H
#include <utility>

#define nullptr NULL
namespace Algorithms {
    template <class __Key, class __Vaule>
    class AVLTreeNode
    {
    public:
        typedef   typename std::pair<__Key, __Vaule>::first_type key_type;
        typedef   typename std::pair<__Key, __Vaule>::second_type value_type;
        typedef enum{LH, RH, EQ}NODE_STATUE;

        AVLTreeNode(key_type key, value_type value):
            _Node(key, value),
            _status(EQ),
            _leftChild(nullptr),
            _rightChild(nullptr){}
        static inline bool IsNull(AVLTreeNode *ptr){
            return ptr == nullptr  ?  true : false;
        }
        AVLTreeNode *getLeftChild(){
            return _leftChild;
        }
        AVLTreeNode *getRightChild(){
            return _rightChild;
        }
        void setLeftChild(AVLTreeNode *left){
            _leftChild = left;
        }
        void setRightChild(AVLTreeNode *right){
            _rightChild = right;
        }
        key_type getKey(){
            return _Node.first;
        }
        value_type getValue(){
            return _Node.second;
        }

        NODE_STATUE  NodeStatus(){
            return _status;
        }

      void setStatus(NODE_STATUE status){
          _status = status;
      }
    private:
        std::pair<key_type, value_type> _Node;
        NODE_STATUE _status;
        AVLTreeNode *_leftChild;
        AVLTreeNode *_rightChild;
    };

    template <class __Key, class __Value>
        void R_Rotate(AVLTreeNode<__Key, __Value> *&ptrTree)
        {
            AVLTreeNode<__Key, __Value> *ptrRChild = ptrTree->getRightChild();
            if (ptrRChild->NodeStatus() == AVLTreeNode<__Key, __Value>::LH){
                //RL Rotate
                 AVLTreeNode<__Key, __Value> *ptrRLChild = ptrRChild->getLeftChild();
                ptrRChild->setLeftChild(ptrRLChild->getRightChild());
                ptrRLChild->setRightChild(ptrRChild);
                ptrTree->setRightChild(ptrRLChild->getLeftChild());
                ptrRLChild->setLeftChild(ptrTree);
                if (ptrRLChild->NodeStatus() == AVLTreeNode<__Key, __Value>::EQ){
                    ptrRChild->setStatus(AVLTreeNode<__Key, __Value>::EQ);
                    ptrTree->setStatus(AVLTreeNode<__Key, __Value>::EQ);
                }else if (ptrRLChild->NodeStatus() == AVLTreeNode<__Key, __Value>::LH){
                    ptrTree->setStatus(AVLTreeNode<__Key, __Value>::EQ);
                    ptrRChild->setStatus(AVLTreeNode<__Key, __Value>::RH);
                }else if (ptrRLChild->NodeStatus() == AVLTreeNode<__Key, __Value>::RH){
                    ptrTree->setStatus(AVLTreeNode<__Key, __Value>::LH);
                    ptrRChild->setStatus(AVLTreeNode<__Key, __Value>::EQ);
                }
                ptrTree = ptrRLChild;
            }else if (ptrRChild->NodeStatus() == AVLTreeNode<__Key, __Value>::RH){
                //RR Rotate
                ptrTree->setRightChild(ptrRChild->getLeftChild());
                ptrRChild->setLeftChild(ptrTree);
                ptrTree->setStatus(AVLTreeNode<__Key, __Value>::EQ);
                ptrTree = ptrRChild;
            }

            ptrTree->setStatus(AVLTreeNode<__Key, __Value>::EQ);
        }

    template <class __Key, class __Value>
        void L_Rotate(AVLTreeNode<__Key, __Value> *&ptrTree)
        {
            AVLTreeNode<__Key, __Value> *ptrLChild = ptrTree->getLeftChild();
            if (ptrLChild->NodeStatus() == AVLTreeNode<__Key, __Value>::RH){
                //LR Rotate
                AVLTreeNode<__Key, __Value>* ptrLRChild = ptrLChild->getRightChild();
                ptrLChild->setRightChild(ptrLRChild->getLeftChild());
                ptrLRChild->setLeftChild(ptrLChild);
                ptrTree->setLeftChild(ptrLRChild->getRightChild());
                ptrLRChild->setRightChild(ptrTree);
                if (ptrLRChild->NodeStatus() == AVLTreeNode<__Key, __Value>::LH){
                    ptrTree->setStatus(AVLTreeNode<__Key, __Value>::RH);
                    ptrLChild->setStatus(AVLTreeNode<__Key, __Value>::EQ);
                }else if (ptrLRChild->NodeStatus() == AVLTreeNode<__Key, __Value>::EQ){
                    ptrLChild->setStatus(AVLTreeNode<__Key, __Value>::EQ);
                    ptrTree->setStatus(AVLTreeNode<__Key, __Value>::EQ);
                }else if (ptrLRChild->NodeStatus() == AVLTreeNode<__Key, __Value>::RH){
                    ptrTree->setStatus(AVLTreeNode<__Key, __Value>::EQ);
                    ptrLChild->setStatus(AVLTreeNode<__Key, __Value>::LH);
                }
                ptrTree = ptrLRChild;
            }else if (ptrLChild->NodeStatus() == AVLTreeNode<__Key, __Value>::LH){
                //LL Rotate
                ptrTree->setLeftChild(ptrLChild->getRightChild());
                ptrLChild->setRightChild(ptrTree);
                ptrTree->setStatus(AVLTreeNode<__Key, __Value>::EQ);
                ptrTree = ptrLChild;
            }

            ptrTree->setStatus(AVLTreeNode<__Key, __Value>::EQ);
        }

    template <class __Key, class __Value>
        bool AVLInsert(AVLTreeNode<__Key, __Value> *&ptrTree,  AVLTreeNode<__Key, __Value> *node)
        {
            if (AVLTreeNode<__Key, __Value>::IsNull(ptrTree)){
                ptrTree = node;
                return true;
            }else if (node->getKey() > ptrTree->getKey()){
                AVLTreeNode<__Key, __Value> *rChild = ptrTree->getRightChild();
                if(AVLInsert(rChild, node)){
                    ptrTree->setRightChild(rChild);
                    if (ptrTree->NodeStatus() == AVLTreeNode<__Key, __Value>::LH){
                        ptrTree->setStatus(AVLTreeNode<__Key, __Value>::EQ);
                        return false;
                    }else if (ptrTree->NodeStatus() == AVLTreeNode<__Key, __Value>::RH){
                        R_Rotate(ptrTree);
                        return false;
                    }else if (ptrTree->NodeStatus() == AVLTreeNode<__Key, __Value>::EQ){
                        ptrTree->setStatus(AVLTreeNode<__Key, __Value>::RH);
                        return true;
                    }
                }
                ptrTree->setRightChild(rChild);
            }else if (node->getKey()  < ptrTree->getKey()){
                AVLTreeNode<__Key, __Value> *lChild = ptrTree->getLeftChild();
                if (AVLInsert(lChild, node)){
                    ptrTree->setLeftChild(lChild);
                    if (ptrTree->NodeStatus() == AVLTreeNode<__Key, __Value>::RH){
                        ptrTree->setStatus(AVLTreeNode<__Key, __Value>::EQ);
                        return false;
                    }else if (ptrTree->NodeStatus() == AVLTreeNode<__Key, __Value>::EQ){
                        ptrTree->setStatus(AVLTreeNode<__Key, __Value>::LH);
                        return true;
                    }else if (ptrTree->NodeStatus() == AVLTreeNode<__Key, __Value>::LH){
                        L_Rotate(ptrTree);
                        return false;
                    }
                 }
            }

            return false;
        }

    template <class __Key, class __Value>
        void AVLPrint(AVLTreeNode<__Key, __Value> *Node)
        {
            if (AVLTreeNode<__Key, __Value>::IsNull(Node))
                return;
            AVLPrint(Node->getLeftChild());
            std::cout << "  AVL Node, Key = " << Node->getKey() <<
                         " Value = " << Node->getValue() << std::endl;
            AVLPrint(Node->getRightChild());
        }
}



#endif // AVLTREENODE_H
