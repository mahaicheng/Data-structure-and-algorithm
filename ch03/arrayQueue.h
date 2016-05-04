/*************************************************************************
	> 文件名: arrayQueue.h
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月30日 星期三 11时52分31秒
 ************************************************************************/

#ifndef _ARRAYQUEUE_H_
#define _ARRAYQUEUE_H_
namespace mhc
{
    template<typename T>
    class queue final
    {
    public:
        queue(int len = 32)
        {
            thelength = len;
            array = new T[thelength];
            theSize = 0;
            front = back = 0;
        }
        //avoid copy queue
        queue(const queue&) = delete;
        const queue& operator=(const queue&) = delete;
        ~queue()
        {
            delete [] array;
        }
    
        void clear()
        {
            theSize = 0;
            front = back = array[0];
        }

        int length() const 
        {
            return theSize;
        }

        bool empty() const
        {
            return theSize == 0;
        }

        void enqueue(const T& item)
        {
            ++theSize;
            array[back%thelength] = item;
            ++back;
        }

        const T dequeue()
        {
            --theSize;
            T tmp = array[front%thelength];
            ++front;
            return tmp;
        }

    private:
        T* array;
        int theSize;
        int thelength;
        int back;
        int front;
    };
};
#endif
