/*************************************************************************
	> 文件名: vectorTest.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月23日 星期三 17时14分18秒
 ************************************************************************/

#include<iostream>
#include"vector.h"
using namespace std;
using namespace mhc;

int main()
{
    vector<int> iVec;
    cout<<"empty(): "<<(iVec.empty() ? "true" : "false")<<endl;

    for(int i = 0; i < 3; ++i){
        iVec.push_back(i);
    }

    cout<<"size()\n"<<iVec.size()<<"\ncapacity()\n"<<iVec.capacity()<<"\nempty()\n"\
        <<(iVec.empty() ? "true" : "false")<<endl;

    for(auto iter = iVec.cbegin(); iter != iVec.cend(); ++iter){
        cout<<*iter<<" ";
    }
    cout<<endl;

    for(int i = 0; i < 20; ++i){
        iVec.push_back(i);
    }

    for(auto i : iVec)
    {
        cout<<i<<" ";
    }

    cout<<"\nsize()\n"<<iVec.size()<<"\ncapacity()\n"<<iVec.capacity()<<"\nempty()\n"\
        <<(iVec.empty() ? "true" : "false")<<endl;

    iVec[2] = 998;

    for(auto i : iVec)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    int i = 0;
    for(auto iter = iVec.begin(); iter != iVec.end(); ++iter)
    {
        *iter = i++;
        cout<<*iter<<" ";
    }
    cout<<endl;

    for(auto i : iVec)
    {
        cout<<i<<" ";
    }
    cout<<endl<<"size() "<<iVec.size()<<"\ncapacity() "<<iVec.capacity()<<endl;


    vector<int> conIVec(iVec);

    for(auto i : conIVec){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> vec;
    vec = conIVec;

    for(auto i : vec)
    {
        cout<<i<<" ";
    }

    const vector<int> cvec(vec);

    cout<<endl;

    for(auto iter = cvec.cbegin(); iter != cvec.cend(); ++iter)
    {
        cout<<*iter<<" ";
    }

    cout<<endl;

    vec.pop_back();
    cout<<"back(): "<<vec.back()<<endl;
    for(auto i : vec)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
