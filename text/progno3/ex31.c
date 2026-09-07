/*
 *  for 文を用いたプログラム例
 */
#include <stdio.h>

int main(void)
{
    int i, i2, sum1, sum2;

    sum1 = sum2 = 0;
    for ( i = 1; i <= 100; i++ ) {
        i2 = i*i;
        printf("i = %3d, i*i = %5d\n", i, i2);
        /* 書式指定文字列の中の%3dや%5dを%dに変えるとどうなるだろうか? */
        sum1 += i;      /* sum1 = sum1 + i; の簡略記法 */
        sum2 += i2;     /* sum2 = sum2 + i2; の簡略記法 */
    }
    printf("iの総計 = %d, i*iの総計 = %d\n", sum1, sum2);
    return (0);
}
