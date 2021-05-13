/*������Ŀ9��������ջʵ��һ�����С�
���е��������£���ʵ��������������`appendTail` �� `deleteHead`���ֱ�����ڶ���β������ڵ�Ͷ���ͷ��ɾ���ڵ�Ĺ��ܡ�
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

    void appendTail(const T& node); //����
    T deleteHead();     //����

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
    if ( stack2.size() <= 0 ) //��stack2��Ϊ�գ����Ƚ�stack1�е���������stack2�С�
    {
        while(stack1.size() != 0)
        temp = stack1.top();
        stack1.pop();
        stack2.push(temp);
    }
    if ( stack2.size() <= 0) //�������stack2��������ȻΪ0
    {
        std::cout << "����Ϊ�գ���ջʧ�ܣ�" << std::endl;
        return -1;
    }

    head = stack2.Top(); //��ʼ���ӡ�
    stack2.pop();

    return head;
} 