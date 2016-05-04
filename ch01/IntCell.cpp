/*************************************************************************
	> 文件名: IntCell.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月09日 星期三 16时23分01秒
 ************************************************************************/

#include"IntCell.h"

IntCell::IntCell(int val) : val_(val) {  }

int IntCell::read() const
{
    return val_;
}

void IntCell::write(int val)
{
    val_ = val;
}
