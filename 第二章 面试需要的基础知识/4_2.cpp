/*
ʱ�䣺2020.5.10
�༭�ˣ�chongqiu00
��Ŀ���������Ĵ���
*/
#include <iostream>

int main(int argc, char* argv[])
{
    char str1[] = "hello world";
    char str2[] = "hello world";   //�ӳ����ַ����Ĵ洢���򣬸�ֵһ�����ݣ��������¿��ٵ�ջ��

    char* str3 = (char*)"hello world";
    char* str4 = (char*)"hello world"; //ָ����������ַ�������ַ����Ĵ洢����ֱ��ָ��

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
���н����
str1 and str2 are not same
str3 and str4 are same
*/