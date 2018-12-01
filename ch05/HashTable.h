/*************************************************************************
        > 文件名: HashTable.h
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月14日 星期三 15时18分28秒
 ************************************************************************/

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_
#include <algorithm>
#include <list>
#include <string>
#include <vector>
namespace mhc {
int hash(const int key) { return key; }
int hash(const string& item) {
  int hashVal = 0;

  for (auto i = 0; i < item.size(); ++i) hashVal = 37 * hashVal + item[i];
  return hashVal;
}
template <typename T>
int hash(const T& item) {
  // being completed by users
}

template <typename T>
class Hashtable {
 public:
  explicit Hashtable(int size = 101) {}
  bool contains(const T& item) const {
    const list<T>& whichList = theList[myHash(item)];
    return find(whichList.cbegin(), whichList.cend(), item) != whichList.cend();
  }
  void makeEmpty() {
    for (auto i = 0; i < theList.size(); ++i) theList[i].clear();
  }
  void insert(const T& item) {
    list<T>& whichList = theList[myHash(item)];
    if (find(whichList.cbegin(), whichList.cend(), item) != whichList.cend())
      return;
    whichList.push_front(item);

    if (++currentSize > theList.size()) rehash();
  }
  void remove(const T& item) {
    list<T>& whichList = theList[myHash(item)];
    auto iter = find(whichList.cbegin(), whichList.cend(), item);
    if (iter == whichList.cend()) return;
    whichList.erase(item);
    --currentSize;
  }

 private:
  vector<list<T>> theList;
  int currentSize;

  void rehash() {
    vector<list<T>> oldList = theList;

    theList.resize(nextPrime(2 * theList.size()));
    for (auto i = 0; i < theList.size(); ++i) {
      theList[i].clear();
    }

    currentSize = 0;
    for (auto i = 0; i < oldList.size(); ++i) {
      auto iter = oldList[i].begin();
      while (iter != oldList[i].end()) insert(*iter++);
    }
  }
  int myHash(const T& item) const  // the actually hash function
  {
    int hashVal = hash(item);
    hashVal %= theList.size();
    if (hashVal < 0) hashVal += theList.size();

    return hashVal;
  }
};
}  // namespace mhc
#endif
