/*************************************************************************
        > 文件名: DisjSets.h
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月23日 星期五 15时45分35秒
 ************************************************************************/

#ifndef _DISJSETS_H_
#define _DISJSETS_H_
namespace mhc {
class DisjSets {
 public:
  explicit DisjSets(int numElement) : s(numElement) {
    for (int i = 0; i < s.size(); ++i) {
      s[i] = -1;
    }
  }
  int find(int x) const {
    if (s[x] == -1)
      return x;
    else
      return s[x] = find(s[x]);
  }
  int find(int x) {
    if (s[x] == -1)
      return x;
    else
      return find(s[x]);
  }
  void unionSets(int root1,
                 int root2)  // union by height. the two argument must be root
  {
    if (s[root2] < s[root1]) {
      s[root1] = root2;
    } else {
      if (s[root1] == s[root2]) s[root1]--;
      s[root2] = root1;
    }
  }

 private:
  vector<int> s;
};
}  // namespace mhc
#endif
