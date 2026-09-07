/*
 * 元金と年利と目標を与えると達成年を計算．(while)
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

    i = 0;
    while ( money < goal ) {
        money *= 1.0 + rate/100.0;
        i++;
    }
    printf("%d年後の元利合計%f円\n", i, money);
    return 0;
}
