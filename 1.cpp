/*
 * 日期：2020.5.9
 * 编辑人：chongqiu00
 * 剑指offer_1:
 *
如下为类型CMyString的声明，请为该类型添加赋值运算符函数
class CMyString
{
    public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    
    private:
    char* m_pData;
    usigned int m_Size;
}

*/


#include <iostream>
#include <string.h>
 
class String
{
public:
  ~String();
  String(const char* str); //构造函数传入char*
  String(const String& str); //构造函数传入Sting
  char& operator[](unsigned int info); //重载[]
  bool operator==(const String& str); //重载==
  String& operator=(const String& str);//考虑到String的隐式构造函数，我们要重载操作符=

  friend std::ostream& operator<<(std::ostream& stream, const String& str);

private:
  char* m_pData;
  unsigned int m_Size;
};


int main(int argc, char* argv[])
{
  String str("zww");
  String str_1(str);
  std::cout << str << std::endl;
  std::cout << str_1 << std::endl;

  std::cout << str_1[1] << std::endl;

  String str_2("张文文");
  std::cout << str_2 << std::endl;
  str_2 = str_1;
  std::cout << str_2 << std::endl;

  if ( str_2 == str_1 )
  std::cout << "同一个字符串！" << std::endl;
  else
  std::cout << "不是一个字符串！" << std::endl;


  return 0;
}

String::~String()
{
  if ( this->m_pData != NULL)
  {
    delete [] this->m_pData;
    this->m_pData = NULL;
    this->m_Size = 0;
  }
}

String::String(const char* str)
{
  if ( str == NULL )
  {
    this->m_pData = NULL;
    this->m_Size = 0;
  }
  else
  {
    this->m_Size = strlen(str);
    this->m_pData = new char[m_Size + 1]; //注意结束符
    memcpy(this->m_pData, str, this->m_Size+1);
    this->m_pData[this->m_Size] = '\0';
  }
}

String::String(const String& str)
{
    this->m_Size = str.m_Size;
    this->m_pData = new char[this->m_Size + 1]; //注意结束符
    memcpy(this->m_pData, str.m_pData, this->m_Size+1);
}

char& String::operator[](unsigned int info)
{
  return this->m_pData[info-1];
}


bool String::operator==(const String& str) //重载==
{
  if ( (this->m_Size == str.m_Size) && (strcmp(this->m_pData, str.m_pData)==0) )
  {
     return true;
  }
  else
  {
    return false;
  }
}
/*
//存在一个小问题，就是内存分配失败的异常抛出。
String& String::operator=(const String& str)//考虑到String的隐式构造函数，我们要重载操作符=
{
  //避免自己等于自己，误释放自己的内存资源
  if ( *this == str )
  {
    return *this;   
  }
  else
  {
    delete [] this->m_pData;//释放自己的内存资源
    this->m_Size = str.m_Size;
    this->m_pData = new char[this->m_Size + 1]; //开辟新内存空间
    memcpy(this->m_pData, str.m_pData, this->m_Size+1);
    return *this;
  }
}
*/

//为了解决内存分配异常抛出
tring& String::operator=(const String& str)//考虑到String的隐式构造函数，我们要重载操作符=
{
  if ( *this == str )
  {
    //在栈中，设置一个临时对象，避免重新申请内存空间。
    String temStr(str);
    //交换两个的字符串
    char* pTem = str.m_pData;
    str.m_pData = this->m_Data;//将本体的所指向的内存空间释放调。
    this->p_Data = pTem;
  }

  return *this;
}
std::ostream& operator<<(std::ostream& stream, const String& str)
{
  stream << str.m_pData;
  return stream;
}

/*
 * 在书写拷贝赋值时需要考虑：
 * 1，返回值：要满足可链式表达。--》&
 * 2，参数：避免参数的赋值拷贝和篡改。--》const + &
 * 3，避免本体的内存没有释放。 --》delete []
 * 4，避免重新申请内存（异常抛出） --》创建临时对象
 * */
