/*************************************************************************
        > 文件名: ex3-2.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年09月24日 星期四 22时41分30秒
 ************************************************************************/

void swapWithNext(Node* p) {
  Node *beforeP, afterP;
  beforeP = p->prev;
  afterP = p->next;

  p->next = afterP->next;
  beforeP->next = afterP;
  afterP->next = p;

  p->prev = afterP;
  afterP->prev = beforeP;
  p->next->prev = p;
}
