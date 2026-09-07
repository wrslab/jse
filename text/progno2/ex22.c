/* 
 * 100点満点のテストの点数を整数値として読み込んで，優，良，可，不可を表示
 */
# include <stdio.h>

int main(void)
{
    int  n;

    printf("点数を入力してください：");
    scanf("%d", &n);
   
    if (n >= 0 && n <60){
      printf("不可\n");
    }else if (n >= 60 && n <70){
      printf("可\n");
    }else if (n >= 70 && n <80){
      printf("良\n");
    }else if (n >= 80 && n <=100){
      printf("優\n");
    }else{
      printf("評価無し\n");
    }

   return 0;
}
