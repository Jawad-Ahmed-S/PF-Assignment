#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void WhichFunction();
void BinaryToDecimal(int number[], int length);
void DecimalToBinary(int number);
void DecimalToHex(int number);
int hexToDecimal(char input[]);
void HextoBinary(char input[]);
int main()
{
    // int arr[2]={3,2};

    char ConvType[3];
    int input[] = {4, 5, 1, 0, 1};
    WhichFunction();
    scanf("%s", ConvType);
    if (strcmp(ConvType, "btd") == 0)
    {
        int length = (sizeof(input) / sizeof(input[0]));
        BinaryToDecimal(input, length);
    }
    else if (strcmp(ConvType, "dtb") == 0)
    {
        int number = 25;
        DecimalToBinary(number);
    }
    else if (strcmp(ConvType, "dth") == 0)
    {
        int number = 2225;
        DecimalToHex(number);
    }
    else if (strcmp(ConvType, "htd") == 0)
    {
        char input[] = "E1";
        hexToDecimal(input);
    }
    else if (strcmp(ConvType, "htb") == 0)
    {
        char input[] = "E1";
        HextoBinary(input);
    }
    else
    {
        printf("Invalid function");
    }
    return 0;
}

void WhichFunction()
{
    printf("Which Conversion you want to perform? \n");
    printf("Binary to Decimal (btd)\n");
    printf("Decimal to Binary (dtb)\n");
    printf("Binary to Hexadecimal(bth)\n");
    printf("Hexadecimal to Decimal(htd)\n");
    printf("Hexadecimal to Binary(htb)\n");
}

void BinaryToDecimal(int number[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        if (number[i] != 0 && number[i] != 1)
        {
            printf("Invalid...");
            break;
        }
        else
        {
            sum += number[i] * pow(2, length - 1 - i);
        }
    }
    printf("%d", sum);
}

void DecimalToBinary(int number)
{
    int binary[16]={-1};

    for (int i = 0; number > 0 && i < 16; i++)
    {
        binary[i] = number % 2;
        number /= 2;
    }
    for (int i = 8; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
}

void DecimalToHex(int number)
{
    char hex[10];

    int i;
    for (i = 0; number > 0 && i < 10; i++)
    {

        int tempRemainder = number % 16;
        if (tempRemainder < 10)
        {
            hex[i] = tempRemainder + '0';
            printf("%c", hex[i]);
        }
        else
        {
            hex[i] = (tempRemainder - 10) + 'A';
        }

        number /= 16;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hex[j]);
    }
}
int hexToDecimal(char input[])
{

    int decimal = 0;
    int power =0;
    int length = strlen(input);
    for (int i = length-1; i > 0; i--)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            decimal += (input[i] - '0') * pow(16, power);
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            decimal += ((input[i] - 'A') + 10) * pow(16, power);
        }
        else if (input[i] >= 'a' && input[i] <= 'f')
        {
            decimal += (input[i] - 'a' + 10) * power;
        }
        power++;
    }

    printf("%d", decimal);
    return (decimal);
}
void HextoBinary(char input[])
{
    int number = hexToDecimal(input);
    printf("%d", number);
    DecimalToBinary(number);
}