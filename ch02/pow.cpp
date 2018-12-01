/*************************************************************************
        > 文件名: pow.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月10日 星期四 15时01分01秒
 ************************************************************************/

#include <cassert>

bool even(uint64_t item) {
  if ((item & 1) == 0) {
    return true;
  } else {
    return false;
  }
}

unsigned long pow(unsigned int base, unsigned int power) {
  assert(power > 0);

  if (power == 1) {
    return base;
  }

  if (even(power)) {
    return pow(base, power / 2) * pow(base, power / 2);
  } else {
    return pow(base, power / 2) * pow(base, power / 2) * base;
  }
}
