/*2.5 ����1+2+3+4+5+...+n
˼·1���ݹ�
ȱ�㣺1����ʱ��Ϳռ�����ġ�
      2��Ҳ������ջ�����
˼·2��ѭ��
˼·3����ѧ����
*/

#include <iostream>
//�ݹ�
int AddFrom1ToN_1(int n);

//ѭ��
int AddFrom1ToN_2(int n);

int main(int argc, char* argv[])
{
    
    std::cout << AddFrom1ToN_1(2) << std::endl;
    std::cout << AddFrom1ToN_2(2) << std::endl;

    return 0;
}

int AddFrom1ToN_1( int n )
{
    return n<=0? 0 : n+AddFrom1ToN_1(n-1);
}

int AddFrom1ToN_2(int n)
{
    int sum = 0;
    for ( int i = 1; i<=n; i++)
    {
        sum +=i;
    }
    return sum;
}