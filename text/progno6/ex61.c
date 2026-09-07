/* 
 * 入力された２つの３次元ベクトルの内積を求めるプログラム
 */

#include<stdio.h>
#include<math.h>

int main (void)
{

    int i;
    double vector1[3];  /* 3次元ベクトル1のための配列 */
    double vector2[3];  /* 3次元ベクトル2のための配列 */
    double naiseki = 0;        

    printf("1つめのベクトル成分\n");
    for (i = 0; i<3; i++){
        scanf("%lf", &vector1[i]);  
    }

    printf("２つめのベクトル成分\n");
    for (i = 0; i<3; i++){
        scanf("%lf", &vector2[i]);  
    }
   
    for ( i = 0; i<3; i++){
        naiseki += vector1[i] * vector2[i];  /*内積の計算*/
    }
    printf("%f\n",naiseki);
   
    return 0;
}
