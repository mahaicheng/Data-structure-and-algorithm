/*************************************************************************
	> 文件名: queueTest.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月24日 星期四 21时18分36秒
 ************************************************************************/

#include<iostream>
#include<string>
#include"arrayQueue.h"
using namespace std;
using namespace mhc;

int main()
{
    queue<string> name;
    name.enqueue("mahaicheng");
    name.enqueue("madongmei");
    cout<<name.empty()<<endl;
    cout<<name.length()<<endl;
    cout<<name.dequeue()<<endl;
    cout<<name.dequeue()<<endl;
}
