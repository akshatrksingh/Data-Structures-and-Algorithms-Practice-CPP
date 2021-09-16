#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node *next;

	node(int d)
	{
		data = d;
		next = NULL;
	}
};

void build()
{

}

void insertAtBeg(node *&head, int d)
{
	if(head == NULL)
	{
		head = new node(d);
		return;
	}

	node *n = new node(d);
	n->next = head; // (*n).next = head;
	head = n; 
}

void display(node *head)
{
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
}

int main()
{
	node *head = NULL;
	insertAtBeg(head, 21);
	insertAtBeg(head, 5);
	insertAtBeg(head, 2);
	insertAtBeg(head, 54);
	display(head);
}