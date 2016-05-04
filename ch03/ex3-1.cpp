/*************************************************************************
	> 文件名: ex3-1.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月24日 星期四 22时19分42秒
 ************************************************************************/

#include<list>
#include<iostream>
using namespace std;

template<typename T>
void printLots(list<T> L, list<int> P)
{
    for(auto Piter = P.begin(); Piter != P.end(); ++Piter)
    {
        int pos = 0;
        auto Liter = L.begin();
        while(pos != *Piter - 1 && Liter != L.end()){
            ++pos;
            ++Liter;
        }
        if(Liter != L.end())
            cout<<*Liter<<endl;
    }
}

int main()
{
    list<string> name{"mahaicheng", "madongmei", "machiehngjian", "liuchunling"};
    list<int> age{1,2,3,4};
    list<int> agi{1,4,3};
    printLots(name, age);
    cout<<endl;
    printLots(name, agi);
}
