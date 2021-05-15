/*
����˾Ա�������������

˼·��
����һ���µ����飬�������±�Ϊ�����С��ÿ���±�洢���Ǵ������������
ͨ���������ÿ�������������,��������顣
��ͨ���������������ԭ�������顣
*/
#include <stdio.h>

void SortAge(int age[], int length)
{
    int* p = age;
    if ( age == nullptr || length <= 0 )  return;
    //����һ��ͳ����ͬ��������������
    const int maxAge = 99;
    int ageNum[maxAge + 1] = {0,};

    //�������еĲ��Ϸ�����ȥ��
    for ( int i=0; i<length; i++)
    {
        if (age[i]<=0 || age[i]>99)
        {
            age[i] = 0;
        }
    }
   
    for ( int i=0; i<length; i++)
    {
        ++ageNum[age[i]];
    }

    for ( int i=0; i<=maxAge; i++)
    {
        while(ageNum[i] != 0)
        {
            *p = i;
            ageNum[i]--;
            p++;
        }
    }
}

int main(void)
{
    int arr[5] = {33, 55, 1, 99, 102};
    SortAge(arr, 5);
    for (int i=0; i<5; i++)
    {
        printf("%d ", arr[i]);
    }
}