#include<stdio.h>

#define N 10

void sort(int *d, int n);
void swap(int *a, int *b);

int main(void){
    int D[N] = {17,39,1,9,5,24,2,11,23,6};
    int i,j;

    //ソート前の配列の出力
    printf("Before sort:{");
    for(i=0;i<N;i++){
        printf("%d ",D[i]);
    }
    printf("}\n");

    //ソート関数の実行
    sort(D,N);

    //ソート後の配列の出力
    printf("After sort:{ ");
    for(i=0;i<N;i++){
        printf("%d ",D[i]);
    }
    printf("}\n");

    return 0;
}

void sort(int *d, int n){
    int i,j,k,max,max_index;
    
    for(i=n-1;i>0;i--){
        max = d[0];
        max_index = 0;
        for(j=1;j<=i;j++){
            if(d[j] >= max){
                max = d[j];
                max_index = j;
            }
        }
        //d[max_index]とd[i]を入れ替え
        swap(&d[max_index],&d[i]);
        printf("SWAP(D[%d],D[%d]):{ ",max_index,i);
        for(k=0;k<N;k++){
            printf("%d ",d[k]);
        }
        printf("}\n");

    }
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}