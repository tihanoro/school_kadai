//sin(x),cos(x)を0から90まで30刻みで表示するプログラム
#include<stdio.h>
#include<math.h>

int main(void){
  int i,deg;
  double rad,a,b;

  deg = 0;

  printf("while文\n");
  while(deg<=90){
    rad = deg*M_PI/180;
    a = sin(rad);
    b = cos(rad);
    printf("sin(%d)=%f,cos(%d)=%f\n",deg,a,deg,b);
    deg += 30;
  }

  printf("for文\n");
  for(deg=0;deg<=90;deg+=30){
    rad = deg*M_PI/180;
    printf("sin(%d)=%f,cos(%d)=%f\n",deg,sin(rad),deg,cos(rad));
  }

  deg = 0;
  printf("do-while文\n");
  do{
    rad = deg*M_PI/180;
    printf("sin(%d)=%f,cos(%d)=%f\n",deg,sin(rad),deg,cos(rad));
    deg += 30;
  }while(deg<=90);

  return 0;
}
