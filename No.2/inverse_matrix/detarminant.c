//IS2 34 田澤秀東
//ｎ次の行列式を求めるプログラム(nの区間は[1,10])
#include <stdio.h>
int main(void){
  int i,j,n,d;
  double a[10][10];
  double total,temp;
  total=1;
  
  for(i=0;i<=9;i++){		
    for(j=0;j<=9;j++){		
    a[i][j]=0;			
    }	
  }	
  
  //次元の入力
  printf("次元の入力\n");
  scanf("%d",&n);	n -= 1;
 
  //ｎの値を調べる
  if(n>=0 && n<=9){
  
    //要素の入力
    for(i=0;i<=n;i++){
      for(j=0;j<=n;j++){
	printf("(%d,%d)要素の入力\n",i+1,j+1);
	scanf("%lf",&a[i][j]);
      }
    }
  
    //入力した行列式を出力
    printf("入力した行列式\n");
    for(i=0;i<=n;i++){
      printf("| ");
      for(j=0;j<=n;j++){
	printf("%1.0f ",a[i][j]);
      }
      printf("|\n");
    }
    printf("\n");
  
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
	    total*=(-1);
	    printf("1行と%d行を入れ替え\n",i);
	    for(i=d;i<=n;i++){
	      printf("| ");
	      for(j=d;j<=n;j++){
		printf("%1.0f ",a[i][j]);
	      }
	      printf("|\n");
	    }
	    break;					}
	}
      }
      //掃き出し法
      if(a[d][d]){
	for(i=d+1;i<=n;i++){
	  temp=a[i][d]/a[d][d];
	  for(j=d;j<=n;j++){
	    a[i][j]-=(temp*a[d][j]);
	  }
	}
	total*=a[d][d];
    
	printf("掃き出し法\n");
	for(i=d;i<=n;i++){
	  printf("| ");
	  for(j=d;j<=n;j++){
	    printf("%1.0f ",a[i][j]);
	  }
	  printf("|\n");
	}
      }else{
	total=0;
	break;
      }
    
    }
    //行列式の出力
    printf("行列式の値:%f\n",total);
  }
  return 0;
}
