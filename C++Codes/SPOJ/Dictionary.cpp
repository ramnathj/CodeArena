#include <iostream>

using namespace std;

struct Node {
	bool isLeaf;
	struct Node* child[ 26 ];
};

struct Node* root;
char str[21];
char searchStr[21];
char suffix[21];

struct Node* createNode() {
	struct Node* p = new Node;
	p->isLeaf = false;
	for( int i = 0;i < 26;i++ ) {
		p->child[i] = NULL;
	}
	return p;
}

void insert(char *s) {
	
	int i, idx;

	struct Node* head = root;
	for( i = 0;s[i];i++ ) {
		idx = s[i] - 'a';
		if( head->child[idx] == NULL ) {
			head->child[idx] = createNode();
		}
		if( s[i+1] == '\0' ) {
			head->child[idx]->isLeaf = true;
		}
		head = head->child[ idx ];
	}
}

struct Node* getNode(char* s) {
	
	struct Node* head = root;
	int idx, i;

	for( i = 0;s[i];i++ ) {
		idx = s[i] - 'a';
		if( head->child[idx] == NULL ) {
			return NULL;
		}
		head = head->child[idx];
	}

	return head; 
}

void printStr(struct Node* head, int level, char* prefixStr){
	if( head->isLeaf ) {
		suffix[level] = '\0';
		if( level ) {
			cout << prefixStr << suffix << "\n";
		}
	}
	for( int i = 0;i < 26;i++ ) {
		if( head->child[i] != NULL ) {
			suffix[level] = (char)('a' + i);
			printStr(head->child[i], level + 1, prefixStr);
		}
	}	
} 

int main() {
	
	int n, k, i, tc = 1;

	cin >> n;

	root = createNode();

	while( n-- ) {
		cin >> str;	
		insert(str);
	}

	cin >> k;

	while( tc <= k ) {
		
		cin >> searchStr;
		cout << "Case #" << tc << ":\n";
		struct Node* h = getNode(searchStr);
		if( h != NULL ) {
			printStr(h, 0, searchStr);
		} else {
			cout << "No match.\n";
		}
		tc++;
	}

	root = NULL;
	return 0;
}