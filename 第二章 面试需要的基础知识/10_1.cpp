/*面试题10：斐波那契数列。
求斐波那契数列的第n项。写一个函数，输入n，求斐波那契数列（Fibonacci）数列的第n项。
0, 1, 1, 2, 3, 5, 8, 13, 21...*/

#include <iostream>

long long Fibonacci_1(unsigned int n); //递归
long long Fibonacci_2(unsigned int n); //循环

int main(int argc, char* argv[])
{
    std::cout << Fibonacci_1(44) << std::endl;
    std::cout << Fibonacci_2(44) << std::endl;
    return 0;
}

long long Fibonacci_1(unsigned int n)//递归
{
    int ret;

    if ( n == 1 ){
        ret = 0;
    }
    else if ( n == 2 ){
        ret = 1;
    }
    else{
        ret = Fibonacci_1(n-1) + Fibonacci_1(n-2);
    }

    return ret;
}

long long Fibonacci_2(unsigned int n) //循环
{
    if ( n == 1 )   return 0;
    if ( n == 2 )   return 1;

    int a = 0;
    int b = 1;
    int c;
    for ( int i=2; i<n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

