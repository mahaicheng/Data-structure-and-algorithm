/*************************************************************************
        > 文件名: insertionSortTest.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月22日 星期四 17时25分23秒
 ************************************************************************/

#include <iostream>
#include "insertionSort.h"
using namespace std;
using namespace mhc;

int main() {
  vector<int> a{3, 1, 4, 1, 5, 9, 2, 6, 5};
  insertionSort(a);

  for (auto i = 0; i < a.size(); ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}
