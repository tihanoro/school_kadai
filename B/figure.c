#include<stdio.h>
#include<stdlib.h>

//構造体の宣言
typedef struct {
    char number[6];       //番号
    char name[21];    //氏名
    int time_yen;     //時給
    int month_time4;  //4月の勤務時間
    int month_time5;  //5月の勤務時間
    int month_time6;  //6月の勤務時間
    int month_yen4;   //4月の給料
    int month_yen5;   //5月の給料
    int month_yen6;   //6月の給料
    int all_time;     //合計勤務時間
    int all_yen;      //合計給料
} DATA;

DATA scan_DATA();
void print_DATA(DATA *data, int num);

int main(void){
    //変数の宣言
    DATA data[10];
    int num,i;

    //入力人数の設定
    printf("入力する人数:");
    scanf("%d",&num);
    while((1<=num&&num<=10)==0){
        printf("1~10人の範囲で入力してください\n入力する人数:");
        scanf("%d",&num);
    }

    //データの入力
    for(i=0;i<num;i++){
        printf("%d人目の入力\n",i+1);
        data[i] = scan_DATA();
    }

    //データの出力
    print_DATA(data,num);
    
    return 0;
}


//データを入力する関数
DATA scan_DATA(){
    DATA data;
    printf("番号:");
    scanf("%s",data.number);
    printf("氏名:");
    scanf("%s",data.name);
    printf("時給:");
    scanf("%d",&data.time_yen);
    printf("4月の勤務時間:");
    scanf("%d",&data.month_time4);
    printf("5月の勤務時間:");
    scanf("%d",&data.month_time5);
    printf("6月の勤務時間:");
    scanf("%d",&data.month_time6);

    //月の給料の計算
    data.month_yen4 = data.month_time4*data.time_yen;
    data.month_yen5 = data.month_time5*data.time_yen;
    data.month_yen6 = data.month_time6*data.time_yen;
    
    //合計勤務時間と合計給料の計算
    data.all_time = data.month_time4+data.month_time5+data.month_time6;
    data.all_yen = data.month_yen4+data.month_yen5+data.month_yen6;

    return data;
}

void print_DATA(DATA *data, int num){
    int i;
    printf("\nNo.   | Name                 | Apr.   | May    | June   | T.Time | T.Salary \n");
    printf("------+----------------------+--------+--------+--------+--------+---------\n");

    for(i=0;i<num;i++){
        printf("%-5s | %-20s | %6d | %6d | %6d | %6d | %8d\n",data[i].number,data[i].name,data[i].month_yen4,data[i].month_yen5,data[i].month_yen6,data[i].all_time,data[i].all_yen);
    }
    printf("\n");

    return;
}