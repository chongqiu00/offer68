/*

链表：
在链表中找到一个含有某个值的节点并删除该节点。

思路：
前提：头节点存数据。
过程：逐一遍历。

注意：
1）避免非法输入。即空指针作为参数输入。
2）由于要更改头指针的指向，故传入参数为指针的指针。
那么为啥子要从头节点的下一位找呢？
因为我们遍历的时候取得是目标数据的前，而头节点没有前一位啊！！！
3）由于涉及的遍历是从头节点的下一个节点开始的，故当目标数据在头节点时，要单独处理。

*/

#include <iostream>

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

bool RemoveNode(ListNode** pHead, int value)
{
    //非法输入
    if ( pHead == nullptr || *pHead == nullptr )
    {
        std::cout << "输入非法！" << std::endl;
        return false;
    }

    //合法输入
    if ( (*pHead)->m_nValue == value )//头节点即为目标数据
    {
        delete *pHead;
        pHead = nullptr;
    }
    else
    {
        ListNode* p = *pHead;
        while ( p->m_pNext != nullptr
                && p->m_pNext->m_nValue != value ) //这样跳出来就是目标数据的前一位。
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