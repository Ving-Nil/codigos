#include <iostream>

using namespace std;

class Node{
    public:
    string book;
    Node *next;
    Node(string,Node*);
};

Node::Node(string s, Node *n){
	book = s;
	next = n;
}

class Stack{
    public:
    int length;
    Node *head;
    Stack();
    void push(string);
    string pop();
    void print();
};

Stack::Stack(){
    length = 0;
    head   = NULL;
}

//      head          one             two
// (book, next) -> (book, next) -> (bokk, next)  -> NULL
// (book,(book, (book,(book,next))))

//      N            
//  ( s , (book,(book, (book,(book,next)))) )
//     N            head           one             two
// (s, head) -> (book, next) -> (book, next) -> (bokk, next)  -> NULL

//     head          
//  ( s , (book,(book, (book,(book,next)))) )

void Stack::push(string s){
    head = new Node(s,head);
    length++;
}

//      head          one             two
// (book, next) -> (book, next) -> (bokk, next)  -> NULL

// explicacion de la linea 66
// si agregamos un nuevo N cuando se ha eliminado old-heald y head (el nuevo head) 
// se actualiza a "one" que es "old-head->next"
//     N            head = one           two
//  (book, next) -> (book, next) -> (bokk, next)  -> NULL
//                 / 
//     (book, next) 
//     aux/old-head 

string Stack::pop(){
    if( head != NULL ){
        string S = head->book;
        Node *aux = head;
        head = head->next;
        aux->next = NULL;
        free(aux);
        length--;
        return S;
    }
    else{
        return "";
    }
}

// Aqui aux vale head
//   aux=head
// imprime: [
//     head             2              3                    4            -> NULL
// imprime: [ math, 
//  ("math",2) -> ("science",3) -> ("literatura",4) -> ("biología",NULL) -> NULL

// Aquí aux valía head y lo convertimos en su next
//   aux=head
//                 aux = aux->next
//                 aux = 2
//     head             2              3                    4            -> NULL
//  ("math",2) -> ("science",3) -> ("literatura",4) -> ("biología",NULL) -> NULL
// imprime: [ math, science, 

//                  aux=2
//                                 aux = aux->next
//                                 aux = 3
//     head             2              3                    4            -> NULL
//  ("math",2) -> ("science",3) -> ("literatura",4) -> ("biología",NULL) -> NULL
// imprime: [ math, science, literatura, 

//                                                      aux = 4
//                                                      aux->next es NULL se acaba el while
//     head             2              3                    4            -> NULL
//  ("math",2) -> ("science",3) -> ("literatura",4) -> ("biología",NULL) -> NULL
// después de while imprime sin ", " y pone un corchete de cierre
// imprime: [math, science, literatura, biología]

void Stack::print(){
    Node *aux = head;
    cout << "[";
    if(head != NULL){
        // if head->next == NULL significa sólo hay un nodo
        // como aux = head sucedería
        //    aux->next == NULL verdadero y no entra al while e imprime sólo un nodo
		while(aux->next != NULL){
			cout << aux->book << ", ";
			aux = aux->next;
		}
        cout << aux->book << "]\n";
    }
    else{
        cout << "]\n";
    }
}

int main(){
    Stack Pila;
    Pila.push("Literature");
    Pila.push("Science");
    Pila.push("History");
    Pila.push("Math");
    Pila.print();

    Pila.push("Other");
    Pila.print();

    Pila.pop();
    Pila.print();

    cout << "Length : " << Pila.length << endl;
    return 0;
}
