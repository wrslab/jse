#include <stdio.h>
#include <math.h>                           /* 数学関数 cos等を使用する時には必要 */
#include <handy.h>                          /* Handy Graphics を使用する時には必要 */
#define PI 3.1415                           /* macro定義を使って円周率を定義 */

int main(void)
{
  int w,i;
  double x1[10];
  double y1[10];
  double x2[10];
  double y2[10];

  w=HgWOpen(100.0, 100.0, 500.0, 500.0);    /* window  を開きます */
  HgWInitEPS(w,"hg_polygon.eps");           /* eps ファイルで保存 */


  for(i=0;i<10;i++){
    x1[i]=250.0+150.0*cos(2.0*PI/10.0*i);
    y1[i]=250.0+150.0*sin(2.0*PI/10.0*i);

    x2[i]=250.0+100.0*cos(2.0*PI/10.0*i);
    y2[i]=250.0+100.0*sin(2.0*PI/10.0*i);
  }
    
  HgWPolygon(w, 10, x1, y1);
  HgWPolygonFill(w, 10, x2, y2);

  getchar();                                /* 何かキーボード入力されるのを待つ */

  HgWClose(w);                              /* window を閉じる */
  return 0;
}

