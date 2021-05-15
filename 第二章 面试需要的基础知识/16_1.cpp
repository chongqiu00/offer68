/*面试题16：数值的整数次方
题目：实现函数double Power(double base, int exponent); 求base的exponent次方。
注意：
1）容易忽略负数幂次方。
2）特殊值，0的0次方，是无意义的，可以是0也可以是1；其他数的0次方为1。*/

#include <iostream>
#include <math.h>

double Power(double base, int exponent); 
int main(int argc, char* argv[])
{
    std::cout << Power(2.0, 3) << std::endl;
    std::cout << Power(0, 0) << std::endl;
    std::cout << Power(2, 0) << std::endl;
    std::cout << Power(2, -2) << std::endl;
    return 0;
}
double Power(double base, int exponent)
{
    if ( abs(base) < 0.00000001 )
    {
        return 0;
    }
    if ( exponent == 0 )
    {
        return 1;
    }
    
    double sum = 1;
    if ( exponent > 0){
        while ( exponent != 0 )
        {
            sum *= base;
            exponent--;
        }
    }
    if ( exponent < 0 ){
        exponent *=(-1);
        while ( exponent != 0 )
        {
            sum *= base;
            exponent--;
        }
        sum = 1/sum;
    }
    
    return sum;
}