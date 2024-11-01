#include <stdio.h>
int A_win(int num);
int main()
{
    int noOfMatches;
    printf("Enter the number of match sticks : ");
    scanf("%d", &noOfMatches);

    if (A_win(noOfMatches) == -1)
    {
        printf("We can't Guarantee A's win");
        return 0;
    }
    else
    {
        printf("A should pick %d to win", A_win(noOfMatches));
    }

    return 0;
}
int A_win(int num)
{
    int pick = num % 5;
    if (pick == 0)
    {
        return -1;
    }
    else
    {
        return pick;
    }
}