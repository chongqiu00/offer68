/*������10��쳲��������С�
��쳲��������еĵ�n�дһ������������n����쳲��������У�Fibonacci�����еĵ�n�
0, 1, 1, 2, 3, 5, 8, 13, 21...*/

#include <iostream>

long long Fibonacci_1(unsigned int n); //�ݹ�
long long Fibonacci_2(unsigned int n); //ѭ��

int main(int argc, char* argv[])
{
    std::cout << Fibonacci_1(44) << std::endl;
    std::cout << Fibonacci_2(44) << std::endl;
    return 0;
}

long long Fibonacci_1(unsigned int n)//�ݹ�
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

long long Fibonacci_2(unsigned int n) //ѭ��
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

