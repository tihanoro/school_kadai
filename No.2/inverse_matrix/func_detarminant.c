#include<stdio.h>
#include<stdlib.h>
#include"func_detarminant.h"

//行列式を求める関数
//1つ目の引数に正方行列の先頭アドレス
//2つ目の引数に正方行列の大きさ
double dat(double **a, int n){
	//変数の宣言
	int i, j, d;
	double temp, dat;
	//行列式の初期化
	//乗算していくので初期値は1
	dat = 1.0;
	
	for(d=0;d<=n;d++){
		
		//対角成分が0のとき他の行と入れ替え
		if(a[d][d]==0){
			for(i=d+1;i<=n;i++){
				if(a[i][d]!=0){
					for(j=d;j<=n;j++){
						temp=a[i][j];
						a[i][j]=a[d][j];
						a[d][j]=temp;
					}
					dat*=(-1);
					break;
				}
			}
		}
			
		//掃き出し法
		//対角成分に0があるとき
		if(a[d][d]){
			for(i=d+1;i<=n;i++){
				temp=a[i][d]/a[d][d];
				for(j=d;j<=n;j++){
					a[i][j]-=(temp*a[d][j]);
				}
			}
			dat*=a[d][d];
		}else{
			dat=0;
			break;
		}
	}
	
	return dat;	
}

//余因子を求める関数
double laplace(double **a, int n, int row, int colmn){
	int i, j;
	double ans;
	
	if((row+colmn)%2){
		ans = -1.0;
	}else{
		ans = 1.0;
	}
	
	return ans*min_dat(a,n,row,colmn);
}

//小行列式を求める関数
double min_dat(double **a, int n, int row, int colmn){
	int i,j;
	double ans;
	double **b;
	
	b = min_matrix(a,n,row,colmn);
	ans = dat(b,n-1);
	
	//bの開放
	arrayfree(b,n-1);
	
	return ans;
}

//小行列を作る関数
double **min_matrix(double **a, int n, int row, int colmn){
	int i,j;
	double **b;
	b = arrayget(n-1,n-1);
	
	//位置が動かないものだけ先に入れる。
	for(i=0;i<row;i++){
		for(j=0;j<colmn;j++){
			b[i][j] = a[i][j];
		}
	}
	
	//１行上にずらす
	for(i=row;i<n-1;i++){
		for(j=0;j<n-1;j++){
			b[i][j] = a[i+1][j];
		}
	}
	
	//１列左にずらす
	for(i=0;i<n-1;i++){
		for(j=colmn;j<n-1;j++){
			b[i][j] = a[i][j+1];
		}
	}
	
	return b;
}

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
