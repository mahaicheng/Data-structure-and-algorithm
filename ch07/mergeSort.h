/*************************************************************************
	> 文件名: mergeSort.h
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年10月22日 星期四 12时17分22秒
 ************************************************************************/

#ifndef _MERGESORT_H_
#define _MERGESORT_H_

#include<vector>
using std::vector;
namespace mhc
{
    template<typename T>
    void merge(vector<T>& a, vector<T>& tmpArray, int leftPos, int rightPos, int rightEnd)
    {
        int leftEnd = rightPos - 1;
        int tmpPos = leftPos;
        int numElements = rightEnd - leftPos + 1;

        while(leftPos <= leftEnd && rightPos <= rightEnd)
        {
            if(a[leftPos] <= a[rightPos])
                tmpArray[tmpPos++] = a[leftPos++];
            else
                tmpArray[tmpPos++] = a[rightPos++];
        }

        while(leftPos <= leftEnd)
            tmpArray[tmpPos++] = a[leftPos++];
        while(rightPos <= rightEnd)
            tmpArray[tmpPos++] = a[rightPos++];

        for(int i = 0; i < numElements; i++, rightEnd--)
            a[rightEnd] = tmpArray[rightEnd];
    }
    template<typename T>
    void mergeSortHelp(vector<T>& a, vector<T>& tmpArray, int left, int right)
    {
        if(left < right){
            int center = (left + right) / 2;
            mergeSortHelp(a, tmpArray, left, center);
            mergeSortHelp(a, tmpArray, center+1, right);
            merge(a, tmpArray, left, center+1, right);
        }
    }

    template<typename T>
    void mergeSort(vector<T>& a)
    {
        vector<T> tmpArray(a.size());
        mergeSortHelp(a, tmpArray, 0, a.size()-1);
    }
}
#endif
