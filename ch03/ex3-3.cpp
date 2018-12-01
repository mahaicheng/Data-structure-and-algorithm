/*************************************************************************
        > 文件名: ex3-3.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月30日 星期三 15时13分02秒
 ************************************************************************/

template <typename Iterator, typename Object>
Iterator find(Iterator start, Iterator end, const Object& value) {
  Iterator iter = start;
  while (iter != end && *iter != value) ++iter;
  return iter;
}
