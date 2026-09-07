/*一辺とその両端角の角度から面積を計算する*/
#include <stdio.h>
#include <math.h>			/*sin, cos 等　数学関数を使用するために必要*/
#define PI 3.14159265358979323846	/*πをマクロ定義*/
	
int main(void)
{
    double len, angleDeg1, angleDeg2, area;
    double angle1,angle2;
    
    printf("一辺とその両端角の角度から面積を計算します\n");
    printf("一辺の長さを入力して下さい\n");
    scanf("%lf", &len);
    printf("一方の角の角度（度）を入力して下さい\n");
    scanf("%lf", &angleDeg1);
    printf("他方の角の角度（度）を入力して下さい\n");
    scanf("%lf", &angleDeg2);
    
    angle1=angleDeg1/180.0*PI;		/*angleDeg1をラジアンに変換*/
    angle2=angleDeg2/180.0*PI;		/*angleDeg2をラジアンに変換*/
    
    area=len*len*sin(angle1)*sin(angle2)/2.0/sin(angle1+angle2);
    printf("面積は%fです\n",area);
    
    return 0;
}
