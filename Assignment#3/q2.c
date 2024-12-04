#include <stdio.h>
struct Player
{
    int score[12];
    char name[10];
    int totalScore;
};
void PlayGame(struct Player *P)
{
    for (int i = 0; i < 12; i++)
    {
        printf("Enter the score for '%d' ball", i + 1);
        scanf("%d", &P->score[i]);
    }
}
void ValidateScore(struct Player *P)
{
    P->totalScore = 0;
    for (int i = 0; i < 12; i++)
    {
        if (P->score[i] < 6 && P->score[i] > 0)
        {
            P->totalScore += P->score[i];
        }
        else
        {
            P->score[i] = 0;
        }
    }
}
int findWinner(struct Player P1, struct Player P2)
{
    int winner;
    if (P1.totalScore > P2.totalScore)
    {
        winner = 1;
    }
    else if (P1.totalScore < P2.totalScore)
    {
        winner = 2;
    }
    else
    {
        winner = 0;
    }
    return winner;
}
void DisplayScoreBoards(struct Player P1, struct Player P2)
{
    printf("\n\nPlayer 1: \n");
    int sum = 0;
    for (int i = 0; i < 12; i++)
    {
        printf("%d : %d \n", i, P1.score[i]);
        sum += P1.score[i];
    }
    printf("Average Score : %f \n", ((float)sum) / 12);
    printf("Total Score : %d \n", P1.totalScore);

    printf("\n\nPlayer 2: \n");

    for (int i = 0; i < 12; i++)
    {
        printf("%d : %d \n", i, P2.score[i]);
        sum += P2.score[i];
    }
    printf("Average Score : %f \n", ((float)sum) / 12);
    printf("Total Score : %d \n", P2.totalScore);
}
int main()
{

    struct Player P1;
    PlayGame(&P1);
    ValidateScore(&P1);

    struct Player P2;
    PlayGame(&P2);
    ValidateScore(&P2);

    int Winner = findWinner(P1, P2);
    if (Winner == 1)
    {
        printf("Player 1 Wins!");
    }
    else if (Winner == 2)
    {
        printf("Player 2 Wins!!");
    }
    else
    {
        printf("Match Drawed!");
    }
    DisplayScoreBoards(P1, P2);

    return 0;
}