#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int);
};

Node::Node(int n){
    data=n;
    next=NULL;
}

class Stack{
    public:
    Node *head;
    Stack();
    void push(int);
    int pop();
    void print();
};

Stack::Stack(){
    head=NULL;
}

// head -> node2 -> node3 -> node4 -> NULL
// head -> NULL
void Stack::push(int n){
    if(head==NULL){
        head = new Node(n);
    }
    else{
        Node *aux = head;
        while( aux->next != NULL ){
            aux = aux->next;
        }
        aux->next = new Node(n);
    }
}

// head -> node2 -> node3 -> node4 -> NULL 
//   5       7        8        1           
// head -> node2 -> node3 -> NULL          
//                             1           
// aux -> node2 -> NULL
int Stack::pop(){
    if(head==NULL){
        return -1;
    }
    else if(head->next == NULL){
        int n = head->data;
        head = NULL;
        return n;
    }
    else{
        Node *aux = head;
        while( aux->next->next != NULL ){
            aux = aux->next;
        }
        aux->next = NULL;
    }
}

void Stack::print(){
    if(head==NULL){
        cout << "[]\n";
    }
    else{
        cout << "[";
        Node *aux = head;
        while( aux->next != NULL ){
            cout << aux->data << ", ";
            aux = aux->next;
        }
        cout << aux->data << "]\n";
    }
}

int main(){
    Stack S;
    S.print();

    S.push(10);
    S.print();

    S.push(7);
    S.push(3);
    S.push(9);
    S.push(1);
    S.push(4);
    S.print();

    S.pop();
    S.pop();
    S.pop();
    S.print();
}
