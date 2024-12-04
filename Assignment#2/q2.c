#include <stdio.h>
int main()
{
    char str[] = "limited_edition";
    char alphabet = 'a';
    int counter[26] ={0};
   
    //---------------------
    for (int i = 0; i < (sizeof(str)/sizeof(str[i])); i++)
    {
        for (int j = 97; j < 122; j++)
        {
            if (str[i] == j)
            {
                counter[j - 97]++;
            }
        }
    }
    // printing the array
    for (int n = 0; n < 26; n++)
    {
        if (counter[n] > 0)
        {
            printf("%c : %d \n", alphabet, counter[n]);
        }
        alphabet++;
    }
    //---------------------------------
    return 0;
}