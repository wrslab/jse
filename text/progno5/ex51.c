/* 
 * 二つのint型整数の小さい方の値を返す関数
 * 関数定義と関数呼び出し，引数，返却値型などの基礎
 */
#include <stdio.h>

int min(int x, int y);                      /*関数 min のプロトタイプ宣言 */

int main(void)
{
   int  m, n;
   printf ("整数Ｍ：");
   scanf("%d", &m);
   printf ("整数Ｎ：");
   scanf("%d", &n);
   
   printf ("小さい方の値は%dです．\n",  min(m, n));
   return 0;
}

int min(int x, int y)
{
   if (x < y)
     return x;
   else
     return y;
}

