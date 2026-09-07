/* 乱数を発生する関数 rand()を用いて、0から99までの乱数を
 *  100個発生させ、平均値と、最大値を計算するプログラム
 * 
 */
#include<stdio.h>
#include<stdlib.h> /* rand, srandのプロトタイプ宣言が書かれている*/
#include <time.h>  /*time のために必要*/

int main (void)
{

    int ransuu[100];
    int i;
    double heikin;
    int max;

    srand(time(NULL));
                              /* srandは，疑似乱数列の初期値を与えるライブラリ関数
                               * timeは現在の暦時間を返すライブラリ関数
                               * NULLはおまじない
                               */

    for (i = 0; i<100; i++) {
       ransuu[i] = rand() % 100; 
                              /* 0から99までの乱数を100個発生 
                               * rand は，0からRAND_MAXまでの疑似乱数列を発生する標準ライブラリ関数
                               * RAND_MAXの値が大きいので，100で割った余りも乱数となる
                               */
    }

    heikin = 0;

    for (i = 0; i<100; i++){
        heikin += ransuu[i];
    }
   
    printf("平均値は%fです。\n", heikin / 100);

    max = ransuu[0];
    for (i = 1; i<100; i++){    /* maxの初期値が ransuu[0]なので，1からループを回す*/
        if (ransuu[i] > max){
            max = ransuu[i];
        }
    }

    printf("最大値は%dです。\n", max);

    return 0;
}

