/*面试题16：数值的整数次方
题目：实现函数double Power(double base, int exponent); 求base的exponent次方。
理解不了啊。
*/

#include <iostream>

double PowerWithUnsingnedExponent(double base, unsigned int exponent)
{
    if ( exponent == 0 )  return 1;
    if ( exponent == 1 )  return base;
    double result = PowerWithUnsingnedExponent( base, exponent>>1);
    result *= result;
    if ( exponent & 0x1 == 1 )  result *= base;

    return result;
}
int main(int argc, char* argv[])
{
    std::cout << PowerWithUnsingnedExponent(2.0, 3) << std::endl;
    return 0;
}