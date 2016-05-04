/*************************************************************************
	> 文件名: ex3-4.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月30日 星期三 17时02分50秒
 ************************************************************************/
//assume both input lists are sorted and each element is unique
#include<list>
using std::list;
template<typename T>
 list<T> listUnion(const list<T>& lhs, const list<T>& rhs)
 {
     list<T> out;
    auto lhsIter = lhs.cbegin();
    auto rhsIter = rhs.cbegin();
    while(lhsIter != lhs.cend() && rhsIter != rhs.cend())
     {
         if(*lhsIter == *rhsIter){
            out.push_back(*lhsIter);
             ++lhsIter;
             ++rhsIter;
             while(*lhsIter == out.back() && lhsIter != lhs.cend()) 
                ++lhsIter;
             while(*rhsIter == out.back() && rhsIter != rhs.cend()) 
                ++rhsIter;
         }else if(*lhsIter < *rhsIter){
             ++lhsIter;
         }
         else{
             ++rhsIter;
         }
     }
     return out;
 }
