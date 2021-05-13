/*
面试题10相关题目：

*/
#include <iostream>

int grid(int n);

int main(int argc, char* argv[])
{
    std::cout << grid(3) << std::endl;
    return 0;
}

int grid(int n)
{
    int sum = 0;
    if ( n==1) return 1;
    if ( n==2) return 2;
    
    return sum = grid(n-1) + grid(n-2);
}