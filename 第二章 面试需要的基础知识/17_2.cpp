/*面试题17：打印从1到最大的n位数。
题目：输入数字n,按顺序打印从1到最大的n位十进制数。
比如，输入3，则打印出1，2，3一直到最大的3位数999。

将n个数进行全排列,
递归结束的条件是我们设置了数字的最后一位。

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

void PrintNumber(char* number) //输出字串数字
{
    int len = strlen(number);
    bool flag = true;

    for ( int i=0; i<len; ++i )
    {
        if (flag && number[i]!='0')//一旦遇到不是为0的数字就开始输出。
        flag = false;//标志位

        if (!flag)
        printf("%c", number[i]);
    }

    printf("\t");
}

