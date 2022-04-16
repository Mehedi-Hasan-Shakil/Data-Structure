#include <stdio.h>
void no_emploee_born(int arr[]);
int num_no_employee_born(int arr[]);
int num_older_than_50_years(int arr[]);
int num_older_than_l_years(int arr[], int l);

int main(void)
{
    printf("Enter year (at least l years old) : ");
    int l;
    scanf("%d", &l);
    int year[71];
    for(int i = 20; i <= 70; i++)
    {
        if(i % 2)
            year[i] = 5;
        else
            year[i] = 0;
    }
    no_emploee_born(year);
    printf("Number of no employee born year is %d\n", num_no_employee_born(year));
    printf("Number of employee older than 50 years is %d\n", num_older_than_50_years(year));
    printf("Number of employee older than %d years is %d\n", l, num_older_than_l_years(year, l));
    return 0;
}
void no_emploee_born(int arr[])
{
    printf("Years when no employee born : ");
    for(int i = 20; i <= 70; i++)
    {
        if(arr[i] == 0)
            printf("19%d ", i);
    }
    printf("\n");
}
int num_no_employee_born(int arr[])
{
    int num = 0;
    for(int i = 20; i <= 70; i++)
    {
        if(arr[i] == 0)
            num++;
    }
    return num;
}
int num_older_than_50_years(int arr[])
{
    int num = 0;
    for(int i = 20; i <= 34; i++)
        num += arr[i];
    return num;
}
int num_older_than_l_years(int arr[], int l)
{
    int num = 0;
    for(int i = 20; i <= (84 - l); i++)
    {
        num += arr[i];
    }
    return num;
}
