#include <stdio.h>
#include <handy.h>                          /* Handy Graphics を使用する時には必ず必要 */
#define PI 3.1415                           /* macro定義を使って円周率を定義 */

int main(void)
{
  int w;
  w=HgWOpen(100.0, 100.0, 500.0, 500.0);    /* window  を開きます */
  HgWInitEPS(w,"hg_fan.eps");               /* eps ファイルで保存 */


  HgWFan(w, 250.0, 250.0, 200.0, 0.0, 0.5*PI);
  HgWFanFill(w, 250.0, 250.0, 100.0, 0.0, 0.5*PI);

  getchar();                                /* 何かキーボード入力されるのを待つ */

  HgWClose(w);                              /* window を閉じる */
  return 0;
}

