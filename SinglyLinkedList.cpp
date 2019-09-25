#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node(int val=0, Node *n=NULL){
			data = val;
			next = n;
		}
};

class LinkedList
{
	private:
		Node *head, *tail;
	
	public:
		LinkedList()
		{
			head = tail = NULL;
		}
		bool isEmpty()
		{
			if(head == NULL)
				return true;
				
			else
				return false;
		}
		void addHead(int n)
		{
			if(isEmpty())
			{
				head = new Node(n,NULL);
				tail = head;
			}
			else
			{
				Node *p = new Node(n,head);
				head = p;
				
			}
		}
		
		void addTail(int n)
		{
			if(isEmpty())
			{
				head = new Node(n,NULL);
				tail = head;
			}
			else
			{
				Node *p = new Node(n,NULL);
				tail->next = p;
				tail = p;
			}
		}
		
		void insert(int val, int pos)
		{
			int count=0;
			for(Node *p=head ; p!=NULL ; p = p->next)
				count++;
			
			if(pos<1 || pos>count+1)
			{
				cout << "Invalid Position";
			}
			else if(pos == 1)
				addHead(val);
			else if(pos == count+1)
			{
				addTail(val);
			}
				
			else
			{
				Node *r = head;
				for(int i=1 ; i<=pos-2 ; i++)
					r = r->next;
				
				Node *p = new Node(val,r->next);
				r->next = p;
			}
		}
		void traverse(void)
		{
			if(isEmpty())
				cout << "LinkedList is Empty";
			
			else
			{
				for(Node *p=head ; p!=NULL ; p=p->next)
				{
					cout << p->data << "\t";
				}
			}
		}
		
		void search(int n)
		{
			int isFound = 0;
			for(Node *p=head ; p!=NULL ; p=p->next)
			{
				if(p->data == n)
				{
					isFound = 1;
					cout << "Found";
					break;
				}
			}
			
			if(isFound == 0)
				cout << "Data not Found";
		}
		
		int removeHead()
		{
			if(isEmpty())
			{
				cout << "LinkedList is Empty";
				return 0;
			}
			else
			{
				int temp = head->data;
				Node *p = head;
				head = head->next;
				if(head==NULL)
					tail = NULL;
				
				delete p;
				return temp;
			}
		}
		
		int removeTail()
		{
			if(isEmpty())
			{
				cout << "LinkedList is Empty";
				return 0;
			}
			else if(head == tail)
				return removeHead();
				
			else
			{
				Node *p = head;
				while(p->next != tail)
					p = p->next;
				
				int temp = tail->data;
				delete tail;
				p->next = NULL;
				tail = p;
				return temp;
			}
		}
		int deletekey(int n)
		{
			if(isEmpty())
			{
				cout << "LinkedList is Empty";
				return 0;
			}
			
			else if(head->data == n)
				return removeHead();
				
			else if(tail->data == n)
				return removeTail();
				
			else
			{
				Node *p, *q;
				for(p=head ; p!=NULL && p->data!=n ; p=p->next)
					q=p;
				
					
				if(p!=NULL)
				{
					q->next = p->next;
					delete p;
					return n;
				}
				else
				{
					cout << "Data Not Found";
					return 0;
				}
			}
		}
		
		void reverse(Node *p = NULL, int n=0)
		{
			if(isEmpty())
			{
				cout << "LinkedList Is Empty";
			}
			else
			{
				if(n == 0)
				{
					p=head;
					n++;
				}
				
				if(p->next!=NULL)
				{
					reverse(p->next,n);	
				}
				cout << p->data << "\t";
			}
		}
		
		void sorting()
		{
			Node *p,*q;
			Node *temp;
			for(p=head ; p!=NULL ; p=p->next)
			{
				int m = p->data;
				for(q=p->next ; q!=NULL ; q=q->next)
				{
					if(q->data < m)
					{
						m = q->data;
						temp = q;
					}
				}
				if(m != p->data)
				{
					int tp = p->data;
					p->data = temp->data;
					temp->data = tp;
				}
			}
		}
		
		
		~LinkedList()
		{
			while(!isEmpty())
				removeHead();
		}
		
};

int main()
{
	LinkedList l;
	int x;
	do
	{
		cout << "\n1. Add Head" << endl;
		cout << "2. Add Tail" << endl;
		cout << "3. Insert" << endl;
		cout << "4. Search" << endl;
		cout << "5. Remove Head" << endl;
		cout << "6. Remove Tail" << endl;
		cout << "7. Delete Key" << endl;
		cout << "8. Traverse" << endl;
		cout << "9. Reverse" << endl;
		cout << "10. Sorting" << endl;
		cout << "Select: ";
		cin >> x;
		
		if(x == 1)
		{
			int num;
			cout << "Enter Number: ";
			cin >> num;
			l.addHead(num);
		}
			
		else if(x == 2)
		{
			int num;
			cout << "Enter Number: ";
			cin >> num;
			l.addHead(num);
		}
		else if(x == 3)
		{
			int num;
			int pos;
			cout << "Enter Pos: ";
			cin >> pos;
			cout << "Enter Number: ";
			cin >> num;
			l.insert(num,pos);
		}
		else if(x == 4)
		{
			int num;
			cout << "Enter Number: ";
			cin >> num;
			l.search(num);
		}
		
		else if(x == 5)
		{
			cout << l.removeHead();
		}
		else if(x == 6)
		{
			cout << l.removeTail();
		}
		else if(x == 7)
		{
			int num;
			cout << "Enter Number to Delete: ";
			cin >> num;
			l.deletekey(num);
		}
		else if(x == 8)
		{
			l.traverse();
		}
		
		else if(x == 9)
		{
			l.reverse();
		}
		else if(x == 10)
		{
			l.sorting();
		}
			
	}while(1);

}
