/*
时间：2021.5.11
编辑人：chongqiu00
题目：替换空格 相关题目

有两个排序的数组A1和A2，内存在A1的末尾有足够多的空余空间容纳A2。
请实现一个函数，把A2中的所有数字插入A1中，并且所有的数字是排序的。
*/
/*
思路：
从后往前复制数字,这样可以避免重复的复制移位。
思路：
主要的就是我们要确定移位完成后目标数组的最后一位在何地方。
pTail指针指向移位完后的数组最后一位。
pHead指向A数组的最后一位。
pBTail指向B数组的最后一位。
pHead和pBTail比较AB数组中的大小，完成后移位。
pTail要一直指向完成移位后的前一位。
PHead要一直指向pHead将要比较的位置。
当pTail和pHead相等时，及完成移位。

pTail和pHead之间的空间就是将要填充的数目。

*/

#include <iostream>

bool Merge(int* pA, int* pB, int lenA, int lenB);

int main(int argc, char* argv[])
{
    // int A[20] = {23, 33,55,66,99, 123,333, 444, 555,1000};
    // int B[20] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    int A[20] = {1, 2, 45, 56, 7, 2, 56, 78, 111, 44};
    int B[20] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    Merge(A, B, 10, 10);
    for ( int i=0; i<20; i++)
    {
        std::cout << A[i] << " ";
    }
    return 0;
}

bool Merge(int* pA, int* pB, int lenA, int lenB)
{
    //输入不合法
    if ( pA == nullptr && pB == nullptr )
    {
        std::cout << "输入非法，数组为空！" << std::endl;
        return false;
    }

    //输入合法
    int* pTail = pA + lenA - 1 + lenB;
    int* pHead = pA + lenA -1;
    int* pBTail = pB + lenB - 1;

    while ( pHead != pTail )
    {
        if ( *pHead >= *pBTail )
        {
            *pTail = *pHead;
             pTail--;
            *pTail = *pBTail;
        }
        else
        {
            *pTail = *pBTail;
             pTail--;
            *pTail = *pHead;
        }
        pBTail--;
        pTail--;
        pHead--;
    }
    return true;
}