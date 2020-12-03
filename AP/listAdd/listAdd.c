#include<stdio.h>
#include<stdlib.h>
#include"listAdd.h"
#define N 5
#define DATA {9, 2, 0, 4, 5}

int main(void){
    record *head;
    int data[N] = DATA;
    int i;

    printf("array:");
    print_array(data,N);

    head = NULL;
    for(i=0;i<N;i++){
        append(&head,data[i]);
        print_list(head);
    }
    free_list(head);

    head = NULL;
    for(i=0;i<N;i++){
        appendToTail(&head,data[i]);
        print_list(head);
    }
    free_list(head);

    head = NULL;
    for(i=0;i<N;i++){
        ascendingOrder(&head,data[i]);
        print_list(head);
    }
    free_list(head);

    return 0;
}