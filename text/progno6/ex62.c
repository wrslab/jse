/*
 * あるクラスの数学の成績を１次元配列を使って表し，その平均値と標準偏差を求めるプログラム
 */

#include<stdio.h>
#include<math.h>

int main (void)
{

    double heikin = 0;
    double sd = 0;
    int i;

    int math[15] = {58, 72, 83, 36, 94, 67, 85, 78, 70, 81, 77, 69, 90, 83, 75};
   
    for (i = 0;i<15;i++){
        heikin += math[i];
    }
    heikin /= 15;
    printf("平均値は%fです\n", heikin);

    for (i = 0;i<15;i++){
        sd += (math[i] - heikin) * (math[i] - heikin);
    }
    sd = sqrt(sd/15);
   
    printf("標準偏差は%fです\n", sd);
    return 0;
}

