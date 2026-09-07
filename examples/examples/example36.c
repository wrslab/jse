/* 
 *do ~whileループの例
*/

#include <stdio.h>

int main(void)
{
    int i;

    i=10;
    do{
        printf("iの値は%dです\n",i);
        i++;
    }while(i<5);
    printf("iの値は%dなので、do~whileループを抜けました\n",i);
    return 0;
}