#include <stdio.h>
int matrix[20][20];
int path_matrix[20][20];
int shortest_path_matrix[20][20];
int main(void)
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j])
            {
                path_matrix[i][j] = 1;
                shortest_path_matrix[i][j] = matrix[i][j];
            }
            else
            {
                path_matrix[i][j] = 0;
                shortest_path_matrix[i][j] = 1000;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                path_matrix[i][j] = path_matrix[i][j] || (path_matrix[i][k] && path_matrix[k][j]);
                shortest_path_matrix[i][j] = shortest_path_matrix[i][j] < (shortest_path_matrix[i][k] + shortest_path_matrix[k][j]) ? shortest_path_matrix[i][j] : (shortest_path_matrix[i][k] + shortest_path_matrix[k][j]);
            }
        }
    }
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
    printf("Shortest path matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", shortest_path_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    return 0;
}
