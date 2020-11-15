# shool_kadai
このリポジトリをクローンする際のコマンド   
```
git clone https://github.com/tihanoro/school_kadai/
```
GitHubにプッシュするときに使う一連のコマンド  
fileName：変更が行われたファイル  
origin：共有リポジトリ（GitHub等）  
master：マスターブランチ（よくわかってない）
```
git add fileName
git commit -m "コメントを何か書く"
git push origin master
```
## AP 応用プログラミング
### binalySearch.c
二分探索法のプログラム
### hash.c
ハッシュ法のプログラム
### selectionSort.c
選択ソートのプログラム
### insertionSort.c
挿入ソートのプログラム
### heapSort.c
ヒープソートを行うプログラム
関数の説明
・push_heap(int *T,int x,int *size)
ヒープを格納する配列Tにxを追加する関数    
・deleate_maximum(int *T,int *size)  
ヒープの先頭を取り出す関数  
※sizeはTの大きさ（要素の数）を格納している変数

## A B C D No.1 No.2 No.3 プログラミング
よくわからんプログラムがいっぱい
時間があるときに整理する。
### A
動的メモリを用いたプログラムたち
#### main.c
行列の積を計算するプログラム
### B
構造体を用いたプログラムたち
#### complex.c
複素数の計算をするプログラム
#### distance.c
座標平面上の距離を求めるプログラム
#### figure.c
構造体を用いて表を作るプログラム
#### figure_file.c
figure.cをファイルで入出力するようにしたもの
### C
ファイルの入出力をするプログラムたち
#### complex_file.c
B/complex.cをファイル入出力にしたもの
#### figure.c
B/figure.cと同じ
### D
線形リストを用いたプログラムたち
#### figure_file.c
B/figure_file.cを線形リスト構造で実装したもの
### No.1
ハノイの塔、最大公約数を求めるプログラム等
### No.2
行列についてのプログラム
### No.3
複素数、座標平面の距離についてのプログラム
