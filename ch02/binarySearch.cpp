/*************************************************************************
        > 文件名: binarySearch.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月10日 星期四 14时33分41秒
 ************************************************************************/
#include <vector>
using std::vector;

template <typename E>
int binarySearch(const vector<E>& EVec, const E& item) {
  int begin = 0, end = EVec.size() - 1;
  int mid = 0;
  while (begin <= end) {
    mid = (begin + end) / 2;
    if (EVec[mid] == item) {
      return mid;
    }

    if (EVec[mid] < item) {
      begin = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1;
}
