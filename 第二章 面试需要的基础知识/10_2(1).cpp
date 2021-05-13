/*
面试题10_2：青蛙跳台阶。
一只青蛙可以跳上一级台阶，也可以跳2级台阶。求该青蛙跳上一个n级的待解总共有多少种跳法。

思路：
仅有一个台阶时，只有一种。
有两个台阶时，有两种。（一级一级跳，二级跳）
大于两个台阶时f(n)，可以发现的是开始有两种跳法，一级f(n-1)，两级f(n-2)，f(n) = f(n-1) + f(n-2)
*/

#include <iostream>

int qinWa(int n);

int main(int argv, char* argc[])
{
    std::cout << qinWa(5) << std::endl;
    return 0;
}

int qinWa(int n)
{
    int sum;
    if (n==1) return 1;
    if (n==2) return 2;

    return sum = qinWa(n-1) + qinWa(n-2);
}