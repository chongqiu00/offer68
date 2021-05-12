/* 时间：2020.5.10
 * 编辑人：chongqiu00
 * 题目：找出数组中重复的数字
 * 在一个长度为n的数组里所有数字都在0~n-的范围内。
 * 数组中某些数字是重复的，但是不知道有几个数字重复，
 * 也不知道每个数字重复了几次。
 * 请找出数组中任意一个重复的数字
 * 例如：
 * 输入长度为7的数组{2， 3， 1， 0， 2， 5， 3},那么对应输出的重复数字应该为2或者3。
 * 
 * 思路：
 * 将数组进容器，排序，使用sdjacent_find()。
 * */

//解法2：容器
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
    std::cout << "其中没有重复的数字" << std::endl; 
  }
  else
  {
    std::cout << "重复数字为" << *it << std::endl;
  }

  return 0;
}
