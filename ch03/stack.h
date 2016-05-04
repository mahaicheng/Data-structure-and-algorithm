/*************************************************************************
	> 文件名: stack.h
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月24日 星期四 20时23分11秒
 ************************************************************************/

#ifndef _STACK_H_
#define _STACK_H_
#include"vector.h"
#include<cassert>
namespace mhc
{
template<typename T>
class stack final
{
public:    
    stack() : topOfStack(-1) {  }
    stack(const stack&) = delete;
    const stack& operator=(const stack&) = delete;

    const T& top() const
    {
        assert(topOfStack >= 0);
        return theArray[topOfStack];
    }

    void clear()
    {
        while(!theArray.empty())
            theArray.pop_back();
        topOfStack = -1;
    }

    bool empty() const
    {
        return theArray.empty();
    }

    int length() const
    {
        return theArray.size();
    }

    void push(const T& item)
    {
        theArray.push_back(item);
        ++topOfStack;
    }
    void pop()
    {
        theArray.pop_back();
        --topOfStack;
    }
private:
    vector<T> theArray;
    int topOfStack;
};
};
#endif
