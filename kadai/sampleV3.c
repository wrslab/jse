/*
 * 学籍番号:    09C99000
 * 氏名:        木曾 浩太郎
 * 担当TA:      町金 山男 
 */

/* 実行結果：
 * ※プログラムが正しく動作していることが確認できるよう，
 * 　主要なパターンを複数示せ．
＜パターン1＞
$ ./test
Input the month of year 2006.
3
Input the date of year 2006.
14
day is 2. (Sun = 0, Mon = 1, ..)

＜パターン2＞
$ ./test
Input the month of year 2006.
12
Input the date of year 2006.
31
day is 0. (Sun = 0, Mon = 1, ..)

＜パターン3＞
$ ./test
Input the month of year 2006.
6
Input the date of year 2006.
31
day is -1. (Sun = 0, Mon = 1, ..)
*/

/* プログラム：
 * 重要な箇所には必ずコメントを入れること
*/
#include <stdio.h>

int main(void) {
  int month, date, day;

  /* 2006年の月と日を入力させる */
  printf("Input the month of year 2006.\n");
  scanf("%d", &month);
  printf("Input the date of year 2006.\n");
  scanf("%d", &date);

  /* 月と日から曜日を求める関数を呼び出す */
  day = day2006(month, date);
  /* 曜日を出力する */
  printf("day is %d. (Sun = 0, Mon = 1, ..)\n", day);

  return 0;
}

/* それぞれの月の日数を記録した配列 */
int dayofmonth[12] = 
{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* 2006年の月と日から曜日を求める関数 */
/* 日曜日を 0, 月曜日を 1, ．．とする */
int day2006(int m, int d) {
  int i, date;

  date = 0; /* 2006年1月1日は日曜日 */
  
  /* 月の数値がおかしい場合は -1 を返す */
  if(m <= 0 || m > 12) {
    return -1;
  }
  /* 日の数値がおかしい場合は -1 を返す */
  if(d <= 0 || d > dayofmonth[m-1]) {
    return -1;
  }

  /* 前月までの日数を加算する */
  for(i = 0; i < m - 1; i++) {
    date += dayofmonth[i];
  }
  /* その月の全日までの日数を加算する */
  date += d - 1;
  /* これにより，元旦からその日までの日数が */
  /* date に求められた */
  
  /* 7 で割った余りにより曜日の数値に変換 */
  return date % 7;
}