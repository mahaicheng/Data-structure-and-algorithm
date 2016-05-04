/*************************************************************************
	> 文件名: quickSortTest.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年10月22日 星期四 17时58分07秒
 ************************************************************************/

#include<iostream>
#include"quickSort.h"
using namespace std;
using namespace mhc;

int main()
{
    vector<int> a{3,1,4,1,5,9,2,6,5};
    quickSort(a, 0, a.size()-1);
    for(int i = 0; i < a.size(); ++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
