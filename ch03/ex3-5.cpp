/*************************************************************************
	> 文件名: ex3-5.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月30日 星期三 18时47分25秒
 ************************************************************************/

#include<list>

using std::list;

template<typename T>
list<T> listHebin(const list<T>& lhs, const list<T>& rhs)
{
    auto lhsIter = lhs.cbegin();
    auto rhsIter = rhs.cbegin();
    list<T> out;

    while(lhsIter != lhs.cend() && rhsIter != rhs.cend())
    {   //process the same length of these two list
        if(*lhsIter < *rhsIter){
            if(out.back() != *lhsIter)
                out.push_back(*lhsIter);
            while(*lhsIter < *rhsIter) ++lhsIter;
        }
        else if(*lhsIter > *rhsIter){
            if(out.back() != *rhsIter)
                out.push_back(*rhsIter);
            while(*lhsIter > *rhsIter) ++rhsIter;
        }
        else{
            if(out.back() != *lhsIter)
                out.push_back(*lhsIter);
            while(*lhsIter == *rhsIter && *lhsIter == out.back()){
                ++lhsIter;
                ++rhsIter;
            }
        }
    }
    if(lhsIter != lhs.cend()){      //list lhs is longer than list rhs
        while(lhsIter != lhs.cend()){
            if(out.back() != *lhsIter)
                out.push_back(*lhsIter);
            ++lhsIter;
        }
    }
    else{
        while(rhsIter != rhs.cend()){
            if(out.back() != *rhsIter)
                out.push_back(*rhsIter);
            ++rhsIter;
        }
    }
    return out;
}
