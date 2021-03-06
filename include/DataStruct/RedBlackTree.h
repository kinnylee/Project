#ifndef _REDBLACKTREE_H_
#define _REDBLACKTREE_H_

#include "DataStruct_Global.h"
#include "DataType.h"

class DATASTRUCT_EXPORT RedBlackTree
{
public:
    RedBlackTree(int nRootKey = -1);
    ~RedBlackTree();

    void LeftRotate(RedBlackNode *pNode);
    void RightRotate(RedBlackNode *pNode);
    void RBInsert(RedBlackNode *pNode);
    void RBDelete(RedBlackNode *pNode);

    RedBlackNode* Mininum(RedBlackNode *pNode = nullptr );

private:
    RedBlackNode* NewNode(int nKey, NodeColor color);
    void RBInsertFix(RedBlackNode *pNode);
    void RBDeleteFix(RedBlackNode *pNode);
    void RBTransplant(RedBlackNode *pObject, RedBlackNode *pSubject);

private:
    RedBlackNode *m_pRoot;
    RedBlackNode *m_pNull;
};
#endif // !_REDBLACKTREE_H_
