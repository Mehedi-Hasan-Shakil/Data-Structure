/*Let A be an n × n square matrix array. Write a module which
(a) Finds the number NUM of nonzero elements in A
(b) Finds the SUM of the elements above the diagonal, i.e., elements A[I, J] where I < J
(c) Finds the product PROD of the diagonal elements (a11, a22, …, ann)*/

#include <stdio.h>
int num_of_nonzero_elements(int mat[3][3], int n);
int sum_of_elements_above_diagonal(int mat[3][3], int n);
int product_of_diagonal_elements(int mat[3][3], int n);

int main(void)
{
    int mat[3][3] = {1, 2, 3,
                     0, 4, 5,
                     5, 6, 7
                    };
    int n = 3;
    printf("Number of nonzero element is %d\n", num_of_nonzero_elements(mat, n));
    printf("Sum of elements above diagonal is %d\n", sum_of_elements_above_diagonal(mat, n));
    printf("Product of diagonal element is %d\n", product_of_diagonal_elements(mat, n));
    return 0;
}
int num_of_nonzero_elements(int mat[3][3], int n)
{
    int num = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(mat[i][j] != 0)
                num++;
        }
    }
    return num;
}
int sum_of_elements_above_diagonal(int mat[3][3], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
            sum += mat[i][j];
    }
    return sum;
}
int product_of_diagonal_elements(int mat[3][3], int n)
{
    int prod = 1;
    for(int i = 0; i < n; i++)
    {
        prod *= mat[i][i];
    }
    return prod;
}
