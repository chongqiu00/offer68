/*
����
���������ĩβ���һ���ڵ㡣

˼·��
ǰ�᣺ͷ�ڵ�������
���̣���pָ��ָ�������ͷ�ڵ㣬��һ������
����������һ��ָ��ָ��ΪNULL��ֹͣ������
��ǰλ�õ���һ���ڵ�ָ�򴴽����½ڵ㡣

ע�⣺
1���������һ���Ƿ����룬������ΪNULL;
2��������Ϊ��ʱ����ͷָ��ֱ��ָ���½ڵ㡣
3������Ҫ�޸ĵ�ַ�������ǽ���������ǵ�ַ�ĵ�ַ��
*/

#include <iostream>

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

bool AddToTail(ListNode** pHead, int value) //��ַ�ĵ�ַ��������
{
    //����Ƿ�
    if ( *pHead == nullptr )
    {
        std::cout << "����Ϊ��ָ�룬�Ƿ���" << std::endl;
        return false;
    }
    
    //����Ϸ�
    ListNode* pNew = new ListNode; //����һ���ڵ㡣
    pNew->m_nValue = value;
    pNew->m_pNext = NULL;

    if ( pHead == NULL )//����������һ��������
    {
        *pHead = pNew;
    }//��������
    else
    {
        ListNode* p = *pHead;
        while ( p->m_pNext != NULL) //ע���ǵ�ǰ����һ����
        {
            p = p->m_pNext;
        }
        p->m_pNext = pNew;
    }

    return true;
}