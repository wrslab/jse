#include <stdio.h>

int mygetline(char s[], int size);

int main(void)
{
    char sei[20], mei[20];

    printf("姓を入力して下さい → "); mygetline(sei, 20);
    printf("名を入力して下さい → "); mygetline(mei, 20);

    printf("あなたは %s %s さんですね．\n", sei, mei);

    return 0;
}

/*
 * 改行までキーボード入力を読み込んで改行直前までを文字列sに格納する．
 * 改行がなくても，size-1文字読み込んだら，そこまでを文字列に格納し，処理を終了する．
 * 戻り値は, 読み込んだ文字数をとする．
 * 入力終了(EOF)を検知して文字を1文字も読み込めなかった場合は，-1を戻り値とする．
 */
int mygetline(char s[], int size)
{
    int         c, i;

    for ( i = 0;  (c = getchar()) != EOF && c != '\n' && i < size - 1; i++ ) {
        s[i] = c;
    }

    s[i] = '\0';

    if ( c == EOF && i == 0 ){
        return -1;
    }

    return i;
}
