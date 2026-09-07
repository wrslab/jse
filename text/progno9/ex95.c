/*
 * 細かな直線を連続して描くことで，曲線を描く例．
 * リサージュ曲線を描く．
 *   x(t) = x0 + r*cos(a*t)
 *   y(t) = y0 + r*sin(b*t)
 * 中心(x0, y0)がウィンドウ外ならば描かない．
 */
#include <stdio.h>
#include <math.h>
#include <handy.h>

#define PI      3.14159265358979323846              /* 円周率 */
#define XMIN    0.0                                 /* x座標の最小値 */
#define XMAX    500.0                               /* x座標の最大値 */
#define YMIN    0.0                                 /* y座標の最小値 */
#define YMAX    400.0                               /* y座標の最大値 */
#define GRID    50.0                                /* 格子の幅 */
#define TBEGIN  0.0                                 /* 媒介数変tの開始値(rad) */
#define TEND    (2.0*PI)                            /* 媒介数変tの終了値(rad) */

int main(void)
{
  int     w;
  double  x0, y0, r, a, b, x, y, xPrev, yPrev, dt, t;
  int     i, imax;

  w = HgWOpen(100.0, 100.0, XMAX, YMAX);            /* ウィンドウの作成 */
  HgWInitEPS(w, "example94.eps");                   /* eps ファイルに保存 */
  
  for ( i = 1; i < (YMAX-YMIN)/GRID; i++ ) {        /* x軸に平行な格子線 */
    y = YMIN + GRID*i;
    HgWLine(w, XMIN, y, XMAX, y);
  }
  
  for ( i = 1; i < (XMAX-XMIN)/GRID; i++ ) {        /* y軸に平行な格子線 */
    x = XMIN + GRID*i;
    HgWLine(w, x, YMIN, x, YMAX);
  }        
                                                    /* パラメータの入力 */
  printf("中心のx座標を入力して下さい→ "); scanf("%lf", &x0);
  printf("中心のy座標を入力して下さい→ "); scanf("%lf", &y0);
  printf("大きさを入力して下さい     → "); scanf("%lf", &r);
  printf("aを入力して下さい          → "); scanf("%lf", &a);
  printf("bを入力して下さい          → "); scanf("%lf", &b);
  printf("分割数を入力して下さい     → "); scanf("%d", &imax);
  
                                                    /* 中心座標のチェック */
  if ( x0 > XMAX || x0 < XMIN || y0 > YMAX || y0 < YMIN ) {
    printf("中心座標(%6.1f, %6.1f)はウィンドウの範囲外です．\n", x0, y0);
    printf("プログラムを終了します．\n");
    exit(1);
  }
                                                    /* 細かい直線の連続でリサージュ曲線を描く */
  xPrev = x0 + r*cos(a*TBEGIN);
  yPrev = y0 + r*sin(b*TBEGIN);
  dt = (TEND-TBEGIN)/imax;
  
  HgWWidth(w, 2.0);                                 /* 線幅を2.0に設定*/
  
  for ( i = 1; i <= imax; i++ ) {
    t = TBEGIN + dt*i;
    x = x0 + r*cos(a*t);
    y = y0 + r*sin(b*t);
    HgWLine(w, x, y, xPrev, yPrev);
    xPrev = x;
    yPrev = y;
  }

  HgWText(w, 10.0, 10.0, "ks7999kk Kiso Kotaro");   /* 名前 */
  
  getchar();
  
  HgWClose(w);                                      /* ウィンドウを閉じる */
  return 0;
}
