/*************************************************************************
        > 文件名: IntCell.h
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月09日 星期三 16时20分48秒
 ************************************************************************/

#ifndef _INTCELL_H_
#define _INTCELL_H_

class IntCell {
 public:
  explicit IntCell(int val = 0);
  int read() const;
  void write(int x);

 private:
  int val_;
};
#endif
