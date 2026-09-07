/*
 * 読み込んだ内容を文字ごとに表示
 */
#include <stdio.h>

int main(void)
{
    int c;                       /* charではいけない! */
    
    printf("文字列を入力して最後にReturnキーを押して下さい．\n");
    printf("(終了はControl-d)\n");

    /* キーボード入力はReturnを押した時に1度にまとめて渡される */
    while ( (c = getchar()) != EOF ) {
        printf("'%c' -> %3d (%xh)\n", c, (int)c, (int)c);
    }
    return 0;
}
