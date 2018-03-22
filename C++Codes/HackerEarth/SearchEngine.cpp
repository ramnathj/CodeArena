#include <iostream>
#define sz 1000001

using namespace std;

struct Node {
	char ch;
	int maxVal;
	int isLeaf;
	struct Node* child[ 26 ];
};


struct Node* createNode( char c, int val ) {
	struct Node* p = new Node;
	p->ch = c;
	p->maxVal = val;
	p->isLeaf = 0;
	for( int  i = 0;i < 26;i++ ) {
		p->child[ i ] = NULL;
	}
	return p;
}

void insertNode( struct Node* root, char* s, int val ) {
	
	struct Node* head = root;
	int idx, i;
	for( i = 0;s[ i ];i++ ) {
		idx = s[ i ] - 97;
		if( head->child[ idx ] == NULL ) {
			head->child[ idx ] = createNode( s[ i ], val );
		} else {
			head->child[ idx ]->maxVal = max( head->child[idx]->maxVal, val );
		}
		head = head->child[ idx ];
	}
	head->isLeaf = 1;
}

int findWeight( struct Node* root, char* s ) {
	
	struct Node* head = root;

	int i, idx;

	for( i = 0;s[ i ];i++ ) {
		idx = s[ i ] - 97;
		if( head->child[ idx ] == NULL ) {
			return -1;
		}
		head = head->child[ idx ];
	}

	return head->maxVal;
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int n, m, i, val;

	cin >> n >> m;

	struct Node* root = createNode('\0', -1);
	for( i = 0;i < n;i++ ) {
		char *s = new char[ sz ];
		cin >> s >> val;
		insertNode( root, s, val );
		delete s;
	}

	for( i = 0;i < m;i++ ) {
		char *s = new char[ sz ];
		cin >> s;
		cout << findWeight( root, s ) << "\n";
		delete s;		
	}

	return 0;
}
