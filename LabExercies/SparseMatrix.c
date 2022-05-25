//Copy elements from lower triangular matrix to 1D array and
//print specified element(a[3][2])
#include<stdio.h>
int main(void) {
    int a[3][3] = {{1},
                   {2, 3},
                   {4, 5, 6}};
    int row = 3, column = 3;
    int n = (row * (row + 1)) / 2;
    int b[n], k = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j <= i; j++) {
            b[k++] = a[i][j];
        }
    }
    int i = 3, j = 2;
    printf("Element at [%d, %d] is %d\n", i, j, b[((i-1) * (i) / 2) + (j-1)]);
}
