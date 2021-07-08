/*

����
���������ҵ�һ������ĳ��ֵ�Ľڵ㲢ɾ���ýڵ㡣

˼·��
ǰ�᣺ͷ�ڵ�����ݡ�
���̣���һ������

ע�⣺
1������Ƿ����롣����ָ����Ϊ�������롣
2������Ҫ����ͷָ���ָ�򣬹ʴ������Ϊָ���ָ�롣
��ôΪɶ��Ҫ��ͷ�ڵ����һλ���أ�
��Ϊ���Ǳ�����ʱ��ȡ����Ŀ�����ݵ�ǰ����ͷ�ڵ�û��ǰһλ��������
3�������漰�ı����Ǵ�ͷ�ڵ����һ���ڵ㿪ʼ�ģ��ʵ�Ŀ��������ͷ�ڵ�ʱ��Ҫ��������

*/

#include <iostream>

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

bool RemoveNode(ListNode** pHead, int value)
{
    //�Ƿ�����
    if ( pHead == nullptr || *pHead == nullptr )
    {
        std::cout << "����Ƿ���" << std::endl;
        return false;
    }

    //�Ϸ�����
    if ( (*pHead)->m_nValue == value )//ͷ�ڵ㼴ΪĿ������
    {
        delete *pHead;
        pHead = nullptr;
    }
    else
    {
        ListNode* p = *pHead;
        while ( p->m_pNext != nullptr
                && p->m_pNext->m_nValue != value ) //��������������Ŀ�����ݵ�ǰһλ��
        {

            p = p->m_pNext;
        }

        if ( p->m_pNext != nullptr
             && p->m_pNext->m_nValue == value )
        {
            delete p->m_pNext;
            p->m_pNext = p->m_pNext->m_pNext;
        }
    }
}