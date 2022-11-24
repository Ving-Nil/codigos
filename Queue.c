#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node * newNode(int n){
    struct Node *N = (struct Node *)malloc(sizeof(struct Node));
    N->data = n;
    N->next = NULL;
    return N;
}

struct Node * enqueue(struct Node *head, int n){
    if( head == NULL ){
        head = newNode(n);
    }
    else{
        struct Node *aux = head;
        while( aux->next != NULL ){
            aux = aux->next;
        }
        aux->next = newNode(n);
    }
    return head;
}

struct Node * dequeue(struct Node *head){
    if( head != NULL ){
        struct Node *aux = head;
        head = head->next;
        free(aux);
        return head;
    }
    else{
        return NULL;
    }
}

void print(struct Node *head){
    printf("[");
    if(head == NULL){
        printf("]\n");
    }
    else{
        struct Node *aux = head;
        while( aux->next != NULL ){
            printf("%d, ",aux->data);
            aux = aux->next;
        }
        printf("%d]\n",aux->data);
    }
}

int main(){
    struct Node *Q = NULL;
    int i;
    for(i=0;i<5;i++){
        Q = enqueue(Q,rand()%10);
        print(Q);
    }

    Q = dequeue(Q);
    print(Q);

    Q = dequeue(Q);
    print(Q);

    Q = dequeue(Q);
    print(Q);
    return 0;
}
