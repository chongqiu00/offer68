/* 时间：2020.5.10
 * 编辑人：chongqiu00

 * 题目：找出数组中重复的数字
 * 在一个长度为n的数组里所有数字都在0~n-的范围内。
 * 数组中某些数字是重复的，但是不知道有几个数字重复，
 * 也不知道每个数字重复了几次。
 * 请找出数组中任意一个重复的数字
 * 
 * 例如：
 * 输入长度为7的数组{2， 3， 1， 0， 2， 5， 3},那么对应输出的重复数字应该为2或者3。
 * 
 * 思路：
 * 将数组中的值视为数组的下标。（ a[0]=0, a[1]=1, a[2]=2, a[3]=3 ... ）
 * 从头开始遍历数组。
 * 当数组的下标与此下标的内容一致时，---> 扫描数组的下一位。
 * 当数组的下标与此下标的内容不一致时，根据下标的内容 查找 以下标内容为下标的数组 中所存储的内容
 *                                   查找结果为 以下标内容为下标的数组中所存储的内容 本来就等于 下标的内容。---> 找到重复目标数字，结束程序。
 *                                   查找结果为 以下标内容为下标的数组中所存储的内容 不等于 下标的内容。 交换以下标内容为下标的数组中所存储的内容 与 下标的内容。---> 继续扫描下一位数组。
 * */

#include <iostream>

bool findRep(int* arr, int len, int* rep)
{
  //排除异常
  if (arr==NULL || len <= 0)  return false;
  for ( int i=0; i<len; i++)
  {
    if ( arr[i]<0 || arr[i]>len-1)  return false;
  }
  //开始查找
  for ( int i=0; i<len; i++)
  {
    while(arr[i] != i)
    {
      if ( arr[arr[i]] == arr[i] )
      {
        *rep = arr[i];
	      return true;
      }
      //交换两者数据
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

