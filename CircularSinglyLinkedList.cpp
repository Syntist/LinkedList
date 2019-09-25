#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node(int val=0; Node *n=NULL){
			data = val;
			next = n;
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
				head = new Node(n,NULL);
				head->next = head;
				tail = head;
			}else{
				Node *p = new Node(n,head);
				head = p;
				tail->next = head;
			}
		}
		
		void addTail(int n){
			if(isEmpty()){
				addHead(n);
			}else{
				Node *p = new Node(n,head);
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
				cout << "wronf input";
			}else if(pos == 1){
				addHead(val;)
			}else if(pos == count+1){
				addTail(val);
			}else{
				Node *r = head;
				for(int i=0; i<=pos-2; i++){
					r = r->next;
				}
				Node *p = new Node(val, r->next);
				r->next = p;
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
				return 0;
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
		}
		else{
			int temp = head->data;
			Node *p = head;
			head = head->next;
			delete p;
			tail->next = head;
			return temp;
		}
		if(head == NULL){
			tail = NULL;
		}
		delete p;
		return temp;
	}
	
	int removeTail(){
		if(isEmpty()){
			cout << "LL is empty";
		}else if(head == tail){
			return removeHead();
		}else{
			Node *p = head;
			do{
				p=p->next;
			}while(p->next!=tail);
			int temp = tail->data;
			delete tail;
			p->next = NULL;
			tail->next = head;
			tail = p;
			return temp;
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
			Node *p,*q;
			p = head;
			while(p!=NULL || p->data!=n){
				q = p;
				p = p->next;
			}if(p!=NULL){
				q->next = p->next;
				delete p;
				return n;
			}else{
				cout << "not found";
				return 0;
			}
		}
	}
};
