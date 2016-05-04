/*************************************************************************
	> 文件名: insertionSort.h
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年10月21日 星期三 15时59分22秒
 ************************************************************************/

#ifndef _INSERTIONSORT_H_
#define _INSERTIONSORT_H_

#include<vector>
using std::vector;
namespace mhc
{
    template<typename T>
    void insertionSort(vector<T>& a)
    {
        int j;
        for(int i = 1; i < a.size(); ++i){
            T tmp = a[i];
            for(j = i; j > 0 && tmp < a[j-1]; j--){
                a[j] = a[j-1];
            }
            a[j] = tmp;
        }
    }

    template<typename T>
    void insertionSort(vector<T>& a, int left, int right)
    {
        int j;
        for(int i = left+1; i <= right; ++i){
            T tmp = a[i];
            for(j = i; j > left && a[j-1] > tmp; --j){
                a[j] = a[j-1];
            }
            a[j] = tmp;
        }
    }
}
#endif
