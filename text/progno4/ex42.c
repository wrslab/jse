/* 
 * 無限ループと，break，関係演算子
 */
# include <stdio.h>

int main(void)
{
  int  n;
  while(1){                /* 偽は0 ，真は0以外として制御されるため，無限ループとなる*/
    printf("何か数値を入力して下さい（0以外を入力すると，終了します)：");
    scanf("%d",&n);
    if(n){                 /* 偽は0 ，真は0以外*/
      printf("nの値が%dでしたので終了します\n",n);
      break;               /* break は，ループを一つ抜ける*/
    }else{
      printf("nの値が0なので，繰り返し処理を実行し続けます\n");
    }
  }
  return 0;
}

