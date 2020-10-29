#include<stdio.h>
#define N 11
#define M 16
int hash(int x);
int search(int x, int *h);

int D[N] = {81, 20, 45, 62, 89, 66, 42,
	   70, 44, 51, 31};

int main(void){
  int H[M];
  int x,i,k;

  //配列Hを-1で初期化
  for(i=0;i<M;i++){
    H[i] = -1;
  }

  //配列Hにハッシュ関数を用いて格納
  for(i=0;i<N;i++){
    k = hash(D[i]);
    while(H[k] != -1) k = (k+1)%M; //Mで割るのは先頭に戻って格納先を探すため
    H[k] = D[i];
  }
  
  //配列Hの出力
  printf("配列Hの中身\n");
  printf("{ ");
  for(i=0;i<M;i++){
    printf("%d, ",H[i]);
  }
  printf("}\n");

  //xの入力
  scanf("%d",&x);

  //xの探索
  search(x,H);
  
  return 0;
}

int hash(int x){
  return x%7;
}

int search(int x, int *h){
  int k;
  k = hash(x);
  while(h[k]!=-1){
    if(h[k] == x){
      printf("%dは配列Hの%d番目に格納されている\n",x,k);
      return 0;
    }
    k = (k+1)%M;
  }
  printf("xは存在しない\n");
}