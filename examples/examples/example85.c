/*
 * 文字列を扱う関数の例
 *
 * monkeyの文字数を数える strlen
 */

#include<stdio.h>
#include<string.h>         /* strlen を使うために必要 */

int main(void){

    int length;
    char moji[10] = "monkey";
      
    length = strlen(moji);   /* 文字列の長さを数える */
    printf("%sは%d文字です。\n",moji,length);
    return 0;

}

