/*************************************************************************
	> 文件名: quickSort.h
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年10月22日 星期四 15时15分31秒
 ************************************************************************/
#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include"insertionSort.h"
namespace mhc
{
    template<typename T>
    inline void swap(T& lhs, T& rhs)
    {
        T tmp = lhs;
        lhs = rhs;
        rhs = tmp;
    }
    template<typename T>
    const T& median3(vector<T>& a, int left, int right)
    {
        int center = (left + right) / 2;
        if(a[center] < a[left])
            swap(a[center], a[left]);
        if(a[right] < a[left])
            swap(a[right], a[left]);
        if(a[center] > a[right])
            swap(a[center], a[right]);

        swap(a[center], a[right-1]);
        return a[right-1];
    }
    template<typename T>
    void quickSort(vector<T>& a, int left, int right)
    {
        if(left + 10 <= right){
            T pivot = median3(a, left, right);

            int i = left, j = right - 1;
            while(1){
                while(a[i++] < pivot) ;
                while(a[--j] > pivot) ;
                if(i < j)
                    swap(a[i], a[j]);
                else
                    break;
            }
            swap(a[i], a[right-1]);
            quickSort(a, left, i-1);
            quickSort(a, i+1, right);
        }
        else
            insertionSort(a, left,right);
    }
    template<typename T>
    void quickSort(vector<T>& a)
    {
        quickSort(a, 0, a.size()-1);
    }

    template<typename T>
    void quickSelect(vector<T>& a, int left, int right, int k)
    {
        if(left + 10 <= right){
            T pivot = median3(a, left, right);

            int i = left, j = right-1;
            while(1){
                while(a[i++] < pivot) ;
                while(a[j--] > pivot) ;
                if(i < j)
                    swap(a[i], a[j]);
                else
                    break;
            }
            swap(a[i], a[right-1]);

            if(k <= i)
                quickSelect(a, left, i-1, k);
            else if(k > i+1)
                quickSelect(a, i+1, right, k);
        }
        else
            insertionSort(a, left, right);
    }
}
#endif
