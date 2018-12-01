/*************************************************************************
        > 文件名: queue.h
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月24日 星期四 21时09分34秒
 ************************************************************************/

#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "list.h"
namespace mhc {
template <typename T>
class queue {
 public:
  queue() = default;
  // avoid copy queue
  queue(const queue&) = delete;
  const queue& operator=(const queue&) = delete;

  void clear() { lst.clear(); }

  int length() const { return lst.size(); }

  bool empty() const { return lst.empty(); }

  void enqueue(const T& item) { lst.push_back(item); }

  const T dequeue() {
    T tmp = lst.front();
    lst.pop_front();
    return tmp;
  }

 private:
  list<T> lst;
};
};  // namespace mhc
#endif
