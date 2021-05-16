/*������17����ӡ��1������nλ����
��Ŀ����������n,��˳���ӡ��1������nλʮ��������
���磬����3�����ӡ��1��2��3һֱ������3λ��999��

��n��������ȫ����,
�ݹ�������������������������ֵ����һλ��

*/
#include <iostream>
#include <stdlib.h>
#include <string.h>

void Print1ToMaxOfNDigits(int n);

void Print1ToOfDigitsRecursively(char* number, int length, int index);
void PrintNumber(char* number);

int main(int argc, char* argv[])
{
    Print1ToMaxOfNDigits(2);
    return 0;
}

void Print1ToMaxOfNDigits(int n)
{
    if ( n <= 0 )   return;
    char* number = new char[n+1];
    //memset(number, '0', n );

    number[n] = '\0';

    for ( int i=0; i<10; i++)
    {
        number[0] = '0' + i;
        Print1ToOfDigitsRecursively(number, n, 0);
    }
    delete [] number;
}

void Print1ToOfDigitsRecursively(char* number, int length, int index)
{
    if (index == length-1)
    {
        PrintNumber(number);
        return;
    }
   
    for ( int i=0; i<10; i++)
    {
        number[index+1] = '0' + i;
        Print1ToOfDigitsRecursively(number, length, index+1);
    }
}

void PrintNumber(char* number) //����ִ�����
{
    int len = strlen(number);
    bool flag = true;

    for ( int i=0; i<len; ++i )
    {
        if (flag && number[i]!='0')//һ����������Ϊ0�����־Ϳ�ʼ�����
        flag = false;//��־λ

        if (!flag)
        printf("%c", number[i]);
    }

    printf("\t");
}

