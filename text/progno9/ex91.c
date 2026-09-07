/* 実行したらリターンキーを何回か入力してみよ */
#include <stdio.h>
#include <handy.h>

int main( void )
{
    int w;

    w = HgWOpen( 200.0, 150.0, 500.0, 400.0 );    /* Windowを開きます*/

    HgWInitEPS(w, "example91.eps");               /* eps ファイルに保存します*/

                                                  /* 何の絵かわかる人います ? */
    HgWWidth(w, 2.0);    
    HgWLine( w, 250.0, 200.0, 200.0, 150.0);
    getchar();
    HgWCircle( w, 250.0, 200.0, 100.0);
    getchar();
    HgWCircleFill( w, 250.0, 200.0, 50.0);
    getchar();
    HgWBox( w, 200.0, 20.0, 50.0, 80.0);
    getchar();
    HgWBoxFill( w, 250.0, 20.0, 50.0, 80.0);
    getchar();
    HgWText( w, 350.0, 50.0, "Kitaro !!");    
    getchar();
   
    HgWClose( w );                                 /* Window を閉じる */

    return  0;
}

