/*斐列数组：
 *
 * */

#include <iostream>
class CFeiArr
{
public:
  ~CFeiArr()
  {
    if (this->m_Arr != NULL)
    {
      delete [] this->m_Arr;
      this->m_Arr = NULL;
      this->m_Size = 0;
    }

  }
  CFeiArr()
  {
    this->m_Arr = NULL;
    this->m_Size = 0;
  }

  CFeiArr(unsigned int size)
  : m_Size(size)
  {
    int i = 2;
    this->m_Arr = new int[this->m_Size];
    this->m_Arr[0] = 1;
    this->m_Arr[1] = 1;

    for (; i<this->m_Size; i++)
    {
      this->m_Arr[i] = this->m_Arr[i-1] + this->m_Arr[i-2];
    }
  }

  bool findArr(unsigned int num)
  {
    int i=0;
    for (; i<this->m_Size; i++)
    {
      if ( this->m_Arr[i] == num )
      {
        break;
      }
    }

    if ( i < this->m_Size)
    {
      std::cout << "此数在构造的" << this->m_Size << "斐列数组中存在，其项数为：" << i << std::endl;
    }
    else
    {
      std::cout << "次数在构造的" << this->m_Size << "项斐列数组中不存在。" << std::endl;
    }
  }
  
private:
  int* m_Arr;
  unsigned int m_Size;
  
};

int main(int argc, char* argv[])
{
  CFeiArr arr(89);
  arr.findArr(556);
  return 0;
}


