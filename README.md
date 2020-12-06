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
#### 関数の説明  
##### push_heap(int *T,int x,int *size)  
ヒープを格納する配列Tにxを追加する関数    
##### deleate_maximum(int *T,int *size)  
ヒープの先頭を取り出す関数  
※sizeはTの大きさ（要素の数）を格納している変数
### quickSort.c
クイックソートを行うプログラム
#### 関数の説明
##### quickSort(int *D, int left, int right)
再帰する関数  
partition関数を用いて分割して分割した配列を再帰させる
##### partition(int *D, int left, int right)
適当に基準値D[k]を決めてD[k]より小さい物をD[k]より前にD[k]より大きいものをD[k]より後ろに持ってきて、D[k]の最終的な位置を返す関数
### listAdd
連結リストの操作を行うプログラム
#### listAdd.h
連結リストの操作を行う関数が記述されたファイル
##### typedef struct _record record
連結リストのレコードの宣言
##### void append(record **head, int x)
連結リストへのデータの追加(先頭)
##### void appendToTail(record **head, int x)
連結リストへのデータの追加(最後尾)  
(2020/12/3 22:45)セグメンテーションフォルトにより動作しない
(2020/12/4 22:25)動作するようになった  
原因はいろいろあるが、一言でまとめるとアドレス操作を間違っていた
##### void ascendingOrder(record **head, int x)
連結リストへのデータの追加(昇順)  
(2020/12/3 22:45) 動作未確認
(2020/12/6 22:42) セグメンテーションフォルトにより動作しない
##### void print_list(record *head)
連結リストのデータの表示
##### void print_array(int *array, int size)
配列のデータの表示
##### void deleate(record *head)
連結リストのデータの削除  
(2020/12/3 22:45) 動作未確認
##### void free_list(record *head)
連結リストの解放

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
