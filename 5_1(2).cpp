/*
时间：2021.5.11
编辑人：chongqiu00
题目：替换空格
请实现一个函数，把字符串中的每个空格替换成"%20"。
例如：输入"We are happy." ,则输出"We%20are%20happy."
*/
/*方法二：从后往前赋值，时间复杂度为O(n)。
思路：
先确定字串转换后的尾指针指向到哪里，然后再遍历。
然后p1指针指向复制完成的子字串最前面一位的再前面一位。
    p2指针指向预留空白空间的首字符。
当p1和p2相遇后，即留给"%20"的字串填充完毕。
*/

#include <iostream>
bool ReplaceBlank(char* str);

void text01(void) //测试数据_1
{
    char str_1[2] = " ";
    std::cout << "字串1" << "\" \"转化后：";   
    ReplaceBlank(str_1); std::cout << str_1 << std::endl;
     
    char str_2[] = "We are happy.";
    std::cout << "字串2" << "\"We are happy.\"转化后：";   
    ReplaceBlank(str_2); std::cout << str_2 << std::endl;

    char str_3[] = " We are happy.";
    std::cout << "字串3" << "\" We are happy.\"转化后：";   
    ReplaceBlank(str_3); std::cout << str_3 << std::endl;

    char str_4[] = "We are happy. ";
    std::cout << "字串4" << "\"We are happy. \"转化后：";   
    ReplaceBlank(str_4); std::cout << str_4 << std::endl;

    char str_5[] = "Wearehappy.";
    std::cout << "字串5" << "\"Wearehappy.\"转化后：";   
    ReplaceBlank(str_5); std::cout << str_5 << std::endl;

    char str_6[1] = "";   
    std::cout << "字串6" << "\"\"转化后：";  
     ReplaceBlank(str_6); std::cout << str_6 << std::endl;

    char* str_7 = NULL;     ReplaceBlank(str_7);

}
void text02(void) //测试数据_2
{
    char str_1[2] = " ";
    char str_2[] = "We are happy.";
    char str_3[] = " We are happy.";
    char str_4[] = "We are happy. ";
    char str_5[] = "Wearehappy.";
    char str_6[1] = "";   
    char* str_7 = NULL;     

    std::cout << "字串1" << "\" \"转化后：";   
    ReplaceBlank(str_1); std::cout << str_1 << std::endl;
    std::cout << "字串2" << "\"We are happy.\"转化后：";   
    ReplaceBlank(str_2); std::cout << str_2 << std::endl;
    std::cout << "字串3" << "\" We are happy.\"转化后：";   
    ReplaceBlank(str_3); std::cout << str_3 << std::endl;
    std::cout << "字串4" << "\"We are happy. \"转化后：";   
    ReplaceBlank(str_4); std::cout << str_4 << std::endl;
    std::cout << "字串5" << "\"Wearehappy.\"转化后：";   
    ReplaceBlank(str_5); std::cout << str_5 << std::endl;
    std::cout << "字串6" << "\"\"转化后：";   
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
    //输入不合法
    if ( str == NULL ){
        std::cout << "输入的字串非法，转换失败！" << std::endl;
        return false;
    } 
    //输入合法
    char* pHead;
    char* pTail = str;
    int count = 0;

    while ( *pTail!= '\0' )//扫描字串中有几个空格。
    {
        if ( *pTail == ' ' )
        {
            count++;
        }
        pTail++;
    }
    pHead = pTail;
    pTail = pTail + count*2;
    if ( count == 0 )   return true;
    while ( pHead != pTail )
    {
        if ( *pHead == ' ' )
        {
                     *pTail = '0';
            pTail--; *pTail = '2';
            pTail--; *pTail = '%';
            pTail--;
            pHead--;
        }
        else
        {
            *pTail = *pHead;
            pTail--;
            pHead--;
        }
    }
    return true;
}