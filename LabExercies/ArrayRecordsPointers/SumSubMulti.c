#include <stdio.h>
int main() {
    int row = 3, column = 3;
    int a[3][3] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};
    int b[3][3] = {{9, 8, 7},
                   {6, 5, 4},
                   {1, 2, 3}};
    int add[row][column], sub[row][column];
    int multi[row][column];

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            add[i][j] = a[i][j] + b[i][j]; //Addition
            sub[i][j] = a[i][j] - b[i][j]; //Subtraction
            multi[i][j] = 0;
            for(int k = 0; k < column; k++) {
                multi[i][j] += a[i][k] * b[k][i] ; //Multiplication
            }
        }
    }
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("%d ", add[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("%d ", sub[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("%d ", multi[i][j]);
        }
        printf("\n");
    }
}
