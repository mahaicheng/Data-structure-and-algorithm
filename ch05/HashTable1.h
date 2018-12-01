/*************************************************************************
        > 文件名: HashTable1.h
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月15日 星期四 10时04分27秒
 ************************************************************************/

#ifndef _HASHTABLE1_H_
#define _HASHTABLE1_H_
#include <vector>
namespace mhc {
int hash(const int item) { return item; }

int hash(const string& item) {
  hashVal = 0;
  for (auto i = 0; i < item.size(); ++i) {
    hashVal += hashVal * 37 + item[i];
  }
  return hashVal;
}

template <typename T>
int hash(const T& item) {}

template <typename T>
class HashTable1 {
 public:
  enum EntryType { ACTIVE, EMPTY, DELETED };
  explicit HashTable1(int size = 101) : array(nextPrime(size)) { makeEmpty(); }
  bool contains(const T& item) const { return isActive(findPos(item)); }
  void makeEmpty() {
    for (auto i = 0; i < array.size(); ++i) {
      array[i].info = EMPTY;
    }
    currentSize = 0;
  }
  bool insert(const T& item) {
    int currentPos = findPos(item);
    if (isActive(currentPos)) return false;

    array[currentPos] = HashEntry(item, ACTIVE);

    if (++currentSize > array.size() / 2) rehash();

    return true;
  }
  bool remove(const T& item) {
    int currentPos = findPos(item);
    if (!isActive(currentPos)) return false;

    array[currentPos].info = DELETED;
    return true;
  }

 private:
  struct HashEntry {
    T element;
    EntryType info;
    HashEntry(const T& item = T(), EntryType i = EMPTY)
        : element(item), info(i) {}
  };

  vector<T> array;
  int currentSize;

  bool isActive(int currentPos) const {
    return array[currentPos].info == ACTIVE;
  }
  int findPos(const T& item) const {
    int currentPos = myhash(item);

    int offset = 1;
    while (array[currentPos].info != EMPTY && array[currentPos].element != x) {
      currentPos += offset;
      offset += 2;

      if (currentPos >= array.size()) currentPos -= array.size();
    }
    return currentPos;
  }
  void rehash() {
    vector<T> oldArray = array;

    array.resize(nextPrime(2 * array.size()));

    for (auto i = 0; i < array.size(); ++i) {
      array[i].info = EMPTY;
    }
    currentSize = 0;
    for (auto i = 0; i < oldArray.size(); ++i) {
      if (oldArray[i].info == ACTIVE) insert(oldArray[i].element);
    }
  }
  int myhash(const T& item) {
    int hashVal = hash(item);
    hashVal %= array.size();

    if (hashVal < 0) hashVal += array.size();
    return hashVal;
  }
};
}  // namespace mhc
#endif
