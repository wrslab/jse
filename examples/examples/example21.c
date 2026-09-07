/* 
 * 読み込んだ整数値が奇数であれば，その旨を表示
 * if 文の例題
 */
# include <stdio.h>

int main(void)
{
    int  n;

    printf("整数を入力してください:");
    scanf("%d", &n);

    if ( (n % 2)!=0 ){
        printf("奇数です．\n");
    }

    return 0;
}

