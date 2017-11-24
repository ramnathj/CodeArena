#include <iostream>

using namespace std;

struct Node {
	
	int data;
	struct Node* left;
	struct Node* right;	
};

struct Node* createNode( int val ) {
	
	struct Node* root = new Node;
	root->data = val;
	root->left = root->right = NULL;

	return root;	
}

struct Node* insert( struct Node* root, int val ) {
	
	struct Node* head = root;

	while( root != NULL ) {
		if( root->data <= val ) {
			if( root->right == NULL ) {
				root->right = createNode( val );
				break;
			} else {
				root = root->right;
			}
		} else {
			if( root->left == NULL ) {
				root->left = createNode( val );
				break;
			} else {
				root = root->left;
			}
		}
	}

	return head;
}

int getHeight( struct Node* root ) {
	
	if( root == NULL ) {
		return 0;
	} else {
		return 1 + max( getHeight( root->left ), getHeight( root->right ) );
	}
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int n, i, val;

	cin >> n;

	cin >> val;

	struct Node* root = createNode( val );
	
	for( i = 1;i < n;i++ ) {
		cin >> val;
		root = insert( root, val );
	}

	cout << getHeight( root ) << "\n";

	return 0;
}