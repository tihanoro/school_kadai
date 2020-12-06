#include<stdio.h>
#include<stdlib.h>

//連結リストのレコードの宣言
typedef struct _record{
    int data;  //データを格納するレコード
    struct _record *next;  //次のリストのアドレスを指すレコード
} record;

//連結リストへのデータの追加(先頭)
void append(record **head, int x){

    //追加するリストの宣言とアドレスの確保
    record *addList;
    addList = (record *)malloc(sizeof(record));
    if(addList == NULL){
        fprintf(stderr,"アドレスの確保に失敗しました。\n");
        exit(1);
    }

    //追加するリストにデータを格納し先頭に追加
    addList->data = x;
    addList->next = *head;
    *head = addList;    
}

//連結リストへのデータの追加(最後尾)
void appendToTail(record **head, int x){

    //追加するリストの宣言とアドレスの確保
    record *addList;
    addList = (record *)malloc(sizeof(record));
    if(addList == NULL){  //エラー処理
        fprintf(stderr,"アドレスの確保に失敗しました。\n");
        exit(1);
    }

    //最後尾のリストの探索
    record **tailList; //最後尾のリストを指すポインタ変数
    tailList = head;
    while(*tailList != NULL){
        tailList = &(*tailList)->next;
    }

    //追加するリストにデータを格納し最後尾に追加
    addList->data = x;
    addList->next = NULL;
    *tailList = addList;
}

//連結リストへのデータの追加(昇順)
void ascendingOrder(record **head, int x){

    //追加するリストの宣言とアドレスの確保
    record *addList;
    addList = (record *)malloc(sizeof(record));
    if(addList == NULL){
        fprintf(stderr,"アドレスの確保に失敗しました。\n");
        exit(1);
    }

    //リストの追加先の探索
    record **addPlace;
    addPlace = head;
    while((x < (*addPlace)->data) && (*addPlace != NULL)){
        addPlace = &(*addPlace)->next;
    }

    //追加するリストにデータを格納しaddPlaceの次に追加
    addList->data = x;
    addList->next = (*addPlace)->next;
    (*addPlace)->next = addList;
}

//連結リストのデータの表示
void print_list(record *head){
    record *p;
    p = head;
    printf("{ ");
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("}\n");
}

//配列のデータの表示
void print_array(int *array, int size){
  int i;
  printf("{ ");
  for(i=0;i<size;i++){
    printf("%d ",array[i]);
  }
  printf("}\n");
}

//連結リストのデータの削除
void deleate(record *head){
    record *deleateList;  //削除するリストのアドレスを格納する変数
    if(head == NULL){
        printf("削除するデータがありません\n");
    }else{
        //先頭リストの削除と解放
        deleateList = head->next;
        head = deleateList->next;
        free(deleateList);
    }
}

//連結リストの解放
void free_list(record *head){
    if(head->next != NULL) free_list(head->next);
    free(head);
}