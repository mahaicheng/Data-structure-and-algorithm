/*************************************************************************
	> 文件名: ex3-5Test.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月30日 星期三 19时35分35秒
 ************************************************************************/

#include<iostream>
#include"ex3-5.cpp"
using namespace std;

int main()
{
    list<int> lst1{1,2,2,3,4,6,6,8,9,9,9,10};
    list<int> lst2{1,2,2,3,4,6,7,8,8,8,9};
    auto out = listHebin(lst1, lst2);
    for(auto i : out)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
