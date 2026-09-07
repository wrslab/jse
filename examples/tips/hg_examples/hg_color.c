#include <stdio.h>
#include <handy.h>                          /* Handy Graphics を使用する時には必要 */
#define PI 3.1415                           /* macro定義を使って円周率を定義 */

int main(void)
{
  int w,i;
  int clr;
  hgimage *image;
  w=HgWOpen(100.0, 100.0, 500.0, 500.0);    /* window  を開きます */
  HgWInitEPS(w,"hg_color.eps");             /* eps ファイルで保存 */

  HgWBox(w, 50.0, 50.0, 300.0, 300.0);      /* 黒色で長方形を描画 */

  clr=HgGray(0.5);                          /* gray 表示の色指定 0.0白、1.0黒 */
  HgColor(clr);
  HgWBox(w, 75.0, 75.0, 250.0, 250.0);      /* gray で長方形を描画 */

  clr=HgRGB(1.0, 0.0, 0.0);                 /* RGB 表示で赤色を指定 */
  HgColor(clr);
  HgWBoxFill(w,100.0, 100.0, 200.0, 200.0); /* 赤色で塗りつぶされた長方形を描画 */

  clr=HgRGB(0.0, 1.0, 0.0);                 /* RGB 表示で緑色を指定 */
  HgColor(clr);
  HgWBoxFill(w,125.0, 125.0, 150.0, 150.0); /* 緑色で塗りつぶされた長方形を描画 */

  clr=HgRGB(0.0, 0.0, 1.0);                 /* RGB 表示で青色を指定 */
  HgColor(clr);
  HgWBoxFill(w,150.0, 150.0, 100.0, 100.0); /* 青色で塗りつぶされた長方形を描画 */

  clr=HgRGB(1.0, 1.0, 0.0);                 /* RGB 表示で黄色を指定 */
  HgColor(clr);
  HgWCircleFill(w,200.0, 200.0, 50.0);      /* 黄色で塗りつぶされた円を描画 */
 
  getchar();                                /*何かキーボード入力されるのを待つ */

  HgWClose(w);                              /*window を閉じる */
  return 0;
}

