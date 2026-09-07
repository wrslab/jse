#include <stdio.h>
#define PI 3.14159265358979323846

int main(void)
{
    int seisu;
    double jissu;

    printf("何か整数を入力して，enterを押して下さい\n");
    scanf("%d", &seisu);
    printf("あなたの入力した整数は%dです\n", seisu);

    printf("何か実数を入力して，enterを押して下さい\n");
    scanf("%lf", &jissu);
    printf("あなたの入力した実数は%fです\n",jissu);

    printf("PIでマクロ定義されている値は%fです\n",PI);
    return 0;
}
