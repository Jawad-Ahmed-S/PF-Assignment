#include <stdio.h>
int main()
{
    int arr[] = {4, 2, 5, 6, 8, 3};
    int max = 0;
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    // printf("%d", max);
    for (int i = 1; i <= max; i++) // rows
    {
        for (int j = 0; j < 6; j++) // col
        {

            if (arr[j] >= i)
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }

    return 0;
}