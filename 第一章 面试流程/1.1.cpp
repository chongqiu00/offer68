/*
��ָoffer:
���ַ���ת��Ϊ������
ע�⣺
1���������ݵĺϷ��ԡ�
*/

#include <iostream>

int StrToInt(const char* str);

int main(int argc, char* argv[])
{
    std::cout << StrToInt("123") << std::endl;
    return 0;
}

int StrToInt(const char* str)
{
    if ( str == NULL )
    {
        return -1;
    } //����Ƿ�����

    char* p = (char*) str;
    int number = 0;

    while ( *str != 0 )
    {
        std::cout << *str << std::endl; 
        number = number*10 + *str - '0';
        ++str;
    }
    return number;
}