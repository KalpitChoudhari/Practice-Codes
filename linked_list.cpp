/*
Author	- RooT NovA
Program - Linked List
To Do	- 1. Insert at middle
	  2. Delete from given key	
	  3. Sort list
	  4. Swap elements
*/
#include <bits/stdc++.h>
#define endl cout<<"\n";
using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node(int d){
			data = d;
			next = NULL;
		}
};

void push(Node** head_ref, int data) {
	Node *new_node = new Node(data);
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void insert_end(Node** head_ref, int data) {
	Node *iterator = (*head_ref);
	Node *new_node = new Node(data);
	
	if(iterator == NULL) {
		(*head_ref) = new_node;
		return;
	}
	
	while(iterator->next != NULL)
		iterator = iterator->next;
	
	iterator->next = new_node; 
	return;
}

void printList(Node* node) {
	if(node == NULL) {
		cout<<"\nLIST IS EMPTY!!\n";
		return;
	}
	while(node != NULL) {
		if(node->next == NULL)
			cout<<node->data<<"\n";
		else
			cout<<node->data<<" -> ";
		node = node->next;
	}
}

void delete_front(Node** head_ref) {
	if((*head_ref) == NULL) {
		cout<<"\nSORRY, LIST IS EMPTY!!\n";
		return;
	}
	
	cout<<(*head_ref)->data<<" is deleted.\n";
	(*head_ref) = (*head_ref)->next;
	return;
}

Node* delete_end(Node *head_ref) {
	if(head_ref == NULL) {
		cout<<"\nSORRY, LIST IS EMPTY!!\n";
		return NULL;
	}
	
	if(head_ref->next == NULL) {
		cout<<head_ref->data<<" is deleted.\n";
		delete(head_ref);
		return NULL;
	}
	
	Node *s_l = head_ref;	//Second last
	while(s_l->next->next != NULL)
		s_l = s_l -> next;
	
	cout<<s_l->next->data<<" is deleted.\n";
	delete(s_l->next);	//Deleting last node
	s_l->next = NULL;
	
	return head_ref;
}

int main() {
	int ch, data;
	Node *head = NULL;
	do {
		cout<<"1.Insert at front\n2.Insert at end\n3.Delete at front\n4.Delete at end\n\n8.Print\n9.Exit";
		cout<<"\nEnter your choice:";
		cin>>ch;
		endl;
		switch(ch) {
			case 1:
				cout<<"\nEnter element to be insert at front:";
				cin>>data;
				push(&head, data);
				break;
			case 2:
				cout<<"\nEnter element to be insert at end:";
				cin>>data;
				insert_end(&head, data);
				break;
			case 3:
				delete_front(&head);
				break;
			case 4:
				head = delete_end(head);
				break;
			case 8:
				printList(head);
				break;
			default:
				break;
		}
	}while(ch!=9);
	return 0;
}
