#include <stdio.h>
int main()
{
    int arr[] = {52, 56, 34, 14, 45, 86};
    int temp;
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
 printf(" The second smallest is : %d", arr[1]);

    return 0;
}