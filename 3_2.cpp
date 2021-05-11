/*
 * ʱ�䣺2020.5.10
 * �༭�ˣ�chongqiu00
 * ��Ŀ�����޸������ҳ��ظ�����
 * ��һ������Ϊn+1������������е����ֶ���1~n�ķ�Χ�ڣ�����������������һ���������ظ��ġ�
 * ���ҳ�����������һ���ظ������֣��������޸���������顣
 *
 * ���磺
 * ���볤��Ϊ8������{2�� 3�� 5�� 4�� 3�� 2�� 6�� 7}����ô��Ӧ��������ظ�����2����3��
 * 
 * ˼·��
 * ʹ�ö��ֲ��ҷ���
 * ������ã�������һ���������ظ��ģ������Ǿ�ͳ��1~n֮�䣬���������������ǳ������ĸ����εġ�
 * ���ȣ�start=0, end=n�� middle = (end-start)<<1+1;
 * ͳ�������У���(start, middle)�е�������Ŀ��������middle-start + 1,���ظ����ֱ��ڴ�(start, middle)���䣬��end=middle, �ظ��˲�����ֱ��start==end; ��ѯ�������Ƿ�����ֵ����Ҫ��
 *                                          ��С��middle-start + 1�����ظ����ֱ���(middle+1, end)���䣬��start=middle+1, �ظ��˲�����ֱ��start==end; ��ѯ�������Ƿ�����ֵ����Ҫ��
 * */


//�ⷨһ�����ֲ���
#include <iostream>

int countRange(const int* numbers,int length, int start, int end);
int getDuplication(const int* numbers, int length);

int main(int argc, char* argv[])
{ 
  int arr[8] = {2, 3, 5, 4, 3, 2, 6, 7};
  std::cout << getDuplication(arr, 8) << std::endl;

  return 0;
}

int getDuplication(const int* numbers, int length)
{
  if ( numbers==NULL || length<=0)
  {
    return -1;
  }//����Ƿ�����

  int start = 1;
  int end = length-1;
  while (end >= start)
  {
    int middle = (end-start)/2 + start;
    int count = countRange(numbers, length, start, middle);

    if ( count > (middle-start+1))  end = middle;
    else                            start = middle + 1;

    if ( end == start )
    {
      if (count > 1)  return start;
      else            break;
    }
    
  }

  return -1;
} 

int countRange(const int* numbers,int length, int start, int end)
{
  if ( numbers == NULL )
  {
    return -1;
  }

  int count = 0;
  for (int i=0; i<length; i++)
  {
    if ( numbers[i]>=start && numbers[i]<=end)
    {
      count++;
    }
  }
  return count;
}
