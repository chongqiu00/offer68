/*
ʱ�䣺2021.5.11
�༭�ˣ�chongqiu00
��Ŀ���滻�ո� �����Ŀ

���������������A1��A2���ڴ���A1��ĩβ���㹻��Ŀ���ռ�����A2��
��ʵ��һ����������A2�е��������ֲ���A1�У��������е�����������ġ�
*/
/*
˼·��
�Ӻ���ǰ��������,�������Ա����ظ��ĸ�����λ��
˼·��
��Ҫ�ľ�������Ҫȷ����λ��ɺ�Ŀ����������һλ�ںεط���
pTailָ��ָ����λ�����������һλ��
pHeadָ��A��������һλ��
pBTailָ��B��������һλ��
pHead��pBTail�Ƚ�AB�����еĴ�С����ɺ���λ��
pTailҪһֱָ�������λ���ǰһλ��
PHeadҪһֱָ��pHead��Ҫ�Ƚϵ�λ�á�
��pTail��pHead���ʱ���������λ��

pTail��pHead֮��Ŀռ���ǽ�Ҫ������Ŀ��

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
    //���벻�Ϸ�
    if ( pA == nullptr && pB == nullptr )
    {
        std::cout << "����Ƿ�������Ϊ�գ�" << std::endl;
        return false;
    }

    //����Ϸ�
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