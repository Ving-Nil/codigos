#include <iostream>
#include <cstring>
using namespace std;

struct Node{
    char text[90];
    struct Node *next;
};

struct Node * newNode(char text[90]){
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    strcpy(p->text, text);
    p->next = NULL;
    return p;
}

struct Node * newNode(string text){
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    strcpy(p->text, text.c_str() );
    p->next = NULL;
    return p;
}

struct Node* append(struct Node * head, struct Node *p){
    if(head==NULL){
        head = p;
        return head;
    }
    else{
        struct Node *aux, *back;
        aux = head;
        back = aux->next;
		if( strcmp(p->text,head->text) < 0 ){
			head = p;
			head->next = aux;
			return head;
		}
        while(aux->next != NULL){
            back = aux;
            aux  = aux->next;
			
            // back < p < aux
            if( strcmp(back->text,p->text) < 0 && strcmp(p->text,aux->text) < 0 ){
                back->next = p;
                p->next = aux;
                return head;
            }
        }
        if( strcmp(aux->text,p->text) < 0 ){
			aux->next = p;
		}
		return head;
    }
}

void print(struct Node * head ){
	cout << "{";
	struct Node *aux = head;
	while( aux != NULL ){
		cout << "\n\t[" << aux->text << "]\n";
		aux = aux->next;
	}
	cout << "}\n";
}

int main(){
	struct Node *head = NULL;
	string text;
	int opc=1;
	while(opc!=3){
		cout << "\nMenu\n";
		cout << "1) append Node\n";
		cout << "2) print list\n";
		cout << "3) exit\n";
		cout << "> ";
		
		cin  >> opc;
		getline(cin,text);
		
		if(opc==1){
			cout << "Introduce a text: ";
			getline(cin,text);
			head = append(head,newNode(text));
		}
		else if(opc==2){
			print(head);
		}
	}
    return 0;
}
