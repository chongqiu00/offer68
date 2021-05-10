/*
 * ���ڣ�2020.5.9
 * �༭�ˣ�chongqiu00
 * ��ָoffer_1:
 *
����Ϊ����CMyString����������Ϊ��������Ӹ�ֵ���������
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
  String(const char* str); //���캯������char*
  String(const String& str); //���캯������Sting
  char& operator[](unsigned int info); //����[]
  bool operator==(const String& str); //����==
  String& operator=(const String& str);//���ǵ�String����ʽ���캯��������Ҫ���ز�����=

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

  String str_2("������");
  std::cout << str_2 << std::endl;
  str_2 = str_1;
  std::cout << str_2 << std::endl;

  if ( str_2 == str_1 )
  std::cout << "ͬһ���ַ�����" << std::endl;
  else
  std::cout << "����һ���ַ�����" << std::endl;


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
    this->m_pData = new char[m_Size + 1]; //ע�������
    memcpy(this->m_pData, str, this->m_Size+1);
    this->m_pData[this->m_Size] = '\0';
  }
}

String::String(const String& str)
{
    this->m_Size = str.m_Size;
    this->m_pData = new char[this->m_Size + 1]; //ע�������
    memcpy(this->m_pData, str.m_pData, this->m_Size+1);
}

char& String::operator[](unsigned int info)
{
  return this->m_pData[info-1];
}


bool String::operator==(const String& str) //����==
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
//����һ��С���⣬�����ڴ����ʧ�ܵ��쳣�׳���
String& String::operator=(const String& str)//���ǵ�String����ʽ���캯��������Ҫ���ز�����=
{
  //�����Լ������Լ������ͷ��Լ����ڴ���Դ
  if ( *this == str )
  {
    return *this;   
  }
  else
  {
    delete [] this->m_pData;//�ͷ��Լ����ڴ���Դ
    this->m_Size = str.m_Size;
    this->m_pData = new char[this->m_Size + 1]; //�������ڴ�ռ�
    memcpy(this->m_pData, str.m_pData, this->m_Size+1);
    return *this;
  }
}
*/

//Ϊ�˽���ڴ�����쳣�׳�
tring& String::operator=(const String& str)//���ǵ�String����ʽ���캯��������Ҫ���ز�����=
{
  if ( *this == str )
  {
    //��ջ�У�����һ����ʱ���󣬱������������ڴ�ռ䡣
    String temStr(str);
    //�����������ַ���
    char* pTem = str.m_pData;
    str.m_pData = this->m_Data;//���������ָ����ڴ�ռ��ͷŵ���
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
 * ����д������ֵʱ��Ҫ���ǣ�
 * 1������ֵ��Ҫ�������ʽ��--��&
 * 2����������������ĸ�ֵ�����ʹ۸ġ�--��const + &
 * 3�����Ȿ����ڴ�û���ͷš� --��delete []
 * 4���������������ڴ棨�쳣�׳��� --��������ʱ����
 * */
