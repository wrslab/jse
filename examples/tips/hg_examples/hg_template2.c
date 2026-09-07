/*
 *   Handy Graphics を用いた描かれた絵をファイルに保存するためのプログラムのテンプレート。
 *   HgWInitEPS 関数は、ファイルを保存するために使われています。WgWOpenの後に続けて呼び
 *   出してください。なお、ファイル名は必ず「"」で囲んで、拡張子を「.eps」としてください。
 *   なお、「"」は日本語で入力せず、必ず「英語」モードで入力すること。

 *   getchar()は、何かキーボード入力が行われるのを待つために使われている。
 *   getchar()がなければ、ウインドウが閉じられてしまうため、何が描かれたか画面上で確認で
 *   きない。
*/

#include <stdio.h>
#include <handy.h>                          /* Handy Graphics を使用する時には必ず必要 */
 
int main(void)
{
  int w;
  w=HgWOpen(100.0, 100.0, 500.0, 500.0);    /* window  を開きます */
  HgWInitEPS(w, "filename.eps");            /* EPS ファイルで保存する設定 */
                                            /* .eps を付けてください */

  /*この部分に絵を描くプログラムを書く*/


  getchar();                                /* 何かキーボード入力されるのを待つ */

  HgWClose(w);                              /* window を閉じる */
  return 0;
}

