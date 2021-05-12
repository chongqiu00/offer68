/*
剑指offer：
构造一个类时，三种不同情况下的字节数。
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
    std::cout << sizeof(A) << std::endl; // 1 (编译器决定，即是空的，你定义了，机器就要区别他，给他一个地址空间)
    std::cout << sizeof(B) << std::endl; // 1 (创建一个类的时候本来就是调用了默认构造和默然析构，与上原因一致)
    std::cout << sizeof(C) << std::endl; // 8 （虚函数创建时，需要创建一个虚函数表，即要给一个地址，由当前使用的是多少位的操作系统决定。）


    return 0;
}