/*
 * ２行３列の行列Lと３行２列の行列Mの積を２行２列の行列Nに格納する関数を用いたプログラム
 * なお行列の値は任意の整数をあらかじめ与えられている．（多次元配列の受け渡し）
 */
# include <stdio.h>

void mul( int x[2][3], int y[3][2], int z[2][2]);

int main(void)
{
    int  i, j;
    int  l[2][3] = { {1, 2, 3}, {4, 5, 6} };
    int  m[3][2] = { {7, 8}, {9, 1}, {2, 3} };
    int  n[2][2];

    mul(l, m, n);

    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++)
            printf("%3d", n[i][j]);
        printf("\n");
    }
    return 0;
}

void mul( int x[2][3], int y[3][2], int z[2][2])
{
    int  i, j, k;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            z[i][j] = 0;
            for (k = 0; k < 3; k++)
               z[i][j] += x[i][k] * y[k][j];
        }
    }
}
