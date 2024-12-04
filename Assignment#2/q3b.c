#include <stdio.h>
#include <string.h>
int main()
{
    char str[10][10] = {"boook", "hook", "croop"};
    char str1[10][10] = {0};
    int j = 0, counter = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int m = 0; m < 10; m++)
        {

            if (str[i][m] == str[i][m + 1])
            {
                counter++;
            }
            else
            {
                str1[i][m] = str[i][m];
                j++;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= 7; j++)
            printf("%c", str1[i][j]);

        printf("\n");
    }
    return 0;
}