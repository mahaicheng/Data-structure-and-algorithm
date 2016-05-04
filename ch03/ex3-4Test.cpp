/*************************************************************************
	> 文件名: ex3-4Test.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月30日 星期三 18时42分34秒
 ************************************************************************/

#include<iostream>
#include"ex3-4.cpp"
using namespace std;

int main()
{
    list<int> lst1{1,2,3,3,4,5,5,5,6,7,7,8,9,9};
    list<int> lst2{1,3,3,4,4,4,6,6,7,8,9,9,9,9};
    auto out = listUnion(lst1, lst2);
    for(auto i : out)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
