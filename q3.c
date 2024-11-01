#include <stdio.h>
int main()
{
   char str[50] = "book";
   char str1[50] = {0};
   int j = 0, counter = 0;
   for (int i = 0; i < 4; i++)
   {

      if (str[i] == str[i + 1])
      {
         counter++;
      }
      else
      {
         str1[j] = str[i];
         j++;
      }
   }

   for (int i = 0; i<50; i++)
   {
      printf("%c", str1[i]);
   }
   return 0;
}