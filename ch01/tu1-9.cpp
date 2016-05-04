/*************************************************************************
	> 文件名: tu1-9.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月09日 星期三 16时32分34秒
 ************************************************************************/

#include<iostream>
#include"IntCell.h"
using namespace std;

int main()
{
    IntCell m;
    m.write(5);
    cout<<"Cell's content: "<<m.read()<<endl;
}
