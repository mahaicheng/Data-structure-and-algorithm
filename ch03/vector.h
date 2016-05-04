/*************************************************************************
	> 文件名: vector.h
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年09月23日 星期三 16时29分05秒
 ************************************************************************/

#ifndef _VECTOR_H_
#define _VECTOR_H_

namespace mhc{
template<typename Object>
class vector
{
public:
    typedef Object* iterator;
    typedef const Object* const_iterator;

    explicit vector(int initSize = 0) : theSize(initSize), theCapacity(theSize+1)
    {
        objects = new Object[theCapacity];
    }

    vector(const vector& rhs)
    {
        theSize = rhs.size();
        theCapacity = rhs.capacity();
        objects = new Object[theCapacity];
        for(int i = 0; i < theSize; ++i){
            objects[i] = rhs[i];
        }
    }

    const Object& operator[](int pos) const
    {
        return objects[pos];
    }

    Object& operator[](int pos)
    {
        return objects[pos];
    }

    const vector& operator=(const vector& rhs)
    {
        if(this != &rhs){
            theSize = rhs.size();
            theCapacity = rhs.capacity();
            delete [] objects;
            objects = new Object[theCapacity];
            for(int i = 0; i < theSize; ++i){
                objects[i] = rhs[i];
            }
        }
        return *this;
    }

    ~vector()
    {
        delete [] objects;
    }

    int capacity() const
    {
        return theCapacity;
    }

    int size() const
    {
        return theSize;
    }

    bool empty() const
    {
        return theSize == 0;
    }

    void reserve(int size)
    {
        if(theCapacity >= size)
            return;
        
        theCapacity = size;
        Object* tmp = new Object[theCapacity];

        for(int i = 0; i < theSize; ++i)
        {
            tmp[i] = objects[i];
        }

        delete [] objects;
        objects = tmp;
        theCapacity = size;
    }

    void resize(int size)   //force to shrank
    {
        if(size > theCapacity)
            reserve(size);
        else{
            theCapacity = size;
            Object* tmp = new Object[theCapacity];
            if(size > theSize){
                for(int i = 0; i < theSize; ++i){
                    tmp[i] = objects[i];
                }
            }
            else{
                for(int i = 0; i < size; ++i){
                    tmp[i] = objects[i];
                }
            }
            delete [] objects;
            objects = tmp;
        }
    }

    void push_back(const Object& item)
    {
        if(theSize == theCapacity)
            reserve(theCapacity * 2);

        objects[theSize++] = item;
    }

    const Object& back() const
    {
        return objects[theSize-1];
    }

    void pop_back()
    {
        --theSize;
    }

    iterator begin()
    {
        return &objects[0];
    }

    iterator end()
    {
        return &objects[theSize];
    }
    
    const_iterator cbegin() const 
    {
        return &objects[0];
    }

    const_iterator cend() const
    {
        return &objects[theSize];
    }

private:
    int theSize;
    int theCapacity;
    Object* objects;
};
};
#endif
