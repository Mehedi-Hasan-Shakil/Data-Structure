#include <stdio.h>

int main(void)
{
    int mat1[2][2] = {1, 3,
                      2, 4
                     };
    int mat2[2][3] = {2, 0, -4,
                      3, 2, 6
                     };
    int mat3[2][3];
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            mat3[i][j] = 0;
            for(int k = 0; k < 2; k++)
            {
                mat3[i][j] += (mat1[i][k] * mat2[k][j]);
            }
        }
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", mat3[i][j]);
        }
        printf("\n");
    }
    return 0;
}
