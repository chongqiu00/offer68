/* ʱ�䣺2020.5.10
 * �༭�ˣ�chongqiu00
 * ��Ŀ���ҳ��������ظ�������
 * ��һ������Ϊn���������������ֶ���0~n-�ķ�Χ�ڡ�
 * ������ĳЩ�������ظ��ģ����ǲ�֪���м��������ظ���
 * Ҳ��֪��ÿ�������ظ��˼��Ρ�
 * ���ҳ�����������һ���ظ�������
 * ���磺
 * ���볤��Ϊ7������{2�� 3�� 1�� 0�� 2�� 5�� 3},��ô��Ӧ������ظ�����Ӧ��Ϊ2����3��
 * */

//�ⷨ1
#include <iostream>

bool findRep(int* arr, int len, int* rep)
{
  //�ų��쳣
  if (arr==NULL || len <= 0)  return false;
  for ( int i=0; i<len; i++)
  {
    if ( arr[i]<0 || arr[i]>len-1)  return false;
  }
  //��ʼ����
  for ( int i=0; i<len; i++)
  {
    while(arr[i] != i)
    {
      if ( arr[arr[i]] == arr[i] )
      {
        *rep = arr[i];
	return true;
      }
      //������������
      int temp = arr[i];
      arr[i] = arr[temp];
      arr[temp] = temp;
    }
  }
  return false;
}

int main(int argc, char* argv[])
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1}; //10
  int a;
  findRep(arr, 10, &a);
  //printf("%d", a);
  std::cout << a;

  return 0;
}
