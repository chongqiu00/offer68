/* 
面试题11：旋转数组的最小数字
把一个数组最开始的若干个元素搬到数组的末尾，我们称为数组的旋转。
输入一个递增排序的数组的一个旋转 输出旋转数组的最小元素。
例如数组{3， 4， 5， 1， 2}为{1， 2， 3， 4， 5}的一个旋转，该数组的最小为1。
思路：
*/

#include <iostream>
#include <stdio.h>

int Min(int arry[], int length)
{
    int index_1 = 0;
    int index_2 = length-1;
    int middle = index_1;

    while ( arry[index_1] >= arry[index_2] )
    {
        if ( (index_2 - index_1) == 1 )
        {
            middle = index_2;
            break;
        }
      
        middle = (index_1+index_2) / 2;
        if ( arry[middle]==arry[index_1] && arry[middle]==arry[index_2] )
        {
            //顺序查找。
            int temp = arry[index_1];
            for ( int i=index_1; i<=index_2; i++)
            {
              if ( arry[i] < temp)
              {
                  temp = arry[i];
              }
            }

            return temp;
        }
        if ( arry[middle] > arry[index_1] )     index_1 = middle;
        else if ( arry[middle] <= arry[index_2] )   index_2 = middle;
    }
    return arry[middle];

}

int main(int argc, char* argv[])
{
    int arry[5] = {3, 4, 5, 1, 2};
    std::cout << "arry中的最小数为：" << Min(arry, 5) << std::endl;

    int arr[5] = {1, 0, 1, 1, 1};
    std::cout << "arr中的最小数为：" << Min(arr, 5) << std::endl;

    return 0;
}