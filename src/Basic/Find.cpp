#include "Find.h"
#include "Common.h"

int Find::RecusionBinarySearch(int a[], int low, int high, int key)
{
    if (low >= high)
    {
        return -1;
    }
    
    int nMid = (low + high) / 2;
    if (a[nMid] == key)
    {
        return nMid;
    }
    if (a[nMid] > key)
    {
        return RecusionBinarySearch(a, low, nMid, key);
    }
    else
    {
        return RecusionBinarySearch(a, nMid + 1, high, key);
    }
}

int Find::BinarySearch(int a[], int low, int high, int key)
{
    while (low < high)
    {
        int nMid = (low + high) / 2;
        if (a[nMid] == key)
        {
            return nMid;
        }
        else if (a[nMid] > key)
        {
            high = nMid;
        }
        else
        {
            low = nMid + 1;
        }
    }
    return -1;
}

int Find::BinaryLocation(int a[], int low, int high, int key)
{
    while (low <= high)
    {
        int nMid = (low + high) / 2;

        if (a[nMid] >= key)
        {
            high = nMid -1;
        }
        else
        {
            low = nMid + 1;
        }
    }
    return low;
}

bool Find::FindTwoNumber(int a[], int n, int sum)
{
    //sort todo
    //Sort::InsertSort(a, n);

    //sort the array, time complexity:nlgn
   // Sort::MergeSort(a, n);

    bool bResult = false;

    //binray find the x and sum -x
    for (int i = 0; i < n; ++i)
    {
        int nPos1 = Find::BinarySearch(a, 0, n, a[i]);
        int nPos2 = Find::BinarySearch(a, 0, n, sum - a[i]);
        if (nPos1 != -1 && nPos2 != -1)
        {
            bResult = true;
        }
    }
    return bResult;
}

int Find::RandomizedSelect(int a[], int p, int r, int pos)
{
    //if p == r, the pos = 1
    if (p == r)
    {
        return a[p];
    }

    int q = Common::RandParition(a, p, r);
    //min array size
    int k = q - p + 1;
    if (pos == k)
    {
        return a[q];
    }
    else if (pos < k)
    {
        return RandomizedSelect(a, p, q - 1, pos);
    }
    else
    {
        return RandomizedSelect(a, q + 1, r, pos - k);
    }
}

