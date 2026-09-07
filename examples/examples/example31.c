/* 
 *for ループを用いたプログラム例
 *s = 1+2+.....10 の計算
 */
#include <stdio.h>

int main(void)
{
    int i, s;
    s=0;            /*s を初期化．変数は初期化するまでその内容は不定*/
    for(i=1; i<=10; i++){
        s+=i;       /* s+=i はs=s+i と等しい*/
    }
    printf("s = 1+2+...+10 = %d\n",s);
    
    return 0;
}

