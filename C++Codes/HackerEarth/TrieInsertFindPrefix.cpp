#include <iostream>

using namespace std;


struct Node {
	
	char ch;
	int count;
	int isLeaf;
	struct Node* child[ 26 ];	
};

struct Node* createNode( char c ) {
	int i;
	struct Node* p = new Node;
	p->ch = c;
	p->isLeaf = 0;
	p->count = 1;
	for( i = 0;i < 26;i++ ) {
		p->child[ i ] = NULL;
	}	

	return p;
}

void insert( struct Node* root, char* s ){
	
	struct Node* head = root;
	int i, idx;

	for( i = 0;s[ i ];i++ ) {
		idx = s[ i ] - 'a';
		if( head->child[ idx ] == NULL ) {
			head->child[ idx ] = createNode( s[ i ] );
		} else {
			(head->child[ idx ]->count)++;
		}
		head = head->child[ idx ];
	}
	head->isLeaf = 1;	
}

int find( struct Node* root, char* s ) {

	struct Node* head = root;
	int i, idx;
	for( i = 0;s[ i ];i++ ) {
		idx = s[ i ] - 'a';
		if( head->child[ idx ] == NULL ) {
			return 0;
		}
		head = head->child[ idx ];
	}	
	return head->count;
}

int main() {
	
	int q;
	struct Node* root = createNode(' ');
	cin >> q;

	while( q-- ) {
		char *cmd = new char[ 10 ];
		char* str = new char[ 30 ];

		cin >> cmd >> str;

		if( cmd[ 0 ] == 'a' ) {
			insert(root, str);
		} else {
			cout << find( root, str ) << "\n";
		}
		delete cmd;
		delete str;
	}

	return 0;
}