#include <iostream>

#include "CyclicLinkList.h"

CyclicLinkList::CyclicLinkList()
{
    m_pHead = new LinkNode;
    m_pHead->m_nData = -1;
    m_pHead->m_pNext = m_pHead;
    m_pTail = m_pHead;
    m_nLength = 0;
}

CyclicLinkList::~CyclicLinkList()
{
    if (nullptr != m_pHead)
    {
        delete m_pHead;
        m_pHead = nullptr;
    }
}

void CyclicLinkList::TailInsert(int nKey)
{
    LinkNode *pNode = new LinkNode;
    pNode->m_nData = nKey;

    //empty
    if (m_pTail == m_pHead)
    {
        m_pHead->m_pNext = pNode;
        pNode->m_pNext = m_pHead;
    }
    else
    {
        pNode->m_pNext = m_pHead;
        m_pTail->m_pNext = pNode;
    }
    m_pTail = pNode;
    ++m_nLength;
}

void CyclicLinkList::FrontInsert(int nKey)
{
    LinkNode *pNode = new LinkNode;
    pNode->m_nData = nKey;

    //empty
    if (m_pTail == m_pHead)
    {
        m_pHead->m_pNext = pNode;
        pNode->m_pNext = m_pHead;
        m_pTail = pNode;
    }
    else
    {
        pNode->m_pNext = m_pHead->m_pNext;
        m_pHead->m_pNext = pNode;
    }
    ++m_nLength;
}

void CyclicLinkList::InceraseInsert(int nKey)
{
    LinkNode *pNode = new LinkNode;
    pNode->m_nData = nKey;

    //empty
    if (m_pTail == m_pHead)
    {
        m_pHead->m_pNext = pNode;
        pNode->m_pNext = m_pHead;
        m_pTail = pNode;
    }
    else
    {
        LinkNode *pTemp = m_pHead->m_pNext;
        LinkNode *pPre = m_pHead;
        while (nullptr != pTemp && pTemp != m_pHead 
            && pTemp->m_nData < nKey)
        {
            pPre = pTemp;
            pTemp = pTemp->m_pNext;
        }
        if (pTemp == m_pHead)
        {
            TailInsert(nKey);
            delete pNode;
            pNode = nullptr;
        }
        else
        {
            pNode->m_pNext = pTemp;
            pPre->m_pNext = pNode;
        }
    }
    ++m_nLength;
}

void CyclicLinkList::Delete(int nKey)
{
    if (m_pHead == m_pTail)
    {
        return;
    }

    LinkNode *pCurr = m_pHead->m_pNext;
    LinkNode *pPer = m_pHead;
    while (nullptr != pCurr && pCurr != m_pHead)
    {
        if (nKey == pCurr->m_nData)
        {
            pPer->m_pNext = pCurr->m_pNext;
            delete pCurr;
            pCurr = nullptr;
        }
        else
        {
            pPer = pCurr;
            pCurr = pCurr->m_pNext;
        }
        
    }

    if (pCurr == m_pTail)
    {
        m_pTail = pPer;
    }
    --m_nLength;
}

int CyclicLinkList::Length()
{
    return m_nLength;
}

void CyclicLinkList::PrintOut()
{
    LinkNode *pNode = m_pHead->m_pNext;
    while (nullptr != pNode && pNode != m_pHead)
    {
        std::cout << pNode->m_nData << std::endl;
        pNode = pNode->m_pNext;
    }
}