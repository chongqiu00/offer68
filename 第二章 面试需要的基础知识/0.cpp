#include <stdio.h>
#include <string.h>

void Print1ToN(int n);
bool AddTo1(char* number);
void Print(char* number);

int main(int argc, char* argv[])
{
    Print1ToN(4);
    return 0;
}

void Print1ToN(int n)
{
    char* number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';

    while ( !AddTo1(number))
    {
        Print(number);
    }
    return;
}

bool AddTo1(char* number)
{
    bool flag = false;
    int sum = 0;
    int over = 0;
    int len = strlen(number);
    for ( int i=len-1; i>=0; i-- )
    {
        sum = number[i] - '0' + over;
        if ( i == (len-1) )     sum++;
        if ( sum < 10 )
        {
            number[i] = sum + '0';
            break;
        }
        else
        {
            if ( i == 0 )
            {
                flag = true;
            }
            else
            {
                over = 1;
                sum = sum - 10;
                number[i] = sum + '0';
            }
        }
    }

    return flag;
}

void Print(char* number)
{
    bool flag = false;

    for ( int i=0; i<strlen(number); i++ )
    {
        while ( (number[i]!='0') && (flag==false) )
        {
            flag = true;
        }
        if ( flag )
        {
            printf("%c", number[i]);
        }
    }
    printf("\t");
}