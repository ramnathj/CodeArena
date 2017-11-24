#include <iostream>

using namespace std;

typedef long long int Lint;

struct Node {
	
	Lint data;
	struct Node* left;
	struct Node* right;	
};

struct Node* createNode( Lint val ) {
	
	struct Node* p = new Node;
	p->data = val;
	p->left = p->right = NULL;

	return p;
}

int search( struct Node* root, Lint val ) {
	
	if( root == NULL ) {
		return 0;
	}

	while( root != NULL ) {

		if( val < root->data ) {
			root = root->left;
		} else if( val > root->data ) {
			root = root->right;
		} else {
			return 1;
		}
	}

	return 0;
}

struct Node* insert( struct Node* root, Lint val ) {
	
	if( root == NULL ) {
		root = createNode( val );
		return root;
	} else {

		struct Node* head = root;

		while( head != NULL ) {
			if( val < head->data ) {
				if( head->left == NULL ) {
					head->left = createNode( val );
					break;
				} else {
					head = head->left;
				}
			} else {
				if( head->right == NULL ) {
					head->right = createNode( val );
					break;
				} else {
					head = head->right;
				}				
			}
		}

		return root;
	}	
}

int main() {
	
	ios_base::sync_with_stdio( false );

	Lint t, n, m, i, val;

	cin >> t;

	while( t-- ) {

		cin >> n >> m;
		struct Node* root = NULL;

		for( i = 0;i < n;i++ ) {
			cin >> val;
			root = insert( root, val );
		}

		for( i = 0;i < m;i++ ) {
			cin >> val;
			if( search( root, val ) ) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
			root = insert( root, val );
		}
	}
	
	return 0;
}