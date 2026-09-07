/* 
 * continue文の例
 */
# include <stdio.h>

int main(void)
{
  int  i, n, num;
  printf("10個の整数値を受け取り、正の整数を受け取った回数を示します。\n");

  for(i=0, num=0 ; i<10; i++){
    printf("何か整数値を入力して下さい。\n");
    scanf("%d",&n);
    if( n < 0){
      continue;
    }
    num++;
  }
  printf("正の整数値は%d回入力されました。\n",num);
  return 0;
}
