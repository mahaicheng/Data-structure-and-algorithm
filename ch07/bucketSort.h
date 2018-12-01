/*************************************************************************
        > 文件名: bucketSort.h
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月22日 星期四 16时37分28秒
 ************************************************************************/

#ifndef _BUCKETSORT_H_
#define _BUCKETSORT_H_

#include <vector>
using std::vector;
namespace mhc {
void bucketSort(vector<int>& a, int M) {
  int array[M] = {0};
  for (int i = 0; i < a.size(); ++i) {
    array[a[i]]++;  // is similar to unordered_map
  }

  a.clear();
  for (int i = 0; i < M; ++i) {
    if (array[i] != 0) a.push_back(i);
  }
}
}  // namespace mhc
#endif
