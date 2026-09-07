/* 
 * 二つの整数値を読み込んで，前者が後者の約数であれば「NはMの約数です．」と
 * 表示し，そうでなければ「NはMの約数ではありません．」と表示
 */
# include <stdio.h>

int main(void)
{
    int  n, m;

    printf("整数を二つ入力してください\n");
    printf("整数N："); scanf("%d", &n);
    printf("整数Ｍ："); scanf("%d", &m);

    if ( (n % m) != 0){
        printf("ＭはＮの約数ではない．\n");
    }else{
        printf("ＭはＮの約数である．\n");
    }

   return 0;
}

