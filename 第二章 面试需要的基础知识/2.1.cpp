/*
��ָoffer��
����һ����ʱ�����ֲ�ͬ����µ��ֽ�����
*/

#include <iostream>

class A
{

};

class B
{
  public:
  B()
  {

  }
  ~B()
  {

  }
};

class C
{
    public:
    virtual void cc() = 0;

};

int main(int argc, char* argv[])
{
    std::cout << sizeof(A) << std::endl; // 1 (���������������ǿյģ��㶨���ˣ�������Ҫ������������һ����ַ�ռ�)
    std::cout << sizeof(B) << std::endl; // 1 (����һ�����ʱ�������ǵ�����Ĭ�Ϲ����ĬȻ����������ԭ��һ��)
    std::cout << sizeof(C) << std::endl; // 8 ���麯������ʱ����Ҫ����һ���麯������Ҫ��һ����ַ���ɵ�ǰʹ�õ��Ƕ���λ�Ĳ���ϵͳ��������


    return 0;
}