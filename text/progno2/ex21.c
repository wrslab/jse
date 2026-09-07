/* 
 * 二つの整数値を読み込んでそれらの値が等しければ「NとMは等しい．」，
 * あるいはMもしくはNが大きければその旨を示す．
 * else if の例題
 */
# include <stdio.h>

int main(void)
{
   int  n, m;

    printf("整数を二つ入力してください\n");
    printf("整数N："); scanf("%d", &n);
    printf("整数M："); scanf("%d", &m);

    if (n == m){
        printf("NとMは等しい\n");
    }else if (n > m){
        printf("NはMより大きい\n");
    }else{
        printf("MはNより大きい\n");
    }

    return 0;
}

