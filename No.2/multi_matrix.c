// 行列の積を求めるプログラム
#include <stdio.h>
#include <stdlib.h>

int main (void) {
  int N, M, L;  // A(L*M),B(M*N),Z(L*N)
  double **a, **b, **z;  // 行列A, B, Z
  int i, j ,k ,temp;
  
  printf("L行M列の行列AとM行N列の行列Bの積の計算\n");
  printf("Lを入力してください: ");
  scanf("%d", &L);
  printf("Mを入力してください: ");
  scanf("%d", &M);
  printf("Nを入力してください: ");
  scanf("%d", &N);

  // 行列A
  // 行の確保：ポインタ配列
  a = (double **)malloc(L * sizeof(double *)); 
  // 列の確保
  for(j = 0; j < L; j++){
    a[j] = (double *)malloc(M * sizeof(double));
  }

  // 行列B
  // 行の確保：ポインタ配列
  b = (double **)malloc(M * sizeof(double *));
  // 列の確保
  for (j = 0; j < M; j++) {
    b[j] = (double *)malloc(N * sizeof(double));
  }

  // 行列Z
  // 行の確保：ポインタ配列
  z = (double **)malloc(L * sizeof(double *));
  // 列の確保
  for (j = 0; j < L; j++) {
    z[j] = (double *)malloc(N * sizeof(double));
  }

  // 入力
  printf("行列Aを入力してください\n");
  for (j = 0; j < L; j++) {
    for (i = 0; i < M; i++) {
      printf("a[%d][%d] = ", j, i);
      scanf("%lf", &a[j][i]);
    }
  }
  printf("行列Bを入力してください\n");
  for (j = 0; j < M; j++) {
    for (i = 0; i < N; i++) {
      printf("b[%d][%d] = ", j, i);
      scanf("%lf", &b[j][i]);
    }
  }
  
  // 行列の積：Z = A × B
  for(i=0;i<L;i++){
    for(j=0;j<N;j++){
      for(k=0;k<M;k++){
        temp += a[i][k]*b[k][j];
      }
      z[i][j] = temp; //Zは初期化してないので素直に足せなかった
    }
  }

  // 出力
  printf("A + B = \n"); 
  for (j = 0; j < L; j++) {
    for (i = 0; i < N; i++) {
      printf("%5.2f ", z[j][i]);
    }
    printf("\n");
  }

  // 領域の解放
  for (j = 0; j < M; j++) {
    free(a[j]);
  }
  free(a);
  for (j = 0; j < N; j++) {
    free(b[j]);
  }
  free(b);
  for (j = 0; j < N; j++) {
    free(z[j]);
  }
  free(z);
  
  return 0;
}
