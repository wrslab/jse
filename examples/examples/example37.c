/* 
 *whileループをforで置き換えた例
*/

#include <stdio.h>

int main(void)
{
    int i;

    for( i=0; i<5 ; i++){
        printf("iの値は%dです\n",i);
    }
    printf("iの値は%dなので、whileループを抜けました\n",i);
    return 0;
}