#include <stdio.h>
#include <string.h>
char str[6][5] = {"eta", "ate", "eat", "nat", "tan", "ant"}; // grou=2;i=6;j=3;
char temp[6][3];
char copy[6][5];
char global[2][6][5];
int length = 6;
void copyarray(void);
void sorting(void);
void checkword(void);
int main()
{

    copyarray();
    sorting();
    checkword();

    for (int i = 0; i < 6; i++)
    {
        if (strlen(global[i][0]) > 0) // Check if the group has any words
        {
            for (int j = 0; j < 6 && strlen(global[i][j]) > 0; j++)
            {
                printf("%s, ", global[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

void copyarray(void)
{

    for (int i = 0; i < length; i++)
    {
        strcpy(copy[i], str[i]);
    }
}
void sorting(void)
{
    for (int i = 0; i < length; i++)
    {
        int len = strlen(copy[i]);
        for (int j = 0; j < len - 1; j++)
        {
            for (int k = 0; k < len - j - 1; k++)
            {
                if (copy[i][k] > copy[i][k + 1])
                {
                    char temp = copy[i][k];
                    copy[i][k] = copy[i][k + 1];
                    copy[i][k + 1] = temp;
                }
            }
        }
    }
}

void checkword()
{
    int group = 0;
    memset(global, '\0', sizeof(global));

    for (int i = 0; i < length; i++) // for strings in global
    {
        int found = 0;
        for (int j = 0; j < group; j++) // Iterate through existing groups
        {
            if (strcmp(copy[i], global[j][0]) == 0)
            {
                found = 1;

                int position = 1;
                while (global[j][position][0] != '\0' && position < 6) // to find where to store in a group
                {
                    position++;
                }

                strcpy(global[j][position], str[i]);
                break;
            }
        }
        if (!found)
        {
            strcpy(global[group][0], str[i]);
            group++;
        }
    }
}
