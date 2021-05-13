/*面试题目9：用两个栈实现一个队列。
队列的声明如下，请实现它的两个函数`appendTail` 和 `deleteHead`，分别完成在队列尾部插入节点和队列头部删除节点的功能。
template <typename T> class CQueue
{
  public:
  CQueue(void);
  ~CQueue(void);
  
  void appendTail(const T& node);
  T deleteHead();
  
  private:
  stack <T> stack1;
  stack <T> stack2;
}*/
#include <iostream>
#include <stack>
#include <queue>

template <typename T> class CQueue
{
    public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node); //进队
    T deleteHead();     //出队

    private:
    std::stack <T> stack1;
    std::stack <T> stack2;
};
template <typename T>
void CQueue<T>::appendTail( const T& node)
{
    stack1.push( node );
}

template <typename T>
T deleteHead()
{
    T head;     
    T temp;
    if ( stack2.size() <= 0 ) //若stack2中为空，将先将stack1中的数据推入stack2中。
    {
        while(stack1.size() != 0)
        temp = stack1.top();
        stack1.pop();
        stack2.push(temp);
    }
    if ( stack2.size() <= 0) //推入后若stack2的容量任然为0
    {
        std::cout << "队列为空！出栈失败！" << std::endl;
        return -1;
    }

    head = stack2.Top(); //开始出队。
    stack2.pop();

    return head;
} 