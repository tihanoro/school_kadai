// 行列の積を求めるプログラムを関数化
#include <stdio.h>
#include <stdlib.h>

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
  //行の確保
  a = (double **)malloc(L*sizeof(double *));
  //列の確保
  for(i=0;i<L;i++){
    a[i] = (double *)malloc(M*sizeof(double));
  }
  if(a==NULL){
    printf("error\n");
    return 1;
  }

  // 行列B
  //行の確保
  b = (double **)malloc(M*sizeof(double *));
  //列の確保
  for(i=0;i<M;i++){
    b[i] = (double *)malloc(N*sizeof(double));
  }
  if(b==NULL){
    printf("error\n");
    return 1;
  }

  // 行列Z
  //行の確保
  z = (double **)malloc(L*sizeof(double *));
  //列の確保
  for(i=0;i<L;i++){
    z[i] = (double *)malloc(N*sizeof(double));
  }
  if(z==NULL){
    printf("error\n");
    return 1;
  }
  
  // 入力
  printf("行列Aを入力してください\n");
  for(i=0;i<L;i++){
    for(j=0;j<M;j++){
      printf("%d行%d列 :",i+1,j+1);
      scanf("%lf",&a[i][j]);
    }
  }

  printf("行列Bを入力してください\n");
  for(i=0;i<M;i++){
    for(j=0;j<N;j++){
      printf("%d行%d列 :",i+1,j+1);
      scanf("%lf",&b[i][j]);
    }
  }
  
  // 行列の積：Z = A × B
  temp = 0;
  for(i=0;i<L;i++){
    for(j=0;j<N;j++){
      for(k=0;k<M;k++){
        temp += a[i][k]*b[k][j];
      }
      z[i][j] = temp;
      temp = 0;
    }
  }

  // 出力
  printf("A * B = \n");
  for(i=0;i<L;i++){
    printf("| ");
    for(j=0;j<N;j++){
      printf("%5.2f ",z[i][j]);
    }
    printf("|\n");
  }
  printf("\n");

  // 領域の解放
  for(i=0;i<M;i++){
    free(a[i]);
  }
  free(a);
  for(i=0;i<N;i++){
    free(b[i]);
  }
  free(b);
  for(i=0;i<N;i++){
    free(z[i]);
  }
  free(z);
  
  return 0;
}