#include <stdio.h>
#include <stdlib.h>

int temp;

void totalScore(int *totalScore, int numEmployee, int **ratings, int numPeriods)
{
    for (int i = 0; i < numEmployee; i++)
    {
        totalScore[i] = 0;
        for (int j = 0; j < numPeriods; j++)
        {
            totalScore[i] += ratings[i][j];
        }
    }
}

void avgScore(int *avgScore, int *totalScore, int numEmployee, int numPeriods)
{
    for (int i = 0; i < numEmployee; i++)
    {
        avgScore[i] = totalScore[i] / numPeriods;
    }
}

void EmployeeRatings(int **ratings, int numEmployee, int numPeriods, int *totalscore, int *avgscore)
{
    for (int i = 0; i < numEmployee; i++)
    {
        ratings[i] = (int *)calloc(numPeriods, sizeof(int));

        for (int j = 0; j < numPeriods; j++)
        {
            printf("Enter a rating for Employee %d (1 to 9): ", i + 1);
            scanf("%d", &temp);
            if (temp >= 1 && temp <= 9)
            {
                ratings[i][j] = temp;
            }
            else
            {
                printf("Invalid rating\n");
                j--;
            }
        }
    }

    totalScore(totalscore, numEmployee, ratings, numPeriods);
    avgScore(avgscore, totalscore, numEmployee, numPeriods);
}

void DisplayPerformance(int **ratings, int numEmployees, int numPeriods)
{
    for (int i = 0; i < numEmployees; i++)
    {
        printf("\nEmployee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++)
        {
            printf("Evaluation period %d: %d\n", j + 1, ratings[i][j]);
        }
    }
}

void findEmployeeOfTheYear(int *avgscore, int numEmployee)
{
    int max = avgscore[0];
    int maxIn = 0;
    for (int i = 1; i < numEmployee; i++)
    {
        if (avgscore[i] > max)
        {
            max = avgscore[i];
            maxIn = i;
        }
    }
    printf("Employee of the year is Employee %d with average score: %d\n", maxIn + 1, max);
}

void findWorstEmployee(int *avgscore, int numEmployee)
{
    int min = avgscore[0];
    int minIn = 0;
    for (int i = 1; i < numEmployee; i++)
    {
        if (avgscore[i] < min)
        {
            min = avgscore[i];
            minIn = i;
        }
    }
    printf("Worst Employee is Employee %d with average score: %d\n", minIn + 1, min);
}

int HighestRatedPeriod(int **ratings, int *avgRatings, int numEmployee, int numPeriods)
{

    for (int i = 0; i < numPeriods; i++)
    {
        avgRatings[i] = 0;
        for (int j = 0; j < numEmployee; j++)
        {
            avgRatings[i] += ratings[j][i];
        }
        avgRatings[i] /= numPeriods;
    }

    int max = avgRatings[0];
    int maxIn = 0;
    for (int i = 1; i < numPeriods; i++)
    {
        if (avgRatings[i] > max)
        {
            max = avgRatings[i];
            maxIn = i;
        }
    }
    printf("The highest rated evaluation is  %d with average ratings: %d\n", maxIn + 1, max);

    return 0;
}

int main()
{
    int numEmployee, numEval;
    printf("How many Employees?\n");
    scanf("%d", &numEmployee);
    printf("How many Evaluation periods?\n");
    scanf("%d", &numEval);

    int **ratings = (int **)calloc(numEmployee, sizeof(int *));
    int *totalscore = (int *)calloc(numEmployee, sizeof(int));
    int *avgscore = (int *)calloc(numEmployee, sizeof(int));
    int *avgRatings = (int *)calloc(numEval, sizeof(int));

    EmployeeRatings(ratings, numEmployee, numEval, totalscore, avgscore);
    DisplayPerformance(ratings, numEmployee, numEval);
    findEmployeeOfTheYear(avgscore, numEmployee);
    findWorstEmployee(avgscore, numEmployee);
    HighestRatedPeriod(ratings, avgRatings, numEmployee, numEval);

    for (int i = 0; i < numEmployee; i++)
    {
        free(ratings[i]);
    }
    free(ratings);
    free(totalscore);
    free(avgscore);
    free(avgRatings);

    return 0;
}
