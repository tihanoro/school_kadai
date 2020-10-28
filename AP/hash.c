#include<stdio.h>
int hash(int x);

int D[] = {81, 20, 45, 62, 89, 66, 42,
	   70, 44, 51, 31};

int main(void){
  int H[16];
  int x,i,k;

  //配列Hを-1で初期化
  for(i=0;i<16;i++){
    H[i] = -1;
  }

  //配列Hにハッシュ関数を用いて格納
  for(i=0;i<11;i++){
    k = hash(D[i]);
    while(H[k] != -1) k++;
    H[k] = D[i];
  }
  
  //配列Hの出力
  printf("配列Hの中身\n");
  printf("{ ");
  for(i=0;i<16;i++){
    printf("%d, ",H[i]);
  }
  printf("}\n");
  
  return 0;
}

int hash(int x){
  return x%7;
}
