#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_

#include "DataStruct_Global.h"
#include "DataType.h"

class BinaryTree;

class DATASTRUCT_EXPORT BinarySearchTree
{
public:
    BinarySearchTree(int nRootData = -1);
    ~BinarySearchTree();

    BSearchTreeNode* CursionSearch(int nKey);
    BSearchTreeNode* Search(int nKey, BSearchTreeNode *pNode = nullptr);

    BSearchTreeNode* Minimum(BSearchTreeNode *pNode = nullptr);
    BSearchTreeNode* Maximum(BSearchTreeNode *pNode = nullptr);
    BSearchTreeNode* CursionMinimum(BSearchTreeNode *pNode = nullptr);
    BSearchTreeNode* CursionMaximum(BSearchTreeNode *pNode = nullptr);

    BSearchTreeNode* Successor(BSearchTreeNode *pNode);
    BSearchTreeNode* Predecessor(BSearchTreeNode *pNode);

    BSearchTreeNode* Insert(int nKey);
    BSearchTreeNode* CursionInsert(int nKey);
    void Delete(BSearchTreeNode *pNode);
    void Delete(int nKey);

    void PreOrder();

private:
    BSearchTreeNode* CursionSearch(BSearchTreeNode *pNode, int nKey);
    BSearchTreeNode* CursionInsert(BSearchTreeNode *pNode, int nKey);
    BSearchTreeNode* CursionMinimumSub(BSearchTreeNode *pNode);
    BSearchTreeNode* CursionMaximumSub(BSearchTreeNode *pNode);
    void Transplant(BSearchTreeNode *pObject, BSearchTreeNode *pSubject);
    BSearchTreeNode* NewNode(int nKey);

private:
    BSearchTreeNode *m_pRoot;
    int m_nSize;
};

#endif