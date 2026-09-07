#include <stdio.h>
#include <handy.h>                          /* Handy Graphics を使用する時には必要 */
#define PI 3.1415                           /* macro定義を使って円周率を定義 */

int main(void)
{
  int w,i;
  int clr;
  w=HgWOpen(100.0, 100.0, 500.0, 500.0);    /* window  を開きます */
  HgWInitEPS(w,"hg_width.eps");             /* eps ファイルで保存 */

  HgWBox(w, 50.0, 50.0, 300.0, 300.0);      /* 黒色で長方形を描画 */

  HgWWidth(w, 2.0);                         /* 線の太さを2.0に指定 */
  HgWBox(w, 75.0, 75.0, 250.0, 250.0);      /* gray で長方形を描画 */

  HgWWidth(w, 5.0);                         /* 線の太さを5.0に指定 */
  HgWBox(w,100.0, 100.0, 200.0, 200.0);     /* 赤色で塗りつぶされた長方形を描画 */
 
  getchar();                                /* 何かキーボード入力されるのを待つ */

  HgWClose(w);                              /* window を閉じる */
  return 0;
}

