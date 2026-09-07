/* 
 * 実数のべき乗を求める関数
 * ループとの組み合わせ
 */

#include <stdio.h>

double power(double r, int a);                 /*関数 power のプロトタイプ宣言*/

int main(void)
{
   int   n;
   double k;
   printf ("実数Ｋを入力してください：");
   scanf("%lf", &k);
   printf ("何乗しますか？：");
   scanf("%d", &n);
   
   printf ("%.3fの%d乗は%.3fです．\n", k, n, power(k, n) );
   return 0;
}

double power(double r, int a)
{
   int   i;
   double tmp=1.0;

   for (i=1; i <=a; i ++)
       tmp *= r;
   return tmp;
}

