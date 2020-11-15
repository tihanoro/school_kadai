#include<stdio.h>

void push_heap(int *T,int x,int *size);
int deleate_maximum(int *T,int *size);
void swap(int *a,int *b);
void print_array(int *array,int n);

int main(void){
  int D[10] = {17,39,1,9,5,24,2,11,23,6};
  int T[10];
  int i,j,size;

  //Dの出力とTの初期化
  printf("Before sort:");
  print_array(D,10);
  for(i=0;i<10;i++){
    T[i] = -1;
  }

  //Tにヒープソートでデータを挿入
  size = -1;
  for(i=0;i<10;i++){
    push_heap(T,D[i],&size);
  }
  printf("heap[%d]:\n",size);
  print_array(T,10);

  
  //Dにデータを戻す
  for(i=0;i<10;i++){
    D[i] = deleate_maximum(T,&size);
  }  

  printf("After Sort:");
  print_array(D,10);

  return 0;
}

void push_heap(int *T,int x,int *size){
  int k;
  
  //節点の追加
  *size = *size + 1;
  T[*size] = x;

  //親節点と大きさ比較と入れ替え
  k=*size;
  while((T[k]>T[k/2]) && (k>0)){
    swap(&T[k],&T[k/2]);
    k = k/2;
  }
}

int deleate_maximum(int *T,int *size){
  int k,big,output;

  output = T[0]; //最大値の取り出し

  T[0] = T[*size];  //最下位節点の消去
  T[*size] = -1;
  *size = *size-1;
  
  //ヒープの入れ替え
  k=0;
  while(2*k <= *size){

    if(2*k == *size){  //子節点が１つのとき

      if(T[k] < T[2*k+1]){  //子節点が親節点より大きいとき
        swap(&T[k],&T[2*k+1]);
        k = 2*k+1;
      }else{  //子節点が親節点以下のとき
        break;
      }

    }else{  //子節点が２つのとき

      if(T[2*k+1]>T[2*k+2]){  //大きい方の子節点を見つける処理
        big = 2*k+1;
      }else{
        big = 2*k+2;
      }

      if(T[k]<T[big]){
        swap(&T[k],&T[big]);
        k = big;
      }else{
        break;
      }

    }
    
  }
  return output;
}

void swap(int *a,int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void print_array(int *array,int n){
  int i;
  printf("{ ");
  for(i=0;i<n;i++){
    printf("%d ",array[i]);
  }
  printf("}\n");
}
