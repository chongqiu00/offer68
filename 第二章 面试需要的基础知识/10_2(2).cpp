/*
������10_2��������̨�ס�(��չ)
һֻ���ܿ�������һ��̨�ף�Ҳ������2��̨��...��Ҳ��������n���������������һ��n���Ĵ����ܹ��ж�����������

˼·��
��ѧ���ɷ�����֤�� f(n) = 2^(n-1)��
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