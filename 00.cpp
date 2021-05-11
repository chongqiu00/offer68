#include <stdio.h>
#include <iostream>
#include <string.h>

void fun(char* str)
{
   //*str = '4';
   *(str+2) = *str;

}

bool ReplaceBlank(char* str)
{
    char* pTail = str;
    int count = 2;

    // while ( *pTail!= '\0' )//扫描字串中有几个空格。
    // {
    //     if ( *pTail == ' ' )
    //     {
    //         count++;
    //     }

    // }

    pTail = pTail + count*2;

    return true;

}

int main(int argc, char* argv[])
{
    char arr[] = "W df dg";

    ReplaceBlank(arr);
    printf("%s", arr);
   
    return 0;
}