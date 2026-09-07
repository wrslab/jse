/* 
 * 配列に入力した要素から，目的の値をもつ要素を探索するプログラム．
 * （逐次探索の実験．）
 */
# include <stdio.h>
#define NUM 5
#define FAIL -1

int search(const int x[], int ky,  int n);

int main(void)
{
    int  i, key, index;
    int  data[NUM];

    for(i = 0; i < NUM; i++){
        printf("data[%d] : ", i);
        scanf("%d", &data[i]);
    }
    printf("探索したい値 : ");
    scanf("%d", &key);

    index = search( data, key, NUM);

    if( index == FAIL)
         printf("探索失敗！");
    else
         printf("%dは%d番目のデータです．\n", key,  index+1);

    return 0;
}
int search(const int x[], int ky,  int n)
/* 配列xをconst宣言しているために，この関数内で配列 x[] に値を代入することはできない*/
{
    int i =0;
    while(1) {
        if (i == n)
            return FAIL;
        if (x[i] == ky)
            return i;
        i++;
    }
}
