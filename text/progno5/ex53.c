/* 
 * int型整数の二乗を計算する関数を用いた四乗値を求めるプログラム
 * 関数のなかから関数を呼び出す
 */

#include <stdio.h>

int sqr(int x);                       /*関数 sqr のプロトタイプ宣言*/

int main(void)
{
   int  n;
   printf ("整数を入力してください．：");
   scanf("%d", &n);
   
   printf ("四乗は%dです．\n",  sqr(sqr(n)));
   return 0;
}

int sqr(int x)
{
   return x*x;
}

