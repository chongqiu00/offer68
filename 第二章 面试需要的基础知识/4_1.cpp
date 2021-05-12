/*
时间：2020.5.10
编辑人：chongqiu00
题目：二维数组中的查找
 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。*/

 #include <iostream>

bool Find(int* matrix, int rows, int columns, int number);

int main(int argc, char* argv[])
{
    //  int arr[4][4] = {{1, 2, 8, 9},
    //                   {2, 4, 9, 12},
    //                   {4, 7, 10, 13},
    //                   {6, 8, 11, 15}};//四行四列
    int arr[16] = {1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15};//四行四列

    bool b = Find(arr, 4, 4, 7);

    std::cout << b << std::endl;

     return 0;
}

bool Find(int* matrix, int rows, int columns, int number)
{
    bool found = false;

    int row = 0;
    int column = columns - 1;

    if ( matrix != NULL && rows > 0 && columns > 0) //避免非法输入
    {
        while ( row < rows && column < columns )
        {
            if ( matrix[row*columns+column] == number )
            {
                found = true;
                break;
            }
            else if ( matrix[row*columns+column] > number )
            {
                --column;
            }
            else
            {
                ++row;
            }
        }
    }

    return found;
}