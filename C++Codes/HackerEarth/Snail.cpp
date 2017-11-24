#include <iostream>

using namespace std;

struct Node {
	
	int data;
	struct Node* left;
	struct Node* right;	
};

struct Node* createNode( int val ) {

	struct Node* p = new Node;
	p->data = val;
	p->left = p->right = NULL;

	return p;
}

struct Node* searchNode( struct Node* root, int val ) {

	if( root != NULL ) {
		if( root->data == val ) {
			return root;
		}
		struct Node* l = searchNode( root->left, val );
		if( l == NULL ) {
			l = searchNode( root->right, val );
		}
		return l;
	} 	

	return NULL;
}

void preOrder( struct Node* root ) {

	if( root != NULL ) {
		cout << root->data << " ";
		preOrder( root->left );
		preOrder( root->right );
	}
}

int main() {

	ios_base::sync_with_stdio( false );

	int t, n, i, x, y, z;

	cin >> t;

	while( t-- ) {
		cin >> n;

		if( n == 0 ) {
			cout << "1\n";
		} else {

			cin >> x >> y >> z;

			struct Node* root = createNode( x );
			root->left =  y ? createNode( y ) : NULL;
			root->right = z ? createNode( z ) : NULL;
			struct Node* head = root;

			for( i = 1;i < n;i++ ) {
				cin >> x >> y >> z;
				root = searchNode( root, x );
				if( root != NULL ) {
					root->left =  y ? createNode( y ) : NULL;
					root->right = z ? createNode( z ) : NULL;
					root = head;
				}
			}

			preOrder( root );
			cout << "\n";
		}
	}
}