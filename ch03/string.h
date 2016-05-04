/*************************************************************************
	> 文件名: string.h
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年02月29日 星期一 20时01分20秒
 ************************************************************************/

#ifndef _STRING_H_
#define _STRING_H_

namespace mhc
{
    template<typename T>
    class string final
    {

    public:

        typedef char* iterator;
        typedef const char* const_iterator;

        string() : data(new char[1]), length(0) { data[0] = '\0'; }
        string(const string& str)
        {

        }
        const string& operator=(const string& str)
        {
            
        }
        string(string&& str)
        {

        }
        ~string()
        {
            delete [] data;
            data = nullptr;
        }
        const_iterator begin() const
        {
            return &data[0];
        }
        const_iterator end() const
        {
            return &data[length];
        }
        iterator begin()
        {
            return &data[0];
        }
        iterator end()
        {
            return &data[length];
        }
        const_iterator cbegin()
        {
            return &data[0];
        }
        const_iterator cend()
        {
            return &data[length];
        }


    private:
        char *data;
        int length;
    };
};

#endif
