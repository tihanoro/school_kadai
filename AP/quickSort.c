#include<stdio.h>

#define N 10
#define DATA {35,21,4,49,55,19,12,32,24,42}

void quickSort(int *D, int left, int right);
int partition(int *D, int left, int right);
void swap(int *a, int *b);
void print_array(int *array, int n);
void printArray(int *array, int left, int right);

int main(void){
    int D[N] = DATA;

    printf("Before sort:");
    print_array(D,N);

    quickSort(D,0,N-1);

    printf("After sort:");
    print_array(D,N);

    return 0;
}

void quickSort(int *D, int left, int right){
    int data;
    static int count =0;

    //left=rightまたはleft>rightのとき再帰終了
    if(left<right){
        //基準値の位置を取得
        data = partition(D,left,right);
        //基準値の前後のソート
        quickSort(D,left,data-1);
        quickSort(D,data+1,right);

        printf("\n組み立て:No.%d\n",++count);
        printf("D1[%d,%d]:",left,data-1);
        printArray(D,left,data-1);
        printf("partition[%d]:",data);
        printArray(D,data,data);
        printf("D2[%d,%d]:",data+1,right);
        printArray(D,data+1,right);
        printf("D[%d,%d]:",left,right);
        printArray(D,left,right);
    }else{
        return;
    }
}

int partition(int *D, int left, int right){
    int i,j,k;
    static int count = 0;

    printf("\n分解:No.%d\n",++count);
    printf("D[%d,%d]:",left,right);
    printArray(D,left,right);

    //基準値の指定[left,right-1]ならなんでもいい
    k = (left+right)/2;

    //基準値より小さいD1と基準値以上のD2に分けて、その間の位置を出力する
    swap(&D[k], &D[right]);
    printf("SWAP(D[%d],D[%d]):\n",k,right);
    i = left;
    j = right-1;
    while(i<=j){
        while(D[i]<D[right]){
            i++;
        }
        while(D[j]>=D[left] && j>=i){
            j--;
        }
        if(i<j){
            swap(&D[i], &D[j]);
            printf("SWAP(D[%d],D[%d])\n",i,j);
        }
    }
    swap(&D[i],&D[right]);

    printf("D1[%d,%d]:",left,i-1);
    printArray(D,left,i-1);
    printf("partition[%d]:",i);
    printArray(D,i,i);
    printf("D2[%d,%d]:",i+1,right);
    printArray(D,i+1,right);

    //基準値を返す
    return i;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void print_array(int *array, int size){
  int i;
  printf("{ ");
  for(i=0;i<size;i++){
    printf("%d ",array[i]);
  }
  printf("}\n");
}

void printArray(int *array, int left, int right){
    int i;
  printf("{ ");
  for(i=left;i<=right;i++){
    printf("%d ",array[i]);
  }
  printf("}\n");
}
