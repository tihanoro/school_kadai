//ハノイの塔のプログラム
#include<stdio.h>
#define N 5
#define PRINT printf("mvdisk(%d,%d)\n",i,j)

//hanoi関数のプロトタイプ宣言
int hanoi(int n,int i,int j,int peg[]);

int main(void){
  //変数の宣言
  int peg[3];
  
  //peg[0],peg[1],peg[2]の中身はDISKの枚数
  peg[0] = N;
  peg[1] = 0;
  peg[2] = 0;

  printf("DISKの枚数：%d\n",N);

  //hanoi関数の呼び出し
  hanoi(N,0,2,peg);

  return 0;
}

//hanoi関数の記述
//nはdiskの枚数、iは移動元、jは移動先
int hanoi(int n,int i,int j,int peg[]){
  //再帰の出口
  if(n==1){
    PRINT;
    return 0;
  }

  //kの宣言
  int k = 3-(i+j);

  //hanoi関数の中身
  hanoi(n-1,i,k,peg);

  peg[i] = peg[i] - 1;
  peg[j] = peg[j] + 1;

  PRINT;

  hanoi(n-1,k,j,peg);

  return 0;
}
