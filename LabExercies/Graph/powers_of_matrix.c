#include <stdio.h>
int power_matrix[20][20][20];
int all_length_matrix[20][20];
int path_matrix[20][20];
int is_strongly_connected = 1;
int main(void)
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int matrix[n][n];
    printf("Enter your adjacency matrix:\n");
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
                    for (int p = 0; p < n; p++)
                    {
                        for (int q = 0; q < n; q++)
                        {
                            power_matrix[0][p][q] = matrix[p][q];
                        }
                    }
                }
                else
                {
                    int sum = 0;
                    for (int l = 0; l < n; l++)
                    {
                        sum += power_matrix[i - 1][j][l] * matrix[l][k]; // matrix multiplication
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
                    all_length_matrix[p][q] += power_matrix[i][p][q]; // creating all length matrix
                }
                else
                {
                    printf("There is no path between %d and %d of length %d\n", p, q, i + 1);
                }
            }
        }
        printf("\n\n");
    }
    printf("All length matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", all_length_matrix[i][j]);
            if (all_length_matrix[i][j]) // creating path matrix
            {
                path_matrix[i][j] = 1;
            }
            if (all_length_matrix[i][j] == 0 && is_strongly_connected)
            {
                is_strongly_connected = 0;
            }
        }
        printf("\n");
    }
    printf("\n\n");
    printf("Path matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", path_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    if (is_strongly_connected)
    {
        printf("The graph is strongly connected.");
    }
    else
    {
        printf("The graph is not connected strongly.");
    }
    printf("\n\n");
    return 0;
}
