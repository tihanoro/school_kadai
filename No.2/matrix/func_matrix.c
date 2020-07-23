#include<stdio.h>
#include<stdlib.h>

//配列の動的確保の関数化
double **arrayget(int row,int column){
  double **p;
  int i;
  //行の確保
  p = (double **)malloc(row*sizeof(double *));
  //列の確保
  for(i=0;i<row;i++){
    p[i] = (double *)malloc(column*sizeof(double));
  }
  return p;
}

//行列の入力の関数化
void scan_matrix(double **p,int row,int column){
  int i, j;
  for(i=0;i<row;i++){
    for(j=0;j<column;j++){
      printf("%d行%d列 :",i+1,j+1);
      scanf("%lf",&p[i][j]);
    }
  }
}

//行列の積の計算を関数化
void multi_matrix(double **a,double **b,double **z,int L,int M ,int N){
  int i,j,k,temp;
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
}

//行列の出力を関数化
void print_matrix(double **p,int row,int column){
  int i,j;
  for(i=0;i<row;i++){
    printf("| ");
    for(j=0;j<column;j++){
      printf("%5.2f ",p[i][j]);
    }
    printf("|\n");
  }
  printf("\n");
}

//領域の開放の関数化
void arrayfree(double **p,int column){
  int i;
  for(i=0;i<column;i++){
    free(p[i]);
  }
  free(p);
}
