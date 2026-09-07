/*
 * 漸化式 x(i+2) = a x(i+1) + b x(i) から数列を求める．
 * xの絶対値がXMAXを越えるかiがIMAXを越えると終了する．
 */
#include <stdio.h>
#include <math.h>
#define IMAX 1000
#define XMAX 1000.0

int
main(void)
{
    int         i;
    double      x1, x2, a, b, x, xm1, xm2;

    /* パラメータの入力 */
    printf("x(i+2) = a x(i+1) + b x(i)で定義される数列を求めます．\n");
    printf("x(1)を入力して下さい  → "); scanf("%lf", &x1);
    printf("x(2)を入力して下さい  → "); scanf("%lf", &x2);
    printf("係数aを入力して下さい → "); scanf("%lf", &a);
    printf("係数bを入力して下さい → "); scanf("%lf", &b);

    printf("x(  1) = %6.1f\n", x1);
    printf("x(  2) = %6.1f\n", x2);
    i = 3;
    xm2 = x1;
    xm1 = x2;
    do {
        x = a*xm1 + b*xm2;
        printf("x(%3d) = %6.1f\n", i, x);
        xm2 = xm1;
        xm1 = x;
    } while ( ++i <= IMAX && fabs(x) <= XMAX );
    /* fabs は, 引数の絶対値を返す関数  */
    /* ++i は i++ でもいいと思いますか? */
    return 0;
}
