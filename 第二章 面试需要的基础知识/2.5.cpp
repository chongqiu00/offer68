/*2.5 计算1+2+3+4+5+...+n
思路1：递归
缺点：1）有时间和空间的消耗。
      2）也许会出现栈溢出。
思路2：循环
思路3：数学技巧
*/

#include <iostream>
//递归
int AddFrom1ToN_1(int n);

//循环
int AddFrom1ToN_2(int n);

int main(int argc, char* argv[])
{
    
    std::cout << AddFrom1ToN_1(2) << std::endl;
    std::cout << AddFrom1ToN_2(2) << std::endl;

    return 0;
}

int AddFrom1ToN_1( int n )
{
    return n<=0? 0 : n+AddFrom1ToN_1(n-1);
}

int AddFrom1ToN_2(int n)
{
    int sum = 0;
    for ( int i = 1; i<=n; i++)
    {
        sum +=i;
    }
    return sum;
}