/*************************************************************************
	> 文件名: stackTest.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月24日 星期四 20时36分53秒
 ************************************************************************/

#include<iostream>
#include<string>
#include"stack.h"
using namespace std;
using namespace mhc;

int main()
{
    stack<string> name;
    name.push("mahaicheng");
    name.push("machengjian");
    cout<<"empty(): "<<name.empty()<<endl;
    cout<<"top(): "<<name.top()<<endl;
    name.push("madongmei");
    cout<<"length(): "<<name.length()<<endl;
    name.pop();
    cout<<"length(): "<<name.length()<<endl;
    name.clear();
    cout<<name.length()<<endl;

}
