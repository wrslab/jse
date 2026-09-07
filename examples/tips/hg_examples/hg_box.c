#include <stdio.h>
#include <handy.h>                          /* Handy Graphics を使用する時には必ず必要 */
 
int main(void)
{
  int w;
  w=HgWOpen(100.0, 100.0, 500.0, 500.0);    /* window を開きます */
  HgWInitEPS(w,"hg_box.eps");               /* eps ファイルで保存 */


  HgWBox(w, 100.0, 100.0, 300.0, 300.0);
  HgWBoxFill(w, 200.0, 200.0, 100.0, 100.0);

  getchar();                                /*何かキーボード入力されるのを待つ*/

  HgWClose(w);                              /*window を閉じる*/
  return 0;
}

