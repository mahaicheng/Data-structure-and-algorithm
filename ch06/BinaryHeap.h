/*************************************************************************
        > 文件名: BinaryHeap.h
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月17日 星期六 15时44分01秒
 ************************************************************************/

#ifndef _BINARYHEAP_H_
#define _BINARYHEAP_H_
namespace mhc {
template <typename T>
class Binaryheap {
 public:
  explicit Binaryheap(int capacity = 100) {}
  explicit Binaryheap(const vector<T>& item)
      : array(item.size() + 10), currentSize(item.size()) {
    for (int i = 0; i < item.size(); ++i) array[i + 1] = item[i];

    buildHeap();
  }
  bool isEmpty() const {}
  const T& findMin() const { return array[1]; }
  void insert(const T& item) {
    if (currentSize == array.size() - 1) array.resize(array.size() * 2);

    int hole = ++currentSize;
    for (; hole > 1 && x < array[hole / 2]; hole /= 2)
      array[hole] = array[hole / 2];

    array[hole] = x;
  }
  void deleteMin() {
    if (isEmpty()) return;

    array[1] = array[--currentSize];
    percolateDdown(1);
  }
  void deleteMin(T& item) {
    item = array[1];
    array[1] = array[--currentSize];
    percolateDdown(1);
  }
  void makeEmpty() {}

 private:
  int currentSize;
  vector<T> array;
  void buildHeap() {
    for (int i = currentSize / 2; i > 0; --i) percolateDdown(i);
  }
  void percolateDdown(int hole) {
    int child;
    T tmp = array[hole];

    for (; hole * 2 <= currentSize; hole = child) {
      child = hole * 2;
      if (child != currentSize && array[child + 1] < array[child])
        child++;  // right child
      if (array[child] < tmp)
        array[hole] = array[child];
      else
        break;
    }
    array[hole] = tmp;
  }
};
}  // namespace mhc
#endif
