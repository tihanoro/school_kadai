#include<stdio.h>

//構造体の宣言
typedef struct {
  double r;
  double i;
} COMPLEX;

COMPLEX comp_add(COMPLEX data1,COMPLEX data2);
COMPLEX comp_sub(COMPLEX data1,COMPLEX data2);
COMPLEX comp_mul(COMPLEX data1,COMPLEX data2);
COMPLEX comp_div(COMPLEX data1,COMPLEX data2);
COMPLEX comp_scan();

int main(void){

  //変数の宣言
  COMPLEX data1, data2, add, sub, mul, div;


  //データの入力
  printf("一つ目の複素数\n");
  data1 = comp_scan();
  printf("二つ目の複素数\n");
  data2 = comp_scan();

  //四則演算

  add = comp_add(data1,data2);
  sub = comp_sub(data1,data2);
  mul = comp_mul(data1,data2);
  div = comp_div(data1,data2);

  //出力
  printf("%f+%fi + %f+%fi = %f + %fi\n",data1.r,data1.i,data2.r,data2.i,add.r,add.i);
  printf("%f+%fi - %f+%fi = %f + %fi\n",data1.r,data1.i,data2.r,data2.i,sub.r,sub.i);
  printf("%f+%fi * %f+%fi = %f + %fi\n",data1.r,data1.i,data2.r,data2.i,mul.r,mul.i);
  printf("%f+%fi / %f+%fi = %f + %fi\n",data1.r,data1.i,data2.r,data2.i,div.r,div.i);

  return 0;

}

COMPLEX comp_add(COMPLEX data1,COMPLEX data2){
  COMPLEX ans;
  ans.r = data1.r + data2.r;
  ans.i = data1.i + data2.i;

  return ans;
}

COMPLEX comp_sub(COMPLEX data1,COMPLEX data2){
  COMPLEX ans;
  ans.r = data1.r - data2.r;
  ans.i = data1.i - data2.i;

  return ans;
}

COMPLEX comp_mul(COMPLEX data1,COMPLEX data2){
  COMPLEX ans;
  ans.r = data1.r*data2.r - data1.i*data2.i;
  ans.i = data1.r*data2.i + data1.i*data2.r;

  return ans;
}

COMPLEX comp_div(COMPLEX data1,COMPLEX data2){
  COMPLEX ans;
  ans.r = (data1.r*data2.r + data1.i*data2.i)/(data2.r*data2.r + data2.i*data2.i);
  ans.i = (data2.r*data1.i + data1.r+data2.i)/(data2.r*data2.r + data2.i*data2.i);

  return ans;
}

COMPLEX comp_scan(){
  COMPLEX data;
  printf("実部 :");
  scanf("%lf",&data.r);
  printf("虚部 :");
  scanf("%lf",&data.i);

  return data;
}