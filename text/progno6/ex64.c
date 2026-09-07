/*
 * 2つの行列の和と差を表示するプログラム
 */
#include<stdio.h>

#define ROW 2
#define COLUMN 2

int main (void)
{
    int a[ROW][COLUMN];
    int b[ROW][COLUMN];
    int c[ROW][COLUMN];
    int d[ROW][COLUMN];
    int i,j;
   
    printf("1番目の２ｘ２行列の値を整数でいれてください\n");
    for (i = 0;i < ROW;i++){
        printf("%d行目\n",i+1);
        for (j = 0;j < COLUMN;j++){
            printf("    %d列目",j+1);
            scanf("%d",&a[i][j]);
        }
    }
    printf("2番目の２ｘ２行列の値を整数でいれてください\n");
    for ( i = 0;i < ROW;i++){
        printf("%d行目\n",i+1);
        for (j = 0;j < COLUMN;j++){
            printf("    %d列目",j+1);
            scanf("%d", &b[i][j]);
        }
    }
    for (i = 0;i < ROW;i++){
        for (j = 0;j < COLUMN;j++){
            c[i][j] = a[i][j] + b[i][j];
            d[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("\n2つのベクトルの和を表示します。\n");
    for ( i = 0;i < ROW;i++){
        for (j = 0;j < COLUMN;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    printf("\n2つのベクトルの差を表示します。\n");
    for ( i = 0;i < ROW;i++){
        for (j = 0;j < COLUMN;j++){
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }
    return 0;
}
