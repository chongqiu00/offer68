/*
将公司员工年龄进行排序

思路：
创建一个新的数组，此数组下标为年龄大小，每个下标存储的是此年龄的人数。
通过遍历存放每个人年龄的数组,填充新数组。
在通过遍历新数组更改原来的数组。
*/
#include <stdio.h>

void SortAge(int age[], int length)
{
    int* p = age;
    if ( age == nullptr || length <= 0 )  return;
    //创建一个统计相同年龄人数的数组
    const int maxAge = 99;
    int ageNum[maxAge + 1] = {0,};

    //将年龄中的不合法数据去除
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