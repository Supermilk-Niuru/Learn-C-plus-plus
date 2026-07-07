#include<iostream>
using namespace std;
template <typename T>
class basic_operation
{
    private:
        T *data;//指针变量data
        int top;
        int length;
        int Max_size;
    public:
        //创建栈
        void createSqstack(int size)
        {
            Max_size = size;
            data = new T[Max_size];//动态内存分配
            length = 0;
        }
        //析构操作 防止内存泄漏
        ~basic_operation()
        {
            delete[] data;
        }
        //初始化操作
        void InitSqstack()
        {
            top = -1;//将栈顶指针初始化为-1
        }
        //判断栈是否为空
        bool Stackempty()
        {
            if(top==-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        //入栈操作
        bool InsertSqstack(T &val)
        {
            if(top==Max_size-1)
            {
                return false;
            }
            else
            {
                data[++top] = val;
                return true;
            }
        }
        //出栈操作->为了取栈顶元素
        bool PopSqstack(T &val)
        {
            if(top==-1)
            {
                return false;
            }
            else
            {
                val = data[top--];
                return true;
            }
        }
        //取栈顶元素
        int GetTop1()
        {
            if(top==-1)
            {
                return -1;//不过这种写法不太好，万一栈顶元素也是-1呢，并且我会使用一个变量来接收这个值啊
            }
            else
            {
                return data[top];
            }
        }//取栈顶元素比较好的写法
        bool GetTop2(T &val)
        {
            if(top==-1)
            {
                return false;
            }
            else
            {
                val = data[top];//使用C++中的引用传递记录栈顶元素
                return true;
            }
        }
};
