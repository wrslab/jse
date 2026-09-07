/* 
 * Hello World!」と表示して改行する関数
 * 値を返さない関数（返却値型void）及び仮引数を受け取らない関数（（）内void）
 */

#include <stdio.h>

void hello(void);                    /*関数 hello のプロトタイプ宣言*/

int main(void)
{
   hello();
   return 0;
}

void hello(void)
{
   printf ("Hello Word! \n");
}

