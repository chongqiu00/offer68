/*
������10_2��������̨�ס�
һֻ���ܿ�������һ��̨�ף�Ҳ������2��̨�ס������������һ��n���Ĵ����ܹ��ж�����������

˼·��
����һ��̨��ʱ��ֻ��һ�֡�
������̨��ʱ�������֡���һ��һ��������������
��������̨��ʱf(n)�����Է��ֵ��ǿ�ʼ������������һ��f(n-1)������f(n-2)��f(n) = f(n-1) + f(n-2)
*/

#include <iostream>

int qinWa(int n);

int main(int argv, char* argc[])
{
    std::cout << qinWa(5) << std::endl;
    return 0;
}

int qinWa(int n)
{
    int sum;
    if (n==1) return 1;
    if (n==2) return 2;

    return sum = qinWa(n-1) + qinWa(n-2);
}