/*
 * 时间：2020.5.10
 * 编辑人：chongqiu00
 * 题目：不修改数组找出重复数字
 * 在一个长度为n+1的数组里的所有的数字都在1~n的范围内，所有数组中至少有一个数字是重复的。
 * 请找出数组中任意一个重复的数字，但不能修改输入的数组。
 *
 * 例如：
 * 输入长度为8的数组{2， 3， 5， 4， 3， 2， 6， 7}，那么对应的输出是重复数组2或者3。
 * 
 * 思路：
 * 使用二分查找法：
 * 由题意得，至少有一个数字是重复的，即我们就统计1~n之间，这个多出来的数字是出现在哪个数段的。
 * 起先，start=0, end=n， middle = (end-start)<<1+1;
 * 统计数组中，在(start, middle)中的数字数目，若大于middle-start + 1,则重复数字必在此(start, middle)区间，将end=middle, 重复此操作。直到start==end; 查询此区间是否还有数值符合要求。
 *                                          若小于middle-start + 1，则重复数字比在(middle+1, end)区间，将start=middle+1, 重复此操作。直到start==end; 查询此区间是否还有数值符合要求。
 * */


//解法一：二分查找
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
  }//避免非法输入

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
