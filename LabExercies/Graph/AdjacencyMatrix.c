#include <stdio.h>
void add_edge(int, int);
void display_matrix(int);
int matrix[20][20], status;
int main(void)
{
    int n, e, u, v;
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    printf("Enter number of edges : ");
    scanf("%d", &e);
    printf("Enter 1 for directed graph or 2 for undirected graph : ");
    scanf("%d", &status);
    printf("Enter nodes in pair like (u, v) :\n");
    for(int i = 0; i < e; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    display_matrix(n);
    return 0;
}
void add_edge(int u, int v)
{
    if(status == 1)
    {
        matrix[u][v] = 1;
    }
    else if(status == 2)
    {
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
}
void display_matrix(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
