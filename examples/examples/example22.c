/* 
 * 読み込んだ整数値が奇数であるか，偶数であるか判断して表示
 * if ~ else の例題
 */
# include <stdio.h>

int main(void)
{
    int  n;

    printf("整数を入力してください:");
    scanf("%d", &n);

    if ( (n % 2)!=0 ){  
        printf("奇数です．\n");
    }else{
        printf("偶数です．\n");
    }

    return 0;
}

