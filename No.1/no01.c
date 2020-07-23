//最大公約数を求めるプログラム
#include<stdio.h>

int gcd(int a,int b);

int main(void){
  int m,n,ans;

  //変数の入力
  printf("2つ文字を入力：");
  scanf("%d %d",&m,&n);

  if(m<n){
    int temp = m;
    m = n;
    n = temp;
  }

  //関数の呼び出し
  ans = gcd(m,n);

  //結果の出力
  printf("最大公約数：%d\n",ans);

  return 0;
}

int gcd(int a,int b){
  int ans;
  //再起の終了条件
  if(b==0){
    return a;
  }

  //ユークリッド互除法
  ans = gcd(b,a%b);

  return ans;
}
