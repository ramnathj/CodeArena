#include <iostream>

using namespace std;

char st[11];

struct Node {
	bool isLeaf;
	struct Node* child[10];
};

struct Node* root;
struct Node nodePool[5000000];

int it;

struct Node* createNode() {
	struct Node* p = &nodePool[it++];
	p->isLeaf = false;
	for( int i = 0;i < 10;i++ ) {
		p->child[i] = NULL;
	}
	return p;
}

bool insert(char* str) {
	
	register int i, idx;
	register bool flag = false;
	struct Node* head = root;
	
	for( i = 0;str[i];i++) {
		idx = str[i] - '0';
		if( head->child[idx] == NULL ) {
			flag = true;
			head->child[idx] = createNode();
		} else {
			if( head->child[idx]->isLeaf ) {
				return false;
			}
		}
		if( str[i+1] == '\0' ) {
			head->child[idx]->isLeaf = true;
		}
		head = head->child[idx];
	}

	if( flag ) {
		return true;
	}

	return false;
}

int main() {
	
	register int t, n, i;
	register bool flag;
	cin >> t;
	it = 0;

	while( t-- ) {
		cin >> n;
		flag = true;
		root = createNode();
		for( i = 0;i < n;i++ ) {
			cin >> st;
			if( !insert(st) ) {
				flag = false;
			}
		}
		if( flag ) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
