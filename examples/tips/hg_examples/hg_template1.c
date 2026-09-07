/*
 * 　Handy Graphics を用いた絵を描くプログラムのテンプレート。
 *   getchar()は、何かキーボード入力が行われるのを待つために使われている。
 *   getchar()がなければ、ウインドウが閉じられてしまうため、何が描かれたか画面上で確認
 *   できない
*/
#include <stdio.h>
#include <handy.h>                          /* Handy Graphics を使用する時には必ず必要 */
 
int main(void)
{
  int w;
  w=HgWOpen(100.0, 100.0, 500.0, 500.0);    /* window  を開きます */
  

  /*この部分に絵を描くプログラムを書く*/


  getchar();                                /* 何かキーボード入力されるのを待つ */

  HgWClose(w);                              /* window を閉じる */
  return 0;
}

