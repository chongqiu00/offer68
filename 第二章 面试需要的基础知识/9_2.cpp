/*������Ŀ9_��չ������������ʵ��һ��ջ��
���е��������£���ʵ��������������`appendTail` �� `deleteHead`���ֱ�����ڶ���β������ڵ�Ͷ���ͷ��ɾ���ڵ�Ĺ��ܡ�
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
void CStack<T>::push(const T& node) //���
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

template <typename T>  //����
T CStack<T>::pop()
{
    T Top; 
    T temp;

    if ( queue1.size() <= 0 && queue2.size() <= 0)
    {
        return -1;
    }
    if ( queue1.size() <=0  && queue2 > 0 ) //������queue1�У��ͽ�queue1�����ݷŵ�queue2�С�(����һ������ǣ�queue1��queue2��Ϊ�ա�)
    {
        if ( queue2.size() <= 0 ) //queue2Ϊ�գ�queue1���ݳ��ӵ�queue2
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