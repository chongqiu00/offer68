/*
������14��������
��Ŀ������һ������Ϊ������ӣ�������Ӽ��ɣ�Σ������������������ң�������ÿ�����ӵĳ��ȼ�Ϊ��ۣ��ݣ���ۣ��ݣ�����������ۣ�ݡ�
���ʣ�ۣ��ݣ���ۣ��ݣ�����������ۣ�ݿ��ܵ����˻��Ƕ��٣�
���磺�����ӵĳ����ǣ�ʱ�����ǰ������ɳ��ȷֱ�Ϊ���������������Σ���ʱ�õ������˻��ǣ�����

����һ��̰���㷨
��������ʹ�����ŵ���ȥ��ˣ����Ǿ����ܵ�������3ȥ��ˣ�Ȼ������Ϊ1ʱ��1+3 ==��1+3 �����ҪС�� 2+2 ==��2*2��

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