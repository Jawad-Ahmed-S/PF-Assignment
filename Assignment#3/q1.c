#include <stdio.h>
struct employee
{
    int employeeCode;
    char employeeName[10];
    // struct date
    // {
    int date;
    int month;
    int year;
    // };
    // struct date D1;
};
// void assign(struct employee E1){
// scanf("%d",&E1.employeeCode);
// scanf("%s",&E1.employeeName);
// scanf("%d",&E1.employeeCode);

// }
int main()
{
    struct employee E1[4] = {
        {123, "Jawad", 1, 1, 2021},
        {456, "Ibrahim", 1, 5, 2015},
        {789, "ABC", 10, 2, 2024},
        {825, "ZYZ", 30, 2, 2022},
    };
    float total_years[4];
    float Tenure[4];
    for (int i = 0; i < 4; i++)
    {
        total_years[i] = ((E1[i].date - 1) / 365.25) + ((E1[i].month - 1) / 12) + E1[i].year;
        float Current_Date = ((11 - 1) / 365.25) + ((23 - 1) / 12) + 2024;

        Tenure[i] = Current_Date - total_years[i];
        if (Tenure[i] > 3)
        {
            printf("Employee Code : %d\n", E1[i].employeeCode);
            printf("Employee Name : %s\n", E1[i].employeeName);
            printf("Date : %d - %d - %d\n", E1[i].date, E1[i].month, E1[i].year);
            printf("Tenure : %f\n", Tenure[i]);
        }
        else
        {
            printf("New Employee");
        }
        printf("\n\n");
    }
    return 0;
}