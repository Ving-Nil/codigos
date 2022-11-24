#include <iostream>
#include <cstdlib>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int);
};
Node::Node(int n){
    data = n;
    next = NULL;
}
class List{
    public:
    int len;
    Node *head;
    List();
    void append(int);
    void print();
};
List::List(){
    len  = 0;
    head = NULL;
}
void List::append(int n){
    Node *N = new Node(n);
    if(head==NULL){
        head = N;
        len++;
    }
    else if(n < head->data){
        N->next = head;
        head    = N;
        len++;
    }
    else{
        Node *aux=head,*back;
        while( aux->next != NULL ){
            back = aux;
            aux  = aux->next;

            // back <  n <  aux no admite repetidos
            // back <= n <= aux si admite repetidos
            if(back->data < n && n < aux->data){
                back->next = N;
                N->next    = aux;
                len++;
                return;
            }
        }
        if(aux->data < n){
            aux->next = N;
            len++;
        }
    }
}
void List::print(){
    cout << "[";
    Node *aux = head;
    while(aux->next != NULL){
        cout << aux->data << ", ";
        aux = aux->next;
    }
    if(head==NULL){
        cout << "]\n";
    }
    else{
        cout << aux->data << "]\n";
    }
}
List mixLists(List A, List B){
    List L;
    Node *aux1 = A.head;
    Node *aux2 = B.head;
    while(aux1!=NULL || aux2!=NULL){
        if(aux1!=NULL){
            L.append(aux1->data);
            aux1 = aux1->next;
        }
        if(aux2!=NULL){
            L.append(aux2->data);
            aux2 = aux2->next;
        }
    }
    return L;
}
int main(){
    int i;
    List A,B,C;
    for(i=0;i<20;i++){
        int r = rand()%20;
        if(r%2==0){
            A.append(r);
        }
        else{
            B.append(r);
        }
    }
    A.print();
    B.print();
    C = mixLists(A,B);
    C.print();
    return 0;
}
