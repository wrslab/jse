/*
 * 行列とベクトルの掛け算
 */
#include <stdio.h>

#define ROWMAX 100
#define COLMAX 100

int
main(void)
{
    double m[ROWMAX][COLMAX] = {{0.0, 0.1, 0.2, 0.3},
                                {1.0, 1.1, 1.2, 1.3},
                                {2.0, 2.1, 2.2, 2.3}},
           v1[COLMAX], v2[ROWMAX];
    int    i, j;

    /* v1 への入力 */
    for ( i = 0; i < 4; i++ ) {
        printf("v1[%d] → ", i);
        scanf("%lf", &v1[i]);
    }

    /* v2 = m * v1 の計算 */
    for ( j = 0; j < 3; j++ ) {
        v2[j] = 0.0;
        for ( i = 0; i < 4; i++ ) {
            v2[j] += m[j][i]*v1[i];
        }
    }
    
    /* v2 の出力 */
    for ( j = 0; j < 3; j++ ) {
        printf("v2[%d] = %8.3f\n", j, v2[j]);
    }
    return 0;
}
