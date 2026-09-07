/*
 * 多重ループの例
 * 16進数 <-> 10進数の変換表の作成
 */
#include <stdio.h>

int main(void)
{
  int i,j;
  
  printf("16進数 <->10進数の変換表\n");
  printf("HEX");
  for(i=0; i<16; i++){
    printf("%4X",i);             /* %x は，整数値を16進数で表示*/
  }
  printf("\n");
  for(i=0; i<16; i++){
    printf( " %1X ", i );        /* %x は，整数値を16進数で表示*/
    for( j=0; j<16; j++){
      printf( "%4d", j+i*16);
    }
    printf("\n");
  }
  return 0;
}
