/*************************************************************************
        > 文件名: tu2-8.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月10日 星期四 09时10分18秒
 ************************************************************************/

#include <cassert>
#include <iostream>
#include <vector>
using std::vector;

int maxSubSum(const vector<int>& a) {
  int n = a.size();
  assert(n > 0);
  int maxSum = 0, thisSum = 0;

  for (int i = 0; i < n; ++i) {
    thisSum += a[i];

    if (thisSum > maxSum) {
      maxSum = thisSum;
    } else if (thisSum < 0) {
      thisSum = 0;
    }
  }

  std::cout << "Using tu2-8.cpp" << std::endl;
  return maxSum;
}
