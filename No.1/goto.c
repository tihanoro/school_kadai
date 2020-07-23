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

  printf("do-while文\n");
  deg = 0;
  do{
    rad = deg*M_PI/180;
    printf("sin(%d)=%f,cos(%d)=%f\n",deg,sin(rad),deg,cos(rad));
    deg += 30;
  }while(deg<=90);

  printf("goto文 前置判定ver\n");
  deg = 0;
  start:
  if(deg>90){
    goto end;
  }
  rad = deg*M_PI/180;
  printf("sin(%d)=%f,cos(%d)=%f\n",deg,sin(rad),deg,cos(rad));
  deg += 30;
  goto start;
  end:

  printf("goto文 後置判定ver\n");
  deg = 0;
  GOTO:
  rad = deg*M_PI/180;
  printf("sin(%d)=%f,cos(%d)=%f\n",deg,sin(rad),deg,cos(rad));
  deg += 30;
  if(deg<=90) goto GOTO;

  return 0;
}
