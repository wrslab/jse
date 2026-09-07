/* 
 *whileループの例
*/

#include <stdio.h>

int main(void)
{
    int i;

    i=0;
    while(i<5){
        printf("iの値は%dです\n",i);
        i++;
    }
    printf("iの値は%dなので、whileループを抜けました\n",i);
    return 0;
}