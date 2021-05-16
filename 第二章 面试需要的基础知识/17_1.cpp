/*面试题17：打印从1到最大的n位数。
题目：输入数字n,按顺序打印从1到最大的n位十进制数。
比如，输入3，则打印出1，2，3一直到最大的3位数999。

注意：数字容易导致溢出问题，可是使用数组或者字符串表示大数呀呀呀！！！
在使用数组或者字符串表示大数时，有字串中的数字加1的操作函数和将字串输出显示的函数。

bool Increment(char* number);  //字串加1
要注意的是，判断字串是否超出了我们的规定范围。

void PrintNumber(char* number); //输出字串数字
按照真正数字显示那样显示，不要将前面的0输出。
*/

#include <iostream>
#include <stdio.h>
#include <string.h>

void PrintToMaxOfNDigits_1(int n); //容易造成溢出问题。

void PrintToMaxNDigits_2(int n); //将输出数字使用字符串表示。
bool Increment(char* number);  //字串加1
void PrintNumber(char* number); //输出字串数字

int main(int argc, char* argv[])
{
    PrintToMaxNDigits_2(2);
    
    return 0;
}

void PrintToMaxOfNDigits_1(int n) //容易造成溢出问题。
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

void PrintToMaxNDigits_2(int n) //将输出数字使用字符串表示。
{
    //非法输入
    if ( n <= 0 )   return;
    //合法输入
    char* number = new char[n+1]; //注意字符串最末尾是'\0'。
    memset(number, '0', n);
    number[n] = '\0';

    while ( !Increment(number) )
    {
        PrintNumber(number);
    }

    delete [] number;
}

bool Increment(char* number)  //字串加1
{
    bool flag = false;
    int over = 0;
    int len = strlen(number);
    int sum = 0;

    for ( int i=len-1; i>=0; i--)
    {
        sum = number[i] - '0' + over;
        if ( i == len-1 )   sum++;

        if ( sum < 10 )//不进位
        {
            number[i] = sum + '0';
            break;
        }
        else//进位
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