#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Display(int valid)
{
    printf("%s", (valid) ? "Valid" : "Invalid");
    // printf("Invalid Email");
}
int ValidateEmail(char email[], int length)
{
    int valid = 1;
    int AT_index;
    int AT_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (email[i] == '@')
        {
            AT_count++;
            AT_index = i;
            printf("//%d", AT_count);
        }
        else
        {
            valid = 0;
        }
        if (AT_count != 1)
        {
            valid = 0;
        }
    }
    if (!valid)
    {
        valid = 0;
    }
    for (int i = AT_index; i < length; i++)
    {
        for (int i = 0; i < length; i++)
        {
            if (email[i] == '.')
            {
                valid = 1;
                AT_index = i;
                break;
            }
            else
            {
                valid = 0;
            }
        }
        if (!valid)
        {
            valid = 0;
        }
    }
    return (valid) ? 1 : 0;
}
int main()
{
    int length;
    char *email;
    printf("Enter the length");
    scanf("%d", &length);

    email = (char *)calloc(length + 1, sizeof(char));
    printf("Enter a string");
    scanf(" ");
    fgets(email, length, stdin);
    int Validate = ValidateEmail(email, length);
    Display(Validate);
}