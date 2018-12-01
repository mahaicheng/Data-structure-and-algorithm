/*************************************************************************
        > 文件名: gcd.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月10日 星期四 14时43分29秒
 ************************************************************************/

#include <cassert>

template <typename E>
void swap(E& lhs, E& rhs) {
  E temp = lhs;
  lhs = rhs;
  rhs = temp;
}

long gcd(long m, long n) {
  assert(m > 0 && n > 0);
  if (m < n) {
    swap(m, n);
  }

  long rem;
  while (n != 0) {
    rem = m % n;
    m = n;
    n = rem;
  }

  return m;
}
