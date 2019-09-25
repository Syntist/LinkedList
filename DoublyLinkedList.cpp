#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next, *prev;
		Node(Node *p=NULL, int val=0, Node *n=NULL){
			data = val;
			next = n;
			prev =p;
		}
};

class LinkedList{
	Node *head,*tail;
	public:
		LinkedList(){
			head = tail = NULL;
		}
		
		~LinkedList(){
			while(!isEmpty()){
				removeHead();
			}
		}
		
		bool isEmpty(){
			if(head == NULL){
				return true;
			}else{
				return false;
			}
		}
		
		void addHead(int n){
			if(isEmpty()){
				head = new Node(NULL,n,NULL);
				tail = head;
			}else{
				Node *p;
				p = new Node(NULL,n,NULL);
				head->prev = p;
				head = p;
			}
		}
		
		void addTail(int n){
			if(isEmpty()){
				addHead(n);
			}else{
				Node *p = new Node(NULL,n,NULL);
				tail->next = p;
				tail = p;
			}
		}
		
		void insert(int val, int pos){
			int count = 0;
			for(Node *p = head; p!=NULL; p = p->next){
				count++;
			}
			if(pos<1 || pos > count+1){
				cout << "wrong input";
			}else if(pos == 1){
				addHead(val);
			}else if(pos == count+1){
				addTail(val);
			}else{
				Node *p = head, *q;
				for(int i=0; i<pos; i++){
					q=p;
					p = p->next;
				}
				Node *r = new Node(q,val,p);
				q->next = p->prev = r;
			}
		}
		
		void traverse(){
			if(isEmpty()){
				cout << "EMPTY";
			}else{
				for(Node *p =head; p!=NULL; p=p->next){
					cout << p->data << "\t";
				}
			}
		}
		
		void search(int n){
			int flag = 0;
			for (Node *p = head; p!=NULL; p= p->next){
				if(p->data ==n){
					flag++;
					cout << "found";
					break;
			}
			if(flag==0){
				cout << "Not found";
			}
		}
	}
	
	int removeHead(){
		if(isEmpty()){
			cout << "LL is empty";
		}else if(head == tail){
			int temp = head->data;
			delete head;
			head = tail = NULL;
			return temp;
		}else{
			int temp = head->data;
			Node *p = head;
			head = head->next;
			delete p;
			head->prev = NULL;
			return temp;
		}
	}
	
	int removeTail(){
		if(isEmpty()){
			cout << "LL is empty";
		}else if(head == tail){
			int temp = head->data;
			delete head;
			head = tail = NULL;
			return temp;
		}else{
			int temp = tail->data;
			Node *p = tail;
			tail = tail->prev;
			delete p;
			tail->next = NULL;
		}
	}
	
	int deleteKey(int n){
		if(isEmpty()){
			cout << "LL is empty";
		}else if(head->data == n){
			return removeHead();
		}else if(tail->data == n){
			return removeTail();
		}else{
			Node *p = head->next;
			while(p->data!=n && p!=NULL){
				p = p->next;
			}if(p == NULL){
				cout << "not found";
				return 0;
			}else{
				Node *q = p->prev;
				Node *r = p->next;
				delete p;
				q->next = r;
				r->prev = q;
				return n;
			}
		}
	}
};
