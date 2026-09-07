/*
 * テイラー展開によるsinの計算
 */
#include <stdio.h>
#include <math.h>    /* sinに必要*/

int main(void)
{
    double x,xn,sinx;
    int n,i;
    printf("sin x を計算します\n");
    printf("xの値を入力して下さい\n");
    scanf("%lf", &x);
    printf("第何項まで計算するか入力してください\n");
    scanf("%d",&n);
    xn=x;
    sinx=x;
    i=1;
     for(i=1; i<n; i++){
        xn*=(-1)*x*x/(2.0*i+1.0)/(2.0*i);
        sinx+=xn;
    }
    printf("sin(x)=%f\n",sin(x));    /*比較のために，sin(a)を計算*/
    printf("テイラー展開では%f\n",sinx);
    return 0;
}

