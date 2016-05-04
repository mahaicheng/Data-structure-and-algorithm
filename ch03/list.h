/*************************************************************************
	> 文件名: list.h
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月24日 星期四 16时02分46秒
 ************************************************************************/

#ifndef _LIST_H_
#define _LIST_H_
namespace mhc
{
template<typename T>
class list
{
private:
    struct Node
    {
        Node(const T& it = T(), Node* pr = nullptr, Node* ne = nullptr) : data(it), prev(pr), next(ne) {  }

        T data;
        Node* prev;
        Node* next;
    };

public:
    class const_iterator
    {
    public:
        const_iterator() : current(nullptr) {  }

        const T& operator*() const
        {
            return retrieve();
        }

        const_iterator& operator++()
        {
            current = current->next;
            return *this;
        }

        const_iterator& operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        const_iterator& operator--()
        {
            current = current->prev;
            return *this;
        }

        const_iterator operator--(int)
        {
            const_iterator old = *this;
            --(*this);
            return old;
        }

        bool operator==(const const_iterator& rhs) const
        {
            return current == rhs.current;
        }

        bool operator!=(const const_iterator& rhs) const
        {
            return !(*this == rhs);
        }

    protected:
        Node* current;

        T& retrieve() const
        {
            return current->data;
        }

        const_iterator(Node* p) : current(p) {  }
        friend class list<T>;
    };

    class iterator : public const_iterator
    {
        using const_iterator::current;      //不是继承下来了吗? 为什么会覆盖?
        using const_iterator::retrieve;
    public:
        iterator() {  }

        T& operator*()
        {
            return retrieve();
        }

        const T& operator*() const
        {
            return retrieve();
        }
        
        iterator& operator++()
        {
            current = current->next;
            return *this;
        }

        iterator operator++(int)
        {
            iterator old = *this;
            ++(*this);
            return old;
        }

        iterator& operator--()
        {
            current = current->prev;
            return *this;
        }

        iterator operator--(int)
        {
            iterator old = *this;
            --(*this);
            return old;
        }

        protected:
        iterator(Node* p) : const_iterator(p) {  }

        friend class list<T>;
    };

public:
    list()
    {
        init();
    }

    list(const list& rhs)
    {
        init();
        *this = rhs;
    }

    const list& operator=(const list& rhs)
    {
        if(this != &rhs)
        {
            clear();
            for(const_iterator iter = rhs.begin(); iter != rhs.end(); ++iter){
                push_back(*iter);
            }
        }
        return *this;
    }

    ~list()
    {
        clear();
        delete head;
        delete tail;
    }

    iterator begin()
    {
        return iterator(head->next);
    }

    iterator end()
    {
        return iterator(tail);
    }

    const_iterator begin() const
    {
        return const_iterator(head->next);
    }

    const_iterator end() const
    {
        return const_iterator(tail);
    }

    int size() const
    {
        return theSize;
    }

    bool empty() const
    {
        return theSize == 0;
    }

    void clear()
    {
        erase(begin(), end());
    }

    const T& front() const
    {
        return *begin();
    }

    const T& back() const
    {
        return *(--end());
    }

    void push_back(const T& data)
    {
        insert(end(), data);
    }

    void push_front(const T& data)
    {
        insert(begin(), data);
    }

    void pop_back()
    {
        erase(--end());
    }

    void pop_front()
    {
        erase(begin());
    }

    iterator insert(iterator curpos, const T& data)
    {
        Node* p = curpos.current;
        Node* insertNode = new Node(data, p->prev, p);
        p->prev->next = insertNode;
        p->prev = insertNode;
        ++theSize;
        return iterator(insertNode);
    }

    iterator erase(iterator pos)
    {
        Node* curr = pos.current;
        if(curr == head || curr == tail)
            return tail;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        --theSize;
        iterator iter(curr->next);
        delete curr;
        return iter;
    }

    iterator erase(iterator start, iterator end)
    {
        for(iterator iter = start; iter != end; )
            iter = erase(iter);

        return end;
    }

private:
    int theSize;
    Node* head;
    Node* tail;

    void init()
    {
        theSize = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        head->prev = tail->next = nullptr;
    }
};
};
#endif
