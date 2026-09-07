/*
 * 配列の全要素を０にする関数．
 *（呼び出された関数側で受け取った配列を変更すると，元の配列にも影響が及ぶことを学ぶ．
 * 普通の引数の値渡しとの 違いを理解する．これを防止するためには，
 * void zeroset(int x[], int n)をvoid zeroset(const int x[], int n)とすれば良い．
 * こうすると代入する式x[i] = 0　が翻訳時にエラーとなる．）
 */
# include <stdio.h>

void zeroset(int x[], int n);

int main(void)
{
    int  i;
    int ary1[] = {1, 2, 3, 4, 5};
    int ary2[] = {4, 3, 2, 1};

    for (i = 0; i < 5; i++)
        printf("ary1[%d] = %d \n", i, ary1[i]);
    for (i = 0; i < 4; i++)
        printf("ary2[%d] = %d \n", i, ary2[i]);
   
    zeroset(ary1, 5);
    zeroset(ary2, 4);

    for (i = 0; i < 5; i++)
        printf("ary1[%d] = %d \n", i, ary1[i]);
    for (i = 0; i < 4; i++)
        printf("ary2[%d] = %d \n", i, ary2[i]);

    return 0;
}
void zeroset(int x[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        x[i] = 0;
}
