/*
链表：
往该链表的末尾添加一个节点。

思路：
前提：头节点存放数据
过程：将p指针指向链表的头节点，逐一遍历，
当遍历的下一个指针指向为NULL，停止遍历。
当前位置的下一个节点指向创建的新节点。

注意：
1）在这里，有一个非法输入，即输入为NULL;
2）此链表为空时，即头指针直接指向新节点。
3）由于要修改地址，即我们将传入参数是地址的地址。
*/

#include <iostream>

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

bool AddToTail(ListNode** pHead, int value) //地址的地址哩！！！
{
    //输入非法
    if ( *pHead == nullptr )
    {
        std::cout << "输入为空指针，非法！" << std::endl;
        return false;
    }
    
    //输入合法
    ListNode* pNew = new ListNode; //创建一个节点。
    pNew->m_nValue = value;
    pNew->m_pNext = NULL;

    if ( pHead == NULL )//链表本来就是一个空链表。
    {
        *pHead = pNew;
    }//特殊输入
    else
    {
        ListNode* p = *pHead;
        while ( p->m_pNext != NULL) //注意是当前的下一个。
        {
            p = p->m_pNext;
        }
        p->m_pNext = pNew;
    }

    return true;
}