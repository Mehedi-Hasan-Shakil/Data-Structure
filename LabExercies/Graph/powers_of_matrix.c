#include <stdio.h>
int power_matrix[20][20][20];
int main(void)
{
    int n;
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    int matrix[n][n];
    printf("Enter your adjacency matrix :\n");
    for (int i = 0; i < n; i++)
    { // take input as matrix
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n\nAdjacency List:\n"); // display adjacency list
    for (int i = 0; i < n; i++)
    {
        printf("%d --> ", i);
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j])
                printf("%d ", j);
        }
        printf("\n");
    }
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i == 0) // copy adjacency matrix to power matrix[0][n][n]
                {
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            power_matrix[0][i][j] = matrix[i][j];
                        }
                    }
                }
                else
                {
                    int sum = 0;
                    for (int l = 0; l < n; l++)
                    {
                        sum += power_matrix[i - 1][j][l] * matrix[l][k];
                    }
                    power_matrix[i][j][k] = sum;
                }
            }
        }
        for (int p = 0; p < n; p++)
        {
            for (int q = 0; q < n; q++)
            {
                if (power_matrix[i][p][q])
                {
                    printf("%d path(s) between %d and %d of length %d\n", power_matrix[i][p][q], p, q, i + 1);
                }
                else
                {
                    printf("There is no path between %d and %d of length %d\n", p, q, i + 1);
                }
            }
        }
        printf("\n\n");
    }
    return 0;
}
