#include<stdio.h>

#define N 10

void sort(int *d, int n);

int main(void){
    int D[N] = {17,39,1,9,5,24,2,11,23,6};
    int i,j;

    //ソート前の配列の出力
    printf("Before sort:{");
    for(i=0;i<N;i++){
        printf("%2d ",D[i]);
    }
    printf("}\n");

    //ソート関数の実行
    sort(D,N);

    //ソート後の配列の出力
    printf("After sort:{ ");
    for(i=0;i<N;i++){
        printf("%2d ",D[i]);
    }
    printf("}\n");

    return 0;
}

void sort(int *d, int n){
    int i,j,k,x;
    
    for(i=1;i<n;i++){
        x = d[i];
        j=i;
        while(d[j-1]>x && j>0){
            d[j] = d[j-1];
            j = j - 1;
        }
        d[j] = x;
        printf("MOVE(D[%d],D[%d]):{ ",i,j);
        for(k=0;k<N;k++){
            printf("%2d ",d[k]);
        }
        printf("}\n");

    }
}