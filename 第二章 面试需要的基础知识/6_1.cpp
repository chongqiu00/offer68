/*
ʱ�䣺2021.5.12
�༭�ˣ�chongqiu00
��Ŀ6����β��ͷ��ӡ����
����һ�������ͷ�ڵ㣬��β��ͷ��������ӡ��ÿһ���ڵ��ֵ��
����ڵ㶨�����£�
struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};

˼·1���ı�����ṹ
���̣�
�ı��������ֵ��ţ���β���ݺ�ͷ����֮������ݷ�ת������

˼·2�����ı�����ṹ��ջ��
���̣�
���ı��������ֵ��ţ�ֱ�Ӵ�����β��ǰ������
����һ�������Ľڵ㣬�����һ����ʾ�������������Ǿ��뵽��ջ���Ƚ��������
ע�⣺
1������Ƿ����룬����ָ����Ϊ�������롣

˼·3�����ı�����ṹ���ݹ飩
���̣�
�ݹ��ڱ����Ͼ���һ��ջ�ṹ���ɴ��뵽���õݹ�ʵ�֡�
������һ���ڵ�ʱ���������ʾ�˽ڵ�ĺ�һ���ڵ��е����ݣ��������������ݡ�
ȱ�㣺
���������ʱ���ᵼ�º������õĲ㼶������ܵ��º�������ջ�����

*/

#include <iostream>
#include <stack>

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};

//˼·2�����ı�����ṹ��ջ��
bool PrintListReversingly_2( ListNode* pHead )
{
    //����Ƿ�
    if ( pHead == nullptr )
    {
        std::cout << "����Ϊ��ָ�룬�Ƿ����룡" << std::endl;
        return false;
    }

    //����Ϸ�
    std::stack<ListNode*> nodes;
    ListNode* p = pHead;

    while ( p != nullptr )
    {
        nodes.push(p);
        p=p->m_pNext;
    } //����ڵ���ջ��

    while ( nodes.empty() != 0 )
    {
        p = nodes.top();
        std::cout << p->m_nKey << " ";
        nodes.pop();
    } //ջ�������ջ��

    return true;
}

//˼·3�����ı�����ṹ���ݹ飩
bool PrintListReversingly_3( ListNode* pHead )
{
    //���벻�Ϸ���
    if ( pHead == nullptr )
    {
        std::cout << "����Ϊ��ָ�룬���Ϸ���" << std::endl;
        return false;
    }
    //����Ϸ���
    ListNode* p = pHead;
    if ( p->m_pNext != nullptr )//�ݹ���ڡ�
    {
        PrintListReversingly_3(p->m_pNext);
    }
    std::cout << p->m_nKey << " ";

    return true;
}




