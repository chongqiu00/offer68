/*
ʱ�䣺2020.5.10
�༭�ˣ�chongqiu00
��Ŀ����ά�����еĲ���
 ��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
 �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������*/

 #include <iostream>

bool Find(int* matrix, int rows, int columns, int number);

int main(int argc, char* argv[])
{
    //  int arr[4][4] = {{1, 2, 8, 9},
    //                   {2, 4, 9, 12},
    //                   {4, 7, 10, 13},
    //                   {6, 8, 11, 15}};//��������
    int arr[16] = {1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15};//��������

    bool b = Find(arr, 4, 4, 7);

    std::cout << b << std::endl;

     return 0;
}

bool Find(int* matrix, int rows, int columns, int number)
{
    bool found = false;

    int row = 0;
    int column = columns - 1;

    if ( matrix != NULL && rows > 0 && columns > 0) //����Ƿ�����
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