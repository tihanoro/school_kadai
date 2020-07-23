// 行列の積を求めるプログラムを関数化
#include <stdio.h>
#include <stdlib.h>
#include "func_matrix.h"

int main (void) {
  int L, M, N;  // A(L*M),B(M*N),Z(L*N)
  double **a, **b, **z;  // 行列A, B, Z
  int i, j, k, temp;
  temp = 0;
  
  printf("L行M列の行列AとM行N列の行列Bの積の計算\n");
  
  //L,M,Nの入力
  printf("Lを入力してください: ");
  scanf("%d", &L);
  printf("Mを入力してください: ");
  scanf("%d", &M);
  printf("Nを入力してください: ");
  scanf("%d", &N);

  //行列の動的メモリ確保
  // 行列A
  a = arrayget(L,M);
  if(a==NULL){
    printf("error\n");
    return 1;
  }

  // 行列B
  b = arrayget(M,N);
  if(b==NULL){
    printf("error\n");
    return 1;
  }

  // 行列Z
  z = arrayget(L,N);
  if(z==NULL){
    printf("error\n");
    return 1;
  }
  
  // 入力
  printf("行列Aを入力してください\n");
  scan_matrix(a,L,M);

  printf("行列Bを入力してください\n");
  scan_matrix(b,M,N);
  
  // 行列の積：Z = A × B
  multi_matrix(a,b,z,L,M,N);

  // 出力
  printf("A * B = \n");
  print_matrix(z,L,N);

  // 領域の解放
  arrayfree(a,M);
  arrayfree(b,N);
  arrayfree(z,N);
  
  return 0;
}


