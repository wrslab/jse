/*
 * 多重ループの例
 * 階乗の計算
 */

#include <stdio.h>

int main(void)
{
  int i,j,fact;

  printf("1!...10!の計算\n");

  for(i = 1; i <= 10; i++){
    fact = 1;
    for(j = 1; j <= i; j++){
      fact *= j;
    }
    printf("%3d! = %d\n", i, fact);
  }
  return 0;
} 
