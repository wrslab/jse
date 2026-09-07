/* 
 * switch case文
 */
# include <stdio.h>

int main(void)
{
  int  n;
  
  while(1){                /* 偽は0 ，真は0以外で表されるので，無限ループとなる*/
    printf("case 1 から 5 へジャンプします \n");
    printf("1~5の値を入力して下さい(負の数を入力すると終了)\n");
    scanf("%d",&n);
    
    if( n < 0){
      break;
    }
    
    switch( n ){
      case 1:    printf( "->case1\n");
                 break;
      case 2:    printf("-> case2\n");
                 break;
      case 3:    printf("-> case3\n");        /*break がないと，次の文をそのまま実行する*/
      case 4:    printf("-> case4\n");
                 break;
      case 5:    printf("-> case5\n");
                 break;
      default:   printf(" -> default\n");
    }
  }
  return 0;
}
