/*
面试题10_2：青蛙跳台阶。(扩展)
一只青蛙可以跳上一级台阶，也可以跳2级台阶...他也可以跳上n级。求该青蛙跳上一个n级的待解总共有多少种跳法。

思路：
数学归纳法可以证明 f(n) = 2^(n-1)。
*/
#include <iostream>
#include <math.h>

int qinWa(int n);

int main(int argc, char* argv[])
{
    std::cout << qinWa(3) << std::endl;
    return 0;
}

int qinWa(int n)
{
    return pow(2, n-1);
}