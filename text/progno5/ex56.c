/*
 * 2分法による方程式f(x)=0の求解 (簡単のため入力のチェックなし)
 */

#include <stdio.h>
#include <math.h>

/* 関数fのプロトタイプ宣言 */
double f(double);

int main(void)
{
    double a, b, c, fa, fb, fc, eps;
    
    printf("探索区間の最小値 → "); scanf("%lf", &a);
    printf("探索区間の最大値 → "); scanf("%lf", &b);
    printf("解の許容誤差     → "); scanf("%lf", &eps);

    fa = f(a);
    fb = f(b);

    while ( 1 ) {
        c = (a + b)/2.0;
        fc = f(c);
        printf("f(%10.7f) = %10.7f\n",  c, fc);
        if ( (b - c) < eps || (c -a) < eps ) {
            break;
        }
        if( (fc > 0.0 && fa > 0.0) || (fc <= 0.0 && fa <= 0.0) ){
            a = c;
            fa = fc;
        } else {
            b = c;
            fb = c;
        }
    }
}

/* 関数fの定義 */
double
f(double x)
{
    return x*x - 2.0;
}
