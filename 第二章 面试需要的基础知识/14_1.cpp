/*
������14��������
��Ŀ������һ������Ϊ������ӣ�������Ӽ��ɣ�Σ������������������ң�������ÿ�����ӵĳ��ȼ�Ϊ��ۣ��ݣ���ۣ��ݣ�����������ۣ�ݡ�
���ʣ�ۣ��ݣ���ۣ��ݣ�����������ۣ�ݿ��ܵ����˻��Ƕ��٣�
���磺�����ӵĳ����ǣ�ʱ�����ǰ������ɳ��ȷֱ�Ϊ���������������Σ���ʱ�õ������˻��ǣ�����

����һ����̬�滮
����ݹ顣��֮���������������

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