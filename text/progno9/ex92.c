/*
 * For ループを使って，白黒円の市松模様を描く
 */
#include <stdio.h>
#include <handy.h>
#define IXMAX   10
#define IYMAX    7
#define RADIUS  25.0

int main(void)
{
  int     w;
  int     ix, iy;
  double  xc, yc; 
  
  w = HgWOpen(100.0, 100.0, 2*RADIUS*IXMAX, 2*RADIUS*IYMAX); /* ウィンドウの作成 */
  HgWInitEPS(w, "example92.eps");                            /* eps ファイルに保存 */  
  HgWWidth(w, 2.0);                                          /* 線幅を2.0に設定*/
  
  for ( ix = 0; ix < IXMAX; ix++ ) {                         /* 格子状に○と●を並べる */
    xc = RADIUS + 2*RADIUS*ix;
    for ( iy = 0; iy < IYMAX; iy++ ) {
      yc = RADIUS + 2*RADIUS*iy;
      if ( (ix+iy)%2 == 0 ) {                                /* 市松模様になるように○と●を切替え */
        HgWCircle(w, xc, yc, RADIUS);
      } else {
        HgWCircleFill(w, xc, yc, RADIUS);
      }
    }
  }
  getchar();
  HgWClose(w);                                               /* ウィンドウを閉じる */
  return 0;
}
