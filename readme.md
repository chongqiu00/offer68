# 剑指offer个人总结

---

##### 第一章 面试流程

1.1 把一个字符串转换为整数。
   	1.2 求链表中的倒数第K个结点（面试题中有）。

----

##### 第二章 面试需要的基础知识
2.1. 定义一个空类型，空类型中有构造和析构函数，空类型有虚函数时，sizeof()为多少。

2.2. 考虑下面代码的运行情况。
				选项：A:编译错误 B:编译成功，运行程序崩溃 C:编译运行正常，输出10。

```C
class A
{
    private:
    int value;

    public:
    A(int n)
    : value(n){}
    A( A& other )
    //A( A other) //形参传值，会拷贝赋值
    {
        value = other.value;
    }

    void Printf()
    {
        std::cout << this->value << std::endl;
    }

};
int main(int arggc, char* argv[])
{
    A a = 10;
    A b = a;
    b.Printf();

}
//拷贝构造函数不允许赋值其构造函数。
```
###### 面试题1：重写赋值运算符

> 如下为类型CMyString的声明，请为该类型添加赋值运算符函数
>
> ```c++
> class CMyString
> {
>  public:
>  CMyString(char* pData = nullptr);
>  CMyString(const CMyString& str);
> 
>  private:
>  char* m_pData;
>  usigned int m_Size;
> };
> ```

**总结：**

注意：

1. 链式表达。

2. 防止传入的参数生成副本，误改参数数据。

3. 避免内存泄漏。

4. 特殊情况就是自己传入自己，把自己的内存释放了。

###### 面试题2：设计模式



###### 面试题3：找出数组中重复的数字

> 例题1：在一个长度为n的数组里所有数字都在0~n-的范围内。
>  数组中某些数字是重复的，但是不知道有几个数字重复，
>  也不知道每个数字重复了几次。
>  请找出数组中任意一个重复的数字
>  例如：
>  输入长度为7的数组{2， 3， 1， 0， 2， 5， 3},那么对应输出的重复数字应该为2或者3。

**思路1：**

将数组中的值视为数组的下标。（ a[0]=0, a[1]=1, a[2]=2, a[3]=3 ... ）

从头开始遍历数组。 

当数组的下标与此下标的内容一致时，---> 扫描数组的下一位。

当数组的下标与此下标的内容不一致时，根据下标的内容 查找 以下标内容为下标的数组 中所存储的内容

​                  查找结果为 以下标内容为下标的数组中所存储的内容 本来就等于 下标的内容。---> 找到重复目标数字，结束程序。

​                  查找结果为 以下标内容为下标的数组中所存储的内容 不等于 下标的内容。 交换以下标内容为下标的数组中所存储的内容 与 下标的内容。---> 继续扫描下一位数组。

**思路2：**

将数组进容器，排序，使用sdjacent_find()。



> 例题2：在一个长度为n的数组里所有数字都在0~n-的范围内。
>  数组中某些数字是重复的，但是不知道有几个数字重复，
>  也不知道每个数字重复了几次。
>  请找出数组中任意一个重复的数字
>  例如：
>  输入长度为7的数组{2， 3， 1， 0， 2， 5， 3},那么对应输出的重复数字应该为2或者3。

**思路：**

使用二分查找法：（找出的重复数字不全）

由题意得，至少有一个数字是重复的，即我们就统计1~n之间，这个多出来的数字是出现在哪个数段的。

起先，start=0, end=n， middle = (end-start)<<1+1;

统计数组中，在(start, middle)中的数字数目，若大于middle-start + 1,则重复数字必在此(start, middle)区间，将end=middle, 重复此操作。直到start==end; 查询此区间是否还有数值符合要求。

​                      若小于middle-start + 1，则重复数字比在(middle+1, end)区间，将start=middle+1, 重复此操作。直到start==end; 查询此区间是否还有数值符合要求。

###### 面试题4：二维数组中的查找

> 示例1：
>
> 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
>  请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

![image-20210512110247245](https://github.com/chongqiu00/offer68/edit/master/readme.assets/image-20210512110247245.png)
<<<<<<< HEAD
=======

>>>>>>> 15c6e156119a6e7c0136d934fb613ec2c3ace3a6

> 示例2：
>
> 理解下面的代码
>
> ```c++
> int main(int argc, char* argv[])
> {
>     char str1[] = "hello world";
>     char str2[] = "hello world";   //从常量字符串的存储区域，赋值一份数据，拷贝到新开辟的栈区
> 
>     char* str3 = (char*)"hello world";
>     char* str4 = (char*)"hello world"; //指针无需分配地址，常量字符串的存储区域直接指向
> 
>     if ( str1 == str2 )
>     {
>         std::cout << "str1 and str2 are same" << std::endl;
>     }
>     else
>     {
>         std::cout << "str1 and str2 are not same" << std::endl;
>     }
> 
>     if ( str3 == str4 )
>     {
>         std::cout << "str3 and str4 are same" << std::endl;
>     }
>     else
>     {
>         std::cout << "str3 and str4 are not same" << std::endl;
>     }
>     return 0;
> }
> ```
>
> 



###### 面试题5：替换空格

> 请实现一个函数，把字符串中的每个空格替换成"%20"。
> 例如：输入"We are happy." ,则输出"We%20are%20happy."

**思路1：**

1. 过程：

   从前往后赋值，时间复杂度为O(n^2)。

思路2：

1. 过程：

   从后往前赋值，时间复杂度为O(n)。

   先确定字串转换后的尾指针指向到哪里，然后再遍历。

   然后p1指针指向复制完成的子字串最前面一位的再前面一位。

     p2指针指向预留空白空间的首字符。

   当p1和p2相遇后，即留给"%20"的字串填充完毕。

   

###### 面试题6：从尾到头打印链表。

> 输入一个链表的头节点，从尾到头反过来打印出每一个节点的值。
> 链表节点定义如下：
>
> ```c++
> struct ListNode
> {
>     int m_nKey;
>     ListNode* m_pNext;
> };
> ```

**思路1**：改变链表结构

			1. 过程：
			改变链表的数值存放，将尾数据和头数据之间的数据反转过来。

**思路2**：不改变链表结构（栈）
1. 过程：

不改变链表的数值存放，直接从链表尾往前遍历。最先一个遍历的节点，最后那一个显示出来，这样我们就想到了栈（先进后出）。

2. 注意：
   	1）避免非法输入，即空指针作为参数传入。

**思路3**：不改变链表结构（递归）
  		1. 过程：
       	递归在本质上就是一个栈结构，由此想到了用递归实现。
       	当访问一个节点时，先输出显示此节点的后一个节点中的数据，再输出自身的数据。
  		2. 缺点：
       当链表过长时，会导致函数调用的层级很深，可能导致函数调用栈溢出。
