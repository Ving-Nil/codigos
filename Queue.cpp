#include <iostream>

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

class Queue{
    public:
    int length;
    Node *head;
    Queue();
    void enqueue(int);
    int dequeue();
    void print();
};

Queue::Queue(){
    length = 0;
    head   = NULL;
}

//                    aux   
//  4      3     7     8     
// head -> N1 -> N2 -> N3 -> NULL
// 10                     -> new Node(10)

//  4      3     7     8     10
// head -> N1 -> N2 -> N3 -> N4 -> NULL
void Queue::enqueue(int n){
    Node *N = new Node(n);
    if( head == NULL ){
        head = N;
    }
    else{
        Node *aux = head;
        while( aux->next != NULL ){
            aux = aux->next;
        }
        aux->next = N;
    }
    length++;
}

// aux = old-head
// head -> N1 -> N2 -> N3 -> N4 -> NULL
// head/N1 -> N2 -> N3 -> N4 -> NULL
int Queue::dequeue(){
    if( head == NULL ){
        return 0;
    }
    else{
        int n = head->data;
        Node *aux = head;
        head = head->next;
        delete(aux);
        length--;
        return n;
    }
}

void Queue::print(){
    Node *aux = head;
    cout << "[";
    if(head != NULL){
		while(aux->next != NULL){
			cout << aux->data << ", ";
			aux = aux->next;
		}
        cout << aux->data << "]\n";
    }
    else{
        cout << "]\n";
    }
}

int main(){
    Queue Q;
    int i;
    for(i=0;i<10;i++){
        Q.enqueue(i+1);
        Q.print();
    }

    for(i=0;i<5;i++){
        Q.dequeue();
        Q.print();
    }
    
    return 0;
}
