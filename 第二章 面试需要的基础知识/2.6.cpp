/*2.6 ≈≈–Ú
≤Â»Î≈≈–Ú
√∞≈›≈≈–Ú
πÈ≤¢≈≈–Ú
øÏÀŸ≈≈–Ú
*/
#include <iostream>

//øÏÀŸ≈≈–Ú
void Quicksort(int arry[], int L, int R)
{
    if ( L >= R )  return;

    int left = L, right = R;
    int pivot = arry[left];
    while(left<right)
    {
        while(left<right && arry[right]>=pivot)     right--;
        if (left<right)     arry[left] = arry[right];

        while(left<right && arry[left]<=pivot)      left++;
        if (left<right)     arry[right] = arry[left];

        if (left>=right)    arry[left] = pivot;
    }

    Quicksort(arry, L, right-1);
    Quicksort(arry, right+1, R);
}

int main(int argc, char* argv[])
{
    int arry[5] = {22, 3, 55, 8, 1};
    Quicksort(arry, 0, 5);
    for ( int i=0; i<5; i++)
    {
        printf("%d ", arry[i]);
    }
    return 0;
}