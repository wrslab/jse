/*
 * 英数文字とアスキーコード
 *
 * アスキーコード -> 英数文字
 */

#include<stdio.h>

int main (void){

    char moji = 0x57;
    
    printf("アスキーコードで、16進数の%xが割り当てられている文字は%cです。\n",moji,moji);

    return 0;
}
