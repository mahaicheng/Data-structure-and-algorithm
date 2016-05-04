/*************************************************************************
	> 文件名: shellSort.h
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年10月22日 星期四 08时59分31秒
 ************************************************************************/

#ifndef _SHELLSORT_H_
#define _SHELLSORT_H_

#include<vector>
using std::vector;
namespace mhc
{
    template<typename T>
    void shellSort(vector<T>& a)
    {
        for(int gap = a.size() / 2; gap > 0; gap /= 2){
            for(int index = gap; index < a.size(); index++){
                T tmp = a[index];
                int j;
                for(j = index; j >= gap && tmp < a[j-gap]; j -= gap)
                    a[j] = a[j-gap];
                a[j] = tmp;
            }
        }
    }
}
#endif
