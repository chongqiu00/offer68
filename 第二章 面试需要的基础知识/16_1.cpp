/*������16����ֵ�������η�
��Ŀ��ʵ�ֺ���double Power(double base, int exponent); ��base��exponent�η���
ע�⣺
1�����׺��Ը����ݴη���
2������ֵ��0��0�η�����������ģ�������0Ҳ������1����������0�η�Ϊ1��*/

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