/*
Author		- RooT_NovA
Program		- Understanding basic concepts of Binary Search Tree
*/

#include <iostream>
#include <stack>
using namespace std;


//Structure of Tree Node
struct node {
	int data;
	struct node* left;
	struct node* right;
};

//Creation of new node and allocating space with given element
struct node* newNode(int item) {
	struct node* temp = (struct node* )malloc(sizeof (struct node));
	temp->data = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

//Insertion in BST
struct node* insert(struct node* node, int item) {
	//If node is null then create new node and allocte dummy node to root node and return root.
	if(node == NULL)
		return newNode(item);
		
	//If element > curr_tree_element then look for right side(Recursive Call)
	if(item > node->data)
		node->right = insert(node->right, item);
	//If element < curr_tree_element then look for left side(Recursive Call)
	else
		node->left = insert(node->left, item);
	return node;
}

//Recursive Inorder Traversal (LVR - Left Vertex Right)
void r_inorder(struct node* root) {
	if(root != NULL) {
		r_inorder(root->left);
		cout<<root->data<<"  ";
		r_inorder(root->right);
	}
}

void r_preorder(struct node* root) {
	if(root != NULL) {
		cout<<root->data<<"  ";
		r_preorder(root->left);
		r_preorder(root->right);
	}
}

void r_postorder(struct node* root) {
	if(root != NULL) {
		r_postorder(root->left);
		r_postorder(root->right);
		cout<<root->data<<"  ";
	}
}

void nr_preorder(struct node* root) {
	struct node* temp = root;
	stack<struct node *> st;
	
	while(!st.empty() || temp != NULL) {

		while(temp != NULL) {
			cout<<temp->data<<"  ";
		
			if(temp->right)
				st.push(temp->right);
		
			temp = temp->left;
		}
		
		if(st.empty() == false) {
			temp = st.top();
			st.pop();
		}
	}
}

//Using two stacks
void nr_postorder(struct node* root) {
	stack<node *> st1, st2;
	node* node;
	
	st1.push(root);
	
	while(!st1.empty()) {
		node = st1.top();
		st2.push(node);
		st1.pop();
		
		if(node->left)
			st1.push(node->left);
		if(node->right)
			st1.push(node->right);
	}
	
	while(!st2.empty()) {
		node = st2.top();
		st2.pop();
		cout<<node->data<<"  ";
	}
}

void nr_inorder(node* root) {
	struct node* temp = root;
	stack<node *> st;
	
	while(!st.empty() || temp != NULL) {
	
		while(temp != NULL) {
			st.push(temp);
			temp = temp->left;
		}
		if(st.empty() == false) {
			temp = st.top();
			st.pop();
		}
		cout<<temp->data<<"  ";
		temp = temp->right;
	}
}

//Finding the minimum value from given non-empty BST(Obviously it will be on left portion).
//Here, no need to traverse whole tree. Just traverse left part(left skewed)
struct node* minVal(struct node* node) {
	struct node* curr = node;
	while(curr && curr->left != NULL)
		curr = curr->left;
	return curr;
}

struct node* deleteNode(struct node* root, int item) {
	if(root == NULL)	return root;
	
	//If data to be deleted < root->data then go for left portion
	if(root->data > item)
		root->left = deleteNode(root->left, item);

	//If data to be deleted > root->data then go for right portion
	else if(root->data < item)
		root->right = deleteNode(root->right, item);
	
	//Else data = root->data
	else {
		//Node has no children or one children
		if(root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		
		//If node has 2 childrens then get inorder successor i.e. Leftmost(min val) child from right sub-tree.
		struct node* temp = minVal(root->right);
		
		//After getting inorder successor from tree as node, copy data to root node;
		root->data = temp->data;
		
		//Delete inorder successor (Node from which we copy min val Because we copied it to node which we wanted to delete)
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

bool search_key(struct node* root, int item) {
	if(root == NULL)
		return false;
	else if(root->data > item)
		search_key(root->left, item);
	else if(root->data < item)
		search_key(root->right, item);
	else if(root->data == item)
		return true;
}

//Main Function
int main() {
	struct node* root = NULL;
	int ch, item;
	do {
		cout<<"\n-----------------MAIN MENU------------------";
		cout<<"\n\n\t\t1.Insert\n\t\t2.Delete\n\t\t3.Display\n\t\t4.Search Element\n\t\t5.Exit";
		cout<<"\n\n--------------------------------------------";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch) {
			case 1:
				cout<<"\nEnter data to insert in BST:";
				cin>>item;
				if(root == NULL)
					root = insert(root, item);
				else
					insert(root, item);
				break;
			case 2:
				cout<<"\nEnter data to be deleted:";
				cin>>item;
				root = deleteNode(root, item);
				if(root == NULL)
					cout<<"TREE is Empty. Please enter elements first!";
				else {
					cout<<item<<" deleted successfully!";
					cout<<"\nInorder Traversal :";
					r_inorder(root);
					cout<<endl;
				}
				break;
			case 3:
				if(root == NULL)
					cout<<"TREE is Empty. Please enter elements first!";
				else {
					int ch1;
					do {
						cout<<"\n----------------DISPLAY TREE----------------";
						cout<<"\n\n\t1.Recursive Inorder\n\t2.Recursive Preorder\n\t3.Recursive Postorder";
						cout<<"\n\t4.Non-Recursive Inorder\n\t5.Non-Recursive Preorder\n\t6.Non-Recursive Postorder";
						cout<<"\n\t7.Main Menu";
						cout<<"\n\n--------------------------------------------";
						cout<<"\nEnter your choice:";
						cin>>ch1;
						cout<<endl;
						switch(ch1) {
							case 1:
								cout<<"Recursive Inorder : ";
								r_inorder(root);
								cout<<endl;
								break;
							case 2:
								cout<<"Recursive Preorder : ";
								r_preorder(root);
								cout<<endl;
								break;
							case 3:
								cout<<"Recursive Postorder : ";
								r_postorder(root);
								cout<<endl;
								break;
							case 4:
								cout<<"Non-Recursive Inorder : ";
								nr_inorder(root);
								cout<<endl;
								break;
							case 5:
								cout<<"Non-Recursive Preorder : ";
								nr_preorder(root);
								cout<<endl;
								break;
							case 6:
								cout<<"Non-Recursive Postorder : ";
								nr_postorder(root);
								cout<<endl;
								break;
							default:
								cout<<"Returning to MAIN MENU...";
								cout<<endl;
								break;
						}
					}while(ch1 < 7);
				}
				break;
			case 4:
				cout<<"\nEnter data to be searched:";
				cin>>item;
				if(root == NULL)
					cout<<"TREE is Empty. Please enter elements first!";
				else
					search_key(root, item) ? cout<<" Key Found" : cout<<" Key not found";
				cout<<endl;
			default:
				cout<<"BYE\n";
				break;
		}
	}while(ch < 5);
	
	return 0;
}
