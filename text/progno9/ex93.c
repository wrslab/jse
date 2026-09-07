/* 
 * sprintf() を用いたプログラム例
 */ 
#include <stdio.h>
#include <handy.h>
#include <stdlib.h>     /* rand(), srand(), RAND_MAX のために必要 */
#include <time.h>       /* time(), のために必要 */
#define MAXTIME 10      /* カウントする秒数 */
#define MINTIME 5

int main( void )
{
    int w, color;
    int i, mtime, ctime, ttime, stime;
    char buf[50];                                    /* 適当な大きさ(49文字以上はつかわんやろ) */

    w = HgWOpen(100.0, 100.0, 300.0, 100.0 );        /* ウィンドウの作成 */
    ctime = 0;
    mtime = MAXTIME;
    stime = time( NULL );                            /* 開始時刻を記録する */

    while( 1 ){
        if( ctime >= mtime ){                        /* mtime 以上経過したら終了 */
            break;
        }
        ttime = time( NULL ) - stime;                /* 開始からの経過時間 */
        if( ttime > ctime ){                         /* 1秒以上経過したら */
            ctime = ttime;
            HgWClear( w );
            sprintf( buf, "Last %02d second to vanish!!", mtime - ctime );

            /* 残り時間が MINTIME を切ったら色を変えてみる */
            if( mtime - ctime <= MINTIME ){
                color = HgRGB( 1.0, 0.0, 0.0 );      /* 赤色 */
                HgColor( color );
            }
            HgWText( w, 25.0, 40.0, buf );           /* sprintf() で指定した buf */
        }
    }
    HgWClose(w);                                     /* ウィンドウを閉じる */
    return 0;
}
