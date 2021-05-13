/*面试题目9_扩展：用两个队列实现一个栈。
队列的声明如下，请实现它的两个函数`appendTail` 和 `deleteHead`，分别完成在队列尾部插入节点和队列头部删除节点的功能。
template <typename T> class CStack
{
 public:
 CStack(void);
 ~CStack(void);

 void push(const T& node);
 T pop();

 private:
 std::queue <T> queue1;
 std::queue <T> queue2;
};*/
#include <iostream>
#include <queue>
#include <stack>

template <typename T> class CStack
{
 public:
 CStack(void);
 ~CStack(void);

 void push(const T& node);
 T pop();

 private:
 std::queue <T> queue1;
 std::queue <T> queue2;
};

template <typename T>
void CStack<T>::push(const T& node) //入队
{
    if ( queue1.size() > 0)
    {
        queue1.push(node);
    }
    else
    {
        queue2.push(node);
    }
}

template <typename T>  //出队
T CStack<T>::pop()
{
    T Top; 
    T temp;

    if ( queue1.size() <= 0 && queue2.size() <= 0)
    {
        return -1;
    }
    if ( queue1.size() <=0  && queue2 > 0 ) //数据在queue1中，就将queue1的数据放到queue2中。(还有一个情况是，queue1和queue2都为空。)
    {
        if ( queue2.size() <= 0 ) //queue2为空，queue1数据出队到queue2
        {
            while ( queue1.size() != 1 )
            {
                temp = queue1.front();
                queue2.push(temp);
                queue1.pop();
            }

            Top  = queue1.back();
            queue1.pop();
        }
        
    }
    else
    {
        if ( queue1.size() <= 0 ) 
        {
            while ( queue2.size() != 1 )
            {
                temp = queue2.front();
                queue1.push(temp);
                queue2.pop();
            }

            Top  = queue2.back();
            queue2.pop();
        }
    }

    return Top;
}