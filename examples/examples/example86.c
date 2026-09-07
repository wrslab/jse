/*
 * 文字列を扱う関数の例
 *
 * 文字列をコピーする strcpy
 */

#include<stdio.h>
#include<string.h>               /* strcpy を使うために必要 */

int main(void){

    char moji1[10];
    char moji2[10]= "cat";
    strcpy(moji1, moji2);      /* strcpy は文字列を文字列にコピーします */
    printf("英語でネコは%sです。\n",moji1);
    return 0; 

}
