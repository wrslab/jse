/*
 * 文字列を読みとる gets
 */

#include<stdio.h>

int main(void){

    char moji[100];
    printf("100文字以内で文字列を入力してください。\n");
    gets(moji);
    printf("入力された文字配列は、%sです。\n", moji);
    return 0;
}

