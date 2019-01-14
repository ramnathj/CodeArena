#include <iostream>

using namespace std;

struct Node {
	int isLeaf;
	struct Node* child[ 128 ];	
};
struct Node* root;
char str[1001];
int globalNodeCount;

struct Node* createNode() {
	
	struct Node* p =  new Node;
	p->isLeaf = 0;
	for( int i = 0;i < 128;i++ ) {
		p->child[ i ] = NULL;
	}	
	return p;
}

void insert(char *s) {
	int i, idx;
	struct Node* head = root;
	for( i = 0;s[i];i++ ) {
		idx = s[i];
		if( head->child[ idx ] == NULL ) {
			globalNodeCount++;
			head->child[idx] = createNode();
		}
		if( s[i+1] == '\0') {
			head->child[idx]->isLeaf = 1;
		}
		head = head->child[idx];
	}
}

int main() {
	
	int t, i;

	cin >> t;

	while( t-- ) {
		cin >> str;
		root = createNode();
		globalNodeCount = 0;
		for( i = 0;str[i];i++ ) {
			insert( str + i );
		}
		cout << globalNodeCount << "\n";
	}
	return 0;
}