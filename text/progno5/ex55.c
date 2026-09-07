/*
 * 自分自身を呼び出す(再帰呼び出し)関数の例
 * (この計算方法が好ましい訳ではない)
 */

#include <stdio.h>


int frac(int);                 /* 関数fracのプロトタイプ宣言 */

int main(void)
{
  int i;
  
  printf("1!...10!の計算\n");
  for(i=1; i<=10; i++){
    printf("%3d! = %d\n", i, frac(i));
  }
  return 0;
}

int frac(int n)                /* 再帰呼び出しによる n! の計算 */
{
  if(n == 1)
    return 1;
  else
    return n*frac(n-1);
}
