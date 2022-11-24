#include <iostream>

using namespace std;

class Node{
	public:
	char data;
	Node *left;
	Node *right;
	Node(char);
};

Node::Node(char c){
	data = c;
	left = NULL;
	right = NULL;
}

class Queue{
	public:
	class NodeQ{
		public:
		int stratum;
		Node *element;
		NodeQ *next;
		NodeQ(Node *N,int n){stratum = n;element = N;next=NULL;}
	};
	NodeQ *head;
	NodeQ *tail;
	Queue();
	Queue(Node*,int);
	void enqueue(Node*,int);
	Node* dequeue();
};

Queue::Queue(){
	head = NULL;
	tail = NULL;
}

Queue::Queue(Node* N, int n){
	head = new NodeQ(N,n);
	tail = head;
}

void Queue::enqueue(Node *N, int n){
	if(head==NULL){
		head = new NodeQ(N,n);
		tail = head;
	}
	else{
		tail->next = new NodeQ(N,n);
		tail = tail->next;
	}
}

Node* Queue::dequeue(){
	if(head==NULL){
		return NULL;
	}
	Node *aux = head->element;
	NodeQ *old = head;
	head = head->next;
	free(old);
	return aux;
}

class BinaryTree{
	public:
	Node *root;
	BinaryTree();
	void countPreOrden(Node*, int*);
	int len();
	void printBFS();
	// traversals 
	void leftRootRight(Node*);
	void rootRightLeft(Node*);
};

BinaryTree::BinaryTree(){
	root = NULL;
}

void BinaryTree::countPreOrden(Node *N, int *n){
	if(N==NULL){return;}
	(*n)++;
	countPreOrden(N->left,n);
	countPreOrden(N->right,n);
}

int BinaryTree::len(){
	int i=0;
	countPreOrden(root,&i);
	return i;
}

void BinaryTree::printBFS(){
	int stratum = 1,i;
	Queue Q(root,stratum);
	while(Q.head != NULL){
		if(Q.head->element != NULL){
			for(i=0;i<Q.head->stratum;i++){cout << "-";}
			stratum = Q.head->stratum;
			Node *current = Q.dequeue();
			if(current != NULL){
				cout << current->data;
				if( current->left != NULL ){
					Q.enqueue(current->left, stratum + 1);
				}
				if( current->right != NULL ){
					Q.enqueue(current->right, stratum + 1);
				}
			}
		}
		else{
			Q.dequeue();
		}
	}
}

// this is not standar traversal
void BinaryTree::rootRightLeft(Node *N){
	if(N==NULL){
		return;
	}
	cout << N->data << " ";
	rootRightLeft(N->right);
	rootRightLeft(N->left);
}

void BinaryTree::leftRootRight(Node *N){
	if(N==NULL){
		return;
	}
	leftRootRight(N->left);
	cout << N->data << " ";
	leftRootRight(N->right);
}

int main(){
	BinaryTree B;
	B.root = new Node('A');
	B.root->left = new Node('B');
	B.root->left->left = new Node('D');
	B.root->left->right = new Node('E');
	B.root->left->right->left = new Node('G');
	B.root->left->right->right = new Node('H');
	B.root->left->right->right->left = new Node('I');
	B.root->right = new Node('C');
	B.root->right->right = new Node('F');
	
	cout << "\nBinary Tree BFS: ";
	B.printBFS();

	cout << "\nBinary Tree root-right-left traversal: ";
	B.rootRightLeft(B.root);
	cout << "\nBinary Tree left-root-right traversal: ";
	B.leftRootRight(B.root);

	cout << "\nBinary Tree Number of nodes: " << B.len() << endl;
	return 0;
}
