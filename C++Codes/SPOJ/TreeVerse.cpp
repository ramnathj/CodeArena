#include <iostream>
#include <stdio.h>

using namespace std;

int n;
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode( int val ) {
	struct Node* p = new Node;
	p->data = val;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void pre( struct Node* root ) {
	static int count = 0;
	if( root != NULL ) {
		if( count == n - 1 ) {
			cout << root->data;
		} else {
			cout << root->data << " ";			
		}
		count++;
		pre(root->left);
		pre(root->right);
	}
}

void in( struct Node* root ) {
	static int count = 0;
	if( root != NULL ) {
		in(root->left);
		if( count == n - 1 ) {
			cout << root->data;
		} else {
			cout << root->data << " ";			
		}
		count++;
		in(root->right);
	}
}

void post( struct Node* root ) {
	static int count = 0;
	if( root != NULL ) {
		post(root->left);
		post(root->right);
		if( count == n - 1 ) {
			cout << root->data;
		} else {
			cout << root->data << " ";			
		}
		count++;
	}
}

void insertNode( struct Node* root, int val ) {
	struct Node* head = root;
	struct Node* prev = root;

	while( head != NULL ) {
		if( val < head->data ) {
			prev = head;
			head = head->left;
		} else {
			prev = head;
			head = head->right;
		}	
	}

	if( val < prev->data ) {
		prev->left = createNode( val );
	} else {
		prev->right = createNode( val );
	}

}

int main() {
	
	int i, val;
	struct Node* root = NULL;
	scanf("%d", &n );	
	scanf("%d", &val );
	root = createNode( val );

	for( i = 1;i < n;i++ ) {
		scanf("%d", &val );
		insertNode( root, val );
	}

	cout << "Pre order : ";
	pre(root); 
	cout << "\n";
	cout << "In order  : " ;
	in(root);
	cout << "\n";
	cout << "Post order: ";
	post(root);
	cout << "\n";

	return 0;
}