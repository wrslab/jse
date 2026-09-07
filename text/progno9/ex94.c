/* 
 * 細かな直線をつなげて描くことで，曲線を描く例
 */

#include <stdio.h>
#include <math.h>
#include <handy.h>
#define PI      3.141592653589793
#define WIDTH   500.0                   /* Windowの幅*/
#define HEIGHT  500.0                   /* Windowの高さ*/

int main(void)
{
  int    w, i, imax;
  double x0, y0, r, x, y, t, xPrev, yPrev;

  w = HgWOpen( 100.0, 100.0, WIDTH, HEIGHT );
  HgWInitEPS(w,"example93.eps");        /* eps ファイルで保存 */

  x0=WIDTH/2.0;                         /* Windowの中央を円の中心とする*/
  y0=HEIGHT/2.0;
  r=100.0;                              /* 円の半径を100とする */  
  imax=32;                              /* 円を３２分割する */  
  xPrev = x0 + r*cos(0.0);
  yPrev = y0 + r*sin(0.0);
  
  for ( i = 1; i <= imax; i++ ) {
    t = 2.0*PI/imax*i;
    x = x0 + r*cos(t);
    y = y0 + r*sin(t);
    HgWLine(w, x, y, xPrev, yPrev);
    xPrev = x;
    yPrev = y;
  }
  getchar();
  HgWClose(w);
  return 0;
}
