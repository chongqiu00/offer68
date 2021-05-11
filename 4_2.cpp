/*
时间：2020.5.10
编辑人：chongqiu00
题目：理解下面的代码
*/
#include <iostream>

int main(int argc, char* argv[])
{
    char str1[] = "hello world";
    char str2[] = "hello world";   //从常量字符串的存储区域，赋值一份数据，拷贝到新开辟的栈区

    char* str3 = (char*)"hello world";
    char* str4 = (char*)"hello world"; //指针无需分配地址，常量字符串的存储区域直接指向

    if ( str1 == str2 )
    {
        std::cout << "str1 and str2 are same" << std::endl;
    }
    else
    {
        std::cout << "str1 and str2 are not same" << std::endl;
    }

    if ( str3 == str4 )
    {
        std::cout << "str3 and str4 are same" << std::endl;
    }
    else
    {
        std::cout << "str3 and str4 are not same" << std::endl;
    }
    return 0;
}

/*
运行结果：
str1 and str2 are not same
str3 and str4 are same
*/