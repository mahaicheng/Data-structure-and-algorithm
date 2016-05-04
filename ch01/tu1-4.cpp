/*************************************************************************
	> 文件名: tu1-4.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月09日 星期三 16时08分14秒
 ************************************************************************/

#include<iostream>
using namespace std;

void printDigit(int n)
{
    cout<<n;
}

void printOut(int n)
{
    if(n >= 10){
        printDigit(n % 10);
        printOut(n / 10);
    }
    else{
        printDigit(n);
    }
}

int main()
{
    printOut(762348933);
}
