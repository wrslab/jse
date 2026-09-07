/*
 * 元金と年利と目標を与えると達成年を計算．(for)
 */
#include <stdio.h>

int
main(void)
{
    int         i;
    double      money, goal, rate;

    printf("元金の額(円) → "); scanf("%lf", &money);
    printf("目標の額(円) → "); scanf("%lf", &goal);
    printf("年利(%%)     → "); scanf("%lf", &rate);          /*printf中で%を表示させるためには%%*/

    for ( i = 0;  money < goal;  i++ ){
        money *= 1.0 + rate/100.0;
    }
    printf("%d年後の元利合計%f円\n", i, money);
    return 0;
}
