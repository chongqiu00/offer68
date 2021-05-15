/*
面试题14：剪绳子
题目：给你一根长度为ｎ的绳子，请把绳子剪成ｍ段（ｍ，ｎ都是整数，ｎ＞１并且ｍ＞１），每段绳子的长度记为ｋ［０］，ｋ［１］，．．．，ｋ［ｍ］。
请问ｋ［０］＊ｋ［１］＊．．．＊ｋ［ｍ］可能的最大乘积是多少？
例如：当绳子的长度是８时，我们把它剪成长度分别为２，３，３的三段，此时得到的最大乘积是１８。

方法一：贪婪算法
就是最大的使用最优的数去相乘，就是尽可能的有数字3去相乘，然后当余数为1时，1+3 ==》1+3 的情况要小于 2+2 ==》2*2。

*/
#include <iostream>
#include <math.h>


int maxProductAfterCutting_solution(int length)
{
    int max=0;
    if ( length < 2 )  return 0;
    if ( length == 2 ) return 1;
    if ( length == 3 ) return 2;
    
    int timesOf3 = length / 3;

    if ( (length - timesOf3*3) == 1 )  --timesOf3;

    int timeOf2 = (length-timesOf3*3) / 2;

    return pow(3, timesOf3)*pow(2, timeOf2);
}

int main(int argc, char* argv[])
{
    std::cout << maxProductAfterCutting_solution(19) << std::endl;    
    return 0;
}