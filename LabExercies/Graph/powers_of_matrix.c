#include <stdio.h>
void create_matrix(int);
void display_matrix(int);
void number_of_paths(int);
void display_adjacency_list(int);
int matrix[20][20];
int power_matrix[20][20];
int main(void)
{
    int n;
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    printf("Enter the matrix :\n");
    create_matrix(n);
    number_of_paths(n);
    display_matrix(n);

    return 0;
}
void create_matrix(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}
void display_adjacency_list(int n)
{
    printf("\nAdjacency List :\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d --> ", i);
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j])
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}
void number_of_paths(int n)
{
    int length, u, v;
    printf("Enter your required length : ");
    scanf("%d", &length);
    printf("Enter source and destination nodes : ");
    scanf("%d%d", &u, &v);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            power_matrix[i][j] = matrix[i][j];
        }
    }
    for(int k = 0; k < length - 1; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int temp = 0;
                for(int l = 0; l < n; l++)
                {
                    temp += power_matrix[i][l] * matrix[l][j];
                }
                power_matrix[i][j] = temp;
            }
        }
    }
    printf("\nNumber of paths of length %d from %d to %d is %d\n", length, u, v, power_matrix[u][v]);
}
void display_matrix(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", power_matrix[i][j]);
        }
        printf("\n");
    }
}
