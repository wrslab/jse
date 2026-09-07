/*
 * 配列を引数として渡される関数の例．
 * GrPolygonを活用して一筆描き星形をたくさん描く
 * 配列を関数に渡して，GrPolygonによって描く図形を作成．
 */
#include <stdio.h>
#include <math.h>
#include <handy.h>

#define PI      3.14159265358979323846  /* 円周率 */
#define PMAX    1000
#define RADIUS  50.0
#define NSTAR   10

/* 関数のプロトタイプ宣言 */
void star(int n, int m, double x0, double y0, double r, double ax[], double ay[]);
void translate(double x, double y, int n, double ax[], double ay[]);

int main(void)
{
    int           w;
    int           i, n, m;
    static double x[PMAX], y[PMAX];

    w = HgWOpen(100.0, 100.0, 2*RADIUS*NSTAR, 2*RADIUS);     /* ウィンドウの作成 */
    HgWInitEPS(w, "example76.eps");                          /* eps ファイルに保存 */
    HgWWidth(w, 3.0);                                        /* 線幅の指定*/

    for (;;) {
        /* パラメータの入力 */
        printf("円周上のn個の点をm個間隔で結びます(不適切な値を入力すると，終了します）．\n");
        printf("n → "); scanf("%d", &n);
        printf("m → "); scanf("%d", &m);
        if ( n < 5 || m < 2 || m >= n || n%m == 0 ) {
            printf("パラメータが不適です．\n");
            break;
        }
        HgWClear(w);                                         /* ウィンドウの消去 */
        star(n, m, RADIUS, RADIUS, RADIUS, x, y);            /* 最初の星形の座標を計算 */
        for ( i = 0; i < NSTAR; i++ ) {                      /* x座標を変化させながら描く */
            HgWPolygon(w, n, x, y);
            translate(2*RADIUS, 0.0, n, x, y);
        }
    }
    HgWClose(w);
    printf("プログラムを終了します．\n");
    return 0;
}

/*
 * 一筆描きの星形のx,y座標を計算する
 * n:      円周上に取る点数                    m:      点を取る間隔
 * x0, y0: 中心座標                            r:      半径
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

/*
 * x, y座標の入った配列の並進変換
 * x, y:    x, yの並進量                       n:       データ数
 * ax, ay: x座標とy座標を格納する配列 (入力/出力)
 */
void translate(double x, double y, int n, double ax[], double ay[])
{
    int         i;

    for ( i = 0; i < n; i++ ) {
        ax[i] += x;
        ay[i] += y;
    }
}
