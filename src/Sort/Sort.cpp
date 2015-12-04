#include <stdlib.h>

#include "Common.h"

#include "Sort.h"
#include "Find.h"

void Sort::InsertSort(int a[], int n)
{
    InsertSortSub(a, 0, n - 1);
}

void Sort::RecursionInsertSort(int a[], int n)
{
    if (n > 1)
    {
        RecursionInsertSort(a, n - 1);
        RecursionInsertSortSub(a, n - 1);
    }
}

void Sort::RecursionInsertSortSub(int a[], int nPos)
{
    int key = a[nPos];
    while (nPos >= 0 && a[nPos - 1] > key)
    {
        a[nPos] = a[nPos - 1];
        nPos--;
    }
    a[nPos] = key;
}

void Sort::SelectSort(int a[], int n)
{

}

void Sort::MergeSort(int a[], int n)
{
    MergeSub(a, 0, n - 1);
}

void Sort::MergeSub(int a[], int nLow, int nHigh)
{
    if (nLow < nHigh)
    {
        int nMid = (nLow + nHigh) / 2;
        MergeSub(a, nLow, nMid);
        MergeSub(a, nMid + 1, nHigh);
        Merge(a, nLow, nMid, nHigh);
    }
}

void Sort::Merge(int a[], int p, int q, int r)
{
    int m = q - p + 1;
    int n = r - q;
    int i = 0, j = 0, k = 0;

    int *left = new int(m);
    for (i = 0; i < m; ++i)
    {
        left[i] = a[p + i];
    }
    int *right = new int(n);
    for (j = 0; j < n; ++j)
    {
        right[j] = a[q + 1 + j];
    }

    i = j = 0;
    k = p;
    while (i < m && j < n)
    {
        if (left[i] <= right[j])
        {
            a[k++] = left[i++];
        }
        else
        {
            a[k++] = right[j++];
        }
    }

    while (i < m)
    {
        a[k++] = left[i++];
    }

    while (j < n)
    {
        a[k++] = right[j++];
    }
}

void Sort::BinaryInsertSort(int a[], int n)
{
    for (int j = 1; j < n; ++j)
    {
        int key = a[j];
        int i = j - 1;
        int nPos = Find::BinaryLocation(a, 0, i, key);
        while (nPos <= i)
        {
            a[i+1] = a[i];
            i--;
        }
        a[nPos] = key;
    }
}

void Sort::MergeInsertSort(int a[], int n)
{
    MergeInsertSortSub(a, 0, n - 1, 4);
}

void Sort::MergeInsertSortSub(int a[], int nLow, int nHigh, int k)
{
    if (nLow < nHigh)
    {
        int nMid = (nHigh - nLow) / 2;

        //if the size lower than k, use insert sort the sub array
        if (nMid + 1 <= k)
        {
            //insert the sub array, size <= k
            InsertSortSub(a, nLow, nLow + nMid);
            InsertSortSub(a, nLow + nMid + 1, nHigh);
        }
        //else recursion
        else
        {
            MergeInsertSortSub(a, nLow, nMid, k);
            MergeInsertSortSub(a, nMid + 1, nHigh, k);
        }

        //merge the sub array
        Merge(a, nLow, nLow + nMid, nHigh);
    }
}

void Sort::InsertSortSub(int a[], int nLow, int nHigh)
{
    for (int j = nLow + 1; j <= nHigh; ++j)
    {
        int i = j - 1;
        int key = a[j];
        while (i >= nLow && key < a[i])
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
}

void Sort::BubbleSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= i; --j)
        {
            if (a[j] < a[j - 1])
            {
                Common::Swap(a[j], a[j - 1]);
            }
        }
    }
}

void Sort::HeapSort(int a[], int n)
{
    BuildMaxHeap(a, n);
    for (int i = n - 1; i > 0; i--)
    {
        Common::Swap(a[0], a[i]);
        MaxHeapify(a, n, 0);
    }
}

void Sort::MaxHeapify(int a[], int n, int nIndex)
{
    int nLeftChild = (nIndex > 1);
    int nRightChild = nLeftChild + 1;

    //find the max
    int nLargest = nIndex;
    if (nLeftChild <= n && a[nLeftChild] > a[nIndex])
    {
        nLargest = nLeftChild;
    }
    if (nRightChild <= n && a[nRightChild] > nLargest)
    {
        nLargest = nRightChild;
    }

    //if nIndex is not max, exchange it
    if (nLargest != a[nIndex])
    {
        Common::Swap(a[nIndex], a[nLargest]);
        //maybe already not a max heap 
        MaxHeapify(a, n, nLargest);
    }
}

void Sort::BuildMaxHeap(int a[], int n)
{
    for (int i = n / 2; i >= 0; --i)
    {
        MaxHeapify(a, n, i);
    }
}

void Sort::QuickSort(int a[], int n)
{
    QuickSortSub(a, 0, n - 1);
}

void Sort::QuickSortSub(int a[], int nLow, int nHigh)
{
    if (nLow < nHigh)
    {
        int q = Partition(a, nLow, nHigh);
        QuickSortSub(a, nLow, q - 1);
        QuickSortSub(a, q + 1, nHigh);
    }
}

int Sort::Partition(int a[], int nLow, int nHigh)
{
    int nBase = a[nLow];
    int i = nLow, j = nHigh;
    while (i < j)
    {
        while (i < j && a[j] >= nBase)
        {
            --j;
        }
        if (i < j)
        {
            a[i++] = a[j];
        }

        while (i < j && a[i] < nBase)
        {
            ++i;
        }
        if (i < j)
        {
            a[j--] = a[i];
        }
    }
    a[i] = nBase;
    return i;
}

void Sort::RandQuickSort(int a[], int n)
{
    RandQuickSortSub(a, 0, n - 1);
}

void Sort::RandQuickSortSub(int a[], int nLow, int nHigh)
{
    if (nLow < nHigh)
    {
        int q = RandParition(a, nLow, nHigh);
        RandQuickSortSub(a, nLow, q - 1);
        RandQuickSortSub(a, q + 1, nHigh);
    }
}

int Sort::RandParition(int a[], int nLow, int nHigh)
{
    int i = Common::RandInt(nLow, nHigh);
    Common::Swap(a[i], a[nLow]);
    return Partition(a, nLow, nHigh);
}

void Sort::QuickInsertSort(int a[], int n)
{
    QuickInsertSortSub(a, 0, n - 1, 3);
    InsertSort(a, n);
}

void Sort::QuickInsertSortSub(int a[], int nLow, int nHigh, int k)
{
    if (nLow < nHigh)
    {
        int q = RandParition(a, nLow, nHigh);
        if (q - nLow >= k)
        {
            QuickInsertSortSub(a, nLow, q - 1, k);
        }
        if (nHigh - q >= k)
        {
            QuickInsertSortSub(a, q + 1, nHigh, k);
        }
    }
}

