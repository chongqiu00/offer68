/* ʱ�䣺2020.5.10
 * �༭�ˣ�chongqiu00
 * ��Ŀ���ҳ��������ظ�������
 * ��һ������Ϊn���������������ֶ���0~n-�ķ�Χ�ڡ�
 * ������ĳЩ�������ظ��ģ����ǲ�֪���м��������ظ���
 * Ҳ��֪��ÿ�������ظ��˼��Ρ�
 * ���ҳ�����������һ���ظ�������
 * ���磺
 * ���볤��Ϊ7������{2�� 3�� 1�� 0�� 2�� 5�� 3},��ô��Ӧ������ظ�����Ӧ��Ϊ2����3��
 * 
 * ˼·��
 * �����������������ʹ��sdjacent_find()��
 * */

//�ⷨ2������
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argv, char* argc[])
{
  std::vector<int> v;
  v.push_back(2);
  v.push_back(3);
  v.push_back(1);
  v.push_back(0);
  v.push_back(2);
  v.push_back(5);
  v.push_back(3);

  sort(v.begin(), v.end());
  std::vector<int>::iterator it = adjacent_find(v.begin(), v.end());
  if ( it == v.end() )
  {
    std::cout << "����û���ظ�������" << std::endl; 
  }
  else
  {
    std::cout << "�ظ�����Ϊ" << *it << std::endl;
  }

  return 0;
}
