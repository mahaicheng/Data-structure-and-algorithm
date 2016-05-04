/*************************************************************************
	> 文件名: slist.h
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月30日 星期三 20时06分45秒
 ************************************************************************/

#ifndef _SLIST_H_
#define _SLIST_H_
namespace mhc
{
    template<typename T>
    class slist final
    {
        struct Node
        {
            Node(T elem_, Node* ptr) : elem(elem_), next(ptr) {  }
            T elem;
            Node* next;
        };
    public:
        slist() : head(nullptr), theSize(0) {  }
        //avoid copy and assignment
        slist(const slist&) = delete;
        slist& operator=(const slist&) = delete;
        ~slist()
        {
            clear();
        }
        int size() const
        {
            return theSize;   
        }
        bool empty() const
        {
            return theSize == 0;
        }
        bool exist(const T& elem)
        {
            Node* curr = head;
            while(curr != nullptr){
                if(curr->elem == elem)
                    return true;
                curr = curr->next;
            }

            return false;
        }
        void insert(const T& elem)
        {
            if(exist(elem))
                return;     //each element is unique in slist
            Node* curr = head;
            while(curr != nullptr){
                if(curr->elem < elem)
                    break;
                curr = curr->next;
            }
            if(curr == nullptr)
        }
        bool erase(const T& elem)   //if no element to be erase, return -1
        {
            if(!exist(elem))
                return -1;


        }
    private:
        void clear()
        {
            theSize = 0;
            while(head != nullptr){
                Node* tmp = head;
                head = head->next;
                delete tmp;
            }
        }
    private:
        Node* head;
        int theSize;
    };
};
#endif
