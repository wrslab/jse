#include <stdio.h>

int main(void)
{
    int a,b,c;
    
    printf( "a+b, a-b, a*b, a/b, a%%bを計算します\n");
    /* printfの" " 内で'%'の文字を出力するためには，'%%'を用いる*/
    printf("整数値 a を入力して下さい\n");
    scanf("%d",&a);
    printf("整数値 b を入力して下さい\n");
    scanf("%d",&b);

    c = a+b;                                                /*和の計算*/
    printf("%d + %d = %d\n",a,b,c);    

    c = a-b;                                                /*差の計算*/
    printf("%d - %d = %d\n",a,b,c); 

    c = a*b;                                                /*積の計算*/
    printf("%d * %d = %d\n",a,b,c);    

    c = a/b;                                                /*商の計算*/
    printf("%d / %d = %d\n",a,b,c);    

    c = a%b;
    printf("%d %% %d = %d\n",a,b,c);                        /*余りの計算*/
    /* printfの" " 内で'%'の文字を出力するためには，'%%'を用いる*/
    
    return 0;
}
