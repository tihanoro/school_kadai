#include<stdio.h>
#include"func_detarminant.h"

int main(void){
	int n;
	int i,j;
	double **a;
	double **b;
	double detar;
	
	printf("ｎ次正方行列 :\n");
	scanf("%d",&n);
	
	a = arrayget(n,n);
	if(a==NULL){
		printf("メモリの確保に失敗\n");
		return 1;
	}
	
	b = arrayget(n,n);
	if(b==NULL){
		printf("メモリの確保に失敗\n");
		return 1;
	}
	
	printf("before scan\n");
	
	scan_matrix(a,n,n);
	
	printf("before scan\n");
	
	detar = dat(a,n);
	
	if(detar==0){
		printf("逆行列が存在しません\n");
		return 1;
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			b[i][j] = laplace(a,n,i,j)/detar;
		}
	}
	
	print_matrix(b,n,n);
	
	arrayfree(a,n);
	arrayfree(b,n);
	
	return 0;
}
