#include <iostream>

using namespace std;

typedef long long int Lint;

struct Node {
	
	Lint data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode( Lint val, struct Node* par ) {
	
	struct Node* root = new Node;
	root->data = val;
	root->left = root->right = NULL;

	return root;
}

struct Node* insert( struct Node* root, Lint val ) {
	
	struct Node* head = root;

	while( root != NULL ) {

		if( val < root->data ) {
			if( root->left == NULL ) {
				root->left = createNode( val, root );
				break;
			} else {
				root = root->left;
			}
		} else {
			if( root->right == NULL ) {
				root->right = createNode( val, root );
				break;
			} else {
				root = root->right;
			}			
		}
	}

	return head;
}

void storePath( struct Node* root, Lint val, Lint* A, Lint& n1 ) {

	while( root != NULL ) {

		if( val < root->data ) {
			A[ n1++ ] = root->data;
			root = root->left;
		} else if( val > root->data ) {
			A[ n1++ ] = root->data;
			root = root->right;
		} else {
			A[ n1++ ] = val;
			break;
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio( false );

	Lint n, i, val, n1, n2, x, y, maxVal, pos;

	cin >> n;

	cin >> val;

	struct Node* root = createNode( val, NULL );


	for( i = 1;i < n;i++ ) {
		cin >> val;
		root = insert( root, val );
	}

	cin >> x >> y; 
	Lint *A = new Lint[ n ];
	Lint *B = new Lint[ n ];
	n1 = n2 = 0;

	storePath( root, x,  A, n1 );
	storePath( root, y,  B, n2 );

/*	cout << "Path for X\n";
	for( i = 0;i < n1;i++ ) {
		cout << A[ i ] << " ";
	}
	cout << "\n";

	cout << "Path for Y\n";
	for( i = 0;i < n2;i++ ) {
		cout << B[ i ] << " ";
	}
	cout << "\n";
*/
	pos = 0;
	flag = 0;
	for( i = 0;i < min( n1, n2 );i++ ) {
		if( A[ i ] != B[ i ] ) {
			pos = i - 1;
			flag = 1;
			break;
		}
	}
	if( !flag ) {
		pos = min(n1, n2) - 1;
	}
	
	maxVal = -1;
	for( i = pos;i < n1;i++ ) {
		maxVal = max( A[ i ], maxVal );
	}
	for( i = pos;i < n2;i++ ) {
		maxVal = max( B[ i ], maxVal );
	}

	cout << maxVal << "\n";

	delete A;
	delete B;

	return 0;
}
