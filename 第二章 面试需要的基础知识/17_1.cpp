/*������17����ӡ��1������nλ����
��Ŀ����������n,��˳���ӡ��1������nλʮ��������
���磬����3�����ӡ��1��2��3һֱ������3λ��999��

ע�⣺�������׵���������⣬����ʹ����������ַ�����ʾ����ѽѽѽ������
��ʹ����������ַ�����ʾ����ʱ�����ִ��е����ּ�1�Ĳ��������ͽ��ִ������ʾ�ĺ�����

bool Increment(char* number);  //�ִ���1
Ҫע����ǣ��ж��ִ��Ƿ񳬳������ǵĹ涨��Χ��

void PrintNumber(char* number); //����ִ�����
��������������ʾ������ʾ����Ҫ��ǰ���0�����
*/

#include <iostream>
#include <stdio.h>
#include <string.h>

void PrintToMaxOfNDigits_1(int n); //�������������⡣

void PrintToMaxNDigits_2(int n); //���������ʹ���ַ�����ʾ��
bool Increment(char* number);  //�ִ���1
void PrintNumber(char* number); //����ִ�����

int main(int argc, char* argv[])
{
    PrintToMaxNDigits_2(2);
    
    return 0;
}

void PrintToMaxOfNDigits_1(int n) //�������������⡣
{
    int number = 1;
    int i = 0;

    while ( i++ < 4 )
    {
        number *= 10;
    }
    
    for ( i=0; i<number; i++ )
    {
        std::cout << i << " " << std::endl;
    }
    return;
}

void PrintToMaxNDigits_2(int n) //���������ʹ���ַ�����ʾ��
{
    //�Ƿ�����
    if ( n <= 0 )   return;
    //�Ϸ�����
    char* number = new char[n+1]; //ע���ַ�����ĩβ��'\0'��
    memset(number, '0', n);
    number[n] = '\0';

    while ( !Increment(number) )
    {
        PrintNumber(number);
    }

    delete [] number;
}

bool Increment(char* number)  //�ִ���1
{
    bool flag = false;
    int over = 0;
    int len = strlen(number);
    int sum = 0;

    for ( int i=len-1; i>=0; i--)
    {
        sum = number[i] - '0' + over;
        if ( i == len-1 )   sum++;

        if ( sum < 10 )//����λ
        {
            number[i] = sum + '0';
            break;
        }
        else//��λ
        {
            if ( i == 0 )
                flag = true;
            else
            {
                sum -= 10;
                number[i] = '0' + sum;
                over = 1;
            }
        }
    }
 
    return flag;
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