/*
ʱ�䣺2021.5.11
�༭�ˣ�chongqiu00
��Ŀ���滻�ո�

��ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"��
���磺����"We are happy." ,�����"We%20are%20happy."

*/
//����һ����ǰ����ֵ��ʱ�临�Ӷ�ΪO(n^2)��

#include <iostream>

bool ReplaceBlank(char* str);

void text01(void) //��������_1
{
    char str_1[2] = " ";
    std::cout << "�ִ�1" << "\" \"ת����";   
    ReplaceBlank(str_1); std::cout << str_1 << std::endl;
     
    char str_2[] = "We are happy.";
    std::cout << "�ִ�2" << "\"We are happy.\"ת����";   
    ReplaceBlank(str_2); std::cout << str_2 << std::endl;

    char str_3[] = " We are happy.";
    std::cout << "�ִ�3" << "\" We are happy.\"ת����";   
    ReplaceBlank(str_3); std::cout << str_3 << std::endl;

    char str_4[] = "We are happy. ";
    std::cout << "�ִ�4" << "\"We are happy. \"ת����";   
    ReplaceBlank(str_4); std::cout << str_4 << std::endl;

    char str_5[] = "Wearehappy.";
    std::cout << "�ִ�5" << "\"Wearehappy.\"ת����";   
    ReplaceBlank(str_5); std::cout << str_5 << std::endl;

    char str_6[1] = "";   
    std::cout << "�ִ�6" << "\"\"ת����";  
     ReplaceBlank(str_6); std::cout << str_6 << std::endl;

    char* str_7 = NULL;     ReplaceBlank(str_7);

}
void text02(void) //��������_2
{
    char str_1[2] = " ";
    char str_2[] = "We are happy.";
    char str_3[] = " We are happy.";
    char str_4[] = "We are happy. ";
    char str_5[] = "Wearehappy.";
    char str_6[1] = "";   
    char* str_7 = NULL;     

    std::cout << "�ִ�1" << "\" \"ת����";   
    ReplaceBlank(str_1); std::cout << str_1 << std::endl;
    std::cout << "�ִ�2" << "\"We are happy.\"ת����";   
    ReplaceBlank(str_2); std::cout << str_2 << std::endl;
    std::cout << "�ִ�3" << "\" We are happy.\"ת����";   
    ReplaceBlank(str_3); std::cout << str_3 << std::endl;
    std::cout << "�ִ�4" << "\"We are happy. \"ת����";   
    ReplaceBlank(str_4); std::cout << str_4 << std::endl;
    std::cout << "�ִ�5" << "\"Wearehappy.\"ת����";   
    ReplaceBlank(str_5); std::cout << str_5 << std::endl;
    std::cout << "�ִ�6" << "\"\"ת����";   
    ReplaceBlank(str_6); std::cout << str_6 << std::endl;

    ReplaceBlank(str_7);

}

int main(int argc, char* argv[])
{
  text01();
  std::cout << "--------------------------------------------" << std::endl;
  text02();
  
  return 0;
}

bool ReplaceBlank(char* str)
{
    //���벻�Ϸ�
    if ( str == NULL ){
        std::cout << "������ִ��Ƿ���ת��ʧ�ܣ�" << std::endl;
        return false;
    } 

    //����Ϸ�
    char* pTail = str; 
    char* pTemp = pTail;
    char* pHead = str;
    while ( *pTail!= '\0' )
    {
        pTail++;
    } //pTail����ָ���ִ�β��
    while ( *pHead!= '\0' ) //��ͷ��βɨ�衣
    {
        if ( *pHead == ' ' ) //����Ŀ��ո񣬿�ʼ����������Ԫ
        {
            pTemp = pTail + 2;
            while ( pHead != pTail )
            {
                *(pTail+2) = *pTail;
                pTail--;
            }
            pTail = pTemp;
            *pHead = '%';   pHead++;
            *pHead = '2';   pHead++;
            *pHead = '0';   pHead++;
        }
        else {
            pHead++;
        }
    }
    return true;  
}
