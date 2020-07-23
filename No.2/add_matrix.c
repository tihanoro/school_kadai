// 第11章　練習プログラム　No.07
#include <stdio.h>
#include <stdlib.h>

int main (void) {
  int nrow;  // 行の数
  int ncolm;  // 列の数
  double **a, **b, **z;  // 行列A, B, Z
  int i, j;
  
  printf("行の数を入力してください: ");
  scanf("%d", &nrow);
  printf("列の数を入力してください: ");
  scanf("%d", &ncolm);

  // 行列A
  // 行の確保：ポインタ配列
  a = (double **)malloc(nrow * sizeof(double *)); 
  // 列の確保
  for (j = 0; j < nrow; j++) {
    a[j] = (double *)malloc(ncolm * sizeof(double));
  }

  // 行列B
  // 行の確保：ポインタ配列
  b = (double **)malloc(nrow * sizeof(double *));
  // 列の確保
  for (j = 0; j < nrow; j++) {
    b[j] = (double *)malloc(ncolm * sizeof(double));
  }

  // 行列Z
  // 行の確保：ポインタ配列
  z = (double **)malloc(nrow * sizeof(double *));
  // 列の確保
  for (j = 0; j < nrow; j++) {
    z[j] = (double *)malloc(ncolm * sizeof(double));
  }

  // 入力
  printf("行列Aを入力してください\n");
  for (j = 0; j < nrow; j++) {
    for (i = 0; i < ncolm; i++) {
      printf("a[%d][%d] = ", j, i);
      scanf("%lf", &a[j][i]);
    }
  }
  printf("行列Bを入力してください\n");
  for (j = 0; j < nrow; j++) {
    for (i = 0; i < ncolm; i++) {
      printf("b[%d][%d] = ", j, i);
      scanf("%lf", &b[j][i]);
    }
  }
  
  // 行列の和：Z = A + B
  for (j = 0; j < nrow; j++) {
    for (i = 0; i < ncolm; i++) {
      z[j][i] = a[j][i] + b[j][i];
    }
  }

  // 出力
  printf("A + B = \n"); 
  for (j = 0; j < nrow; j++) {
    for (i = 0; i < ncolm; i++) {
      printf("%5.2f ", z[j][i]);
    }
    printf("\n");
  }

  // 領域の解放
  for (j = 0; j < nrow; j++) {
    free(a[j]);
  }
  free(a);
  for (j = 0; j < nrow; j++) {
    free(b[j]);
  }
  free(b);
  for (j = 0; j < nrow; j++) {
    free(z[j]);
  }
  free(z);
  
  return 0;
}

