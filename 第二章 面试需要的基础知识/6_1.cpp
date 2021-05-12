/*
时间：2021.5.12
编辑人：chongqiu00
题目6：从尾到头打印链表。
输入一个链表的头节点，从尾到头反过来打印出每一个节点的值。
链表节点定义如下：
struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};

思路1：改变链表结构
过程：
改变链表的数值存放，将尾数据和头数据之间的数据反转过来。

思路2：不改变链表结构（栈）
过程：
不改变链表的数值存放，直接从链表尾往前遍历。
最先一个遍历的节点，最后那一个显示出来，这样我们就想到了栈（先进后出）。
注意：
1）避免非法输入，即空指针作为参数传入。

思路3：不改变链表结构（递归）
过程：
递归在本质上就是一个栈结构，由此想到了用递归实现。
当访问一个节点时，先输出显示此节点的后一个节点中的数据，再输出自身的数据。
缺点：
当链表过长时，会导致函数调用的层级很深，可能导致函数调用栈溢出。

*/

#include <iostream>
#include <stack>

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};

//思路2：不改变链表结构（栈）
bool PrintListReversingly_2( ListNode* pHead )
{
    //输入非法
    if ( pHead == nullptr )
    {
        std::cout << "输入为空指针，非法输入！" << std::endl;
        return false;
    }

    //输入合法
    std::stack<ListNode*> nodes;
    ListNode* p = pHead;

    while ( p != nullptr )
    {
        nodes.push(p);
        p=p->m_pNext;
    } //链表节点入栈。

    while ( nodes.empty() != 0 )
    {
        p = nodes.top();
        std::cout << p->m_nKey << " ";
        nodes.pop();
    } //栈中输出出栈。

    return true;
}

//思路3：不改变链表结构（递归）
bool PrintListReversingly_3( ListNode* pHead )
{
    //输入不合法。
    if ( pHead == nullptr )
    {
        std::cout << "输入为空指针，不合法！" << std::endl;
        return false;
    }
    //输入合法。
    ListNode* p = pHead;
    if ( p->m_pNext != nullptr )//递归出口。
    {
        PrintListReversingly_3(p->m_pNext);
    }
    std::cout << p->m_nKey << " ";

    return true;
}




