#include <stdio.h>
#include <handy.h>                          /* Handy Graphics を使用する時には必ず必要 */
 
int main(void)
{
  int w;
  w=HgWOpen(100.0, 100.0, 500.0, 500.0);    /* window を開きます */
  HgWInitEPS(w,"hg_text.eps");              /* eps ファイルで保存 */

  HgWText(w, 100.0, 100.0, "Dep. of System Science 0001 Kiso Kotaro");
  HgWText(w, 100.0, 200.0, "Information and Computer Science");

  getchar();                                /* 何かキーボード入力されるのを待つ */

  HgWClose(w);                              /* window を閉じる */
  return 0;
}

