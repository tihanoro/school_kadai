#include <stdio.h>
#define N 10

int data[N] = {1,3,5,7,9,11,13,15,17,19};

int main(void){
	int right,left,mid,x,count;
	left = 0;
	right = N-1;
	mid = (right+left)/2;
	count = 0;
	
	scanf("%d",&x);
	
	while(right>left){
		printf("count = %3d\n", ++count);
		printf("%d番目の配列を調べる\n",mid+1);
		if(x==data[mid]){
			printf("%d番目の配列に%dが格納されています。\n",mid+1,data[mid]);
			return 0;
		}
		if(data[mid]<x){
			left = mid + 1;
		}else{
			right = mid - 1;
		}
		mid = (left+right)/2;
	}
	
	if(data[mid]==x){
		printf("%d番目の配列に%dが格納されています。\n",mid,data[mid]);
	}else{
		printf("%dは存在しません\n",x);
	}
	
	return 0;
}
