/*
 * 文字列の中の小文字を大文字に変換する関数の実験
 */
#include <stdio.h>

int mygetline(char s[], int size);
int oomoji(char s[]);

int main(void)
{
    char        str[100];
    int         ret;

    while ( 1 ) {
        printf("\n入力   → ");
        if ( mygetline(str, 100) == -1 ) {
            break;
        }
        ret = oomoji(str);
        printf("出力   → %s\n", str);
        printf("戻り値 → %d\n", ret);
    }
    printf("\nお疲れ様でした．\n");

    return 0;
}

/*
 * example82.c などを参照
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

/*
 * 文字列sの中の'a'～'z'の文字を'A'～'Z'に置き換える．
 * 戻り値は置き換えた文字数．
 */
int oomoji(char s[])
{
    int         i, r = 0;

    for ( i = 0; s[i] != '\0'; i++ ) {
        if ( s[i] >= 'a' && s[i] <= 'z' ) {
            s[i] += 'A' - 'a';
            r++;
        }
    }

    return r;
}
