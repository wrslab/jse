/*
 * HgWPolygonを活用して図形を描く．
 * HgWPolygon は  配列を引数として渡される．
 */
#include <stdio.h>
#include <math.h>                          /* 数学関数 cos等を使用する時には必要 */
#include <handy.h>                         /* Handy Graphics を使用する時には必要 */
#define PI     3.14159265358979323846      /* macro定義を使って円周率を定義 */
#define NUM 5
/* 関数のプロトタイプ宣言 */
void star(int n, int m, double x0, double y0, double r, double ax[], double ay[]);

int main(void)
{
    int w;
    double x[NUM];
    double y[NUM];

    w=HgWOpen(100.0, 100.0, 500.0, 500.0);    /* window  を開きます */
    HgWInitEPS(w,"example95.eps");            /* eps ファイルで保存 */

    star(NUM, 2, 250.0, 250.0, 150.0, x, y);
    HgWPolygon(w, NUM, x, y);

    getchar();                                /* 何かキーボード入力されるのを待つ */
    HgWClose(w);                              /* window を閉じる */
    return 0;
}

/*
 * 一筆描きの星形のx,y座標を計算する
 * n:      円周上に取る点数                   m:      点を取る間隔
 * x0, y0: 中心座標                           r:      半径
 * ax, ay: x座標とy座標を格納する配列 (出力)
 */
void star(int n, int m, double x0, double y0, double r, double ax[], double ay[])
{
    int         i;
    double      dt;

    dt = (2*PI/n)*m;
    for ( i = 0; i < n; i++ ) {
        ax[i] = x0 + r*cos(dt*i);
        ay[i] = y0 + r*sin(dt*i);
    }
}
