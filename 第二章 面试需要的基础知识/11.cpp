/* 
������11����ת�������С����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�Ϊ�������ת��
����һ����������������һ����ת �����ת�������СԪ�ء�
��������{3�� 4�� 5�� 1�� 2}Ϊ{1�� 2�� 3�� 4�� 5}��һ����ת�����������СΪ1��
˼·��
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
            //˳����ҡ�
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
    std::cout << "arry�е���С��Ϊ��" << Min(arry, 5) << std::endl;

    int arr[5] = {1, 0, 1, 1, 1};
    std::cout << "arr�е���С��Ϊ��" << Min(arr, 5) << std::endl;

    return 0;
}