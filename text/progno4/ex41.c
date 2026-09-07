/*
 * 白黒円の市松模様を描く
 */
#include <stdio.h>

#define IXMAX   10
#define IYMAX    7
int main(void)
{
  int ix, iy;
  
  /* 格子状に○と●を並べる */
  for ( ix = 0; ix < IXMAX; ix++ ) {
    for ( iy = 0; iy < IYMAX; iy++ ) {
      /* 市松模様になるように○と●を切替え */
      if ( (ix+iy)%2 == 0 ) {
        printf("○");
      } else {
        printf("●");
      }
    }
    printf("\n");
  }
  return 0;
}
