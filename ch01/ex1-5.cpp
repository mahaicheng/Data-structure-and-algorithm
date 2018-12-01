/*************************************************************************
        > 文件名: ex1-5.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月09日 星期三 17时13分03秒
 ************************************************************************/

#include <cassert>
#include <iostream>
using namespace std;

int bitNumber(int n) {
  assert(n >= 1);

  // if the number is even, the lower bit is 0. remove it
  while (n % 2 == 0) {
    n = n / 2;
  }

  if (n == 1) {
    return 1;
  } else {
    return bitNumber(n / 2) + 1;
  }
}

int main() {
  for (auto i = 1; i < 2000; ++i) {
    cout << bitNumber(i) << " ";
  }
  cout << endl;
}
