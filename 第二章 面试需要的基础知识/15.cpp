/*
面试题15：二进制中1的个数
题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。
例如：数字9表示二进制为1001，有2位是1。因此，如果输入为9，则该函数输出为2。

思路：
方法一：通过右移被测数，查看被测数每一位是否为0----》忽略了被测数是负数的情况。

方法二：避免被测数右移，故设置一个标志位1，通过标志位左移，被测数不动，检测被测数每一位是否为1---》当被测数规模较大时，工作量加大。

方法三：避免多次循环，将被测数二进制最后一位变为0，与原被测数相&，若结果不为0，则最末尾变为0的被测数中还有1的位数，故循坏上述过程。
*/

#include <iostream>

int NumberOf1_1(int n);//没有考虑到负数的情况。


int NumberOf1_2(int n);//避免右移，使用左移。
//被测数字不动，使用标志位检测每一位是否为1，为1加一。

int NumberOf1_3(int n);//新奇的方法。将被测数字减一，就是将被测数最后一位变为0，看被测数是否为0,实时检测被测数是否为0，当为0时，检测结束。

int main(int argc, char* argv[])
{
    std::cout << NumberOf1_1(9) << std::endl;
    std::cout << NumberOf1_2(9) << std::endl;
    std::cout << NumberOf1_3(9) << std::endl;

    return 0;
}

int NumberOf1_1(int n)
{
    int count = 0;
    
    while ( n )
    {
        if ( (n&1) == 1)//只取二进制中的最后一位。
        {
            count++;
        }
        n = n>>1;//右移数字，正数补0，负数补1。
    }
    return count;
}

int NumberOf1_2(int n)
{
   int count = 0;
   int flag = 1;

   while ( flag != 0 )
   {
       if ( n & flag )  count++;
       flag = flag<<1;
   }

   return count;
}


int NumberOf1_3(int n)
{
  int count = 0;
  while ( n != 0 )
  {
      ++count;
      n = (n-1) & n;
  }

  return count;
}