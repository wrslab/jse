/* 
 * 要素数がNであるint型の配列の要素の最小値を返す関数を用いて，
 * 10人の英語と数学の成績を入力して，それぞれの最低点を求めるプログラム．（配列の受け渡しについて）
 */
# include <stdio.h>
# define  NUM  10

int minimum( int x[], int n);

int main(void)
{
    int  i, engmin, mathmin;
    int eng [NUM] = { 80, 78, 93, 62, 55, 93, 72, 68, 74, 82};
    int math[NUM] = { 88, 92, 48, 62, 88, 93, 95, 68, 83, 75};
 
    engmin = minimum(eng, NUM);
    mathmin = minimum(math, NUM);
    printf("英語の最低点は%dです．\n", engmin);
    printf("数学の最低点は%dです．\n", mathmin);

    return 0;
}
int minimum(int x[], int n)        /* 要素数を引数とすることで，プログラムを一般化 */
{
    int i;
    int min;

    min = x[0];                    /* min を x[0] で初期化 しているため */
    for (i = 1; i < n; i++){       /* ループは，1 からでよい */
        if (x[i] < min)
            min = x[i];
    }
    return min;
}
