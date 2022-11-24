#include <iostream>
#include <cstdlib>
using namespace std;

class Node{
	public:
    char data;
    Node *next;
    Node(char);
};

Node::Node(char c){
	data = c;
	next = NULL;
}

class Queue{
    public:
    int len;
    Node *head;
    Queue();
    void enqueue(char);
    char dequeue();
    void print();
};

Queue::Queue(){
    len  = 0;
    head = NULL;
}

void Queue::enqueue(char c){
    if( 65<=c && c<=90 || 97<=c && c<=122 ){
        Node *N = new Node(c);
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
        len++;
    }
}

char Queue::dequeue(){
    if( head == NULL ){
        return '\0';
    }
    else{
        char c = head->data;
        Node *aux = head;
        head = head->next;
        free(aux);
        len--;
        return c;
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
    for(i=0;i<20;i++){
        char c = (rand()%57)+65;
        cout << "Append: <" << c << ">\n";
        Q.enqueue(c);
    }

    Q.print();
    
    cout << "First element: " << Q.dequeue() << endl;
    return 0;
}
