#include <iostream>

using namespace std;

struct Node {
	
	char ch;
	int isLeaf;
	int count;
	struct Node* child[ 26 ];
};

struct Node* createNode( char c ) {
	struct Node* p = new Node;
	p->ch = c;
	p->count = 1;
	p->isLeaf = 0;
	for( int i = 0;i < 26;i++ ) {
		p->child[ i ] = NULL;
	}

	return p;
}

void insert( struct Node* root, char* s ) {
	
	int i, idx;
	struct Node* head = root;
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
	
	int i, idx;
	struct Node* head = root;
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
	
	int n, q;
	struct Node* root = createNode(' ');
	
	cin >> n >> q;
	while( n-- ) {
		char* str = new char[ 100001 ];
		cin >> str;
		insert( root, str );
		delete str;
	}

	while( q-- ) {
		char* str = new char[ 100001 ];
		cin >> str;
		cout << find( root, str ) << "\n";
		delete str;		
	}
	return 0;
}