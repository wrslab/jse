#include <stdio.h> 
void swap(int x, int y); 
/* void swap(int, int); でも構いません*/ 

int main(void) 
{ 
    int x; 
    int y; 

    x=5; 
    y=3; 
    printf("関数を呼び出す x=%d, y=%d\n",x,y); 
    swap(x,y);
    printf("関数の結果 x=%d, y=%d\n",x,y); 
    return 0;
} 

void swap( int x, int y) 
{ 
    int tmp; 

    printf("関数に入ってきたとき x=%d, y=%d\n", x, y); 
    tmp=y; 
    y=x; 
    x=tmp; 
    printf("関数を出るとき x=%d, y=%d\n", x, y); 
                              /* 関数の戻り値がvoidならreturnはいらない*/ 
} 
