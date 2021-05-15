/*������16����ֵ�������η�
��Ŀ��ʵ�ֺ���double Power(double base, int exponent); ��base��exponent�η���
��ⲻ�˰���
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