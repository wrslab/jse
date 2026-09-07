/*
 *積立貯金を 複利計算 １０年後の預金額を計算
 */
#include <stdio.h>

int main(void)
{
    int i,yokin, risoku,tsumitate;
    double riritsu;
    
    printf("毎年の積み立て金額を入力して下さい\n");
    scanf("%d",&tsumitate);
    printf("利率(%%)を入力して下さい\n");
    scanf("%lf",&riritsu);
    
    riritsu /= 100;            /* %から割合へ変換*/
    yokin=0;
    for(i=1;i<=10;i++){
        yokin+=tsumitate;
        risoku=riritsu*yokin;
        yokin+=risoku;
        printf("%2d後の，１年間の利息は%d円，全預金額は%d円です．\n",i, risoku, yokin);
    }
    return 0;
}

