#include<stdio.h>
#include<math.h>

//構造体の宣言
typedef struct {
  double x;
  double y;
} POINT;

double distance(POINT p,POINT q);
POINT scanP();

int main(void){

  //変数の宣言
  POINT p,q;
  double ans;

  //入力
  printf("P(x,y)の入力\n");
  p = scanP();
  printf("Q(x,y)の入力\n");
  q = scanP();

  //2点間の距離を求める
  ans = distance(p,q);

  //出力
  printf("PとQの距離:%f\n",ans);

  return 0;

}

double distance(POINT p,POINT q){
  POINT dis;
  double ans;
  dis.x = p.x - q.x;
  dis.y = p.y - q.y;

  ans = sqrt(pow(dis.x,2)+pow(dis.y,2));

  return ans;
}

POINT scanP(){
  POINT data;
  printf("X座標 :");
  scanf("%lf",&data.x);
  printf("Y座標 :");
  scanf("%lf",&data.y);

  return data;
}