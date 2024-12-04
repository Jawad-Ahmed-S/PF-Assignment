#include <stdio.h>
int main()
{
    int arr[] = {1, 2, 5, 6, 8, 3};

    for (int i = 0; i <=6; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}