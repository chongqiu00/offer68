/*
面试题14：剪绳子
题目：给你一根长度为ｎ的绳子，请把绳子剪成ｍ段（ｍ，ｎ都是整数，ｎ＞１并且ｍ＞１），每段绳子的长度记为ｋ［０］，ｋ［１］，．．．，ｋ［ｍ］。
请问ｋ［０］＊ｋ［１］＊．．．＊ｋ［ｍ］可能的最大乘积是多少？
例如：当绳子的长度是８时，我们把它剪成长度分别为２，３，３的三段，此时得到的最大乘积是１８。

方法一：动态规划
反向递归。将之间的情况先求出来。

*/

#include <iostream>

int maxProductAfterCutting_solution(int length)
{
    int max=0;
    if ( length < 2 )  return 0;
    if ( length == 2 ) return 1;
    if ( length == 3 ) return 2;
    
    int* product = new int [length+1];
    product[0] = 0;
    product[1] = 1;
    product[2] = 2;
    product[3] = 3;

    for ( int i=4; i<=length; i++)
    {
        max = 0;
        for (int j=1; j<=i/2; j++)
        {
            int p = product[j] * product[i-j];
            if ( max < p )  max = p;
            product[i] = max;
        }
    }

    max = product[length];
    delete [] product;

    return max;
}

int main(int argc, char* argv[])
{
    std::cout << maxProductAfterCutting_solution(8) << std::endl;    
    return 0;
}